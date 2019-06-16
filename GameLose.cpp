#include "GameLose.h"

Scene* CGameLose::createLoseScene()
{
	return CGameLose::create();
}
bool CGameLose::init()
{
	if (!Scene::init())
		return false;


	auto size = Director::getInstance()->getVisibleSize();
	auto victory = Sprite::create("lose.png");
	victory->setPosition(Vec2(size.width / 2, size.height / 2));
	this->addChild(victory);

	return true;
}

