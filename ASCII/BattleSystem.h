#pragma once
#include "EnemyClasses/Enemy.h"

class BattleSystem {
public:
	BattleSystem(Character *user1);
	~BattleSystem();
	void fight(Enemy* enemy);
	
private:
	bool calculateOrder();
	void run();
	void gainExperience();

	Enemy* enemy;
	Character* user1;
	bool battle;
	bool userTurn;
	

};