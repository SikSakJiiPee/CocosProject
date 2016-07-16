#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MenuScene.h"
#include "GraphicsScene.h"
#include "MouseScene.h"
#include "KeyboardScene.h"
#include "KeyboardScene2.h"
#include "HelloWorld.h"
#include "HelloWorld2.h"
#include "HelloWorld3.h"
#include "AudioScene.h"
#include "AudioScene2.h"
#include "TextFieldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() 
{

}

AppDelegate::~AppDelegate() 
{
}


bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("NewCocosProject");
		glview->setFrameSize(640, 480);
        director->setOpenGLView(glview);
    }

    // create a scene. it's an autorelease object
    //auto scene = GraphicsScene::createScene();
	//auto scene1 = MouseScene::createScene();
	//auto scene2 = KeyboardScene::createScene();
	//auto scene3 = KeyboardScene2::createScene();
	//auto scene4 = HelloWorld::createScene();
	//auto scene5 = HelloWorld2::createScene();
	//auto scene6 = HelloWorld3::createScene();
	//auto scene7 = AudioScene::createScene();
	//auto scene8 = AudioScene2::createScene();
	auto scene9 = TextFieldScene::createScene();


    // run
    director->runWithScene(scene9);
	
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    //Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->pauseAllEffects();
	audio->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    //Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->resumeAllEffects();
	audio->resumeBackgroundMusic();
}
