#pragma once
#include "../Character.h"

class Enemy {
public:
	Enemy();
	~Enemy();
	void setmonster(int _level, int _attack, int _defense, int _speed, int _health);
	virtual void draw() {}
	virtual void enemyAction(Character* user1) {}
	virtual void getStruck(Character* user1) {}
	virtual void itemChance(Character* user1) {}
	virtual void getAttacked(Character* user1);
	
	void takedamage(int damage);
	void changedef(int _defense);
	void changeattack(int _attack);
	void changespeed(int _speed);
	void enemystatus();

	std::string getName() { return name; }
	int gethealth() { return health; }
	int getattack() { return attack; }
	int getdefense() { return defense; }
	int getspeed() { return speed; }
	int getlevel() { return level; }

protected:
	int attack;
	int defense;
	int speed;
	int level;
	int health;
	std::string name;
};