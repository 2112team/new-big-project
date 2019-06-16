#include "cocos2d.h"
#include "Bullet.h"

USING_NS_CC;

class CBulletMgr : public Layer
{
public:
	static CBulletMgr *getInstance();
	static void setNull();						//��̬����
	virtual bool init();

	void addBullet(float fATK, int iType, Vec2 srcPos, Vec2 destPos);		//����ӵ�
	void update(float dt);

	__Array *getBulletList(){ return m_pBulletList; }

	CREATE_FUNC(CBulletMgr);
private:
	__Array				*m_pBulletList;			//�ӵ��б�
};