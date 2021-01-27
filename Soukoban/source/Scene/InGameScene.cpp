#include "InGameScene.h"

InGameScene::InGameScene()
{
	textureManager = TextureManager::GetInstance();
	textureManager->LoadSceneTexture(SceneID_InGame);

	stage = new Stage();
}

InGameScene::~InGameScene()
{
	delete stage;
	stage = nullptr;

	textureManager->DeleteSceneTexture(SceneID_InGame);
	textureManager = nullptr;
}

void InGameScene::Exec()
{
	stage->Exec();
}

void InGameScene::Draw()
{
	stage->Draw();
}

bool InGameScene::IsEnd() const
{
	return (stage->GetGameStatus());
}
