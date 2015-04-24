#include "AppDelegate.h"
//#include "HelloWorldScene.h"
#include "StartScene.h"
#include "UserData.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "hellocpp/PayClass.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#endif

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("Puzzle_Bubble", Rect(0, 0, 540, 960));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(540, 960, ResolutionPolicy::FIXED_WIDTH);
	//director->getOpenGLView()->setFrameZoomFactor(0.8f);
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

	/*TextureCache::getInstance()->addImage("Gift/Gift.plist");*/
	/*TextureCache::addImage("Gift/Gift.plist");*/
	//Director::getInstance()->getTextureCache()->addImage("Gift/Gift.plist");

	ArmatureDataManager::getInstance()->addArmatureFileInfo("Particle/baozha.ExportJson");
	ArmatureDataManager::getInstance()->addArmatureFileInfo("BubbleSpecial/paopaolong.ExportJson");
	ArmatureDataManager::getInstance()->addArmatureFileInfo("BubbleSpecial/daojubaozha.ExportJson");

	Director::getInstance()->getTextureCache()->addImage("Start/Start.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Gift/Gift.plist");
	//Director::getInstance()->getTextureCache()->addImage("Turnplate/Turn.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Turnplate/Turn.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Gameover/Gameover.plist");
	Director::getInstance()->getTextureCache()->addImage("Prop/Prop.plist");



	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Music/bgm.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Ending.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Fuhuo.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Guoguan.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Click.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Clock.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Remove.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Hit.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Bomb.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/start.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/end.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/Hitwall.mp3");
	SimpleAudioEngine::getInstance()->preloadEffect("Music/good.mp3");
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	//IsMusicOn();
#endif
	
    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();
	auto scene = StartLayer::scene();
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
	UserData::getInstance()->saveData();
    // if you use SimpleAudioEngine, it must be pause
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	SimpleAudioEngine::getInstance()->setEffectsVolume(0);
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    if(UserData::getInstance()->getIsMusicOn()){
    	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		SimpleAudioEngine::getInstance()->setEffectsVolume(1);
    }
}
