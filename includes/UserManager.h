#ifndef USERMANAGER_H
#define USERMANAGER_H
#pragma once
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

	//Login to account
	void login();

	//Account screen
	void loginScreen(User* user);

	//Save or Load Screen
	void restart(User* user);

	//Load Manual Save
	void loadManualSave(User* user);

	//Load Auto Save
	void loadAutoSave(User* user);

	//Create account
	void createAccount();
	
	//Delete account
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