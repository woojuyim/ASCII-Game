#include "Guitarist.h"

Guitarist :: Guitarist() {
	name = "Hippie Guitarist";
	level = 2;
	attack = 1;
	defense = 1;
	speed = 2;
	health = 7;
	guitar = true;
	magicdefense = 10;
}
void Guitarist::draw() {
	std::cout << "  O   \n"
		<< " /|\\  \n"
		<< " (o-\"= " << std::endl
		<< " / \\   \n\n";
}
void Guitarist::enemyAction(Character* user1) {
	std::cout << "\nIt's the Hippie Guitarist's turn. \n";
	srand((unsigned)time(0));
	if (guitar == false) {
		std::cout << "The Hippie Guitarist continued to cry. \n";
	}
	else if ((rand() % 100) < 30) {
		srand((unsigned)time(0));
		std::cout << "The Hippie Guitarist played a funky riff. \n";
		if ((rand() % 100) < 30) {
			std::cout << "You lost all your hearing. \n";
			user1->takedamage((getattack() - user1->getdefense()) * 3);
		}
		else
			std::cout << "The melody was actually not too bad??? \n";
	}
	else {
		std::cout << "The Hippie Guitarist whacked you on the head with his guitar!\n";
		user1->takedamage(getattack() - user1->getdefense());
		if ((rand() % 100) < 50) {
			guitar = false;
			std::cout << "The guitar broke. The Hippie Guitarist started sobbing due to his lack of soul. \n";
		}
	}
}
void Guitarist::getStruck(Character* user1) {
	srand((unsigned)time(0));
	std::cout << "You attempted to hit the Hippie Guitarist with his guitar! \n";
	if (guitar == false) {
		std::cout << "His guitar is broken and does no damage... \n";
	}
	else if ((rand() % 100) < 30) {
		takedamage((user1->getattack() - getdefense()) * 3);
		std::cout << "His guitar broke. The Hippie Guitarist started sobbing due to his lack of soul. \n\n";
		guitar = false;
	}
	else {
		std::cout << "The Hippie Guitarist had a firm grip on his guitar... \n\n";
	}
}
void Guitarist::itemChance(Character* user1) {
	if (guitar) {
		user1->itemget("Guitar");
		std::cout << "You found a Guitar. \n";
	}
}
