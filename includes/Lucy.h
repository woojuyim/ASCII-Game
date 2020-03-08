#pragma once
#include "Enemy.h"

class Lucy : public Enemy {
public:
	Lucy();
	void draw() override;
	void enemyAction(Character* user1) override;
	void getStruck(Character* user1) override;
	void itemChance(Character* user1) override;
	void getAttacked(Character* user1) override;

private:
	bool attract;
};