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

	bool battle;
	bool userTurn;
	Enemy *enemy;
	Character *user1;

};