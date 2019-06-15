#include "cocos2d.h"
#include "Player.h"
#include "MonsterMgr.h"
USING_NS_CC;


class CMap : public Layer
{
public:
	virtual bool init();
	static CMap*	getInstance();

	void update(float dt);

	// �����
	void click(Point location);
	// �ƶ�
	void move(Point location);
	//��ӹ���
	void addEnemy(float dt);
	//������
	Vec2 checkClick(Point location);

	CREATE_FUNC(CMap);
private:
	cocos2d::Sprite* pMap;
	Size     m_winSize;   //��Ļ�ߴ�
	CPlayer *m_pPlayer;   //���
	CMonsterMgr *m_pMonMgr;   //�������
};