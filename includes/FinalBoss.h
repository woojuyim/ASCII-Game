#pragma once
#include "Character.h"

void linebreak();

class FinalBoss {
public:
	FinalBoss(Character* user1);

	void timer();
	void fightFinal();
	void drawfinalboss();
	bool math();
	void congrats();

private:
	std::vector<std::string> goodresponses;
	std::vector<std::string> badresponses;
	std::vector<int> damageArray;

	Character* user1;
};

