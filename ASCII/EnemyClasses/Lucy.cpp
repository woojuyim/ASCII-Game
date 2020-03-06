#include "Lucy.h"

using namespace std;
Lucy::Lucy() {
	name = "Lucy";
	level = 4;
	attack = rand() % 5 + 1;
	defense = rand() % 2;
	speed = 10;
	health = rand() % 4 + 6;
	magicdefense = 0;
	bool attract = false;
}
void Lucy::enemyAction(Character* user1) {
	std::cout << "\nIt's Lucy's turn. \n";
	srand((unsigned)time(0));
	int random = rand() % 100;
	if (random < 20) {
		std::cout << "Lucy critically stabbed you!\n";
		user1->takedamage((getattack() - user1->getdefense()) * 2);
	}
	else if (random > 70 && attract == false) {
		std::cout << "Lucy used her charm on you. You may not be able to move. \n";
		attract = true;
	}
	else {
		std::cout << "Lucy slapped you! \n";
		user1->takedamage(getattack() - user1->getdefense());
	}
}
void Lucy::getStruck(Character* user1) {
	srand((unsigned)time(0));
	int r = (rand() % 10);
	if (attract && r < 5) {
		std::cout << "You were overcome with love to Lucy! \n";
	}
	else if ((rand() % 100) < 30) {
		std::cout << "You critically slapped Lucy! \n";
		takedamage((user1->getattack() - getdefense()) * 3);
	}
	else {
		std::cout << "You were too lovestruck by Lucy... \n";
	}

}
void Lucy::itemChance(Character* user1) {
	int chance = rand() % 101;
	if (chance > 30) {
		user1->itemget("Lucy");
		std::cout << "You captured Lucy! Just... she might be a bit volatile... \n";
	}
}
void Lucy::getAttacked(Character* user1) {
	int r = (rand() % 10);
	if (attract && r < 5) {
		std::cout << "You were overcome with love to Lucy! \n";
	}
	else {
		std::cout << "You punched Lucy. \n";
		takedamage(user1->getattack() - getdefense());
	}
}
void Lucy::draw() {
	cout << "    ,-,  " << endl
		<< "   (('')) " << endl
		<< "  __/  \\__ " << endl
		<< "   /____\\ " << endl
		<< "    _| \\_" << endl << endl;
}