#ifndef SINGLETON_H
#define SINGLETON_H

//シングルトンデザインパターン
template< class T >
class Singleton
{
protected:
	Singleton() {}
	virtual ~Singleton() {}

private:
	static T* m_pInstance;

public:
	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new T();
		}
	}

	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	static T* GetInstance()
	{
		return m_pInstance;
	}

	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}

};
//staticなメンバ変数を初期化(コンストラクタではやらない)
template< class T >
T* Singleton<T>::m_pInstance = nullptr;

#endif // !SINGLETON_H

