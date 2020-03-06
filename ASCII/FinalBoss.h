#pragma once
#include "Character.h"

class FinalBoss {
public:
	FinalBoss();

	void fightFinal(Character *user1);
	void drawfinalboss();
	bool math(Character* user1);
	void congrats();

private:
	std::vector<std::string> goodresponses;
	std::vector<std::string> badresponses;
	std::vector<int> damageArray;
};

