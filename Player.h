#include "cocos2d.h"

USING_NS_CC;


class CPlayer : public Layer
{
public:
	virtual bool init();
	static CPlayer*	getInstance();
	static void setNull();
	void update(float dt);
	//初始化血条
	void initHp();	
	//玩家移动
	void walkMove(Vec2 distPos);
	//行走姿势
	void walkPost();	
	//还原到不动的动作
	void plyStayPost();
	//尝试攻击
	void tryAtc(Point location);
	//攻击动画
	void atcAnim(Point location);
	//攻击结束
	void atcFinish();
	//获取传入点相对玩家的方向
	int getDirect(Point location);
	//获取放置弓箭的位置
	Vec2 getAtcPos();
	//设置攻击目标精灵
	void setTarget(Sprite *target);
	//减少血量
	float dropHp(float atk);

	Sprite *getPlayerSpt() { return m_pPlySprite; }
	Vec2 getPlayerPos() { return m_pPlySprite->getPosition(); }

	CREATE_FUNC(CPlayer);
private:

	Sprite     *m_pPlySprite;			//人物精灵
	Sprite     *m_pHPBG;                //人物血条
	Sprite     *m_pTarget;              //目标精灵
	ProgressTimer *m_pHPProgess;        //血条

	float       m_fHp;					//血量
	float       m_fMaxHp;				//血量上限
	int			m_iDirection;			//人物方向
	int			m_iWalkState;			//人物行走状态
	float		m_fSpeed;			    //人物速度
	float       m_fAtcRang;             //攻击范围
	Vec2		m_atcPos;               //攻击目标的位置
	bool        m_bAtcing;              //是否在攻击
};