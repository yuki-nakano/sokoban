#ifndef STAGE_H
#define STAGE_H

#include "Definition.h"

#include "Manager/GameManager.h"
#include "Manager/InputManager.h"
#include "Manager/TextureManager.h"
#include "Manager/SceneManager.h"
#include "Player.h"

#include <stdio.h>
#include <string>
#include <sstream>

class Stage
{
public:
	Stage();
	~Stage();

	void Exec();
	void Draw();
	bool IsClear();
	void UpdateStageDate(const int stageDate_[][STAGE_WIDTH]);

	int GetStageDate(int height_, int width_) const { return stageDate[height_][width_]; };
	bool GetGameStatus() const { return finishedGame; };
	int SetStageDate(int height_, int width_, int date_) { return stageDate[width_][height_] = date_; };

private:
	int stageDate[STAGE_HEIGHT][STAGE_WIDTH];

	int animationCount = 0;
	int animationPlayer = 0;

	int finishedCount = 0;
	bool finishedGame = false;

	std::ostringstream oss;

	InputManager* inputManager = nullptr;
	TextureManager* textureManager = nullptr;
	Player* player = nullptr;
};


#endif // !STAGE_H
