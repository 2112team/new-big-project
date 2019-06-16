#include "cocos2d.h"
//水晶和小兵都在这里 
USING_NS_CC;

class CMonster : public Layer
{
public:
//	static CMonster *getInstance();

	virtual bool init();
	void createMonster();					//创建小兵 
	void createCrystal();					//创建水晶
	void createTower();					    //创建防御塔
	void atackPlayer(float dt);				//攻击玩家（仅限防御塔）
	void initHp(int hp);
	float dropHp(float atk);
	void changeDirction(float dt);													//设置小兵方向
	void update(float dt);															//数据更新
	void walkPost();																//行走姿势
	bool checkPlayer();																//探测玩家
	void moveToPlayer();															//向玩家移动
	void wander();																	//游荡移动
	void resetTouched(float dt);													//重置触碰

	Sprite *getMonster(){ return m_pMonster; }										//获得小兵sprite 
	Vec2 getMonsterPos(){ return m_pMonster->getPosition(); }						//获得小兵坐标
	int getType(){ return m_iType; }						//获得小兵类型
	bool getTouched() { return m_bTouched; }                //获取是否被触碰

	CREATE_FUNC(CMonster);
private:
	Sprite *m_pMonster;				//小兵精灵
	ProgressTimer *m_pHPProgess;    //血条进度
	int     m_iDirection;			//小兵方向
	float	m_fRange;				//探测玩家范围
	int     m_iWalkState;			//怪物行走方向
	int     m_iType;				//小兵类型
	float   m_fSpeed;				//小兵速度
	float   m_fMaxHp;               //血量值上限
	float   m_fHp;                  //血量值
	bool    m_bLockPlayer;          //是否锁定玩家
	int		m_iThinkTime;           //思考时间
	int     m_iTouchTime;			//触碰间隔
	bool    m_bTouched;				//是否触碰了玩家
};
