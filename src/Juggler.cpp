#include "Juggler.h"

Juggler::Juggler() {
	name = "Juggler";
	level = 2;
	// 5 - 7
	attack = rand() % 3 + 5;
	// 1 - 2
	defense =  rand() % 3 + 2;
	// 5 - 7
	speed = rand() % 3 + 5;
	// 7 - 10
	health = rand() % 3 + 7;
	// 0 - 2
	magicdefense = rand() % 2;
}

void Juggler::draw() {
	int prob = rand() % 100;
	if (prob < 60)
		drawjugman();
	else if (prob > 70)
		drawjugman1();
	else
		drawjugman2();
}
void Juggler::enemyAction(Character* user1) {
	std::cout << "It's the Juggler's turn. \n";
	sleep();
	srand((unsigned)time(0));
	if ((rand() % 100) < 30) {
		srand((unsigned)time(0));
		if ((rand() % 100) < 40) {
			std::cout << "The Juggler threw a knife at you! \n";
			user1->takedamage((getattack() - user1->getdefense()) * 2);
		}
		else {
			std::cout << "The Juggler is hoping to win the audition to perform at Lacey's Carnival to impress the kids.";
		}
	}

	else {
		std::cout << "The Juggler threw his balls at you! \n";
		user1->takedamage(getattack() - user1->getdefense());
	}
}
void Juggler::getAttacked(Character* user1) {
	sleep();
	std::cout << "You stole his balls and threw them back at him!\n";
	takedamage(user1->getattack() - getdefense());
}

void Juggler::getStruck(Character* user1) {
	srand((unsigned)time(0));
	std::cout << "You tried juggling four balls in front of him! \n";
	sleep();
	if ((rand() % 100) < 30) {
		std::cout << "The Juggler was shocked at your ball handling skills! \n";
		takedamage((user1->getattack() - getdefense()) * 3);
	}
	else {
		std::cout << "You slipped on one of his balls and failed... \n";
	}
}
void Juggler::itemChance(Character* user1) {
	int chance = rand() % 101;
	if (chance > 70) {
		user1->itemget("Flying Bat");
		std::cout << "You found a Flying Bat. \n";
	}
}

void Juggler::drawjugman1() {
	std::cout << "    o  \n"
		<< "       o   \n"
		<< "  o O    \n"
		<< " `\\/Y\\/~  \n"
		<< "___/_\\____  \n" << std::endl;
}
void Juggler::drawjugman2() {
	std::cout << "     o     \n"
		<< "        o   \n"
		<< "  o  O      \n"
		<< "  `--| \\o  \n"
		<< "    /<'      \n"
		<< "    \\ \\    \n\n";
}
void Juggler::drawjugman() {
	std::cout << "        /   \n"
		<< "o      o   \n"
		<< " \\         \n"
		<< "     0    o  \n "
		<< "  / # \\ /  \n"
		<< "  +  #  +   \n"
		<< "   /   \\    \n"
		<< " =       =  \n\n";
}