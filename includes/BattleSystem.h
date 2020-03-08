#pragma once
#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H
#include "Enemy.h"

void linebreak();
void sleep();

class BattleSystem {
public:
	BattleSystem(Character *user1);
	~BattleSystem();
	void fight(Enemy* enemy, bool Saved);
	
private:
	bool calculateOrder();
	void run();
	void gainExperience();

	Enemy* enemy;
	Character* user1;
	bool battle;
	bool userTurn;
	

};

#endif