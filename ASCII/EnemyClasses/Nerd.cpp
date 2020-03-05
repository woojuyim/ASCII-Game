#include "Nerd.h"

using namespace std;
Nerd::Nerd() {
	name = "Modern Day Nerd";
	level = 1;
	attack = 0;
	defense = 0;
	speed = 100;
	health = 20;
	rage = false;
}
void Nerd::enemyAction(Character* user1) {
	std::cout << "It's the Modern Day Nerd's turn. \n";
	int _damage;
	srand((unsigned)time(0));
	if (rage) {
		std::cout << "The enraged Modern Day Nerd hits you on the head with his wood katana. \n";
		_damage = getattack() - user1->getdefense();
		if (_damage <= 0)
			_damage = 0;
		std::cout << "You took " << _damage << " damage. \n";
		user1->takedamage(_damage);
		
	}
	else {
		int j = rand() % 100;
		if (j < 50) {
			std::cout << "The Modern Day Nerd roasted you with his anime knowledge. \n"
				<< "You felt bad for the The Modern Day Nerd so you took 1 damage for him. \n";
			user1->takedamage(1);
			
		}
		else if (j > 80) {
			std::cout << "The Modern Day Nerd is thinking about what anime figures to buy next weekend. \n";
		}

		else {
			std::cout << "The Modern Day Nerd is looking up some anime images from the internet. \n";
		}
	}
}
void Nerd::getStruck(Character* user1) {
	srand((unsigned)time(0));
	std::cout << "You questioned the Modern Day Nerd's anime tastes. \n";
	int _damage = (user1->getattack() - getdefense()) * 3;
	takedamage(_damage);
	std::cout << "Your hit directly hit the heart of Modern Day Nerd! He took " << _damage << " damage \n";
}
void Nerd::itemChance(Character* user1) {
	int chance = rand() % 101;
	if (chance > 70) {
		user1->itemget("Potion");
		std::cout << "You found a Potion in his secret stash. \n";
	}
}
void Nerd::getAttacked(Character* user1) {
	std::cout << "You hit the anime bodypillow that the Modern Day Nerd was holding. \n"
		<< "The Modern Day Nerd became enraged due to the damage to his waifu. His attack rose by 10." << std::endl;
	changeattack(10);
	takedamage(user1->getattack() - getdefense());
	std::cout << "The Modern Day Nerd lost " << user1->getattack() - getdefense() << " HP. \n";
	rage = true;
}

void Nerd:: draw() {
	std::cout << "        _    \n"
		<< "   ~0  (_|   \n"
		<< "  |(_~|^~~|  \n"
		<< "  TT/_ T\"T   \n\n";
}