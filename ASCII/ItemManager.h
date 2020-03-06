#pragma once
//#include "Character.h"
#include <vector>
#include <string>

void linebreak();
class Character;

class ItemManager {
public:
	ItemManager(Character *user1);
	void printItems();
	void getItem(std::string name);
	bool itemMenu();

	void potion();
	void megapotion();
	void lucy();
	void flyingbat();
	void guitar();

private:
	std::vector<std::string> itemlist;
	Character *user1;

};