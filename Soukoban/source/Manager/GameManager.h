#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../Singleton.h"

class GameManager : public Singleton<GameManager>
{
public:
	GameManager();
	~GameManager();

	int GetCount() const { return count; };

	void SetCount(int count_) { count = count_; };

private:
	int count;

};




#endif // !GAME_MANAGER_H

