#pragma once
//#include "Character.h"
#include <vector>
#include <string>

void linebreak();
class Character;

class ItemManager {
public:
	ItemManager(Character *user1);
	
	//Item menus
	bool itemMenu();
	void printItems();
	void getItem(std::string name);

	//Getters
	int getItemSize() { return (int)itemlist.size(); }
	std::vector<std::string> getitemList() { return itemlist; }

	//Items
	void potion();
	void megapotion();
	void lucy();
	void flyingbat();
	void guitar();

private:
	std::vector<std::string> itemlist;
	Character *user1;

};