#pragma once
#include "Enemy.h"

class Nerd : public Enemy {
public:
	Nerd();
	void draw() override;
	void enemyAction(Character* user1) override;
	void getStruck(Character* user1) override;
	void itemChance(Character* user1) override;
	void getAttacked(Character* user1) override;

private:
	bool rage;
};