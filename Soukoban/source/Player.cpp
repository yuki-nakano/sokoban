#include "Player.h"

Player::Player()
{
	inputManager = InputManager::GetInstance();
}

Player::~Player()
{
	inputManager = nullptr;
}

void Player::MoveMethod(int stageDate_[][STAGE_WIDTH])
{
	if (inputManager->IsPush(KeyType_Up))
	{
		playerDirection = kUp;

		frontPosx = 0;
		frontPosy = -1;
		front2Posx = 0;
		front2Posy = -2;

		Move(stageDate_);
	}
	else if (inputManager->IsPush(KeyType_Down))
	{
		playerDirection = kDown;

		frontPosx = 0;
		frontPosy = 1;
		front2Posx = 0;
		front2Posy = 2;

		Move(stageDate_);
	}
	else if (inputManager->IsPush(KeyType_Left))
	{
		playerDirection = kLeft;

		frontPosx = -1;
		frontPosy = 0;
		front2Posx = -2;
		front2Posy = 0;

		Move(stageDate_);
	}
	else if (inputManager->IsPush(KeyType_Right))
	{
		playerDirection = kRight;

		frontPosx = 1;
		frontPosy = 0;
		front2Posx = 2;
		front2Posy = 0;

		Move(stageDate_);
	}
}

void Player::Move(int stageDate_[][STAGE_WIDTH])
{
	switch (stageDate_[posy + frontPosy][posx+ frontPosx])
	{
	case ObjectType_Ground:

		ChangePos();

		break;
	case ObjectType_Target:

		ChangePos();

		break;
	case ObjectType_UnsetCreate:

		switch (stageDate_[posy + front2Posy][posx + front2Posx])
		{
		case ObjectType_Ground:

			stageDate_[posy + front2Posy][posx + front2Posx] = ObjectType_UnsetCreate;
			stageDate_[posy + frontPosy][posx + frontPosx] = ObjectType_Ground;
			ChangePos();

			break;
		case ObjectType_Target:

			stageDate_[posy + front2Posy][posx + front2Posx] = ObjectType_SetCreate;
			stageDate_[posy + frontPosy][posx + frontPosx] = ObjectType_Ground;
			ChangePos();

			break;
		default:
			break;
		}

		break;
	case ObjectType_SetCreate:

		switch (stageDate_[posy + front2Posy][posx + front2Posx])
		{
		case ObjectType_Ground:

			stageDate_[posy + front2Posy][posx + front2Posx] = ObjectType_UnsetCreate;
			stageDate_[posy + frontPosy][posx + frontPosx] = ObjectType_Target;
			ChangePos();

			break;
		case ObjectType_Target:

			stageDate_[posy + front2Posy][posx + front2Posx] = ObjectType_SetCreate;
			stageDate_[posy + frontPosy][posx + frontPosx] = ObjectType_Target;
			ChangePos();

			break;
		default:
			break;
		}

		break;
	default:
		break;
	}

}

void Player::ChangePos()
{
	count++;

	switch (playerDirection)
	{
	case kUp:

		posy--;

		break;
	case kDown:
		
		posy++;
		
		break;
	case kLeft:
		
		posx--;
		
		break;
	case kRight:
		
		posx++;
		
		break;
	}
}


