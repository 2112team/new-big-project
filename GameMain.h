#include"cocos2d.h"
//#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "Map.h"

using namespace cocos2d::ui;
USING_NS_CC;

class CGameMain : public Scene
{
public:
	static Scene *createGmaeScene();

	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);


	void gamePause(Ref* pSender);			//”Œœ∑‘›Õ£

	CREATE_FUNC(CGameMain);

private:
	cocos2d::EventListenerTouchOneByOne* listener;
	CMap *m_pMap;         //µÿÕº
};