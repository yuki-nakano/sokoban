#ifndef PLAYER_H
#define PLAYER_H

#include "Manager/InputManager.h"
#include "Manager/TextureManager.h"

enum PlayerDirection
{
	kUp,
	kDown,
	kLeft,
	kRight,
};

class Player
{
public:
	Player();
	~Player();

	void MoveMethod(int stageDate_[][STAGE_WIDTH]);

	int GetPosX() const { return posx; };
	int GetPosY() const { return posy; };
	PlayerDirection GetPlayerDirection() const { return playerDirection; };
	int GetCount() const { return count; };
	void SetPosX(int posx_) { posx = posx_; };
	void SetPosY(int posy_) { posy = posy_; };

private:
	int posx = 0;
	int posy = 0;

	int frontPosx = 0;
	int frontPosy = 0;
	int front2Posx = 0;
	int front2Posy = 0;

	int count = 0;

	PlayerDirection playerDirection = kUp;

	InputManager* inputManager = nullptr;

private:
	void Move(int stageDate_[][STAGE_WIDTH]);
	void ChangePos();

};

#endif // !PLAYER_H
