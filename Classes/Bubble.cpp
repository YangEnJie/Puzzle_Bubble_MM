#include "Bubble.h"
#include "GameConst.h"
#include "cocostudio/CocoStudio.h"
#include "GameConst.h"
using namespace cocostudio;

Bubble::Bubble()//���캯����ʼ��
{
	_flag = false;
	_type = BUBBLE_TYPE_UNKNOW;
	_isSame = false;
	_isPass = false;
	_isMove = false;
	_isDie = false;
}

Bubble::~Bubble()
{

}

Bubble * Bubble::initWithType(BubbleType type) //���ݴ���������������������
{
	Bubble *pRet = Bubble::create();
// 	int str = (int)type + BubbleMap;
// 	if (str > 7)
// 	{
// 		str %= 7;
// 	}
	int str = (int)type;
	pRet->setType((BubbleType)str);
	pRet->initWithSpriteFrameName(pRet->getStringByType(type));
// 
// 	ArmatureDataManager::getInstance()->addArmatureFileInfo("BubbleSpecial/baozha.ExportJson");
// 	Armature* armature = Armature::create("baozha");
// 	pRet->addChild(armature);
// 	armature->setPosition(pRet->getContentSize() / 2);
// 	armature->setTag(20);


	return pRet;
}



std::string Bubble::getStringByType(BubbleType type) //��ͬ���ͻ�ȡ��ͬ��ͼƬ��Դ
{
	std::string pRet;

// 	int str = (int)type + BubbleMap;
// 	if (str > 7)
// 	{
// 		str = str % 7;
// 	}
	int str = (int)type;
	switch (type) {
	case BUBBLE_TYPE1:
	case BUBBLE_TYPE2:
	case BUBBLE_TYPE3:
	case BUBBLE_TYPE4:
	case BUBBLE_TYPE5:
	case BUBBLE_TYPE6:
	case BUBBLE_TYPE7:
		pRet = StringUtils::format(BUBBLE_NAME.c_str(), str);
		break;
	case BUBBLE_TYPE_COLOR:
		pRet = BUBBLE_COLOR_NAME;
		break;
	case BUBBLE_TYPE_BOMB:
		pRet = BUBBLE_BOMB_NAME;
	default:
		this->setType(BUBBLE_TYPE1);
		pRet = StringUtils::format(BUBBLE_NAME.c_str(), 1);
		break;
	}
	return pRet;
}