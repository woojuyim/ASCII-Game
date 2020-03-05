#include "Guitarist.h"

Guitarist :: Guitarist() {
	name = "Hippie Guitarist";
	level = 2;
	attack = 1;
	defense = 1;
	speed = 2;
	health = 7;
	guitar = true;
}
void Guitarist::draw() {
	std::cout << "  O   \n"
		<< " /|\\  \n"
		<< " (o-\"= " << std::endl
		<< " / \\   \n\n";
}
void Guitarist::enemyAction(Character* user1) {
	std::cout << "It's the Hippie Guitarist's turn. \n";
	srand((unsigned)time(0));
	if (guitar == false) {
		std::cout << "The Hippie Guitarist continued to cry. \n";
	}
	else if ((rand() % 100) < 30) {
		int _damage;
		srand((unsigned)time(0));
		std::cout << "The Hippie Guitarist played a funky riff. \n";
		if ((rand() % 100) < 30) {
			_damage = (getattack() - user1->getdefense()) * 3;
			if (_damage <= 0)
				_damage = 1;
			std::cout << "You lost all your hearing. You took " << _damage << " HP \n";
			user1->takedamage(_damage);

		}
		else
			std::cout << "The melody was actually not too bad??? \n";
	}
	else {
		int _damage = getattack() - user1->getdefense();
		if (_damage <= 0)
			_damage = 0;
		std::cout << "The Hippie Guitarist whacked you on the head with his guitar! You lost " << _damage << " HP \n";
		user1->takedamage(_damage);
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
		int _damage = (user1->getattack() - getdefense()) * 3;
		takedamage(_damage);
		std::cout << "The guitarist took " << _damage << " damage! His guitar broke. "
			<< "The Hippie Guitarist started sobbing due to his lack of soul. \n\n";
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
