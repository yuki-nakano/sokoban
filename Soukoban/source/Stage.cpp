#include "Stage.h"

int debugStage[STAGE_HEIGHT][STAGE_WIDTH] =
{
	0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,1,1,1,1,0,0,0,
	0,0,0,1,0,3,0,1,0,0,0,
	0,0,0,1,0,4,0,1,0,0,0,
	0,0,0,1,0,2,0,1,0,0,0,
	1,1,1,1,1,0,1,1,1,1,1,
	1,0,0,0,0,0,1,0,0,0,1,
	1,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,1,1,1,0,0,0,1,
	1,1,1,0,1,0,1,0,1,1,1,
	0,0,1,0,1,0,1,0,1,0,0,
	0,0,1,0,0,0,0,0,1,0,0,
	0,0,1,0,0,0,0,0,1,0,0,
	0,0,1,1,1,0,1,1,1,0,0,
	0,0,0,0,1,0,1,0,0,0,0,
};

Stage::Stage()
{
	inputManager = InputManager::GetInstance();
	textureManager = TextureManager::GetInstance();
	player = new Player();

	UpdateStageDate(g_SampleStage);
}

Stage::~Stage()
{
	delete player;
	player = nullptr;

	textureManager = nullptr;
	inputManager = nullptr;

	SceneManager::GetInstance()->SetNextScene(SceneID_Result);
}

void Stage::Exec()
{
	if (IsClear())
	{
		finishedCount++;

		if (finishedCount > 60)
		{
			finishedGame = true;

			GameManager::GetInstance()->SetCount(player->GetCount());
		}

		return;
	}

	animationCount++;

	if (animationCount % 20 == 0)
	{
		animationPlayer++;
	}
	
	player->MoveMethod(stageDate);

	oss.str("");
	oss << player->GetCount();
}

void Stage::Draw()
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			DrawGraph(x * CHIP_WIDTH, y * CHIP_HEIGHT, textureManager->GetTextureDate(ground), TRUE);

			switch (stageDate[y][x])
			{
			case ObjectType_Wall:
				DrawGraph(x * CHIP_WIDTH, y * CHIP_HEIGHT, textureManager->GetTextureDate(block), TRUE);
				break;
			case ObjectType_Target:
				DrawGraph(x * CHIP_WIDTH, y * CHIP_HEIGHT, textureManager->GetTextureDate(crate_target), TRUE);
				break;
			case ObjectType_UnsetCreate:
				DrawGraph(x * CHIP_WIDTH, y * CHIP_HEIGHT, textureManager->GetTextureDate(crate_unset), TRUE);
				break;
			case ObjectType_SetCreate:
				DrawGraph(x * CHIP_WIDTH, y * CHIP_HEIGHT, textureManager->GetTextureDate(crate_set), TRUE);
				break;
			}
		}
	}

	switch (player->GetPlayerDirection())
	{
	case kUp:
		DrawGraph(player->GetPosX() * CHIP_WIDTH, player->GetPosY() * CHIP_HEIGHT, textureManager->GetTextureDate(player_up_00 + animationPlayer % 4), TRUE);
		break;
	case kDown:
		DrawGraph(player->GetPosX() * CHIP_WIDTH, player->GetPosY() * CHIP_HEIGHT, textureManager->GetTextureDate(player_down_00 + animationPlayer % 4), TRUE);
		break;
	case kLeft:
		DrawGraph(player->GetPosX() * CHIP_WIDTH, player->GetPosY() * CHIP_HEIGHT, textureManager->GetTextureDate(player_left_00 + animationPlayer % 4), TRUE);
		break;
	case kRight:
		DrawGraph(player->GetPosX() * CHIP_WIDTH, player->GetPosY() * CHIP_HEIGHT, textureManager->GetTextureDate(player_right_00 + animationPlayer % 4), TRUE);
		break;
	}

	DrawExtendGraph(400, 350, 550, 500, textureManager->GetTextureDate(key), TRUE);
	DrawString(530, 420, "ÅFà⁄ìÆ", GetColor(0, 0, 0));

	DrawString(450, 100, oss.str().c_str(), GetColor(0, 0, 0));
}

bool Stage::IsClear()
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (stageDate[y][x] == ObjectType_Target)
			{
				return false;

			}
		}
	}

	return true;
}

void Stage::UpdateStageDate(const int stageDate_[][STAGE_WIDTH])
{
	if (player == nullptr)
	{
		return;
	}

	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (stageDate_[y][x] == ObjectType_Player)
			{
				player->SetPosX(x);
				player->SetPosY(y);
				stageDate[y][x] = ObjectType_Ground;
			}
			else
			{
				stageDate[y][x] = stageDate_[y][x];
			}
		}
	}
}
