#pragma once
#include "FinalBoss.h"

void FinalBoss::fightFinal(Character* user1) {
	std::cout << "Final Boss time! \n"
		<< "Michael Sonthi is a former math professor! \n"
		<< "He gives you the math problems that have been plauging the world!!! \n\n";
	drawfinalboss();
	if (math(user1))
		return;
	if (math1(user1))
		return;
	if (math2(user1))
		return;
	if (math3(user1))
		return;
	if (finalmath(user1))
		return;
	congrats();
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

bool FinalBoss::math(Character* user1) {
	int rand1, rand2, answer;
	double t = clock();
	std::cout << "You have " << user1->gethealth() << " health points left. \n";
	srand((unsigned)time(0));
	rand1 = (rand() % 10) + 1;
	rand2 = (rand() % 10) + 1;
	std::cout << "The answer to this question is: " << rand1 << " * " << rand2 << std::endl;
	std::cin >> answer;
	if (answer == rand1 * rand2) {
		std::cout << "Professor Sonthi is shocked at your intelligence. \n";
		return true;
	}
	else {
		std::cout << "Professor Sonthi has no regrets in life anymore. \n"
			<< "You take 10 damage. \n" << std::endl;
		user1->takedamage(10);
		return 1;
		if (user1->gethealth() <= 0) {
			user1->gameover();
			return false;
		}
	}

}

bool FinalBoss::math1(Character* user1) {
	int rand1, rand2, answer;
	double t = clock();
	std::cout << "You have " << user1->gethealth() << " health points left. \n";
	srand((unsigned)time(0));
	rand1 = (rand() % 15) + 5;
	rand2 = (rand() % 15) + 5;
	std::cout << "What is the answer to this question? " << rand1 << " * " << rand2 << std::endl;
	std::cin >> answer;
	if (answer == rand1 * rand2) {
		std::cout << "Professor Sonthi shakes his head vigorously! \n";
		return true;
	}
	else {
		std::cout << "Professor Sonthi congratulates you for being so dumb. \n"
			<< "You take 4 damage.\n" << std::endl;
		user1->takedamage(4);
		return true;
		if (user1->gethealth() <= 0) {
			user1->gameover();
			return false;
		}
	}
}

bool FinalBoss::math2(Character* user1) {
	int rand1, rand2, answer;
	double t = clock();
	std::cout << "You have " << user1->gethealth() << " health points left. \n";
	rand1 = (rand() % 20) + 10;
	rand2 = (rand() % 20) + 10;
	std::cout << "What is the answer to this question? " << rand1 << " * " << rand2 << std::endl;
	std::cin >> answer;
	if (answer == rand1 * rand2) {
		std::cout << "Professor Sonthi is going to quit his vacation to work on his math problems. \n";
		return true;
	}
	else {
		std::cout << "Professor Sonthi congratualates himself for making such great math problems. \n"
			<< "You take 3 damage.\n" << std::endl;
		user1->takedamage(3);
		return true;
		if (user1->gethealth() <= 0) {
			user1->gameover();
			return false;

		}
	}
}

bool FinalBoss::math3(Character* user1) {
	int rand1, rand2, answer;
	double t = clock();
	std::cout << "You have " << user1->gethealth() << " health points left. \n";
	rand1 = (rand() % 35) + 20;
	rand2 = (rand() % 35) + 20;
	std::cout << "What is the answer to this question? " << rand1 << " * " << rand2 << std::endl;
	std::cin >> answer;
	if (answer == rand1 * rand2) {
		std::cout << "Professor Sonthi is thinking about giving essay questions for his next midterm! \n";
		return true;
	}
	else {
		std::cout << "Professor Sonthi is going to ask for a raise for his exemplary work on mathematics. \n"
			<< "You take 2 damage.\n" << std::endl;
		user1->takedamage(2);
		return true;
		if (user1->gethealth() <= 0) {
			user1->gameover();
			return false;

		}
	}
}

bool FinalBoss::finalmath(Character* user1) {
	int rand1, rand2, answer;
	double t = clock();
	std::cout << "You have " << user1->gethealth() << " health points left. \n";
	rand1 = (rand() % 70) + 30;
	rand2 = (rand() % 70) + 30;
	std::cout << "What is the answer to this question? " << rand1 << " * " << rand2 << std::endl;
	std::cin >> answer;
	if (answer == rand1 * rand2) {
		std::cout << "Professor Sonthi decides to teach a different class...";
		return true;
	}
	else {
		std::cout << "Professor Sonthi thinks vididly about the youth of his day...\n"
			<< "You take 100 damage.\n";
		user1->takedamage(100);
		return true;
		if (user1->gethealth() <= 0) {
			user1->gameover();
			return false;
		}
	}
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