#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include <time.h>
//#include "ItemManager.h"
class ItemManager;
class Enemy;

class Character {
public:
	Character();
	~Character();

	void gameover();
	void changeMiles(int _miles);
	void increaseexp(int _experience);
	void changeattack(int _attack);
	void changedef(int _defense);
	void levelup();
	void takedamage(int damage);
	void increaseHealth(int num);
	void items(); 
	
	bool isFighting() { return fight; }
	void setFight(bool maybe);

	void itemget(std::string _item);
	void status();
	void saveEnemy(Enemy* enemy);

	int gethealth() { return health; }
	int getMaxHealth() { return maxhealth; }
	int getattack() { return attack; }
	int getdefense() { return defense; }
	int getspeed() { return speed; }
	int getexperience() { return experience; }
	int getlevel() { return level; }
	int getMiles() { return miles; }
	Enemy* getEnemy() { return tempenemy; }

private:
	int health;
	int maxhealth;
	int attack;
	int defense;
	int speed;
	int experience;
	int level;
	ItemManager *itemManager;
	int miles; 
	bool fight;
	Enemy* tempenemy;

};

#endif
