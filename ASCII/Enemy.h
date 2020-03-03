#pragma once
#include "Character.h"
#include <iostream>
class Enemy {
private:
protected:
	int attack;
	int defense;
	int speed;
	int level;
	int health;
	std::string name;

public:
	virtual void battle(Character& user1) {}
	void setmonster(int _level, int _attack, int _defense, int _speed, int _health);
	virtual void draw() {}
	bool calculateOrder(Character& user1, Enemy& enemy);

	std::string getName() { return name; }
	int gethealth() { return health; }
	int getattack() { return attack; }
	int getdefense() { return defense; }
	int getspeed() { return speed; }
	int getlevel() { return level; }
	void takedamage(int damage);
	void changedef(int _defense);
	void changeattack(int _attack);
	void changespeed(int _speed);
	void enemystatus();
};