#include "InputManager.h"

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::Update()
{
	for (int i = 0; i < KeyType_Max; i++)
	{
		//���݂̃L�[�̓��͏�Ԃ��擾
		const bool now = (CheckHitKey(KEY_ASSAIGN[i]) == 1);

		//�O��̃L�[���Ɣ�r���Č��݂̏�Ԃ��X�V
		m_State[i].on = now;
//		m_State[i].push = (now == true) && (m_State[i].old == false);
//		m_State[i].pull = (now == false) && (m_State[i].old == true);
		m_State[i].push = now & !m_State[i].old;
		m_State[i].pull = (!now) & m_State[i].old;

		//���݂̒l����
		m_State[i].old = now;

	}
}

bool InputManager::IsPush(KeyType key) const
{
	if (key == KeyType_Max) { return false; }

	return m_State[key].push;
}

bool InputManager::IsOn(KeyType key) const
{
	if (key == KeyType_Max) { return false; }

	return m_State[key].on;
}

bool InputManager::IsPull(KeyType key) const
{
	if (key == KeyType_Max) { return false; }

	return m_State[key].pull;
}
