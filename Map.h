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

	// 鼠标点击
	void click(Point location);
	// 移动
	void move(Point location);
	//添加怪物
	void addEnemy(float dt);
	//点击检测
	Vec2 checkClick(Point location);

	CREATE_FUNC(CMap);
private:
	cocos2d::Sprite* pMap;
	Size     m_winSize;   //屏幕尺寸
	CPlayer *m_pPlayer;   //玩家
	CMonsterMgr *m_pMonMgr;   //怪物管理
};