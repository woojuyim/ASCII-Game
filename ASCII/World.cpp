#pragma once
#include "World.h"

World::World() {
	finalboss = false;
}
//Move forward in the world
void World::forward(Character* user1) {
	BattleSystem system(user1);
	srand((unsigned int)time(0));
	//Has more miles, doesn't have an enemy saved, and has more than 0 health
	while (user1->getMiles() > 0 && !(user1->hasEnemy()) && user1->gethealth() > 0) {
		user1->changeMiles(-1);
		std::cout << user1->getMiles() << " miles left. \n";
		int prob = rand() % 100;
		//30% enemy encounter 
		if ((rand() % 10) < 3) {
			if (prob <= 15) {
				Cat* cat = new Cat();
				system.fight(cat, false);
			}
			else if (prob > 15 && prob <= 25) {
				Lucy *lucy = new Lucy();
				system.fight(lucy, false);
				
			}
			else if (prob > 25 && prob <= 40) {
				Turtle* turtle = new Turtle();
				system.fight(turtle, false);

			}
			else if (prob > 40 && prob < 60) {
				Juggler* juggler = new Juggler();
				system.fight(juggler, false);

			}
			else if (prob > 60 && prob < 80) {
				Guitarist *guitarist = new Guitarist();
				system.fight(guitarist, false);
			}
			else {
				Nerd* nerd = new Nerd();
				system.fight(nerd, false);
			}
		}
	}
}

//Starting game menu
void World::gameMenu(Character* user1) {
	std::string x;
	std::cout << "\nSoham Sonthi has been committing unthinkable crimes against humanity! "
		<< "It is your job to stop him! You need to travel " << user1->getMiles() << " miles to get to him. \n";
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
			<< "Press 1 to go forward, 2 to open item menu, 3 to open status menu. "
			<< "Press 9 to skip to final boss. \n";
		std::cin >> x;
		if (x == "1" || x == "forward") {
			forward(user1);
		}
		else if (x == "2" || x == "item" || x == "Item") {
			user1->items();
		}
		else if (x == "3" || x == "Status" || x == "status") {
			user1->status();
		}
		//Switch accounts
		else if (x == "4") {

		}
		else if (x == "9" || x == "skip") {
			break;
		}
		else
			std::cout << "Please input a valid command. \n";
	}
	if (!(user1->hasEnemy())) {
		FinalBoss fb;
		fb.fightFinal(user1);
	}
	
}
