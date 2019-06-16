#include "cocos2d.h"

USING_NS_CC;

class CBullet : public Layer
{
public:
	virtual bool init();

	void createBullet(float fATK, int iType, Vec2 srcPos, Vec2 destPos);	  //创建子弹
	float getRotating(Point curPos, Point distPos);		//得到两点之间的角度
	void removeBullet();								//移除子弹

	Sprite *getBulletSprite(){ return m_pBulletSprite; } //获得子弹精灵;
	int getBulletType(){ return m_iType; }				 //获得子弹类型
	float getATK(){ return m_fATK; }					 //获得子弹攻击力
	CREATE_FUNC(CBullet);
private:
	Sprite			*m_pBulletSprite;		//子弹精灵
	int				 m_iType;				//子弹类型
	float			 m_fSpeed;				//子弹速度
	float			 m_fATK;				//子弹攻击力
};