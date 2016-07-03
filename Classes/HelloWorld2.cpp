#include "HelloWorld2.h"

//USING_NS_CC; //using namespace cocos2d

cocos2d::Scene* HelloWorld2::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = HelloWorld2::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	sprite = cocos2d::Sprite::create("Veyron.png");
	sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	this->addChild(sprite, 0);

	auto listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)->void
	{
		//This is where our different actions are going to be implemented
		auto action = cocos2d::MoveTo::create(2, cocos2d::Vec2(0, 0));
		sprite->runAction(action);
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}