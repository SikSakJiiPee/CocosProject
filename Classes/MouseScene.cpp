#include "MouseScene.h"

USING_NS_CC;

cocos2d::Scene* MouseScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MouseScene::create();
	scene->addChild(layer);

	return scene;
}

bool MouseScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto listener = EventListenerMouse::create();
	listener->onMouseDown = [](cocos2d::Event* event)
	{
		try
		{
			EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
			mouseEvent->getMouseButton();
			std::stringstream message;
			message << "Mouse event: Button: " << mouseEvent->getMouseButton() << "pressed at point(" <<
				mouseEvent->getLocation().x << "," << mouseEvent->getLocation().y << ")";
			MessageBox(message.str().c_str(), "Mouse Event Details");
		}
		catch (std::bad_cast& e)
		{
			//cocos passed wrong kind of event
			return;
		}
	};

	listener->onMouseMove = [](cocos2d::Event* event)
	{
		//Cast Event to EventMouse for position details like above
		cocos2d::log("Mouse moved event");
	};

	listener->onMouseScroll = [](cocos2d::Event* event)
	{
		cocos2d::log("Mouse wheel scrolled");
	};
	
	listener->onMouseUp = [](cocos2d::Event* event)
	{
		cocos2d::log("Mouse button released");
	};

	_eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

	cocos2d::log("init ok");
	return true;
}