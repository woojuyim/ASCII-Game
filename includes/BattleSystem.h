#pragma once
#include "Enemy.h"

void linebreak();
void sleep();

class BattleSystem {
public:
	BattleSystem(Character *user1);
	~BattleSystem();
	void fight(Enemy* enemy, bool Saved);
	
private:
	//Calculate turn order
	bool calculateOrder();

	//Running away from fight
	void run();

	//Gain experience
	void gainExperience();

	Enemy* enemy;
	Character* user1;
	bool battle;
	bool userTurn;
	

};
