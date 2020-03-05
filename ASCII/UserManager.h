#pragma once
#include "User.h"
#include "World.h"
#include <vector>
#include <cctype>

class UserManager {
public:
	UserManager();
	~UserManager();
	void startMenu();
	void login();
	void createAccount();

private:
	void checkallAccounts();
	bool takenAccount(std::string& username, std::string& password);
	std::vector<User*> userList;
	bool compareString(std::string& one, std::string& two);
	bool program;
	World w;

};
	
	
