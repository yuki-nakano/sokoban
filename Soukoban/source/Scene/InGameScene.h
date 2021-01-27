#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "DxLib.h"
#include "SceneBase.h"
#include "../Definition.h"
#include "../Player.h"
#include "../Stage.h"
#include "../Manager/SceneManager.h"

class InGameScene : public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Exec();
	virtual void Draw();
	virtual bool IsEnd() const;

private:
	int m_StageDate[STAGE_HEIGHT][STAGE_WIDTH];

	TextureManager* textureManager = nullptr;

	Stage* stage = nullptr;
	Player* player = nullptr;

	bool IsClear = false;
};

#endif // !INGAME_SCENE_H
