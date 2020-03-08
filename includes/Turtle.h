#pragma once
#include "Enemy.h"

class Turtle : public Enemy {
public:
	Turtle();

	void draw() override;
	void enemyAction(Character* user1) override;
	void getStruck(Character* user1) override;
	void getAttacked(Character* user1) override;
	void itemChance(Character* user1) override;

private:
	void drawturtle();
	void drawturtle1();
	void drawturtle2();
};