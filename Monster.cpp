#include "Monster.h"
#include "Player.h"
#include "Head.h"
#include "BulletMgr.h"
#include "GameOver.h"

/*
static CMonster *s_pMonster = NULL;
CMonster* CMonster::getInstance()
{
	if (s_pMonster == NULL)
		s_pMonster = CMonster::create();

	return s_pMonster;
}*/
bool CMonster::init()
{
	if (!Layer::init())
		return false;


	m_iDirection = STAY;	
	m_iWalkState = STAY;
	m_fRange = 400;
	m_pMonster = NULL;
	m_pHPProgess = NULL;
	m_iType = -1;
	m_fSpeed = 0.5f;
	m_fMaxHp = 0;
	m_fHp = 0;
	m_bLockPlayer = false;
	m_bTouched = false;
	m_iThinkTime = 0;
	m_iTouchTime = 1;

	//setDirction(1.0f);
	this->scheduleUpdate();
	return true;
}
void CMonster::createMonster()
{
	m_iType = SOLDIER;
	m_pMonster = Sprite::createWithSpriteFrameName("monster_5.png");
	m_pMonster->setPosition(Vec2(1300, 200));
	this->addChild(m_pMonster);

	m_iDirection = LEFT;
	initHp(3);
	this->schedule(schedule_selector(CMonster::changeDirction), 3.5);
}

void CMonster::createCrystal()
{
	m_iType = CRYSTAL;
	m_pMonster = Sprite::create("crystal.png");
	m_pMonster->setScale(0.3);
	m_pMonster->setPosition(Vec2(1500, 200));
	this->addChild(m_pMonster);

	initHp(5);
}

void CMonster::createTower()
{
	m_iType = TOWER;
	m_pMonster = Sprite::createWithSpriteFrameName("Light_One_1.png");
	//m_pMonster->setScale(0.3);
	m_pMonster->setPosition(Vec2(1400, 200));
	this->addChild(m_pMonster);

	initHp(5);
	this->schedule(schedule_selector(CMonster::atackPlayer), 1.0f);
}

void CMonster::initHp(int hp)
{
	m_fMaxHp = hp;
	m_fHp = m_fMaxHp;

	auto m_pHPBG = Sprite::create("hero/hp_bg.png");
	m_pHPBG->setAnchorPoint(Vec2(0.5, 0.5));
	m_pHPBG->setPosition(Vec2(25, 60));
	m_pMonster->addChild(m_pHPBG, 2);
	auto sizeOfBG = m_pHPBG->getContentSize();

	m_pHPProgess = ProgressTimer::create(Sprite::create("hero/hp2.png"));
	m_pHPProgess->setType(ProgressTimer::Type::BAR);
	m_pHPProgess->setMidpoint(Vec2(0, 0));
	m_pHPProgess->setBarChangeRate(Vec2(1, 0));
	m_pHPProgess->setPosition(Vec2(sizeOfBG.width / 2, sizeOfBG.height / 2));
	m_pHPProgess->setPercentage(100.0f);
	m_pHPBG->addChild(m_pHPProgess, 2);

	if (m_iType == CRYSTAL)
	{
		m_pHPBG->setScale(4);
		m_pHPBG->setPosition(Vec2(100, 350));
	}
	else if (m_iType == TOWER)
	{
		m_pHPBG->setPosition(Vec2(35, 100));
	}
}

void CMonster::resetTouched(float dt)
{
	m_bTouched = false;
}

float CMonster::dropHp(float atk)
{
	m_fHp -= atk;

	//如果是水晶死亡，游戏结束
	if (m_fHp <= 0 && m_iType == CRYSTAL)
	{
		Scene *pScene = CCTransitionFadeTR::create(1.0f, CGameOver::createOverScene());
		Director::getInstance()->replaceScene(pScene);
	}
	return m_fHp;
}

