#pragma once
#include "Enemy.h"

void sleep();
class Guitarist : public Enemy {
public:
	Guitarist();
	void draw() override;
	void enemyAction(Character* user1) override;
	void getStruck(Character* user1) override;
	void itemChance(Character* user1) override;

private:
	bool guitar;
};