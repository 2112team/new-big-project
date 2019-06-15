#include "Player.h"

float g_fPlySpeed = 1.5f;

static CPlayer *s_plySprite = NULL;
CPlayer* CPlayer::getInstance()
{
	if (s_plySprite == NULL)
		s_plySprite = CPlayer::create();

	return s_plySprite;
}
bool CPlayer::init()
{
	if (!Layer::init())
		return false;

	auto size = Director::getInstance()->getVisibleSize();
	m_pPlySprite = Sprite::createWithSpriteFrameName("hero_walk_1.png");
	m_pPlySprite->setScale(1.5);
	m_pPlySprite->setPosition(Vec2(100  , size.height / 2));
	this->addChild(m_pPlySprite);
	//初始化血条
	this->initHp();

	this->scheduleUpdate();
		
	m_fSpeed = 100;
	m_iDirection = STAY;
	m_iWalkState = STAY;
	m_fMapMoveX = 0;
	m_bisOver = false;

	return true;
}
void CPlayer::setNull()
{
	s_plySprite = NULL;
}
void CPlayer::update(float dt)
{

}

void CPlayer::initHp()
{
	m_pHPBG = Sprite::create("hero/hp_bg.png");
	m_pHPBG->setAnchorPoint(Vec2(0.5, 0.5));
	m_pHPBG->setPosition(Vec2(25, 70));
	m_pPlySprite->addChild(m_pHPBG, 2);
	auto sizeOfBG = m_pHPBG->getContentSize();

	auto m_pHPProgess = ProgressTimer::create(Sprite::create("hero/hp.png"));
	m_pHPProgess->setType(ProgressTimer::Type::BAR);
	m_pHPProgess->setMidpoint(Vec2(0, 0));
	m_pHPProgess->setBarChangeRate(Vec2(1, 0));
	m_pHPProgess->setPosition(Vec2(sizeOfBG.width / 2, sizeOfBG.height / 2));
	m_pHPProgess->setPercentage(100.0f);
	m_pHPBG->addChild(m_pHPProgess, 2);
}

void CPlayer::walkMove(Vec2 midPos, Vec2 distPos)
{
	//移动前先停止所有动作
	plyStayPost();
	//判断方向
	m_iDirection = distPos.x > m_pPlySprite->getPositionX() ? RIGHT : LEFT;

	auto allTime = getDist(m_pPlySprite->getPosition(), distPos) / m_fSpeed;
	auto midTime = getDist(m_pPlySprite->getPosition(), midPos) / m_fSpeed;
	auto waitTime = allTime - midTime;
	auto moveToX = MoveTo::create(midTime, midPos);
	auto delay = DelayTime::create(waitTime);
	auto func = CallFunc::create(CC_CALLBACK_0(CPlayer::plyStayPost, this));
	m_pPlySprite->runAction(Sequence::create(moveToX, delay, func, NULL));

	walkPost();

}
void CPlayer::walkPost()
{
	auto firstInt = 1;
	if (m_iDirection == LEFT)
	{
		firstInt = 5;
	}

	auto pCache = SpriteFrameCache::getInstance();
	auto animation = Animation::create();
	for (int i = firstInt; i <= firstInt + 3; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "hero_walk_%d.png", i);
		animation->addSpriteFrame(pCache->getSpriteFrameByName(szName));
	}
	animation->setDelayPerUnit(0.15f);
	animation->setRestoreOriginalFrame(true);
	auto action = Animate::create(animation);
	m_pPlySprite->runAction(RepeatForever::create(action));
}

void CPlayer::plyStayPost()
{
	m_pPlySprite->stopAllActions();

	auto framePath = "hero_walk_1.png";
	if (m_iDirection == LEFT)
	{
		framePath = "hero_walk_5.png";
	}

	m_iDirection = STAY;
	m_fMapMoveX = 0;
	auto pCache = SpriteFrameCache::getInstance();
	m_pPlySprite->setSpriteFrame(pCache->getSpriteFrameByName(framePath));

}

float CPlayer::getDist(Point curPos, Point distPos)
{
	int iDx = curPos.x - distPos.x;
	int iDy = curPos.y - distPos.y;

	float dist = sqrt(float(iDx*iDx + iDy*iDy));
	return dist;
}