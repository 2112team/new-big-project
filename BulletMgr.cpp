#include "BulletMgr.h"
#include "Monster.h"
#include "MonsterMgr.h"
#include "Player.h"
#include "Head.h"



static CBulletMgr *s_pBulletMgr = NULL;
CBulletMgr* CBulletMgr::getInstance()
{
	if (s_pBulletMgr == NULL)
		s_pBulletMgr = CBulletMgr::create();

	return s_pBulletMgr;
}
void CBulletMgr::setNull()
{
	s_pBulletMgr = NULL;
}
bool CBulletMgr::init()
{
	if (!Layer::init())
		return false;

	m_pBulletList = __Array::create();
	m_pBulletList->retain();

	this->scheduleUpdate();

	return true;
}
void CBulletMgr::addBullet(float fATK, int iType, Vec2 srcPos, Vec2 destPos)
{
	auto pBullet = CBullet::create();
	pBullet->createBullet(fATK,iType, srcPos, destPos);
	this->addChild(pBullet);
	m_pBulletList->addObject(pBullet);
}
void CBulletMgr::update(float dt)
{
	Object *pMonsterObj = NULL;
	Object *pBulletObj = NULL;
	__Array *pMonList = CMonsterMgr::getInstance()->getMonList();
	auto pPlayer = CPlayer::getInstance();
	auto pPlayerSpt = pPlayer->getPlayerSpt();

	CCARRAY_FOREACH(m_pBulletList, pBulletObj)
	{
		auto pCurBullet = (CBullet*)pBulletObj;
		auto pBullet = pCurBullet->getBulletSprite();
		if (pCurBullet && !pCurBullet->isVisible())
		{
			m_pBulletList->removeObject(pBulletObj);
			this->removeChild(pCurBullet);
			return;
		}
		//�������ײ���
		CCARRAY_FOREACH(pMonList, pMonsterObj)
		{
			auto pCurMonster = (CMonster*)pMonsterObj;
			auto pMonster = pCurMonster->getMonster();
			if (pCurMonster && !pCurMonster->isVisible())
			{
				pMonList->removeObject(pMonsterObj);
				pCurMonster->removeFromParent();
				return;
			}
			//�ӵ��������ײ
			if (pCurBullet->getBulletType() == HERO && pMonster->boundingBox().containsPoint(pBullet->getPosition()))
			{
				pCurBullet->setVisible(false);
				if (pCurMonster->dropHp(pCurBullet->getATK()) <= 0)
				{
					auto pPlayer = CPlayer::getInstance();
					pPlayer->setTarget(NULL);
				}
				return;
			}
		}
		//�������ײ���
		if (pCurBullet->getBulletType() == ENEMY && pPlayerSpt->boundingBox().containsPoint(pBullet->getPosition()))
		{
			pCurBullet->setVisible(false);
			pPlayer->dropHp(pCurBullet->getATK());
			return;
		}
	}
}