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

	//Stat change functions
	void changeMiles(int _miles);
	void increaseexp(int _experience);
	void changeattack(int _attack);
	void changedef(int _defense);
	void takedamage(int damage);
	void increaseHealth(int num);
	void levelup();

	//Items
	void items(); 
	void itemget(std::string _item);

	//Saving functions
	bool hasEnemy() { return isFighting; }
	void setFight(bool maybe);
	void saveEnemy(Enemy* enemy);

	//Status 
	void status();
	void gameover();

	//Getters
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
	Enemy* tempenemy;
	ItemManager* itemManager;
	int health;
	int maxhealth;
	int attack;
	int defense;
	int speed;
	int experience;
	int level;
	int miles; 
	bool isFighting;

};

#endif
