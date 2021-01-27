#include "Initialize.h"

InitializeScene::InitializeScene()
{
}

InitializeScene::~InitializeScene()
{
}

void InitializeScene::Exec()
{
	SceneManager::GetInstance()->SetNextScene(SceneID_Title);
}

void InitializeScene::Draw()
{
	DrawString(280, 180, "road", GetColor(255, 0, 0));
}

bool InitializeScene::IsEnd() const
{
	return true;
}
