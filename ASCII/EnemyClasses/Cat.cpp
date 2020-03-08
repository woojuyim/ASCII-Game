#include "Cat.h"

Cat::Cat() {
	name = "Black Cat of Death";
	level = 1;
	// 4 - 6
	attack = rand() % 3 + 4;
	// 1 - 4
	defense = rand() % 4 + 1;
	// 0 - 9
	speed = rand() % 10;
	// 9 - 11
	health = rand() % 3 + 9;
	// 1 - 4
	magicdefense = rand() % 3 + 1;
}
void Cat::enemyAction(Character* user1) {
	std::cout << "It's the Black Cat of Death's turn. \n";
	sleep();
	srand((unsigned)time(0));
	if ((rand() % 100) < 30) {
		if ((rand() % 100) < 30) {
			std::cout << "The Black Cat of Death scratched your face! \n";
			user1->takedamage((getattack() - user1->getdefense()) * 3);
		}
		else
			std::cout << "The Black Cat of Death was overcome with tiredness to move. \n";
	}
	else {
		std::cout << "The Black Cat of Death used its powers of die! \n";
		user1->takedamage(getattack() - user1->getdefense());

	}
}
void Cat::getStruck(Character* user1) {
	srand((unsigned)time(0));
	std::cout << "You attempted to beat the Black Cat of Death! \n";
	sleep();
	if ((rand() % 100) < 30) {
		std::cout << "You directly hit the Black Cat of Death! It whimpered and meowed softly... \n";
		takedamage((user1->getattack() - getdefense()) * 3);
	}
	else {
		std::cout << "The cat nimbly dodged the attack... \n";
	}
}
void Cat::itemChance(Character* user1) {
	int chance = rand() % 101;
	if (chance > 80) {
		user1->itemget("Potion");
		std::cout << "You found a Potion. \n";
	}
	else if (chance < 5) {
		user1->itemget("Mega Potion");
		std::cout << "You found a Mega Potion. \n";
	}
}

void Cat::draw() {
	int prob = rand() % 100;
	if (prob < 55)
		drawcat();
	else
		drawcat1();
}
void Cat::drawcat1() {
	std::cout << "   (""`-''-/"").___..--''""`-._ " << std::endl
		<< "   `6_ 6  )   `-.  (     ).`-.__.`) " << std::endl
		<< "  (_Y_.)'  ._   )  `._ `. ``-..-' " << std::endl
		<< "   _..`--'_..-_/  /--'_. ' ,' " << std::endl
		<< "  (  ),-''  (  ),'   ((.-'	 " << std::endl << std::endl;
}

void Cat::drawcat(){
	std::cout << "          (`.          " << std::endl
		<< "           ) )        " << std::endl
		<< "	  ( ( "			<< std::endl
		<< "	   \\ \\ "			<< std::endl
		<< "	    \\ \\ "		<< std::endl
		<< "	  .-'  `-. "		<< std::endl
		<< "	 /        `. "			<< std::endl
		<< "	(      )    `-._ ,    _" << std::endl
		<< "	 )   ,'         (.\\--'( " << std::endl
		<< "	 \\  (         ) /      \\ " << std::endl
		<< "	  \\  \\_(     / (    <6 (6 " << std::endl
		<< "	   \\_)))\\   (   `._  .:Y)__ " << std::endl
		<< "	    '''  \\   `-._.'`---^_))) " << std::endl
		<< "	          `-._ )))       ``` " << std::endl
		<< "	               ```           " << std::endl << std::endl;
}