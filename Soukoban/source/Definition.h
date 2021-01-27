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
	ObjectType_Ground,			//0 �n��
	ObjectType_Wall,			//1 ��
	ObjectType_Player,			//2 �v���C���[�����l
	ObjectType_Target,			//3 �N���[�Ɣz�u�ꏊ
	ObjectType_UnsetCreate,		//4 ���z�u�̃N���[�g
	ObjectType_SetCreate = 7,	//7 �z�u�ς݃N���[�g
};


#endif // !DEFINITION_H
