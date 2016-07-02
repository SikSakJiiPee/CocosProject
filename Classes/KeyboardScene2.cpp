#include "KeyboardScene2.h"

USING_NS_CC;

Scene* KeyboardScene2::createScene()
{
	auto scene = Scene::create();

	KeyboardScene2* layer = KeyboardScene2::create();
	scene->addChild(layer);
	return scene;
}

bool KeyboardScene2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	label = cocos2d::Label::createWithSystemFont("Press the CTRL Key", "Arial", 32);
	label->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	addChild(label);
	auto eventListener = EventListenerKeyboard::create();


	Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);
	eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		//If key already exists, do nothing as it will already have a time stamp
		//Otherwise, sets the timestamp to now
		if (keys.find(keyCode) == keys.end())
		{
			keys[keyCode] = std::chrono::high_resolution_clock::now();
		}
	};
	eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
	{
		//remove the key. std::map.erase() doesn't care if the key doesn't exist
		keys.erase(keyCode);
	};

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

	//Let cocos know we have an update function to be called.
	//No worries I'll cover this in more detail later on
	this->scheduleUpdate();
	return true;
}

bool KeyboardScene2::isKeyPressed(EventKeyboard::KeyCode code)
{
	//Check if the key is currently pressed by seeing if it's in the std::map keys
	//In retrospect, keys is a terrible name for a key/value paried datatype isn't it?
	if (keys.find(code) != keys.end())
	{
		return true;
	}
	return false;
}

double KeyboardScene2::keyPressedDuration(EventKeyboard::KeyCode code)
{
	if (!isKeyPressed(EventKeyboard::KeyCode::KEY_CTRL))
	{
		return 0; //Not pressed, no duration
	}

	//Return the amount of time that has elapsed between now and when the user
	//first started holding down the key in milliseconds
	//Obviously the start time is the value we hold in our std::map keys
	return std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - keys[code]).count();
}

void KeyboardScene2::update(float delta)
{
	//Register a  update function that checks to see if the CTRL key is pressed
	//and if it is displays how long, otherwise teel the user to press it
	Node::update(delta);
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_CTRL))
	{
		std::stringstream ss;
		ss << "Control key has been pressed for " <<
			keyPressedDuration(EventKeyboard::KeyCode::KEY_CTRL) << " ms";
		label->setString(ss.str().c_str());
	}
	else
	{
		label->setString("Press the CTRL Key");
	}
}
//Because cocs2d-x requires createScene to be static, we need to make other non-pointer members static
std::map < cocos2d::EventKeyboard::KeyCode,
	std::chrono::high_resolution_clock::time_point> KeyboardScene2::keys;
