#include "MonsterMgr.h"
#include "Monster.h"
#include "Player.h"

static  CMonsterMgr *s_pMonsterMgr = NULL;
CMonsterMgr *CMonsterMgr::getInstance()
{
	if (s_pMonsterMgr == NULL)
		s_pMonsterMgr = CMonsterMgr::create();

	return s_pMonsterMgr;
}
bool CMonsterMgr::init()
{
	if (!Layer::init())
		return false;

	m_iMadeMonsterCount = 0;
	m_pMonsterList = __Array::create();
	m_pMonsterList->retain();

	this->scheduleUpdate();
	return true;
}
void CMonsterMgr::setNull()
{
	s_pMonsterMgr = NULL;
}
void CMonsterMgr::addMonster()
{
	if (m_iMadeMonsterCount >= 5)
	{
		//产生的怪物数量超过5，不再制造
		return;
	}

	auto pMonster = CMonster::create();
	pMonster->createMonster();
	this->addChild(pMonster);
	m_pMonsterList->addObject(pMonster);
	m_iMadeMonsterCount++;
}

void CMonsterMgr::addCrystal()
{
	auto pMonster = CMonster::create();
	pMonster->createCrystal();
	this->addChild(pMonster);
	m_pMonsterList->addObject(pMonster);
}

void CMonsterMgr::addTower()
{
	auto pMonster = CMonster::create();
	pMonster->createTower();
	this->addChild(pMonster);
	m_pMonsterList->addObject(pMonster);
}

void CMonsterMgr::update(float dt)
{
	
}
