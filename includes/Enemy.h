#pragma once
#include "Character.h"
#include <chrono>
#include <thread>

void sleep();

//Abstract Enemy class
class Enemy {
public:
	Enemy();
	virtual ~Enemy();
	Enemy(const Enemy* other);
	Enemy& operator=(const Enemy* other);

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
	void changemagicdef(int _magicdef);

	//Status
	void enemystatus();

	//Testing purposes
	void setmonster(int _level, int _attack, int _defense, int _speed, int _health);

	//Getters
	std::string getName() { return name; }
	int gethealth() { return health; }
	int getattack() { return attack; }
	int getdefense() { return defense; }
	int getmagicdefense() {return magicdefense; }
	int getspeed() { return speed; }
	int getlevel() { return level; }

protected:
	std::string name;
	int attack;
	int defense;
	int magicdefense;
	int speed;
	int level;
	int health;
};