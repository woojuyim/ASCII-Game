#include "UserManager.h"
#include <algorithm>
#include <cctype>

UserManager::UserManager() {
	program = true;
	w = new World();

}
UserManager::~UserManager() {
	for (auto user : userList) {
		delete user;
		user = nullptr;
	}
	userList.clear();
	delete w;
}

void UserManager:: printStart() {
	linebreak();
	std::cout << "Welcome to the ASCII game! Press the number! \n";
	std::cout << "1. Create an Account.     "
		<< "2. Login.     "
		<< "3. Show all Accounts made.     "
		<< "0. Quit     \n";
}
//Starting screen
void UserManager::startMenu() {
	int choice;
	while (program) {
		printStart();
		std::cin >> choice;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Please input a valid number. \n";
			printStart();
			std::cin >> choice;
		}
		switch(choice){
			case 1:
				createAccount();
				break;
			case 2:
				login();
				break;
			//Debugging
			case 3:
				checkallAccounts();
				break;
			case 0:
				program = false;
				break;
			default:
				std::cout << "Please input a valid number. \n";
				break;
		}
	}
}
		
//Create an account
void UserManager::createAccount() {
	std::string username, password;
	linebreak();
	std::cout << "Create an Account! \n"
		<< "Please enter a username: ";
	std::cin >> username;
	std::cout << "Please enter a password: ";
	std::cin >> password;
	//Account successful
	if (!takenAccount(username, password)) {
		User* newUser = new User(username, password);
		std::string input;	
		linebreak();
		std::cout << "Character Customization! \n";
		makeCharacter(newUser);
		userList.push_back(newUser);
	}
	else {
		std::cout << "There is an account with that username or password already. \n";
	}
}

void UserManager::loginScreen(User* user) {
	std::string input;
	while (true) {
		linebreak();
		std::cout << "What would you like to do? Press the number. \n"
			<< "1. Play ASCII     2. Check status of characters     3. Delete Account     4. Log out \n";
		std::cin >> input;
		if (input == "1" || input == "play") {
			//If Gameover or cleared
			if (user->getCharacter()->gethealth() <= 0 || user->getCharacter()->getMiles() == 0) {
				std::cout << "Would you like to start over? Type yes: ";
				std::cin >> input;
				if (input == "yes") {
					delete user->getCharacter();
					makeCharacter(user);
					w->gameMenu(user->getCharacter());
				}
				else {
					std::cout << "I guess not playing the game isn't that bad... maybe? \n";
				}
			}
			else {
				w->gameMenu(user->getCharacter());
			}
		}
		else if (input == "2") {
			user->getCharacter()->status();
		}
		else if (input == "3" || input == "delete") {
			if (deleteAccount(user)) {
				break;
			}
		}
		else if (input == "4") {
			break;
		}
		else {
			std::cout << "Please select a valid input. \n";
		}
	}
}
//Login to existing account
void UserManager::login() {
	std::string username, password;
	linebreak();
	std::cout << "Login! \n"
		<< "Please enter your username: ";
	std::cin >> username;
	std::cout << "Please enter your password: ";
	std::cin >> password;
	User* u = accountExists(username, password);
	if (u != nullptr) {
		std::cout << "Login successful. \n ";
		loginScreen(u);
	}
	else {
		std::cout << "There is no account with that username and password. \n";
	}
}
//Create character
void UserManager::makeCharacter(User* user) {
	std::string input;
	while (true) {
		std::cout << "Which character class do you want to select? Press the number. \n"
			<< "1. Warrior     "
			<< "2. Sorcerer \n";
		std::cin >> input;
		if (input == "1") {
			user->createWarrior();
			std::cout << "Account successfully made! \n";
			break;
		}
		else if (input == "2") {
			user->createSorcerer();
			std::cout << "Account successfully made! \n";
			break;
		}
		else {
			std::cout << "Select a valid number. \n";
		}
	}

}
bool UserManager::deleteAccount(User *user) {
	if (user != nullptr) {
		std::cout << "Are you really going to delete this account? Type yes to continue: ";
		std::string ask;
		std::cin >> ask;
		if (ask == "yes") {
			std::cout << "Delete successful. \n";
			userList.erase(std::remove(userList.begin(), userList.end(), user), userList.end());
			delete user;
			return true;
		}
		else {
			std::cout << "I knew you wouldn't ^*^ \n";
		}
	}
	else {
		throw std::exception("ACCOUNT FAILURE");
	}
	return false;
}

//Check if username or password is taken
bool UserManager::takenAccount(std::string &username, std::string &password) {
	std::string name, pass;
	for (auto user : userList) {
		name = user->getName();
		pass = user->getPassword();
		if (compareString(name, username)){
			return true;
		}
	}
	return false;
}

//Check if account exists
User* UserManager::accountExists(std::string& username, std::string& password) {
	std::string name, pass;
	for (auto user : userList) {
		name = user->getName();
		pass = user->getPassword();
		if (compareString(name, username) && compareString(pass, password)) {
			return user;
		}
	}
	return nullptr;
}

//Show all accounts made
void UserManager::checkallAccounts() {
	linebreak();
	if (userList.empty()) {
		std::cout << "There are no accounts made. \n";
		return;
	}
	std::cout << "ACCOUNTS: \n";
	for (auto account : userList) {
		std::cout << "Name: " << account->getName() << "     Password: " << account->getPassword()
			<< "     Class: " << account->getCharacter()->getClassName() << std::endl;
	}
}

//Compare string function
bool UserManager :: compareString(std::string &one, std::string& two){
	return ((one.size() == two.size()) && std::equal(one.begin(), one.end(), two.begin(), [](char& a, char& b) {
		return std::tolower(a) == std::tolower(b);
	}));
}