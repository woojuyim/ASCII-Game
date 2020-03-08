#pragma once
#include "FinalBoss.h"
#include <chrono>
using namespace std::chrono;

FinalBoss::FinalBoss(Character * user1) {
	goodresponses = { "Professor Sonthi is shocked at your intelligence.\n",
		"Professor Sonthi shakes his head vigorously! \n",
		"Professor Sonthi is going to quit his vacation to work on his math problems. \n",
		"Professor Sonthi is thinking about giving essay questions for his next midterm! \n",
		"Professor Sonthi believes that math is not his path and decides to teach English. \n" };

	badresponses = { "Professor Sonthi has made the hypothesis that you are quite stupid. \n",
		"Professor Sonthi congratulates you for being so dumb. \n",
		"Professor Sonthi congratualates himself for making such great math problems. \n",
		"Professor Sonthi is going to ask for a raise for his exemplary work on mathematics. \n",
		"Professor Sonthi thinks vididly about the youth of his day...\n" };

	damageArray = { 10, 5, 4, 3, 100 };
	this->user1 = user1;
}

void FinalBoss::fightFinal() {
	linebreak();
	std::cout << "Final Boss time! \n";
	sleep();
	std::cout << "Michael Sonthi is a former math professor! \n";
	sleep();
	std::cout << "He gives you the math problems that have been plauging the world!!! \n\n";
	sleep();
	drawfinalboss();
	//Passed
	if (math()) {
		congrats();
		user1->setWon();
	}
}

void FinalBoss::drawfinalboss() {
	std::cout << "		 ________________________________ \n"
		<< "		|.==============================,| \n"
		<< "		||                              || \n"
		<< "		||    .----.    ,               || \n"
		<< "		||   / ><   \\  /                || \n"
		<< "		||  |        |/\\                || \n"
		<< "		||   \\______//\\/                || \n"
		<< "		||   _(____)/ /                 || \n"
		<< "		||__/ ,_ _  _/__________________|| \n"
		<< "		'===\\___\\_) |====================' \n"
		<< "		     |______| \n"
		<< "		     |  ||  | \n"
		<< "		     |__||__| \n"
		<< "		     (__)(__) \n\n";
}

bool FinalBoss::math() {
	int turns = 0;
	int rand1, rand2, answer;
	while (turns < 5) {
		sleep();
		std::cout << "You have " << user1->gethealth() << " health points left. \n";
		srand((unsigned)time(0));
		switch (turns) {
			case 0:
				rand1 = (rand() % 10) + 1;
				rand2 = (rand() % 10) + 1;
				break;
			case 1:
				rand1 = (rand() % 15) + 5;
				rand2 = (rand() % 15) + 5;
				break;
			case 2:
				rand1 = (rand() % 20) + 10;
				rand2 = (rand() % 20) + 10;
				break;
			case 3:
				rand1 = (rand() % 35) + 20;
				rand2 = (rand() % 35) + 20;
				break;
			case 4:
				rand1 = (rand() % 70) + 30;
				rand2 = (rand() % 70) + 30;
				break;
		}
		auto start = high_resolution_clock::now();
		std::cout << "The answer to this question is: " << rand1 << " * " << rand2 << std::endl
			<< "There is a 5 second time limit... \n";
		std::cin >> answer;
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<seconds>(end - start);
		if (std::cin.fail() || answer != rand1 * rand2 || duration >= seconds(5)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			sleep();
			std::cout << badresponses[turns];
			user1->takedamage(damageArray[turns]);
			if (user1->gethealth() <= 0) {
				user1->gameover();
				return false;
			}
		}
		else if (answer == rand1 * rand2) {
			sleep();
			std::cout << goodresponses[turns];
		}
		++turns;
		linebreak();
		
	}
	return true;
}


void FinalBoss::congrats() {
	std::cout << "Congratulations!!! You have defeated Professor Sonthi and put an end to his evil crimes. " << std::endl
		<< "                                                                       ,d  " << std::endl
		<< "								       88  " << std::endl
		<< " ,adPPYba,  ,adPPYba,  8b,dPPYba,   ,adPPYb,d8 8b,dPPYba, ,adPPYYba, MM88MMM    ,adPPYba, " << std::endl
		<< "a8\"     \"\" a8\"     \"8a 88P'   `\"8a a8\"    `Y88 88P'   \"Y8 \"\"     `Y8   88       I8[\"\" " << std::endl
		<< "8b         8b       d8 88       88 8b       88 88         ,adPPPPP88   88       `\"Y8ba, " << std::endl
		<< "\"8a,   ,aa \"8a,   ,a8\" 88       88 \"8a,   ,d88 88         88,    ,88   88,      aa    ]8I " << std::endl
		<< " `\"Ybbd8\"'  `\"YbbdP\"'  88       88  `\"YbbdP\"Y8 88         `\"8bbdP\"Y8   \"Y888    `\"YbbdP\"'  " << std::endl
		<< "                                    aa,    ,88" << std::endl
		<< "			  	     \"Y8bbdP\" " << std::endl;

}