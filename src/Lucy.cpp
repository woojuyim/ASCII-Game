#include "Lucy.h"

Lucy::Lucy() {
	name = "Lucy";
	level = 3;
	// 6 - 7
	attack = rand() % 3 + 6;
	// 2 - 3
	defense = rand() % 2 + 2;
	// 2 - 8 
	speed = rand () % 6 + 2;
	// 12 - 16
	health = rand() % 4 + 12;
	// 0 - 2
	magicdefense = rand() % 3;
	bool attract = false;
}
void Lucy::enemyAction(Character* user1) {
	std::cout << "It's Lucy's turn. \n";
	srand((unsigned)time(0));
	sleep();
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
	std::cout << "You tried to slap Lucy! \n";
	sleep();
	srand((unsigned)time(0));
	int r = (rand() % 10);
	if (attract == true && r < 5) {
		std::cout << "You were overcome with love to Lucy! \n";
		return;
	}
	if (r < 4) {
		std::cout << "You critically hit her! \n";
		takedamage((user1->getattack() - getdefense()) * 3);
	}
	else {
		std::cout << "You couldn't bring yourself to slap her... \n";
	}

}
void Lucy::itemChance(Character* user1) {
	int chance = rand() % 100;
	if (chance <= 20) {
		user1->itemget("Lucy");
		std::cout << "You captured Lucy! Just... she might be a bit volatile... \n";
	}
}
void Lucy::getAttacked(Character* user1) {
	int r = (rand() % 10);
	sleep();
	if (attract && r < 5) {
		std::cout << "You were overcome with love to Lucy! \n";
	}
	else {
		std::cout << "You punched Lucy. \n";
		takedamage(user1->getattack() - getdefense());
	}
}
void Lucy::draw() {
	std::cout << "    ,-,  " << std::endl
		<< "   (('')) " << std::endl
		<< "  __/  \\__ " << std::endl
		<< "   /____\\ " << std::endl
		<< "    _| \\_" << std::endl << std::endl;
}