#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "SceneBase.h"
#include "../Manager/GameManager.h"

#include <stdio.h>
#include <string>
#include <sstream>

class ResultScene : public SceneBase
{
public:
	ResultScene();
	virtual ~ResultScene();

	virtual void Exec();
	virtual void Draw();
	virtual bool IsEnd() const;

private:
	void step_Start();
	void step_Stay();
	void step_Input();

	std::ostringstream oss;

};


#endif // !RESULT_SCENE
