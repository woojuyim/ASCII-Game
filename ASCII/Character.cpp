#include "Character.h"
#include "ItemManager.h"
#include "EnemyClasses/Enemy.h"

Character :: Character() {
	attack = 3;
	defense = 1;
	speed = 3;
	level = 1;
	health = 20;
	maxhealth = 20;
	experience = 0;
	itemManager = new ItemManager(this);
	miles = 40;
}
Character :: ~Character() {
	delete itemManager;
	itemManager = nullptr;
}
void Character::changeMiles(int _miles) {
	miles += _miles;
}
void Character :: increaseexp(int _experience) {
	experience += _experience;
}
void Character ::changeattack(int _attack) {
	attack += _attack;
}
void Character::changedef(int _defense) {
	defense += _defense;
}
void Character::levelup() {
	srand((unsigned)time(0));
	int c = rand() % 4 + 1;
	experience -= 10;
	attack += rand() % 3;
	defense += rand() % 3;
	speed += rand() % 3;
	health += c;
	maxhealth += c;
	level++;
}
void Character::takedamage(int damage) {
	health -= damage;
	if (gethealth() > 0)
		std::cout << "You have " << gethealth() << " HP left. \n\n";
}
void Character::increaseHealth(int num) {
	health += num;
	if (health > maxhealth) {
		health = maxhealth;
		std::cout << "You are at max health! \n";
	}
}
void Character::items() {
	itemManager->itemMenu();
}

void Character :: itemget(std::string _item) {
	itemManager->getItem(_item);
}
void Character::setFight(bool maybe) {
	fight = maybe;
}
void Character::saveEnemy(Enemy* enemy) {
	tempenemy = enemy;
	setFight(true);
}


void Character :: status() {
	std::cout << "Current level is " << level << std::endl
		<< "Max health is " << maxhealth << std::endl
		<< "Health remaining is " << health << std::endl
		<< "Attack is " << attack << std::endl
		<< "Defense is " << defense << std::endl
		<< "Speed is " << speed << std::endl
		<< "Experience is " << experience << std::endl
		<< "Need " << 10 - experience << " more for a level up. \n" << std::endl;
}

void Character:: gameover() {
	std::cout << "You have been defeated... \n\n";
	std::cout << " ________    _____      _____  ___________        ____________   _________________________   " << std::endl
		<< " /  _____/   /  _  \\    /     \\ \\_   _____/       \\_____  \\   \\ /   /\\_   _____/\\______   \\ " << std::endl
		<< "/   \\  ___  /  /_\\  \\  /  \\ /  \\ |    __)_         /   |   \\   Y   /  |    __)_  |       _/ " << std::endl
		<< "\\    \\_\\  \\/    |    \\/    Y    \\|        \\       /    |    \\     /   |        \\ |    |   \\ " << std::endl
		<< " \\______  /\\____|__  /\\____|__  /_______  /       \\_______  /\\___/   /_______  / |____|_  / " << std::endl
		<< "        \\/         \\/         \\/        \\/                \\/                 \\/         \\/   " << std::endl << std::endl;

}