#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class AudioScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(AudioScene);

};