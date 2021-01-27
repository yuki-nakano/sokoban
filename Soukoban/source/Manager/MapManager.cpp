#include "MapManager.h"

MapManager* MapManager::mapManager = nullptr;

MapManager::MapManager()
{
}

void MapManager::CreateInstance()
{
	if (mapManager == nullptr)
	{
		mapManager = new MapManager();
	}
}

void MapManager::DeleteInstance()
{
	delete mapManager;
	mapManager = nullptr;
}
