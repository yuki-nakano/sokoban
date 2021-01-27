#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../Definition.h"

enum
{
	//タイトルシーン
	title,

	//ゲームシーン
	crate_target,
	crate_set,
	crate_unset,

	block,
	ground,

	clear,

	player_up_00,
	player_up_01,
	player_up_02,
	player_up_03,

	player_down_00,
	player_down_01,
	player_down_02,
	player_down_03,

	player_left_00,
	player_left_01,
	player_left_02,
	player_left_03,

	player_right_00,
	player_right_01,
	player_right_02,
	player_right_03,

	key,
	
	TextureMax
};

class TextureManager
{
private:
	TextureManager();
	static TextureManager* textureManager;

public:
	static void CreateInstance();
	static void DeleteInstance();

	static TextureManager* GetInstance() { return textureManager; };

	void LoadSceneTexture(SceneID sceneid);

	void DeleteSceneTexture(SceneID sceneid);

	int GetTextureDate(int num);

private:
	int Texture[TextureMax];

};

#endif // !SCENE_MANAGER_H
