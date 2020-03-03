#pragma once
#include "Character.h"
#include "Enemy.h"
#include <iostream>

class BattleSystem {
public:
	BattleSystem(Enemy& m, Character& user1);

	void fight();
	bool calculateOrder();
	void attack();
	void strike();
	void run();
	void gainExperience();
private:
	bool battle;
	bool userTurn;
	Enemy m;
	Character user1;

};