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
	SetMainWindowText("倉庫番");

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)		
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//管理クラスの作成
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

			//処理
			InputManager::GetInstance()->Update();
			SceneManager::GetInstance()->Exec();

			//描画
			SceneManager::GetInstance()->Draw();

			ScreenFlip();
		}
	}
	//管理クラスの後始末
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();
	TextureManager::DeleteInstance();

	// ＤＸライブラリ使用の終了処理
	DxLib_End();			

	return 0;				// ソフトの終了 
}
