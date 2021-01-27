#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "SceneBase.h"
#include "../Manager/SceneManager.h"
#include "../Manager/TextureManager.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool IsEnd() const;

private:
	void step_Input();

private:
	TextureManager* textureManager = nullptr;

};

#endif // !TITLE_SCENE
