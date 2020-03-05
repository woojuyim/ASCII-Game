#pragma once
#include "../Character.h"

//Abstract Enemy class
class Enemy {
public:
	Enemy();
	virtual ~Enemy() {}

	//Main attack functions and defense functions
	virtual void draw() = 0;
	virtual void enemyAction(Character* user1) = 0;
	virtual void getStruck(Character* user1) = 0;
	virtual void itemChance(Character* user1) = 0;
	virtual void getAttacked(Character* user1);
	
	//Change stats
	void takedamage(int damage);
	void changedef(int _defense);
	void changeattack(int _attack);
	void changespeed(int _speed);
	void enemystatus();

	//Testing purposes
	void setmonster(int _level, int _attack, int _defense, int _speed, int _health);

	//Getters
	std::string getName() { return name; }
	int gethealth() { return health; }
	int getattack() { return attack; }
	int getdefense() { return defense; }
	int getspeed() { return speed; }
	int getlevel() { return level; }

protected:
	std::string name;
	int attack;
	int defense;
	int speed;
	int level;
	int health;
};