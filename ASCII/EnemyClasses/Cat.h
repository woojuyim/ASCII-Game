#pragma once
#include "Enemy.h"

class Cat : public Enemy {
public:	
	Cat();
	void draw() override;
	void enemyAction(Character* user1) override;
	void getStruck(Character* user1) override;
	void itemChance(Character* user1) override;

private:
	void drawcat1();
	void drawcat();
};