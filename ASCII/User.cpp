#include "User.h"

User::User(std::string name, std::string password) {
	this->name = name;
	this->password = password;
	autoSaved = nullptr;
	manuallySaved = nullptr;
	hasManualSave = false;
	hasAutoSave = false;
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

void User:: saveState() {
	delete manuallySaved;
	if (user1->getClassName() == "Warrior") {
		manuallySaved = new Warrior(dynamic_cast<Warrior*>(user1));
	}
	else if (user1->getClassName() == "Sorcerer") {
		manuallySaved = new Sorcerer(dynamic_cast<Sorcerer*>(user1));
	}
	hasManualSave = true;
}
void User::autoSave() {
	delete autoSaved;
	if (user1->getClassName() == "Warrior") {
		autoSaved = new Warrior(dynamic_cast<Warrior*>(user1));
	}
	else if (user1->getClassName() == "Sorcerer") {
		autoSaved = new Sorcerer(dynamic_cast<Sorcerer*>(user1));
	}
	hasAutoSave = true;
}
//Overwrite fails
void User:: overwriteCharacter(bool manual) {
	delete user1;
	if (manual) {
		if (manuallySaved->getClassName() == "Warrior") {
			user1 = new Warrior(dynamic_cast<Warrior*>(manuallySaved));
		}
		else if (manuallySaved->getClassName() == "Sorcerer") {
			user1 = new Sorcerer(dynamic_cast<Sorcerer*>(manuallySaved));
		}
	}
	else {
		if (autoSaved->getClassName() == "Warrior") {
			user1 = new Warrior(dynamic_cast<Warrior*>(autoSaved));
		}
		else if (autoSaved->getClassName() == "Sorcerer") {
			user1 = new Sorcerer(dynamic_cast<Sorcerer*>(autoSaved));
		}
	}
}

