#pragma once
#include "EnemyClasses/Enemy.h"


class User {
public:
	User(std::string name, std::string password);
	~User();
	std::string getName() { return name; }
	std::string getPassword() { return password; }
	Character *getCharacter() { return user1; }
	
	
private:
	std::string name;
	std::string password;
	Character *user1;
};