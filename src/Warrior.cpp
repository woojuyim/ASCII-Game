#include "Warrior.h"

Warrior::Warrior() {
	attack = 6;
	magic = 2;
	defense = 2;
	speed = 4;
	health = 22;
	className = "Warrior";
	abilities.push_back("Green Tea");
}
Warrior::Warrior(const Warrior* rhs) {
	attack = rhs->attack;
	magic = rhs->magic;
	defense = rhs->defense;
	speed = rhs->speed;
	health = rhs->health;
	level = rhs->level;
	maxhealth = rhs->maxhealth;
	experience = rhs->experience;
	itemManager = new ItemManager(this);
	for (int i = 0; i < rhs->itemManager->getItemSize(); ++i) {
		itemManager->getitemList().push_back(rhs->itemManager->getitemList()[i]);
	}
	for (int i = 0; i < rhs->abilities.size(); ++i) {
		abilities.push_back(rhs->abilities[i]);
	}
	miles = rhs->miles;
	isFighting = rhs->isFighting;
	won = rhs->won;
	className = rhs->className;
	tempenemy = nullptr;
}
Warrior& Warrior ::operator= (const Warrior* rhs) {
	if (this != rhs) {
		attack = rhs->attack;
		magic = rhs->magic;
		defense = rhs->defense;
		speed = rhs->speed;
		health = rhs->health;
		level = rhs->level;
		maxhealth = rhs->maxhealth;
		experience = rhs->experience;
		itemManager = new ItemManager(this);
		for (int i = 0; i < rhs->itemManager->getItemSize(); ++i) {
			itemManager->getitemList()[i] = rhs->itemManager->getitemList()[i];
		}
		for (int i = 0; i < rhs->abilities.size(); ++i) {
			abilities.push_back(rhs->abilities[i]);
		}
		miles = rhs->miles;
		isFighting = rhs->isFighting;
		won = rhs->won;
		className = rhs->className;
		tempenemy = nullptr;
	}
	return *this;
}


void Warrior::subclassSpecial(Enemy* enemy, std::string& ability) {
	std::cout << "You used " << ability << "\n";
	sleep();
	if (ability == "Green Tea") {
		greentea(enemy);
	}
	else if (ability == "Guava Tea") {
		guavatea(enemy);
	}
	else {
		throw std::exception("ITEM DOES NOT EXIST");
	}
}

void Warrior::greentea(Enemy* enemy) {
	std::cout << "You threw Green Tea at the " + enemy->getName() << std::endl;
	sleep();
	std::cout << "It only caused some first degree burns... \n";
	enemy->takedamage(1);
}
void Warrior::guavatea(Enemy* enemy) {
	std::cout << "You threw Guava Tea at the " + enemy->getName() << std::endl;
	sleep();
	std::cout << "It was better than the Green Tea, but not by much... \n";
	sleep();
	std::cout << "It only caused some second degree burns... \n";
	enemy->takedamage(2);

}
void Warrior::levelup() {
	std::cout << "\nYou gained a level up! \n";
	srand((unsigned)time(0));
	int c = rand() % 2 + 2;
	experience -= 10;
	changeattack(rand() % 3 + 1);
	changemagic(1);
	changedef(rand() % 2);
	changespeed(rand() % 2);
	changeMaxHealth(c);
	health = maxhealth;
	++level;
	if (level == 2) {
		std::cout << "You learned Guava Tea! \n";
		abilities.push_back("Guava Tea");
	}
}