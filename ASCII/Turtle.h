#pragma once
#include "Enemy.h"
#include "Character.h"
#include <iostream>
class Turtle : public Enemy {
private:

public:
	Turtle();
	void battle(Character& user1) override;
	void draw() override;
	void drawturtle();
	void drawturtle1();
	void drawturtle2();
};