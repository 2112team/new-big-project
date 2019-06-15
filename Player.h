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
	//��ʼ��Ѫ��
	void initHp();	
	//����ƶ�
	void walkMove(Vec2 midPos, Vec2 distPos);
	//��������
	void walkPost();	
	//��ԭ�������Ķ���
	void plyStayPost();
	//��ȡ�����ľ���
	float getDist(Point curPos, Point distPos);

	Vec2 getPlayerPos() { return m_pPlySprite->getPosition(); }

	CREATE_FUNC(CPlayer);
private:

	Sprite     *m_pPlySprite;			//���ﾫ��
	Sprite     *m_pHPBG;                //����Ѫ��

	int			m_iDirection;			//���﷽��
	int			m_iWalkState;			//��������״̬
	float		m_fSpeed;			    //�����ٶ�
	float       m_fMapMoveX;            //��ͼ��Ҫ�ƶ���X����
	bool		m_bisOver;				//�Ƿ���Ϸ����
};