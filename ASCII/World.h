#pragma once
#include "Character.h"
#include "EnemyClasses/Enemy.h"
#include "EnemyClasses/Cat.h"
#include "EnemyClasses/Guitarist.h"
#include "EnemyClasses/Juggler.h"
#include "EnemyClasses/Lucy.h"
#include "EnemyClasses/Turtle.h"
#include "EnemyClasses/Nerd.h"
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
	bool finalboss;

};


