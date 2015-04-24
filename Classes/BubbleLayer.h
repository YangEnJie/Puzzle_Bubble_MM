#ifndef BUBBLE_LAYER_H_
#define BUBBLE_LAYER_H_

#include "cocos2d.h"
#include "Bubble.h"
#include "GameConst.h"
#include "GameEnum.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"


USING_NS_CC;
using namespace cocostudio;

class BubbleLayer : public Layer
{
public:
		virtual bool init();

		static cocos2d::Scene* scene();

	
	void onTouch(Point target);
	  


	CREATE_FUNC(BubbleLayer);
	virtual void update(float delta);

public:
	Bubble *board[MAX_ROWS][MAX_COLS]; 	 //��������
	Vector<Armature*> armatures;

private:
	Bubble *wait[MAX_WAIT_PAOPAO]; 	    // �ȴ�������
public:
	Bubble *ready;  // ���ᷢ�������
private:
	
	CC_SYNTHESIZE(Vec2, real, Real);
	CC_SYNTHESIZE(int, _level, Level);
	bool _havePass = false;
	

	EventListenerTouchOneByOne* _listener;
	bool initTheBoard(int level = 0);  //��ʼ���ؿ�
	Bubble *randomPaoPao(); //��ȡ�������
	Point getPointByRowAndCol(int row, int col); //�������м��Ƿ���ȱȷ��λ��
	Point getRowAndColByPoint(Point target);
	void initWaitPaoPao(); //��ʼ���ȴ�������
	void initReadyPaoPao(); //��ʼ��׼�����������
	void setEnable();	//���ô�����Ч
	void setDisable();	//���ô�����Ч
	bool isCollideBorder();
	bool checCollideBoard();
	void changeWaitToReady();
	void correctReadyPosition();
	bool getFirstRowFlag();
	bool isCircleCollision(Point pos1, float radius1, Point pos2, float radius2);
	void findTheSameBubble(int i, int j, bool flag, BubbleType type);
	void bubbleBlast(int i, int j, bool flag);
	void moveTheBubble(int i, int j, bool flag, float distance, bool ready = true);
	void deleteTheSameBubble(int i, int j, bool flag);
	void deleteSameBubbles(int i, int j, int step);
	void bubbleAction(Bubble *obj);
	void callbackRemoveBubble(Node *obj);
	void downBubbleActionCallBack(Node *obj);
	void jumpActionCallBack();
	void resetAllPass();
	void checkDownBubble(int i, int j);
	void downBubble();
	void downBubbleAction(Bubble *obj);
	void initBubbleAction(Bubble *obj, int i, int j);
	void gameOver(bool over = false);
	void setReadyAngle(Point target);
	void throwBallAction();
	bool isPass();
	bool isGameover();
	void movementPassCallBack(Armature * armature, MovementEventType type, const std::string &name);
	void moveParantCallBack(Armature * armature, MovementEventType type, const std::string &name);
	void readyAction();
	void addReadGo();
	void setDetermineLineVisible(float delat);

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	void dropBubble(float dat);
	

public:

	Vector<Sprite*> _auxiliary;

	void colorBubble(bool use = true);
	void swapBubble();
	void bombBubble(bool use = true);
	void auxiliaryLine(Point tagrat);
	void savaCurrentBoard();
	bool initTheBoardWithData();
};

#endif /* defined(__paopaolong__MainLayer__) */