void CMonster::changeDirction(float dt)
{
	if (m_iDirection == RIGHT)
	{
		m_iDirection = LEFT;
		auto pCache = SpriteFrameCache::getInstance();
		m_pMonster->setSpriteFrame(pCache->getSpriteFrameByName("monster_5.png"));
	}
	else
	{
		m_iDirection = RIGHT;
		auto pCache = SpriteFrameCache::getInstance();
		m_pMonster->setSpriteFrame(pCache->getSpriteFrameByName("monster_1.png"));
	}
}

void CMonster::atackPlayer(float dt)
{
	auto pPlayer = CPlayer::getInstance();
	auto distance = getDist(m_pMonster->getPosition(), pPlayer->getPlayerPos());
	if (pPlayer->isVisible() && distance <= 300)
	{
		//子弹管理
		auto pBulletMgr = CBulletMgr::getInstance();
		pBulletMgr->addBullet(1, ENEMY, m_pMonster->getPosition()+Vec2(0, 50), pPlayer->getPlayerPos());
	}
}

void CMonster::update(float dt)
{
	//if (m_pMonster != NULL)
	//	monsterColli();
	if (m_pMonster != NULL)
	{
		m_pHPProgess->setPercentage(100 * m_fHp / m_fMaxHp);
		if (m_fHp <= 0)
		{
			this->setVisible(false);
		}

		if (m_iType != SOLDIER)
		{
			return;
		}

		m_iThinkTime += int(dt * 1000);
		//如果没有检测到玩家，就自己游荡
		if (m_iThinkTime > 500 && this->checkPlayer())
		{
			m_iThinkTime = 0;
			this->moveToPlayer();
		}
		else if (!this->checkPlayer())
		{
			this->wander();
		}
	}

	//与玩家的碰撞检测
	auto pPlayer = CPlayer::getInstance();
	auto pPlayerSpt = pPlayer->getPlayerSpt();
	if (!m_bTouched && pPlayerSpt->boundingBox().containsPoint(m_pMonster->getPosition()))
	{
		pPlayer->dropHp(1);
		m_bTouched = true;
		this->scheduleOnce(schedule_selector(CMonster::resetTouched), m_iTouchTime);
	}
}
void CMonster::walkPost()
{
	
	if (m_iWalkState == m_iDirection)
	{
		return;
	}

	m_pMonster->stopAllActions();
	auto firstInt = 1;
	if (m_iDirection == LEFT)
	{
		firstInt = 5;
	}

	m_iWalkState = m_iDirection;
	auto pCache = SpriteFrameCache::getInstance();
	auto animation = Animation::create();
	for (int i = firstInt; i <= firstInt + 3; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "monster_%d.png", i);
		animation->addSpriteFrame(pCache->getSpriteFrameByName(szName));
	}
	animation->setDelayPerUnit(0.15f);
	animation->setRestoreOriginalFrame(true);
	auto action = Animate::create(animation);
	m_pMonster->runAction(RepeatForever::create(action));
}

bool CMonster::checkPlayer()
{
	auto pPlayer = CPlayer::getInstance();
	auto distance = getDist(m_pMonster->getPosition(), pPlayer->getPlayerPos());
	if (distance <= m_fRange)
	{
		m_bLockPlayer = true;
		this->unschedule(schedule_selector(CMonster::changeDirction));
		return true;
	}
	else if (m_bLockPlayer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CMonster::moveToPlayer()
{
	m_pMonster->stopActionByTag(101);
	this->walkPost();
	auto pPlayer = CPlayer::getInstance();
	auto playerPos = pPlayer->getPlayerPos();
	auto distance = getDist(m_pMonster->getPosition(), playerPos);
	m_iDirection = playerPos.x > m_pMonster->getPosition().x ? RIGHT : LEFT;
	auto moveTo = MoveTo::create(distance / 40, playerPos);
	moveTo->setTag(101);
	m_pMonster->runAction(moveTo);
}

void CMonster::wander()
{
	if (m_iDirection == RIGHT)
	{
		walkPost();
		m_pMonster->setPositionX(m_pMonster->getPositionX() + m_fSpeed);
	}
	else if (m_iDirection == LEFT)
	{
		walkPost();
		m_pMonster->setPositionX(m_pMonster->getPositionX() - m_fSpeed);
	}
}
