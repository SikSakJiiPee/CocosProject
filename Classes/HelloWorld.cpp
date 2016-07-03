#include "HelloWorld.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}

	sprite = Sprite::create("Veyron.png");
	sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	this->addChild(sprite, 0);

	this->scheduleUpdate();
	//this->scheduleUpdateWithPriority(1); //isompi numero == pienempi prioriteetti
	return true;
}

void HelloWorld::update(float delta)
{
	auto position = sprite->getPosition();
	position.x -= 250 * delta;
	if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
	{
		position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
	}
	sprite->setPosition(position);
}