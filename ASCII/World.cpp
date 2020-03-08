#pragma once
#include "World.h"
#include <chrono>
#include <thread>
World::World() {

}
//Move forward in the world
void World::forward(Character* user1, User* user) {
	BattleSystem system(user1);
	srand((unsigned int)time(0));
	//Has more miles, doesn't have an enemy saved, and has more than 0 health
	while (user1->getMiles() > 0 && !(user1->hasEnemy()) && user1->gethealth() > 0) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		user1->changeMiles(-1);
		std::cout << user1->getMiles() << " miles left. \n";
		if (user1->getMiles() % 10 == 0) {
			user->autoSave();
		}
		int prob = rand() % 100;

		//20% enemy encounter 
		if (prob % 100 < 20) {
			int prob2 = rand() % 100;
			if (prob2 <= 20) {
				Cat* cat = new Cat();
				system.fight(cat, false);
				break;
			}
			else if (prob2 > 20 && prob2 <= 30) {
				Lucy *lucy = new Lucy();
				system.fight(lucy, false);
				break;
			}
			else if (prob2 > 30 && prob2 <= 45) {
				Turtle* turtle = new Turtle();
				system.fight(turtle, false);
				break;
			}
			else if (prob2 > 45 && prob2 <= 60) {
				Juggler* juggler = new Juggler();
				system.fight(juggler, false);
				break;
			}
			else if (prob2 > 60 && prob2 <= 85) {
				Guitarist *guitarist = new Guitarist();
				system.fight(guitarist, false);
				break;
			}
			else {
				Nerd* nerd = new Nerd();
				system.fight(nerd, false);
				break;
			}
		}

		//5% Item encounter
		else if (prob % 10 > 94) {
			int prob2 = rand() % 10;
			if (prob2 == 0 ) {
				linebreak();
				std::cout << "You found a half opened Mega Potion! Hopefully, it's safe. \n";
				user1->itemget("Mega Potion");
			}
			else if(prob2 == 1){
				linebreak();
				std::cout << "You found a trashed guitar? You look cool now holding trash! \n";
				user1->itemget("Guitar");
			}
			else{
				linebreak();
				std::cout << "You found a potion! Maybe someone threw out one after having 999 of them. \n";
				user1->itemget("Potion");
			}
			
		}
		//10% Random Encounters ? 
		/*else if (prob % 100 > 80 && prob % 100 <= 90) {

		}*/
	}
}

//Starting game menu
void World::gameMenu(Character* user1, User* user) {
	std::string x;
	bool quit = false;
	linebreak();
	std::cout << "Soham Sonthi has been committing unthinkable crimes against humanity! \n";
	sleep();
	std::cout << "It is your job to stop him! You need to travel " << user1->getMiles() << " miles to get to him. \n";
	sleep();
	if (user1->hasEnemy()) {
		std::cout << "You were in the middle of a fight! \n";
		BattleSystem system(user1);
		system.fight(user1->getEnemy(), true);
	}

	while (user1->getMiles() > 0 && !(user1->hasEnemy())) {
		if (user1->gethealth() <= 0) {
			user1->gameover();
			return;
		}
		std::cout << "You have " << user1->getMiles() << " miles left, \n"
			<< "1. Forward     2. Item     3. Status     4. Save     9. Final Boss     0. Quit \n";
		std::cin >> x;
		if (x == "1" || x == "forward") {
			forward(user1, user);
		}
		else if (x == "2" || x == "item" || x == "Item") {
			user1->items();
		}
		else if (x == "3" || x == "Status" || x == "status") {
			user1->status();
		}
		else if (x == "4") {
			user->saveState();
		}
		else if (x == "9" || x == "skip") {
			break;
		}
		else if (x == "0") {
			quit = true;
			break;
		}
		else
			std::cout << "Please input a valid command. \n";
	}
	if (!(user1->hasEnemy()) && !quit) {
		FinalBoss fb(user1);
		fb.fightFinal();
	}
	
}
