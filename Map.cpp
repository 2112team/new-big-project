#include "Map.h"
#include "Monster.h"
#include "BulletMgr.h"

static CMap *s_pMap = NULL;
CMap* CMap::getInstance()
{
	if (s_pMap == NULL)
		s_pMap = CMap::create();

	return s_pMap;
}
bool CMap::init()
{
	if (!Layer::init())
		return false;

	m_winSize = Director::getInstance()->getVisibleSize();
	pMap = Sprite::create("map.png");
	pMap->setAnchorPoint(Vec2(0, 0.5));
	pMap->setPosition(Vec2(0, m_winSize.height / 2));
	this->addChild(pMap, 0);

	//玩家
	m_pPlayer = CPlayer::getInstance();
	this->addChild(m_pPlayer);

	//怪物管理
	m_pMonMgr = CMonsterMgr::getInstance();
	this->addChild(m_pMonMgr);

	//子弹管理类
	this->addChild(CBulletMgr::getInstance());

	//每3秒生成一个怪物
	this->schedule(schedule_selector(CMap::addEnemy), 3.0f);

	this->scheduleUpdate();

	return true;
}

void CMap::click(Point location)
{
	auto nodePos = this->convertToNodeSpace(location);
	auto checkPos = checkClick(nodePos);
	if (checkPos != Vec2(0, 0))
	{
		m_pPlayer->tryAtc(checkPos);
	}
	else
	{
		move(location);
	}
	
}

void CMap::move(Point location)
{
	auto nodePos = this->convertToNodeSpace(location);
	m_pPlayer->setTarget(NULL);
	m_pPlayer->walkMove(nodePos);
}

void CMap::addEnemy(float dt)
{
	m_pMonMgr->addMonster();
}

void CMap::update(float dt)
{
	auto playerWorldPos = m_pPlayer->convertToWorldSpace(m_pPlayer->getPlayerPos());
	if (playerWorldPos.x > m_winSize.width / 2 && this->getPositionX() > m_winSize.width - pMap->getContentSize().width)
	{
		this->setPositionX(this->getPositionX() - (playerWorldPos.x - m_winSize.width / 2));
	}
	else if (playerWorldPos.x < m_winSize.width / 2 && this->getPositionX() < 0)
	{
		this->setPositionX(this->getPositionX() - (playerWorldPos.x - m_winSize.width / 2));
	}
}

Vec2 CMap::checkClick(Point location)
{
	Object *pMonsterObj = NULL;
	__Array *pMonsterList = m_pMonMgr->getMonList();
	CCARRAY_FOREACH(pMonsterList, pMonsterObj)
	{
		auto pCurMonster = (CMonster*)pMonsterObj;
		Sprite *pMonster = pCurMonster->getMonster();
		Vec2 monColliPos = pCurMonster->getMonsterPos();
		if (pMonster->boundingBox().containsPoint(location))
		{
			m_pPlayer->setTarget(pMonster);
			return monColliPos;
		}
	}

	return Vec2(0, 0);
}