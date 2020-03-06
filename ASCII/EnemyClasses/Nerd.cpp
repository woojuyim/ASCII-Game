#include "Nerd.h"

using namespace std;
Nerd::Nerd() {
	name = "Modern Day Nerd";
	level = 1;
	attack = 0;
	defense = 0;
	speed = 100;
	health = 20;
	magicdefense = 5;
	rage = false;
}
void Nerd::enemyAction(Character* user1) {
	std::cout << "\nIt's the The Modern Day Nerd's turn. \n";
	srand((unsigned)time(0));
	if (rage) {
		std::cout << "The enraged Modern Day Nerd hits you on the head with his wood katana. \n";
		user1->takedamage(getattack() - user1->getdefense());
		
	}
	else {
		int j = rand() % 100;
		if (j < 50) {
			std::cout << "The Modern Day Nerd roasted you with his anime knowledge. \n"
				<< "You felt bad for the The Modern Day Nerd... so you decided to take some damage. \n";
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
	std::cout << "You questioned the Modern Day Nerd's anime tastes. \n"
		"Your hit directly hit the heart of Modern Day Nerd! \n";
	takedamage((user1->getattack() - getdefense()) * 3);
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
		<< "The Modern Day Nerd became enraged due to the damage to his waifu. " << std::endl;
	changeattack(10);
	takedamage(user1->getattack() - getdefense());
	rage = true;
}

void Nerd:: draw() {
	std::cout << "        _    \n"
		<< "   ~0  (_|   \n"
		<< "  |(_~|^~~|  \n"
		<< "  TT/_ T\"T   \n\n";
}