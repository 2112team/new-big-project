#include "cocos2d.h"

USING_NS_CC;


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
	void walkMove(Vec2 distPos);
	//��������
	void walkPost();	
	//��ԭ�������Ķ���
	void plyStayPost();
	//���Թ���
	void tryAtc(Point location);
	//��������
	void atcAnim(Point location);
	//��������
	void atcFinish();
	//��ȡ����������ҵķ���
	int getDirect(Point location);
	//��ȡ���ù�����λ��
	Vec2 getAtcPos();
	//���ù���Ŀ�꾫��
	void setTarget(Sprite *target);
	//����Ѫ��
	float dropHp(float atk);

	Sprite *getPlayerSpt() { return m_pPlySprite; }
	Vec2 getPlayerPos() { return m_pPlySprite->getPosition(); }

	CREATE_FUNC(CPlayer);
private:

	Sprite     *m_pPlySprite;			//���ﾫ��
	Sprite     *m_pHPBG;                //����Ѫ��
	Sprite     *m_pTarget;              //Ŀ�꾫��
	ProgressTimer *m_pHPProgess;        //Ѫ��

	float       m_fHp;					//Ѫ��
	float       m_fMaxHp;				//Ѫ������
	int			m_iDirection;			//���﷽��
	int			m_iWalkState;			//��������״̬
	float		m_fSpeed;			    //�����ٶ�
	float       m_fAtcRang;             //������Χ
	Vec2		m_atcPos;               //����Ŀ���λ��
	bool        m_bAtcing;              //�Ƿ��ڹ���
};