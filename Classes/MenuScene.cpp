#include "MenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MenuScene::createScene()
{
	auto scene = Scene::create();

	auto listener = EventListenerKeyboard::create();
	//listener->onKeyPressed = CC_CALLBACK_2(KeyboardTest::onKeyPressed, this);

	return scene;
}

bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto mySprite = Sprite::create("bullet_green.png");

	return true;
}
