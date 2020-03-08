#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Cat.h"
#include "Guitarist.h"
#include "Juggler.h"
#include "Lucy.h"
#include "Turtle.h"
#include "Nerd.h"
#include "BattleSystem.h"
#include "FinalBoss.h"
#include "User.h"

void linebreak();
class World {
public:
	World();

	void forward(Character* user1, User* user);
	void gameMenu(Character* user1, User* user);

private: 

};


