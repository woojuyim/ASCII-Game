#include "Warrior.h"



Warrior::Warrior() {
	attack = 3;
	magic = 1;
	defense = 2;
	speed = 2;
	className = "Warrior";
	abilities.push_back("Green Tea");
}

void Warrior::specialAttack(Enemy* enemy) {
}

void Warrior::subclassSpecial(Enemy* enemy, std::string& ability) {
	std::cout << "You used " << ability << "\n";
	if (ability == "Green Tea") {
		greentea(enemy);
	}
	else {
		throw std::exception("ITEM DOES NOT EXIST");
	}
}

void Warrior::greentea(Enemy* enemy) {
	std::cout << "You threw Green Tea at the " + enemy->getName()
		<< ". It only caused some first degree burns... \n";
	enemy->takedamage(1);
}
void Warrior::levelup() {
	std::cout << "\nYou gained a level up! \n";
	srand((unsigned)time(0));
	int c = rand() % 3 + 1;
	experience -= 10;
	changeattack(rand() % 2 + 1);
	changemagic(1);
	changedef(rand() % 2);
	changespeed(rand() % 2);
	changeMaxHealth(c);
	increaseHealth(c);
	++level;
	/*if (level == 2) {
		std::cout << "You learned Math! \n";
		abilities.push_back("Math");
	}*/
}