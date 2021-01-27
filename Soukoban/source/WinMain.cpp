#include "DxLib.h"
#include "Manager/SceneManager.h"
#include "Manager/GameManager.h"
#include "Manager/InputManager.h"
#include "Manager/TextureManager.h"

const int WINDOW_W = 640;
const int WINDOW_H = 480;
const int COLOR_BIT = 16;

int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_W, WINDOW_H, COLOR_BIT);
	SetBackgroundColor(255, 255, 255);
	SetMainWindowText("�q�ɔ�");

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)		
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//�Ǘ��N���X�̍쐬
	GameManager::CreateInstance();
	InputManager::CreateInstance();
	SceneManager::CreateInstance();
	TextureManager::CreateInstance();

	while (true)
	{
		if (ProcessMessage() != 0)
		{
			break;
		}
		else
		{
			ClearDrawScreen();
			clsDx();

			//����
			InputManager::GetInstance()->Update();
			SceneManager::GetInstance()->Exec();

			//�`��
			SceneManager::GetInstance()->Draw();

			ScreenFlip();
		}
	}
	//�Ǘ��N���X�̌�n��
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();
	TextureManager::DeleteInstance();

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();			

	return 0;				// �\�t�g�̏I�� 
}
