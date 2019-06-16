#include "cocos2d.h"
USING_NS_CC;

class CMenu : public Scene
{
public:
	static Scene *createMenuScene();

	virtual bool  init();

	void gameStart(Ref* pSender);		//游戏开始 
	void gameExit(Ref* pSender);		//游戏退出
	void gameAbout(Ref* pSender);		//关于

	CREATE_FUNC(CMenu);
};