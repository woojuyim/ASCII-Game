#pragma once
#include "Enemy.h"
#include "Warrior.h"
#include "Sorcerer.h"

class User {
public:
	User(std::string name, std::string password);
	~User();
	
	//Create Characters
	void createWarrior();
	void createSorcerer();

	//Create manual savestate
	void saveState();
	//Create auto savestate
	void autoSave();
	//Overwrite savestate with current save
	void overwriteCharacter(bool manual);

	//Getters
	std::string getName() { return name; }
	std::string getPassword() { return password; }
	Character* getCharacter() { return user1; }
	bool isManSaved() { return hasManualSave; }
	bool isAutoSaved() { return hasAutoSave; }
	Character* getManual() { return manuallySaved; }
	Character* getAuto() { return autoSaved; }

private:
	std::string name;
	std::string password;
	Character* user1;
	Character* manuallySaved;
	Character* autoSaved;
	bool hasAutoSave;
	bool hasManualSave;
};