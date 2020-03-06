#include "ItemManager.h"
#include "Character.h"


ItemManager::ItemManager(Character * user1) {
	this->user1 = user1;

	//Starting itemlist
	itemlist.push_back("Potion");
	itemlist.push_back("Potion");
	itemlist.push_back("Mega Potion");
}
//Prints out items
void ItemManager::printItems() {
	linebreak();
	if (itemlist.empty()) {
		std::cout << "You have no items left. \n";
		return;
	}
	std::cout << "The items you currently have are: \n";
	for (int i = 0; i < (int)itemlist.size(); ++i) {
		std::cout << i + 1 << ". " << itemlist[i] << "   ";
	}
}
//Starting item menu
bool ItemManager::itemMenu() {
	int number;
	while (true) {
		if (itemlist.empty()) {
			std::cout << "You have no items left. \n";
			break;
		}		
		printItems();
		std::cout << "\nWhich one would you like to use? Press the number to use. Press 0 to go back. \n";
		std::cin >> number;
		//Fails
		while (std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Please enter the number of the item. \n\n";
			printItems();
			std::cout << "\nWhich one would you like to use? Press the number to use. Press 0 to go back. \n";
			std::cin >> number;
		}
		if (number == 0) {
			return false;
		}
		else if (number > 0 && number <= (int)itemlist.size()) {
			number -= 1;
			std::cout << "You used the " << itemlist[number] << "\n";
			if (itemlist[number] == "Potion")
				potion();
			else if (itemlist[number] == "Mega Potion")
				megapotion();
			else if (itemlist[number] == "Lucy")
				lucy();
			else if (itemlist[number] == "Flying Bat")
				flyingbat();
			else if (itemlist[number] == "Guitar")
				guitar();
			else {
				throw std::exception("ITEM DOES NOT EXIST");
			}
			itemlist.erase(itemlist.begin() + number);
			return true;
		}
		else {
			std::cout << "Please input a valid command. \n";
		}
	}
	return false;

}
//Character gets an item
void ItemManager ::getItem(std::string name) {
	itemlist.push_back(name);
}

void ItemManager::potion() {
	user1->increaseHealth(5);
}
void ItemManager::megapotion() {
	user1->increaseHealth(10);
}
void ItemManager::lucy() {
	std::cout << "Lucy got angry and mortally slapped you. \n";
	user1->takedamage(-9999);
}
void ItemManager::flyingbat() {
	std::cout << "The bat flew around the area and gave you encouragement! \n";
}
void ItemManager::guitar() {
	srand((unsigned)time(0));
	if (rand() % 100 < 20) {
		std::cout << "Somehow you played something good? \n";
		user1->changeattack(1);
		user1->changedef(1);
	}
	else {
		std::cout << "Do you even know how to play guitar? \n";
	}
}