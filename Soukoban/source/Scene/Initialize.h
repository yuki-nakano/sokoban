#ifndef INITIALIZE_SCENE_H
#define INITIALIZE_SCENE_H

#include "DxLib.h"
#include "SceneBase.h"
#include "../Manager/SceneManager.h"

class InitializeScene : public SceneBase
{
public:
	InitializeScene();
	virtual ~InitializeScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool IsEnd() const;
};

#endif // !INITIALIZE_SCENE_H
