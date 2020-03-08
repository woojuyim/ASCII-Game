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

	//Start
	void startMenu();

	//Login
	void login();
	void loginScreen(User* user);

	//Save or Load Screen
	void loadingscreen(User* user);
	void restart(User* user);
	void loadManualSave(User* user);
	void loadAutoSave(User* user);



	//Account Management
	void createAccount();
	bool deleteAccount(User* user);

	//Make Character
	void makeCharacter(User* user);

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