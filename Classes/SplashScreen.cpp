#include "SplashScreen.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SplashScreen::createScene()
{
	auto scene = Scene::create();

	return scene;
}

bool SplashScreen::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto mySprite = Sprite::create("res/Texture/bullet_green.png");

	return true;
}