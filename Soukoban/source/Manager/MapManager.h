#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

class MapManager
{
private:
	MapManager();
	static MapManager* mapManager;

public:
	static void CreateInstance();
	static void DeleteInstance();

	static MapManager* GetInstance() { return mapManager; };

private:

};

#endif // !MAP_MANAGER_H
