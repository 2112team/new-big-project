#include "GameMain.h"


int g_iLevel = 5;

Scene* CGameMain::createGmaeScene()
{
	return CGameMain::create();
}

bool CGameMain::init()
{
	if (!Scene::init())
		return false;
#ifdef WIN32
	srand(unsigned int(time(0)));
#else
	std::srand(0);
#endif

	SpriteFrameCache *pCache = SpriteFrameCache::getInstance();
	pCache->addSpriteFramesWithFile("hero/hero.plist");
	pCache->addSpriteFramesWithFile("monster/monster.plist");
	pCache->addSpriteFramesWithFile("tower/Tower_Light.plist");

	listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(CGameMain::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(CGameMain::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(CGameMain::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//µØÍ¼
	m_pMap = CMap::getInstance();
	this->addChild(m_pMap);


	return true;
}

bool CGameMain::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto location = touch->getLocation();
	m_pMap->click(location);

	return true;
}

void CGameMain::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

}

void CGameMain::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

}


void CGameMain::gamePause(Ref* pSender)
{
	if(Director::getInstance()->isPaused())
		Director::getInstance()->resume();
	else
		Director::getInstance()->pause();
}