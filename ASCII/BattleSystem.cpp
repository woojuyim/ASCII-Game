#include "BattleSystem.h"


BattleSystem::BattleSystem(Character* user1) {
	this->user1 = user1;
	enemy = nullptr;
	battle = false;
	userTurn = true;
}
BattleSystem::~BattleSystem() {
	/*if (enemy != nullptr) {
		delete enemy;
		enemy = nullptr;
	}*/
}
void BattleSystem::run() {
	srand((unsigned)time(0));
	//User > Enemy Level
	if (user1->getlevel() > enemy->getlevel()) {
		if (rand() % 100 < 70) {
			std::cout << "You have successfully ran away. \n";
			battle = false;
		}
		else
			std::cout << "You have failed at running away. \n";
	}
	//Enemy level > User level
	else if (user1->getlevel() < enemy->getlevel()) {
		if (rand() % 100 < 30) {
			std::cout << "You have successfully ran away. \n";
			battle = false;
		}
		else
			std::cout << "You have failed at running away. \n";
	}
	//Equal Levels
	else {
		if (rand() % 100 < 50) {
			std::cout << "You have successfully ran away. \n";
			battle = false;
		}
		else
			std::cout << "You have failed at running away. \n";
	}
}

void BattleSystem::fight(Enemy * enemy, bool Saved) {
	this->enemy = enemy;
	std::string input, input2;
	srand((unsigned)time(0));
	battle = true;
	linebreak();
	std::cout << "You got into a battle!\n"
		<< "It's the " + enemy->getName() + "! \n";
	enemy->draw();
	userTurn = true;
	if(!Saved){
		std::cout << "The " + enemy->getName() + " is level " << enemy->getlevel() << std::endl
			<< "Calculating turn order... \n";
		if (calculateOrder())
			userTurn = true;
		else
			userTurn = false;
	}
	while (battle) {
		//User Turn
		while (userTurn) {
			linebreak();
			std::cout << "Your turn! What would you like to do?\n";
			std::cout << "1. Fight     2. Item     3. Status     4. Run     5. Save and Quit \n";
			std::cin >> input;
			if (input == "fight" || input == "Fight" || input == "1") {
				while (userTurn) {
					std::cout << "1. Attack     2. Strike     3. Special     4. Back\n";
					std::cin >> input2;
					if (input2 == "attack" || input2 == "Attack" || input2 == "1") {
						enemy->getAttacked(user1);
						userTurn = false;
					}
					else if (input2 == "strike" || input2 == "Strike" || input2 == "2") {
						enemy->getStruck(user1);
						userTurn = false;
					}
					else if (input2 == "special" || input2 == "Special" || input2 == "3") {
						if (user1->specialAttack(enemy)) {
							userTurn = false;
						}
					}
					else if (input2 == "back" || input2 == "Back" || input2 == "4")
						break;
					else {
						std::cout << "Please input a valid command. \n";
					}
				}
			}
			else if (input == "item" || input == "Item" || input == "2") {
				if (user1->items()) {
					userTurn = false;
				}
			}
			else if (input == "status" || input == "3" ) {
				user1->status();
			}
			else if (input == "run" || input == "Run" || input == "4") {
				run();
				userTurn = false;
			}
			//Debugging
			else if (input == "spy")
				enemy->enemystatus();
			else if (input == "save" || input == "Save" || input == "5") {
				user1->saveEnemy(enemy);
				user1->setFight(true);
				userTurn = false;
				battle = false;
			}
			else {
				std::cout << "Please input a valid command. \n";
			}
		}
		
		//If Enemy is defeated
		if (enemy->gethealth() <= 0) {
			battle = false;
			std::cout << "You have defeated the " + enemy->getName() + "! ";
			user1->setFight(false);
			gainExperience();
			enemy->itemChance(user1);
			delete enemy;
			enemy = nullptr;
			linebreak();
			break;
		}
		//Successfully ran away or saved
		if (battle == false)
			break;
		linebreak();
		enemy->enemyAction(user1);
		userTurn = true;

		if (user1->gethealth() <= 0) {
			delete enemy;
			enemy = nullptr;
			battle = false;
		}
	}
}

bool BattleSystem::calculateOrder() {

	//User is faster
	if (user1->getspeed() > enemy->getspeed())
		return true;
	//Enemy is faster
	else if (user1->getspeed() < enemy->getspeed())
		return false;		
	//Same Speed
	else {
		//Random
		if ((rand() % 2) == 0)
			return true;
		else
			return false;
	}
}

void BattleSystem::gainExperience() {
	int leveldiff = user1->getlevel() - enemy->getlevel();
	if (abs(leveldiff) <= 2) {
		int _experience = rand() % (leveldiff + 9) + 1;
		user1->increaseexp(_experience);
	}
	else if (leveldiff >= 3) {
		int _experience = (rand() % 9) + 1;
		user1->increaseexp(_experience);
	}
	else if (leveldiff <= -3) {
		int _experience = rand() % abs((leveldiff * 2) + 1);
		user1->increaseexp(_experience);
	}
	//Levelup
	if (user1->getexperience() >= 10) {
		linebreak();
		user1->levelup();
	}
}