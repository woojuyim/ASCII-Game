#pragma once
#include "EnemyClasses/Enemy.h"
#include "Warrior.h"
#include "Sorcerer.h"

class User {
public:
	User(std::string name, std::string password);
	~User();
	std::string getName() { return name; }
	std::string getPassword() { return password; }
	Character* getCharacter() { return user1; }

	void createWarrior();
	void createSorcerer();
	void saveState();
	void autoSave();
	bool isManSaved() { return hasManualSave; }
	bool isAutoSaved() { return hasAutoSave; }
	Character* getManual() { return manuallySaved; }
	Character* getAuto() { return autoSaved; }
	void overwriteCharacter(bool manual);


private:
	std::string name;
	std::string password;
	Character* user1;
	Character* manuallySaved;
	Character* autoSaved;
	bool hasAutoSave;
	bool hasManualSave;
};