#ifndef KEY_DEFINITION_H
#define KEY_DEFINITION_H

#include "DxLib.h"

enum KeyType
{
	KeyType_Up,		//��ړ�
	KeyType_Down,	//���ړ�
	KeyType_Left,	//���ړ�
	KeyType_Right,	//�E�ړ�
	KeyType_Enter,	//����
	KeyType_Reset,	//���Z�b�g
	
	KeyType_Max,	//�L�[�̎�ނ̐�

};

//�L�[�̎�ނɑΉ�����A���ۂ̓��͔z�u
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
