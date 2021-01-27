#include "ResultScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"

enum
{
	STEP_START,
	STEP_STAY,
	STEP_INPUT,
	STEP_END,
};

ResultScene::ResultScene()
{
	m_Step = STEP_START;

	oss.str("");
	oss << GameManager::GetInstance()->GetCount();
}

ResultScene::~ResultScene()
{
}

void ResultScene::Exec()
{
	switch (m_Step)
	{
	case STEP_START:step_Start(); break;
	case STEP_STAY:	step_Stay(); break;
	case STEP_INPUT:	step_Input(); break;
	default: break;
	}
}

void ResultScene::Draw()
{
	DrawString(290, 220, oss.str().c_str(), GetColor(0, 0, 0));
	DrawString(270, 180, "ˆÚ“®‰ñ”", GetColor(0, 0, 0));

	DrawString(250, 400, "PLEASE ENTER", GetColor(255, 0, 0));
}

bool ResultScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

void ResultScene::step_Start()
{
	m_Step = STEP_STAY;
}

void ResultScene::step_Stay()
{
	InputManager* pInputMng = InputManager::GetInstance();

	if (pInputMng->IsPush(KeyType_Enter))
	{
		m_Step = STEP_INPUT;
	}
}

void ResultScene::step_Input()
{
	m_Step = STEP_END;
	SceneManager::GetInstance()->SetNextScene(SceneID_Title);
}
