#pragma once

#include "cocos2d.h"
#include <map>

class KeyboardScene2 : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
	double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);

	virtual void update(float delta) override;

	CREATE_FUNC(KeyboardScene2);

private:
	static std::map < cocos2d::EventKeyboard::KeyCode,
		std::chrono::high_resolution_clock::time_point > keys;
	cocos2d::Label* label;

};
