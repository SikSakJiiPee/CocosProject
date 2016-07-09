#include "AudioScene.h"

cocos2d::Scene* AudioScene::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = AudioScene::create();
	scene->addChild(layer);
	return scene;
}

bool AudioScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->preloadBackgroundMusic("hungerland.wav");
	audio->playBackgroundMusic("hungerland.wav");

	auto eventListener = cocos2d::EventListenerKeyboard::create();
	eventListener->onKeyPressed = [audio](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_SPACE:
		{
			if (audio->isBackgroundMusicPlaying())
			{
				audio->pauseBackgroundMusic();
			}
			else
			{
				audio->resumeBackgroundMusic();
			}
			break;
		}
		case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			audio->playBackgroundMusic("noncombat.wav");
			break;
		}
		case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		{
			audio->playBackgroundMusic("hungerland.wav");
			break;
		}
		}
	};

	_eventDispatcher->addEventListenerWithFixedPriority(eventListener, 2);

	return true;
}
