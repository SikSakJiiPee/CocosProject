#pragma once

#include "cocos2d.h"

class HelloWorld2 : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HelloWorld2);

	//void update(float) override;

private:
	cocos2d::Sprite* sprite;
};