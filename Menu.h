#include "cocos2d.h"
USING_NS_CC;

class CMenu : public Scene
{
public:
	static Scene *createMenuScene();

	virtual bool  init();

	void gameStart(Ref* pSender);		//��Ϸ��ʼ 
	void gameExit(Ref* pSender);		//��Ϸ�˳�
	void gameAbout(Ref* pSender);		//����

	CREATE_FUNC(CMenu);
};