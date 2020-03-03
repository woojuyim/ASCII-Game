#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include <time.h>
#include <vector>


class Character {
public:
	Character();
	~Character();
	int gethealth() { return health; }
	int getattack() { return attack; }
	int getdefense() { return defense; }
	int getspeed() { return speed; }
	int getexperience() { return experience; }
	int getlevel() { return level; }
	int getMiles() { return miles; }
	bool getgameStatus() { return gameStatus; }

	void gameover();
	void changeMiles(int _miles);
	void increaseexp(int _experience);
	void changeattack(int _attack);
	void changedef(int _defense);
	void levelup();
	void takedamage(int damage);
	void items();
	void potion();
	void megapotion();
	void lucy();
	void flyingbat();
	void guitar();
	void itemget(std::string _item);
	void status();
	
private:
	int health;
	int maxhealth;
	int attack;
	int defense;
	int speed;
	int experience;
	int level;
	std::vector<std::string> itemlist;
	int itemcount;
	int miles; 
	bool gameStatus;

};

#endif
