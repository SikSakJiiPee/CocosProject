#include "MenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MenuScene::createScene()
{
	auto scene = Scene::create();



	return scene;
}

bool MenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}



	return true;
}
