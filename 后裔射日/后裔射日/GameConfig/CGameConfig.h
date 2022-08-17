#pragma once

//-----------------image-------------------
//背景
#define IMG_BK_ONE_WIDTH			793
#define IMG_BK_ONE_HEIGHT			600

//人物
#define IMG_PEO_WIDTH				50
#define IMG_PEO_HEIGHT				80

//箭的出发点
#define IMG_TAR_WIDTH				26
#define IMG_TAR_HEIGHT				26

//箭
#define IMG_ARR_WIDTH				20
#define IMG_ARR_HEIGHT				20

//太阳
#define IMG_SUN_WIDTH				50
#define IMG_SUN_HEIGHT				50

//盾牌
#define IMG_SHE_WIDTH				25
#define	IMG_SHE_HEIGHT				25

//-----------------timer--------------------
//背景定时移动
#define TIMER_BK_ONE_MOVE_ID		1
#define TIMER_BK_ONE_MOVE_INTERVAL  100
#define TIMER_BK_ONE_MOVE_STEP	    1


//箭的出发点定时移动
#define TIMER_TAR_MOVE_ID			2
#define TIMER_TAR_MOVE_INTERVAL		100
#define TIMER_TAR_MOVE_STEP			1


//箭的定时移动
#define TIMER_ARR_MOVE_ID			3
#define TIMER_ARR_MOVE_INTERVAL		10
#define TIMER_ARR_MOVE_STEP			12

//太阳的定时产生
#define TIMER_SUN_CREAT_ID			4
#define TIMER_SUN_CREAT_INTERVAL	1000

//太阳的受伤判定
#define TIMER_SUN_HURT_ID			5
#define TIMER_SUN_HURT_INTERVAL		100

//计时器结束游戏
#define TIMER_GAMEOVER_ID			6
#define TIMER_GAMEOVER_INTERVAL		1000

//判断盾是否吸收箭
#define TIMER_DEARROW_ID			7
#define TIMER_DEARROW_INTERVAL		10


//------------------data-------------------
//太阳的血量
#define SUN_BLOOD					5

//弓箭的伤害
#define SUN_HURT					1

//盾牌的数量
#define	NUM_SHIELD					8

//盾牌的间隔
#define NUM_SHIELD_INTERVAL_X		20
#define NUM_SHIELD_INTERVAL_Y		45

//******************************************
#define PEO_ATTACK_J				106
#define PEO_ATTACKS_TIME			9999
