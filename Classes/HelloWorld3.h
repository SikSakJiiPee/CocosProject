#pragma once

#include "cocos2d.h"

class HelloWorld3 : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();
	void callOnce(float delta);
	virtual bool init() override;
	CREATE_FUNC(HelloWorld3);

private:
	cocos2d::Sprite* sprite, *sprite2;
	cocos2d::Label* label;
	bool spritePaused = false;
	cocos2d::Vector<Node*>pausedNodes;
};