#include "TitleScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"
#include "../Manager/TextureManager.h"

//実行ステップ定義
enum
{
	STEP_LOGO_IN,
	STEP_INPUT,
	STEP_END,
};

TitleScene::TitleScene()
{
	textureManager = TextureManager::GetInstance();
	textureManager->LoadSceneTexture(SceneID_Title);

	m_Step = STEP_INPUT;
}

TitleScene::~TitleScene()
{
	textureManager->DeleteSceneTexture(SceneID_Title);
	textureManager = nullptr;
}

void TitleScene::Exec()
{
	step_Input();
}

void TitleScene::Draw()
{
	DrawString(250, 400, "PLEASE ENTER", GetColor(255, 0, 0));
	
	DrawExtendGraph(70, 50, 550, 334, textureManager->GetTextureDate(title), TRUE);

}

bool TitleScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

void TitleScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Enter))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_InGame);
	}
}
