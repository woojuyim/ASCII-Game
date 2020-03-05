#include "User.h"

User::User(std::string name, std::string password) {
	this->name = name;
	this->password = password;
	user1 = new Character();
}

User::~User() {
	delete user1;
	user1 = nullptr;
}


