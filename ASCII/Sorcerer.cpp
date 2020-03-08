#include "Sorcerer.h"
#include "EnemyClasses/Enemy.h"


Sorcerer::Sorcerer() {
	attack = 5;
	magic = 4;
	defense = 2;
	speed = 6;
	health = 24;
	className = "Sorcerer";
	abilities.push_back("Physics Homework");
}
Sorcerer::Sorcerer(const Sorcerer* rhs) {
	attack = rhs-> attack;
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
Sorcerer& Sorcerer ::operator= (const Sorcerer* rhs) {
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

void Sorcerer::subclassSpecial(Enemy* enemy, std::string& ability) {
	std::cout << "You used " << ability << "\n";
	sleep();
	if (ability == "Physics Homework") {
		physicshw(enemy);
	}
	else if (ability == "Math") {
		mathAbility(enemy);
	}
	else {
		throw std::exception("ITEM DOES NOT EXIST");
	}
}
void Sorcerer::physicshw(Enemy* enemy) {
	std::cout << "You threw your physics homework at the " + enemy->getName() << std::endl;
	sleep();
	std::cout << "Hundreds of papers hit " + enemy->getName() + " on the head. \n";
	int damage = (getmagic() - enemy->getmagicdefense()) * 2;
	enemy->takedamage(damage);
}


void Sorcerer::mathAbility(Enemy* enemy) {
	std::cout << "You showed the " + enemy->getName() + " how to solve 1 + 1! \n";
	sleep();
	std::cout << "The " + enemy->getName() + " was enlightened! \n";
	int damage = (getmagic() - enemy->getmagicdefense()) * 3;
	enemy->takedamage(damage);
}

void Sorcerer::levelup() {
	std::cout << "\nYou gained a level up! \n";
	srand((unsigned)time(0));
	int c = rand() % 3 + 1;
	experience -= 10;
	changeattack(rand() % 3);
	changemagic(rand() % 2 + 1);
	changedef(rand() % 2);
	changespeed(rand() % 3);
	changeMaxHealth(c);
	health = maxhealth;
	++level;
	if (level == 2) {
		std::cout << "You learned Math! \n";
		abilities.push_back("Math");
	}
}