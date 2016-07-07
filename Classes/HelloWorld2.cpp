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
	if (!LayerColor::initWithColor(cocos2d::Color4B::BLACK))
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
		//auto action = cocos2d::MoveTo::create(2, cocos2d::Vec2(0, 0)); //liikkuu annettuun koordinaattiin
		//auto action = cocos2d::MoveBy::create(2, cocos2d::Vec2(300, 300)); //liikkuu annetun määrän (x,y)
		//sprite->runAction(action);
		//----

		//cocos2d::Vector<cocos2d::FiniteTimeAction*> actions; //huom. ei ole std::Vector!
		//actions.pushBack(cocos2d::ScaleBy::create(1.5, 1.5));
		//actions.pushBack(cocos2d::TintTo::create(1.5, 255, 0, 0));
		//actions.pushBack(cocos2d::FadeTo::create(1.5, 30));

		//auto sequence = cocos2d::Sequence::create(actions);
		//auto parallel = cocos2d::Spawn::create(actions);

		//sprite->runAction(sequence);
		//sprite->runAction(parallel);
		//----

		//auto action = cocos2d::MoveBy::create(0.2, cocos2d::Vec2(10, 0));
		//auto action2 = cocos2d::ScaleBy::create(2, 1.3);
		//auto repeat = cocos2d::Repeat::create(action, 10);
		//auto repeatForever = cocos2d::RepeatForever::create(action2);

		//sprite->runAction(repeat);
		//sprite->runAction(repeatForever);
		//----

		cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
		actions.pushBack(cocos2d::MoveTo::create(1, cocos2d::Vec2(0, 0)));
		actions.pushBack(cocos2d::DelayTime::create(1));
		actions.pushBack(cocos2d::Place::create(cocos2d::Vec2(
			this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY())));
		actions.pushBack(cocos2d::DelayTime::create(1));
		actions.pushBack(cocos2d::FlipX::create(true));
		actions.pushBack(cocos2d::DelayTime::create(1));
		actions.pushBack(cocos2d::FlipY::create(true));
		actions.pushBack(cocos2d::DelayTime::create(1));
		actions.pushBack(cocos2d::Hide::create());
		actions.pushBack(cocos2d::DelayTime::create(1));
		actions.pushBack(cocos2d::Show::create());
		actions.pushBack(cocos2d::DelayTime::create(1));

		//joku häikkää (ratkaisu tutossa)
		actions.pushBack(cocos2d::CallFunc::create([=]()->void{
			this->setColor(cocos2d::Color3B::RED);
		}));

		actions.pushBack(cocos2d::DelayTime::create(1));
		actions.pushBack(cocos2d::RemoveSelf::create(false));

		auto sequence = cocos2d::Sequence::create(actions);
		sprite->runAction(sequence);
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}