#include "Linebreak.h"
#include "Character.h"
#include "ItemManager.h"
#include "EnemyClasses/Enemy.h"


Character :: Character() {
	attack = 1;
	magic = 1;
	defense = 1;
	speed = 1; 
	health = 20;
	level = 1;
	maxhealth = 20;
	experience = 0;
	itemManager = new ItemManager(this);
	miles = 40;
	tempenemy = nullptr;
	isFighting = false;
	won = false;
	className = "ERROR";
}
Character :: ~Character() {
	delete itemManager;
	itemManager = nullptr;
}
void Character::setWon() {
	won = true;
}
void Character::changeMiles(int _miles) {
	miles += _miles;
}
void Character :: increaseexp(int _experience) {
	std::cout << "You gained " << _experience << " experience points. \n";
	experience += _experience;
}
void Character ::changeattack(int _attack) {
	if (_attack > 0)
		std::cout << "Attack increased by " << _attack << std::endl;
	else if (_attack < 0) {
		std::cout << "Attack decreased by " << -_attack << std::endl;
	}
	attack += _attack;
}
void Character::changemagic(int _magic) {
	if (_magic > 0)
		std::cout << "Magic increased by " << _magic << std::endl;
	else if (_magic < 0) {
		std::cout << "Magic decreased by " << -_magic << std::endl;
	}
	magic += _magic;
}
void Character::changedef(int _defense) {
	if (_defense > 0)
		std::cout << "Defense increased by " << _defense << std::endl;
	else if (_defense < 0)
		std::cout << "Defense decreased by " << -_defense << std::endl;
	defense += _defense;
}
void Character::changespeed(int _speed) {
	if (_speed > 0)
		std::cout << "Speed increased by " << _speed << std::endl;
	else if (_speed < 0) {
		std::cout << "Speed decreased by " << -_speed << std::endl;
	}
	speed += _speed;
}
void Character::levelup() {
	std::cout << "You gained a level up! \n";
	srand((unsigned)time(0));
	int c = rand() % 4 + 1;
	experience -= 10;
	changeattack(rand() % 3);
	changemagic(2);
	changedef(rand() % 3);
	changespeed(rand() % 3);
	changeMaxHealth(c);
	increaseHealth(c);
	++level;
}
void Character::takedamage(int damage) {
	if (damage < 0)
		damage = 0;
	std::cout << "You took " << damage << " damage. ";
	health -= damage;
	if (gethealth() > 0)
		std::cout << "You have " << gethealth() << " HP left. \n";
	else
		health = 0;
}
void Character::increaseHealth(int num) {
	std::cout << "Health increased by " << num << std::endl;
	health += num;
	if (health > maxhealth) {
		health = maxhealth;
		std::cout << "You are at max health! \n";
	}
}
void Character::changeMaxHealth(int _maxhealth) {
	if (_maxhealth > 0)
		std::cout << "Max Health increased by " << _maxhealth << std::endl;
	else if (_maxhealth < 0) {
		std::cout << "Max Health decreased by " << -_maxhealth << std::endl;
	}
	maxhealth += _maxhealth;
}
bool Character::items() {
	return itemManager->itemMenu();
}

void Character :: itemget(std::string _item) {
	itemManager->getItem(_item);
}
void Character::setFight(bool maybe) {
	isFighting = maybe;
}
void Character::saveEnemy(Enemy* enemy) {
	tempenemy = enemy;
	setFight(true);
}
void Character::printAbilities() {
	for (size_t i = 0; i < abilities.size(); ++i) {
		std::cout << (i + 1) << ". " << abilities[i] << std::endl;
	}
}

bool Character::specialAttack(Enemy* enemy) {
	while (true) {
		linebreak();
		std::cout << "Select an ability. Press the number to use. Press 0 to go back. \n";
		printAbilities();
		int input;
		std::cin >> input;
		//Fails
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Please enter the number of the ability. \n\n";
			printAbilities();
			std::cout << "\nWhich one would you like to use? Press the number to use. Press 0 to go back. \n";
			std::cin >> input;
		}
		if (input == 0)
			return false;
		else if (input > 0 && input <= (int)abilities.size()) {
			input -= 1;
			subclassSpecial(enemy, abilities[input]);
			return true;
		}
		else {
			std::cout << "Please input a valid command. \n";
		}
	}
}

void Character :: status() {
	linebreak();
	std::cout << "Class: " << className << std::endl
		<< "Current level: " << level << std::endl
		<< "Max health: " << maxhealth << std::endl
		<< "Health remaining: " << health << std::endl
		<< "Attack: " << attack << std::endl
		<< "Magic: " << magic << std::endl
		<< "Defense: " << defense << std::endl
		<< "Speed: " << speed << std::endl
		<< "Experience: " << experience << std::endl
		<< "Need " << 10 - experience << " more for a level up. \n"
		<< "Miles left: " << miles << std::endl;

	if (isFighting && tempenemy!=nullptr) {
		std::cout << "Currently in the middle of fighting " << tempenemy->getName() << std::endl;
	}
	if (health == 0)
		std::cout << "THIS CHARACTER HAS UNFORTUNATELY EXPERIENCED MATH AND DIED. \n";
	else if (won) {
		std::cout << "THIS CHARACTER HAS BEATEN PROFESSOR SONTHI. \n";
	}
	
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