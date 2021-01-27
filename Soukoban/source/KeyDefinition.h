#ifndef KEY_DEFINITION_H
#define KEY_DEFINITION_H

#include "DxLib.h"

enum KeyType
{
	KeyType_Up,		//上移動
	KeyType_Down,	//下移動
	KeyType_Left,	//左移動
	KeyType_Right,	//右移動
	KeyType_Enter,	//決定
	KeyType_Reset,	//リセット
	
	KeyType_Max,	//キーの種類の数

};

//キーの種類に対応する、実際の入力配置
const int KEY_ASSAIGN[KeyType_Max] =
{
	KEY_INPUT_UP,		//keyType_Up
	KEY_INPUT_DOWN,		//keyType_Down
	KEY_INPUT_LEFT,		//keyType_Left
	KEY_INPUT_RIGHT,	//keyType_Right
	KEY_INPUT_RETURN,	//keyType_Enter
	KEY_INPUT_R,		//keyType_Reset
};


#endif // !KEY_DEFINITION_H
