#pragma once
#include "Math.h"
#include "Combat.h"
using namespace std;

void drawfinalboss() {
	cout << "		 ________________________________ \n"
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

int math(Character& user1) {
	int rand1, rand2, answer;
	double t = clock();
	cout << "You have " << user1.gethealth() << " health points left. \n";
	srand((unsigned)time(0));
	rand1 = (rand() % 10) + 1;
	rand2 = (rand() % 10) + 1;
	cout << "The answer to this question is: " << rand1 << " * " << rand2 << endl;
	cin >> answer;
	if (answer == rand1 * rand2) {
		cout << "Professor Lacey is shocked at your intelligence. \n";
		return 1;
	}
	else {
		cout << "Professor Lacey has no regrets in life anymore. \n"
			<< "You take 10 damage. \n" << endl;
		user1.takedamage(10);
		return 1;
		if (user1.gethealth() <= 0) {
			user1.gameover();
			return 0;
		}
	}

}

int math1(Character& user1) {
	int rand1, rand2, answer;
	double t = clock();
	cout << "You have " << user1.gethealth() << " health points left. \n";
	srand((unsigned)time(0));
	rand1 = (rand() % 15) + 5;
	rand2 = (rand() % 15) + 5;
	cout << "What is the answer to this question? " << rand1 << " * " << rand2 << endl;
	cin >> answer;
	if (answer == rand1 * rand2) {
		cout << "Professor Lacey shakes his head vigorously! \n";
		return 1;
	}
	else {
		cout << "Professor Lacey congratulates you for being so dumb. \n"
			<< "You take 4 damage.\n" << endl;
		user1.takedamage(4);
		return 1;
		if (user1.gethealth() <= 0) {
			user1.gameover();
			return 0;
		}
	}
}

int math2(Character& user1) {
	int rand1, rand2, answer;
	double t = clock();
	cout << "You have " << user1.gethealth() << " health points left. \n";
	srand((unsigned)time(0));
	rand1 = (rand() % 20) + 10;
	rand2 = (rand() % 20) + 10;
	cout << "What is the answer to this question? " << rand1 << " * " << rand2 << endl;
	cin >> answer;
	if (answer == rand1 * rand2) {
		cout << "Professor Lacey is going to quit his vacation to work on his math problems. \n";
		return 1;
	}
	else {
		cout << "Professor Lacey congratualates himself for making such great math problems. \n"
			<< "You take 3 damage.\n" << endl;
		user1.takedamage(3);
		return 1;
		if (user1.gethealth() <= 0) {
			user1.gameover();
			return 0;

		}
	}
}

int math3(Character& user1) {
	int rand1, rand2, answer;
	double t = clock();
	cout << "You have " << user1.gethealth() << " health points left. \n";
	srand((unsigned)time(0));
	rand1 = (rand() % 35) + 20;
	rand2 = (rand() % 35) + 20;
	cout << "What is the answer to this question? " << rand1 << " * " << rand2 << endl;
	cin >> answer;
	if (answer == rand1 * rand2) {
		cout << "Professor Lacey is thinking about giving essay questions for his next midterm! \n";
		return 1;
	}
	else {
		cout << "Professor Lacey is going to ask for a raise for his exemplary work on mathematics. \n"
			<< "You take 2 damage.\n" << endl;
		user1.takedamage(2);
		return 1;
		if (user1.gethealth() <= 0) {
			user1.gameover();
			return 0;

		}
	}
}

int finalmath(Character& user1) {
	int rand1, rand2, answer;
	double t = clock();
	cout << "You have " << user1.gethealth() << " health points left. \n";
	srand((unsigned)time(0));
	rand1 = (rand() % 70) + 30;
	rand2 = (rand() % 70) + 30;
	cout << "What is the answer to this question? " << rand1 << " * " << rand2 << endl;
	cin >> answer;
	if (answer == rand1 * rand2) {
		cout << "Professor Lacey decides to teach a different class...";
		return 1;
	}
	else {
		cout << "Professor Lacey thinks vididly about the youth of his day...\n"
			<< "You take 100 damage.\n";
		user1.takedamage(100);
		return 1;
		if (user1.gethealth() <= 0) {
			user1.gameover();
			return 0;
		}
	}
}

void congrats() {
	cout << "Congratulations!!! You have defeated Professor Lacey and put an end to his evil crimes. " << endl
		<< "                                                                       ,d  " << endl
		<< "								       88  " << endl
		<< " ,adPPYba,  ,adPPYba,  8b,dPPYba,   ,adPPYb,d8 8b,dPPYba, ,adPPYYba, MM88MMM    ,adPPYba, " << endl
		<< "a8\"     \"\" a8\"     \"8a 88P'   `\"8a a8\"    `Y88 88P'   \"Y8 \"\"     `Y8   88       I8[\"\" " << endl
		<< "8b         8b       d8 88       88 8b       88 88         ,adPPPPP88   88       `\"Y8ba, " << endl
		<< "\"8a,   ,aa \"8a,   ,a8\" 88       88 \"8a,   ,d88 88         88,    ,88   88,      aa    ]8I " << endl
		<< " `\"Ybbd8\"'  `\"YbbdP\"'  88       88  `\"YbbdP\"Y8 88         `\"8bbdP\"Y8   \"Y888    `\"YbbdP\"'  " << endl
		<< "                                    aa,    ,88" << endl
		<< "			  	     \"Y8bbdP\" " << endl;

}