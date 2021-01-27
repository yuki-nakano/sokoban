#include "TextureManager.h"
#include "DxLib.h"

TextureManager* TextureManager::textureManager = nullptr;

TextureManager::TextureManager()
{	
}

void TextureManager::CreateInstance()
{
	if (textureManager == nullptr)
	{
		textureManager = new TextureManager();
	}
}

void TextureManager::DeleteInstance()
{
	delete textureManager;
	textureManager = nullptr;
}

void TextureManager::LoadSceneTexture(SceneID sceneid)
{
	switch (sceneid)
	{
	case SceneID_Title:

		Texture[title] = LoadGraph("res/Title/sokoban.png");

		break;
	case SceneID_InGame:

		Texture[crate_target] = LoadGraph("res/game/Crate/crate_00.png");
		Texture[crate_set] = LoadGraph("res/game/Crate/crate_01.png");
		Texture[crate_unset] = LoadGraph("res/game/Crate/crate_02.png");
		Texture[block] = LoadGraph("res/game/Ground/block.png");
		Texture[ground] = LoadGraph("res/game/Ground/ground.png");
		Texture[clear] = LoadGraph("res/game/Clear.png");
		
		Texture[player_up_00] = LoadGraph("res/game/Player/player_00.png");
		Texture[player_up_01] = LoadGraph("res/game/Player/player_01.png");
		Texture[player_up_02] = LoadGraph("res/game/Player/player_00.png");
		Texture[player_up_03] = LoadGraph("res/game/Player/player_02.png");

		Texture[player_down_00] = LoadGraph("res/game/Player/player_03.png");
		Texture[player_down_01] = LoadGraph("res/game/Player/player_04.png");
		Texture[player_down_02] = LoadGraph("res/game/Player/player_03.png");
		Texture[player_down_03] = LoadGraph("res/game/Player/player_05.png");

		Texture[player_left_00] = LoadGraph("res/game/Player/player_06.png");
		Texture[player_left_01] = LoadGraph("res/game/Player/player_07.png");
		Texture[player_left_02] = LoadGraph("res/game/Player/player_06.png");
		Texture[player_left_03] = LoadGraph("res/game/Player/player_08.png");

		Texture[player_right_00] = LoadGraph("res/game/Player/player_09.png");
		Texture[player_right_01] = LoadGraph("res/game/Player/player_10.png");
		Texture[player_right_02] = LoadGraph("res/game/Player/player_09.png");
		Texture[player_right_03] = LoadGraph("res/game/Player/player_11.png");

		Texture[key] = LoadGraph("res/game/kii.png");

		break;
	case SceneID_Result:
		break;
	default:
		break;
	}
}

void TextureManager::DeleteSceneTexture(SceneID sceneid)
{
	for (int i = 0; i < TextureMax; i++)
	{
		DeleteGraph(Texture[i]);
	}
}

int TextureManager::GetTextureDate(int num)
{
	return Texture[num];
}
