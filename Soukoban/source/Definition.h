#ifndef DEFINITION_H
#define DEFINITION_H

enum SceneID
{
	SceneID_Initialize,
	SceneID_Title,
	SceneID_InGame,
	SceneID_Result,

	SceneID_Max,
	SceneID_Invalid
};

const int STAGE_WIDTH = 11;
const int STAGE_HEIGHT = 15;

const int CHIP_WIDTH = 32;
const int CHIP_HEIGHT = 32;

const int g_SampleStage[STAGE_HEIGHT][STAGE_WIDTH] =
{
	0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,0,0,0,
	0,0,0,1,3,3,3,1,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,
	1,1,1,1,1,0,1,1,1,1,1,
	1,0,0,4,0,0,1,0,0,0,1,
	1,0,1,0,0,4,0,4,0,0,1,
	1,0,0,0,1,1,1,0,0,0,1,
	1,1,1,0,1,0,1,0,1,1,1,
	0,0,1,0,1,0,1,0,1,0,0,
	0,0,1,0,0,0,0,0,1,0,0,
	0,0,1,0,0,2,0,0,1,0,0,
	0,0,1,1,1,0,1,1,1,0,0,
	0,0,0,0,1,0,1,0,0,0,0,
};

enum ObjectType
{	
	ObjectType_Ground,			//0 地面
	ObjectType_Wall,			//1 壁
	ObjectType_Player,			//2 プレイヤー初期値
	ObjectType_Target,			//3 クレーと配置場所
	ObjectType_UnsetCreate,		//4 未配置のクレート
	ObjectType_SetCreate = 7,	//7 配置済みクレート
};


#endif // !DEFINITION_H
