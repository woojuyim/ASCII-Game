#pragma once
#include "Character.h"

void linebreak();

class FinalBoss {
public:
	FinalBoss(Character* user1);

	//Fight Final Boss
	void fightFinal();

	//Draw
	void drawfinalboss();
	
	//Draw math problems
	bool math();

	//Ending scene
	void congrats();

private:
	std::vector<std::string> goodresponses;
	std::vector<std::string> badresponses;
	std::vector<int> damageArray;

	Character* user1;
};

