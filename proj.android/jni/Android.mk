LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
				   hellocpp/PayClass.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
				   ../../Classes/Bubble.cpp \
				   ../../Classes/BubbleLayer.cpp \
				   ../../Classes/GameScene.cpp \
				   ../../Classes/PropLayer.cpp \
				   ../../Classes/StartScene.cpp \
				   ../../Classes/TouchLayer.cpp \
				   ../../Classes/UserData.cpp \
				   ../../Classes/PauseLayer.cpp \
				   ../../Classes/ReviveLayer.cpp \
				   ../../Classes/GameOverLayer.cpp \
				   ../../Classes/TurnplateLayer.cpp \
				   ../../Classes/ShopLayer.cpp \
				   ../../Classes/FailLayer.cpp \
				   ../../Classes/GiftLayer.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,./prebuilt-mk)
