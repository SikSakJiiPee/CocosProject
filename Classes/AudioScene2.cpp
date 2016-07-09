#include "AudioScene2.h"

cocos2d::Scene* AudioScene2::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = AudioScene2::create();
	scene->addChild(layer);
	return scene;
}

bool AudioScene2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	auto audio2 = CocosDenshion::SimpleAudioEngine::getInstance();

	audio2->preloadBackgroundMusic("noncombat.wav");
	audio2->playBackgroundMusic("noncombat.wav");

	audio->preloadEffect("jingle2.wav");
	audio->preloadEffect("boom.wav");
	audio->preloadEffect("bigboom.wav");

	audio->playEffect("boom.wav");

	cocos2d::Director::getInstance()->getScheduler()->schedule([audio](float delta)
	{
		audio->playEffect("bigboom.wav");
		audio->unloadEffect("boom.wav");
	}, this, 1.5f, 0, 0.0f, false, "myCallbackKey");

	return true;
}
