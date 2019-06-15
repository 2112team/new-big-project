#include "cocos2d.h"
USING_NS_CC;

typedef enum direction
{
	STAY = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,

}RDIRECTION;

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
	void walkMove(Vec2 midPos, Vec2 distPos);
	//行走姿势
	void walkPost();	
	//还原到不动的动作
	void plyStayPost();
	//获取两点间的距离
	float getDist(Point curPos, Point distPos);

	Vec2 getPlayerPos() { return m_pPlySprite->getPosition(); }

	CREATE_FUNC(CPlayer);
private:

	Sprite     *m_pPlySprite;			//人物精灵
	Sprite     *m_pHPBG;                //人物血条

	int			m_iDirection;			//人物方向
	int			m_iWalkState;			//人物行走状态
	float		m_fSpeed;			    //人物速度
	float       m_fMapMoveX;            //地图需要移动的X距离
	bool		m_bisOver;				//是否游戏结束
};