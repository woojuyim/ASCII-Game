#pragma once
//#include "Character.h"
#include <vector>
#include <string>

class Character;

class ItemManager {
public:
	ItemManager(Character *user1);
	void printItems();
	void getItem(std::string name);
	void itemMenu();

	void potion();
	void megapotion();
	void lucy();
	void flyingbat();
	void guitar();

private:
	std::vector<std::string> itemlist;
	Character *user1;

};