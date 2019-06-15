#include "SecondScene.h"
Scene* SecondScene::createScene() {
	auto scene = Scene::create();
	auto layer = SecondScene::create();
	scene->addChild(layer);
	return scene;
}
bool SecondScene::init() {
	Label* label = Label::create("Hi,are you mutou?", "Arial", 40);
	label->setPosition(ccp(200, 200));
	this->addChild(label);
	/*Ìí¼Ó°´Å¥*/
	MenuItemImage *pCloseItem = MenuItemImage::create(
		"CloseNorma1.png",
		"CloseSe1ected.png",
		this,
		menu_selector(SecondScene::popScene));
	pCloseItem->setPosition(ccp(Director::getInstance()->getWinSize().width -20, 20));

	Menu* pMenu = Menu::create(pCloseItem, NULL); 
	pMenu->setPosition(Point(0, 0));
	this->addChild(pMenu, 1);
	return true;
}

void SecondScene::popScene(Ref* pSender) {
	Director::getInstance()->popScene();
}