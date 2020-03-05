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
	bool compareString(std::string& one, std::string& two);

	World *w;
	std::vector<User*> userList;
	bool program;
	

};
	
	
