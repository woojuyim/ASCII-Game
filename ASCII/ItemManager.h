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

	int getItemSize() { return (int)itemlist.size(); }
	std::vector<std::string> getitemList() { return itemlist; }

	void potion();
	void megapotion();
	void lucy();
	void flyingbat();
	void guitar();

private:
	std::vector<std::string> itemlist;
	Character *user1;

};