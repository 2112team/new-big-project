#include "cocos2d.h"
//ˮ����С���������� 
USING_NS_CC;

class CMonster : public Layer
{
public:
//	static CMonster *getInstance();

	virtual bool init();
	void createMonster();					//����С�� 
	void createCrystal();					//����ˮ��
	void createTower();					    //����������
	void atackPlayer(float dt);				//������ң����޷�������
	void initHp(int hp);
	float dropHp(float atk);
	void changeDirction(float dt);													//����С������
	void update(float dt);															//���ݸ���
	void walkPost();																//��������
	bool checkPlayer();																//̽�����
	void moveToPlayer();															//������ƶ�
	void wander();																	//�ε��ƶ�
	void resetTouched(float dt);													//���ô���

	Sprite *getMonster(){ return m_pMonster; }										//���С��sprite 
	Vec2 getMonsterPos(){ return m_pMonster->getPosition(); }						//���С������
	int getType(){ return m_iType; }						//���С������
	bool getTouched() { return m_bTouched; }                //��ȡ�Ƿ񱻴���

	CREATE_FUNC(CMonster);
private:
	Sprite *m_pMonster;				//С������
	ProgressTimer *m_pHPProgess;    //Ѫ������
	int     m_iDirection;			//С������
	float	m_fRange;				//̽����ҷ�Χ
	int     m_iWalkState;			//�������߷���
	int     m_iType;				//С������
	float   m_fSpeed;				//С���ٶ�
	float   m_fMaxHp;               //Ѫ��ֵ����
	float   m_fHp;                  //Ѫ��ֵ
	bool    m_bLockPlayer;          //�Ƿ��������
	int		m_iThinkTime;           //˼��ʱ��
	int     m_iTouchTime;			//�������
	bool    m_bTouched;				//�Ƿ��������
};
