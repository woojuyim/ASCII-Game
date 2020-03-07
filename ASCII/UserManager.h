#pragma once
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "World.h"
#include <vector>

void linebreak();

class UserManager {
public:
	UserManager();
	~UserManager();
	void startMenu();
	void login();
	void loginScreen(User* user);
	void createAccount();
	bool deleteAccount(User* user);
	void makeCharacter(User* user);
	void loadingscreen(User* user);

private:
	void printStart();
	User* accountExists(std::string& username, std::string& password);
	void checkallAccounts();
	bool takenAccount(std::string& username, std::string& password);
	bool compareString(std::string& one, std::string& two);

	World *w;
	std::vector<User*> userList;
	bool program;
};
	
	
#endif