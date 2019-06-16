#include "Menu.h"
#include "GameMain.h"

Scene* CMenu::createMenuScene()
{
	return CMenu::create();
}

bool CMenu::init()
{
	if (!Scene::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	SpriteFrameCache *pCache = SpriteFrameCache::getInstance();
	pCache->addSpriteFramesWithFile("title/title.plist");

	//背景
	auto bg = Sprite::createWithSpriteFrameName("bg.png");
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg->setContentSize(visibleSize);
	this->addChild(bg, 0);


	//按钮//--------------------------------------------------------------------------------
	//按钮背景
	auto bgBtn = Sprite::createWithSpriteFrameName("buttonBG.png");
	bgBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 150));
	this->addChild(bgBtn, 1);

	auto bgBtn2 = Sprite::createWithSpriteFrameName("buttonBG.png");
	bgBtn2->setPosition(Vec2(visibleSize.width / 2 + 200, visibleSize.height / 2 - 250));
	this->addChild(bgBtn2, 1);

	auto bgBtn3 = Sprite::createWithSpriteFrameName("buttonBG.png");
	bgBtn3->setPosition(Vec2(visibleSize.width / 2 - 200, visibleSize.height / 2 - 250));
	this->addChild(bgBtn3, 1);
	//开始按钮
	auto startBtn = MenuItemImage::create();
	startBtn->setNormalSpriteFrame(pCache->getSpriteFrameByName("startbutton1.png"));
	startBtn->setSelectedSpriteFrame(pCache->getSpriteFrameByName("startbutton2.png"));
	startBtn->initWithCallback(CC_CALLBACK_1(CMenu::gameStart, this));
	startBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 150));
	auto startPlay = Sprite::createWithSpriteFrameName("start.png");
	startPlay->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 150));
	this->addChild(startPlay, 3);
	//退出按钮
	auto exitBtn = MenuItemImage::create();
	exitBtn->setNormalSpriteFrame(pCache->getSpriteFrameByName("startbutton1.png"));
	exitBtn->setSelectedSpriteFrame(pCache->getSpriteFrameByName("startbutton2.png"));
	exitBtn->initWithCallback(CC_CALLBACK_1(CMenu::gameExit, this));
	exitBtn->setPosition(Vec2(visibleSize.width / 2 + 200, visibleSize.height / 2 - 250));
	auto endPlay = Sprite::createWithSpriteFrameName("end.png");
	endPlay->setPosition(Vec2(visibleSize.width / 2 + 200, visibleSize.height / 2 - 250));
	this->addChild(endPlay, 3);
	//关于按钮
	auto aboutBtn = MenuItemImage::create();
	aboutBtn->setNormalSpriteFrame(pCache->getSpriteFrameByName("startbutton1.png"));
	aboutBtn->setSelectedSpriteFrame(pCache->getSpriteFrameByName("startbutton2.png"));
	aboutBtn->initWithCallback(CC_CALLBACK_1(CMenu::gameAbout, this));
	aboutBtn->setPosition(Vec2(visibleSize.width / 2 - 200, visibleSize.height / 2 - 250));
	auto about = Sprite::createWithSpriteFrameName("about.png");
	about->setPosition(Vec2(visibleSize.width / 2 - 200, visibleSize.height / 2 - 250));
	this->addChild(about, 3);

	Menu *pMenu = Menu::create();
	pMenu->addChild(startBtn);
	pMenu->addChild(exitBtn);
	pMenu->addChild(aboutBtn);
	pMenu->setPosition(Vec2::ZERO);
	this->addChild(pMenu, 2);


	return true;
}
void CMenu::gameStart(Ref* pSender)
{
	Scene *pScene = TransitionFade::create(1.5, CGameMain::createGmaeScene());
	Director::getInstance()->replaceScene(pScene);
}
void CMenu::gameExit(Ref* pSender)
{
	Director::getInstance()->end();
}
void CMenu::gameAbout(Ref* pSender)
{

}