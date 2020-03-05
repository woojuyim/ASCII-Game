#pragma once
#include "Enemy.h"

class Juggler : public Enemy {
public:
	Juggler();
	void draw() override;
	void enemyAction(Character* user1) override;
	void getStruck(Character* user1) override;
	void itemChance(Character* user1) override;
	void getAttacked(Character* user1) override;


private:
	void drawjugman();
	void drawjugman1();
	void drawjugman2();
};

