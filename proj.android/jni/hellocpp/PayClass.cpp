
#include <jni.h>
#include "PayClass.h"
//#include "ShopLayer.cpp"
#include "ShopLayer.h"
#include "UserData.h"
#include "platform/android/jni/JniHelper.h"



using namespace cocos2d;

extern "C"
{


void Java_com_dqfx_ppldz_MainActivity_payOK(JNIEnv *env, jobject thiz, jint oid)
{

	buyGoldAddGold(oid);
}

void Java_com_dqfx_ppldz_MainActivity_payFailed(JNIEnv *env, jobject thiz)
{
	Director::getInstance()->startAnimation();
}
void Java_com_dqfx_ppldz_MainActivity_musicOn(JNIEnv *env, jobject thiz, jint IsOn)
{

	setMusicOn(IsOn);
}

void Java_com_dqfx_ppldz_MainActivity_endGame(JNIEnv *env, jobject thiz)
{

	Director::getInstance()->end();
}


void payGold(int index)
{

	JniMethodInfo t;
	if(JniHelper::getStaticMethodInfo(t, "com.dqfx.ppldz.MainActivity", "payGold", "(I)V")){
		//Jint Jindex = t.env->NewIntUTF(index);
		t.env->CallStaticBooleanMethod(t.classID, t.methodID, index);
		//t.env->DeleteLocalRef(jIndex);
		//CCLOG("call java");
	}
}

void IsMusicOn()
{

	JniMethodInfo t;
	if(JniHelper::getStaticMethodInfo(t, "com.dqfx.ppldz.MainActivity", "IsMusicOn", "()V")){
		t.env->CallStaticVoidMethod(t.classID, t.methodID);
	}
}
void onKeyDown(int keyCode)
{
	JniMethodInfo t;
	if(JniHelper::getStaticMethodInfo(t, "com.dqfx.ppldz.MainActivity", "exitGame", "()V")){
		t.env->CallStaticVoidMethod(t.classID, t.methodID);
	}
}

}
