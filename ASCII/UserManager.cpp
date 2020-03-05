#include "UserManager.h"

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

//Starting screen
void UserManager::startMenu() {
	while (program) {
		std::cout << "Welcome to the ASCII game! \n";
		std::cout << "1. Create an Account. \n"
			<< "2. Login. \n"
			<< "3. Quit \n"
			<< "4. Show all Accounts made. \n"
			<< "Press 1, 2, or 3. \n";
		std::string choice;
		std::cin >> choice;
		if (choice == "1") {
			createAccount();
		}
		else if (choice == "2") {
			login();
		}
		else if (choice == "3") {
			program = false;
		}
		//Debugging
		else if (choice == "4") {
			checkallAccounts();
		}
		else {
			std::cout << "Please input a valid number. \n";
		}
	}

}
		
//Create an account
void UserManager::createAccount() {
	std::string username, password;
	std::cout << "Create an Account! \n"
		<< "Please enter a username. \n";
	std::cin >> username;
	std::cout << "Please enter a password. \n";
	std::cin >> password;
	if (!takenAccount(username, password)) {
		User* newUser = new User(username, password);
		userList.push_back(newUser);
	}
}

//Login to existing account
void UserManager::login() {
	std::string username, password;
	std::cout << "Login! \n"
		<< "Please enter your username. \n";
	std::cin >> username;
	std::cout << "Please enter your password. \n";
	std::cin >> password;
	std::string name, pass;
	User* u = nullptr;
	for (auto user : userList) {
		name = user->getName();
		pass = user->getPassword();
		if (compareString(name, username) && compareString(pass, password)) {
			u = user;
			break;
		}
	}
	if (u != nullptr) {
		w->gameMenu(u->getCharacter());
	}
	else {
		std::cout << "There is no account with that username and password. \n";
	}


}
//Check if account is taken
bool UserManager::takenAccount(std::string &username, std::string &password) {
	std::string name, pass;
	for (auto user : userList) {
		name = user->getName();
		pass = user->getPassword();
		if (compareString(name, username) || compareString(pass, password)){
			std::cout << "There is an account with that username or password already. \n";
			return true;
		}
	}
	return false;
}

//Show all accounts made
void UserManager::checkallAccounts() {
	for (auto account : userList) {
		std::cout << "Name: " << account->getName() << " Password: " << account->getPassword() << std::endl;
	}
}

//Compare string function
bool UserManager :: compareString(std::string& one, std::string& two){
	return ((one.size() == two.size()) && std::equal(one.begin(), one.end(), two.begin(), [](char& a, char& b) {
		return std::tolower(a) == std::tolower(b);
	}));
}