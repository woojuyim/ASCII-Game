#include "pch.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <sstream>
#include "Character.h"
#include "Combat.h"
#include "Math.h"
using namespace std;

int main(){
	Character user1;
	string x;
	cout << "Michael Lacey has been committing unthinkable crimes against humanity! It is your job to stop him! \n"
		<< "You need to travel " << user1.getMiles() << " miles to get to him. \n";
	while (user1.getMiles() > 0) {
		if (user1.getgameStatus() == false)
			return 0;
		if (user1.gethealth() <= 0) {
			user1.gameover();
			return 0;
		}
		cout << "You have " << user1.getMiles() << " miles left, \n"
			<< "Press 1 to go forward, 2 to open item menu, 3 to open status menu. Press 9 to skip to final boss." << endl;
		cin >> x;
		if (x == "1" || x == "forward") {
			forward(user1);
		}
		else if (x == "2" || x == "item" || x == "Item") {
			user1.items();
		}
		else if (x == "3" || x == "Status" || x == "status") {
			user1.status();
		}
		else if (x == "9" || x == "skip") {
			break;
		}
		else
			cout << "Please input a valid command. \n";
	}
	cout << "Final Boss time! \n"
		<< "Michael Lacey is a former math professor! \n"
		<< "He gives you the math problems that have been plauging the world!!! \n\n";
	drawfinalboss();
	if (math(user1) == 0)
		return 0;
	if (math1(user1) == 0)
		return 0;
	if (math2(user1) == 0)
		return 0;
	if (math3(user1) == 0)
		return 0;
	if (finalmath(user1) == 0)
		return 0;
	else {
		congrats();
	}
	return 0;
}

