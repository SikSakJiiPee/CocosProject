#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class AudioScene2 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(AudioScene2);

};