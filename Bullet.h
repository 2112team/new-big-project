#include "cocos2d.h"

USING_NS_CC;

class CBullet : public Layer
{
public:
	virtual bool init();

	void createBullet(float fATK, int iType, Vec2 srcPos, Vec2 destPos);	  //�����ӵ�
	float getRotating(Point curPos, Point distPos);		//�õ�����֮��ĽǶ�
	void removeBullet();								//�Ƴ��ӵ�

	Sprite *getBulletSprite(){ return m_pBulletSprite; } //����ӵ�����;
	int getBulletType(){ return m_iType; }				 //����ӵ�����
	float getATK(){ return m_fATK; }					 //����ӵ�������
	CREATE_FUNC(CBullet);
private:
	Sprite			*m_pBulletSprite;		//�ӵ�����
	int				 m_iType;				//�ӵ�����
	float			 m_fSpeed;				//�ӵ��ٶ�
	float			 m_fATK;				//�ӵ�������
};