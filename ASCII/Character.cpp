#include "Character.h"

using namespace std;

Character :: Character() {
	attack = 3;
	defense = 1;
	speed = 3;
	level = 1;
	health = 20;
	maxhealth = 20;
	experience = 0;
	itemlist.push_back("Potion");
	itemlist.push_back("Potion");
	itemlist.push_back("Mega Potion");
	itemcount = 3;
	miles = 40;
	gameStatus = true;
}
Character :: ~Character() {

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
}


void Character::items() {
	int x;
	while (true) {
		if (itemcount == 0) {
			cout << "You have no items left. \n";
			break;
		}
		cout << "The items you currently have are: \n";
		for (int i = 0; i < itemcount; i++) {
			cout << i + 1 << ". " << itemlist[i] << "   ";
		}
		cout << "\nWhich one would you like to use? Press the number to use. Press 0 to go back. \n";
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Please enter the number of the item. \n\n"
				<< "The items you currently have are: \n";
			for (int i = 0; i < itemcount; i++) {
				cout << i + 1 << ". " << itemlist[i] << "   ";
			}
			cout << "\nWhich one would you like to use? Press the number to use. Press 0 to go back. \n";
			cin >> x;
		}
		if (x == 0)
			break;
		else if (x <= itemcount) {
			cout << "You have used " << itemlist[x - 1] << "\n\n";
			if (itemlist[x - 1] == "Potion")
				potion();
			else if (itemlist[x - 1] == "Mega Potion")
				megapotion();
			else if (itemlist[x - 1] == "Lucy")
				lucy();
			else if (itemlist[x - 1] == "Flying Bat")
				flyingbat();
			else if (itemlist[x - 1] == "Guitar")
				guitar();
			for (int j = x; j < itemcount; j++) {
				itemlist[j - 1] = itemlist[j];
			}
			itemcount--;
			break;
		}
		else
			cout << "Please input a valid command. \n";
	}
}
	
void Character:: potion() {
	health += 5;
	cout << "Your health increased by 5. \n";
	if (health > maxhealth) {
		health = maxhealth;
		cout << "You are at max health! \n";
	}
}
void Character :: megapotion() {
	health += 10;
	cout << "Your health increased by 10. \n";
	if (health > maxhealth) {
		health = maxhealth;
		cout << "You are at max health! \n";
	}
}

void Character :: lucy() {
	cout << "Lucy got angry and mortally slapped you. \n"
		<< "You took 9999 damage. \n";
	health -= 9999;
}
void Character::flyingbat() {
	cout << "It flew around the area and gave you encouragement! \n";
}
void Character :: guitar() {
	srand((unsigned)time(0));
	cout << "Do you even know how to play guitar?\n";
	if (rand() % 100 < 20) {
		cout << "Somehow you played something good? \n"
			<< "Your attack and defense increased by 1. \n";
		changeattack(1);
		changedef(1);
	}
}
void Character :: itemget(string _item) {
	itemlist.push_back(_item);
	++itemcount;
}

void Character :: status() {
	cout << "Current level is " << level << endl
		<< "Max health is " << maxhealth << endl
		<< "Health remaining is " << health << endl
		<< "Attack is " << attack << endl
		<< "Defense is " << defense << endl
		<< "Speed is " << speed << endl
		<< "Experience is " << experience << endl
		<< "Need " << 10 - experience << " more for a level up. \n" << endl;
}

void Character:: gameover() {
	gameStatus = false;
	cout << "You have been defeated... \n\n";
	cout << " ________    _____      _____  ___________        ____________   _________________________   " << endl
		<< " /  _____/   /  _  \\    /     \\ \\_   _____/       \\_____  \\   \\ /   /\\_   _____/\\______   \\ " << endl
		<< "/   \\  ___  /  /_\\  \\  /  \\ /  \\ |    __)_         /   |   \\   Y   /  |    __)_  |       _/ " << endl
		<< "\\    \\_\\  \\/    |    \\/    Y    \\|        \\       /    |    \\     /   |        \\ |    |   \\ " << endl
		<< " \\______  /\\____|__  /\\____|__  /_______  /       \\_______  /\\___/   /_______  / |____|_  / " << endl
		<< "        \\/         \\/         \\/        \\/                \\/                 \\/         \\/   " << endl << endl;

}