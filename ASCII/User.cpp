#include "User.h"

User::User(std::string name, std::string password) {
	this->name = name;
	this->password = password;
}

User::~User() {
	delete user1;
	user1 = nullptr;
}

void User::createWarrior() {
	user1 = new Warrior();
}
void User::createSorcerer() {
	user1 = new Sorcerer();
}
