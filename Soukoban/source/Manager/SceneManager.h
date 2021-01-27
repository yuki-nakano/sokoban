#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Definition.h"
#include "../Singleton.h"

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

public:
	void Exec();
	void Draw();

	void SetNextScene(SceneID next_);

private:
	class SceneBase* create_NextScene();

private:
	class SceneBase* m_pScene;
	static SceneID m_NextSceneID;

};

#if 0
//------------
//�V���O���g���f�U�C���p�^�[��(�N���X�ɒ��ڏ����ꍇ)

private:
	static SceneManager* m_pInstance;

public:
	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SceneManager();
		}
	}

	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	static SceneManager* GetInstance()
	{
		return m_pInstance;
	}

	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}
};
 
//static�����o�ϐ���������
SceneManager* SceneManager::m_pInstance = nullptr;
#endif // !0


#endif // !SCENEMANAGER_H
