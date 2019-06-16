#include "GameOver.h"

Scene* CGameOver::createOverScene()
{
	return CGameOver::create();
}
bool CGameOver::init()
{
	if (!Scene::init())
		return false;


	auto size = Director::getInstance()->getVisibleSize();
	auto victory = Sprite::create("victory.png");
	victory->setPosition(Vec2(size.width / 2, size.height / 2));
	this->addChild(victory);

	return true;
}

