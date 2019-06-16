#include "Bullet.h"
#include "Head.h"

bool CBullet::init()
{
	if (!Layer::init())
		return false;

	m_pBulletSprite = NULL;
	m_iType = HERO;
	m_fSpeed = 600.0f;
	m_fATK = 1.0;

	return true;
}
static int s_iCount = 0;	//计算子弹数量
void CBullet::createBullet(float fATK, int iType, Vec2 srcPos, Vec2 destPos)
{
	m_fATK = fATK;
	m_iType = iType;

	auto bulletPath = m_iType == HERO ? "hero/arrow.png" : "tower/Bullet_Normal.png";

	m_pBulletSprite = Sprite::create(bulletPath);
	m_pBulletSprite->setPosition(srcPos);
	m_pBulletSprite->setRotation(getRotating(srcPos, destPos));
	this->addChild(m_pBulletSprite);

	auto moveTime = getDist(srcPos, destPos) / m_fSpeed;
	auto moveTo = MoveTo::create(moveTime, destPos);
	auto callBack = CallFunc::create(CC_CALLBACK_0(CBullet::removeBullet, this));
	m_pBulletSprite->runAction(Sequence::create(moveTo, callBack, NULL));
}
void CBullet::removeBullet()
{
	if (m_pBulletSprite)
	{
		this->setVisible(false);
	}
}
float CBullet::getRotating(Point curPos, Point distPos)
{
	float iDx = distPos.x - curPos.x;
	float iDy = distPos.y - curPos.y;
	float angle = (float)CC_RADIANS_TO_DEGREES(atanf(iDx / iDy));

	if (iDy < 0)
	{
		if (iDx < 0)
			angle = 180 + fabs(angle);
		else
			angle = 180 - fabs(angle);
	}
	if (angle < -15.0f)
		angle += 360.0f;
	return angle;
}
