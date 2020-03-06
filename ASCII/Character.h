#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include <time.h>
#include <vector>
//#include "ItemManager.h"
class ItemManager;
class Enemy;

class Character {
public:
	Character();
	~Character();

	//Special 
	bool specialAttack(Enemy* enemy);
	virtual void subclassSpecial(Enemy* enemy, std::string &ability) = 0;

	//Stat change functions
	void changeMiles(int _miles);
	void increaseexp(int _experience);
	void changeattack(int _attack);
	void changedef(int _defense);
	void changespeed(int _speed);
	void takedamage(int damage);
	void increaseHealth(int num);
	void changeMaxHealth(int _maxHealth);
	virtual void levelup();
	void setWon();

	//Items
	bool items(); 
	void itemget(std::string _item);

	//Saving functions
	bool hasEnemy() { return isFighting; }
	void setFight(bool maybe);
	void saveEnemy(Enemy* enemy);

	//Status 
	void status();
	void gameover();
	void printAbilities();

	//Getters
	int gethealth() { return health; }
	int getMaxHealth() { return maxhealth; }
	int getattack() { return attack; }
	int getmagic() { return magic; }
	int getdefense() { return defense; }
	int getspeed() { return speed; }
	int getexperience() { return experience; }
	int getlevel() { return level; }
	int getMiles() { return miles; }
	Enemy* getEnemy() { return tempenemy; }
	std::string getClassName() { return className; }
	

protected:
	Enemy* tempenemy;
	ItemManager* itemManager;
	std::vector<std::string> abilities;

	std::string className;
	int health;
	int maxhealth;
	int attack;
	int magic;
	int defense;
	int speed;
	int experience;
	int level;
	int miles; 
	bool isFighting;
	bool won;

};

#endif
