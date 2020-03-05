#include "Turtle.h"

Turtle::Turtle() {
	name = "Crazy Turtle";
	level = 2;
	attack = rand() % 1 + 1;
	defense = rand() % 2 + 2;
	speed = 10;
	health = rand() % 4 + 4;
}

void Turtle::enemyAction(Character* user1) {
	std::cout << "It's the Crazy Turtle's turn. \n";
	if ((rand() % 100) < 30) {
		int _damage;
		srand((unsigned)time(0));
		if ((rand() % 100) < 40) {
			_damage = (getattack() - user1->getdefense()) * 3;
			if (_damage <= 0)
				_damage = 0;
			std::cout << "The Crazy Turtle jumped 10 meters in the air and flattened you! You lost " << _damage << " HP \n\n";
			user1->takedamage(_damage);
		}
		else {
			std::cout << "The turtle slowly moved towards you...\n\n";
			changeattack(1);
		}
	}

	else {
		int _damage = getattack() - user1->getdefense();
		if (_damage <= 0)
			_damage = 0;
		std::cout << "The Crazy Turtle drove at super speed and rammed in you! You lost " << _damage << " HP \n";
		user1->takedamage(_damage);
			
	}
}


void Turtle::getStruck(Character* user1) {
	std::cout << "You attempted to break open the turtle's shell with your hand! \n";
	if ((rand() % 100) < 70) {
		int _damage = (user1->getattack() - getdefense()) * 3;
		takedamage(_damage);
		changedef(-2);
		std::cout << "You chopped open the turtle's shell! The enemy took " << _damage << " damage. The turtle's defense decreased by 2. \n";
	}
	else {
		std::cout << "Your hand wasn't strong enough...You took one damage... \n";
		user1->takedamage(1);
	}
}
void Turtle::itemChance(Character* user1) {
	if (rand() % 100 > 95) {
		user1->itemget("Mega Potion");
		std::cout << "You found a Mega Potion. \n";
	}
}

void Turtle::draw() {
	int prob = rand() % 100;
	if (prob < 60)
		drawturtle();
	else if (prob > 70)
		drawturtle1();
	else
		drawturtle2();
}

void Turtle::drawturtle() {
	std::cout << "                             __-------___                        " << std::endl
		<< "                         -~~               ~~-                   " << std::endl
		<< "                      -~                    /~-_                  " << std::endl
		<< "   /^\\__/^\\          /  \\                  /     \\               " << std::endl
		<< " /|  O|| O|        /      \\_______________/        \\              " << std::endl
		<< "| |___||__|      /       /               \\          \\            " << std::endl
		<< "|          \\   /      /                   \\          \\          " << std::endl
		<< "|   (_______) /______/                       \\_________ \\         " << std::endl
		<< "|         / /        \\                       /            \\       " << std::endl
		<< " \\         \\^\\\\        \\                   /               \\    //" << std::endl
		<< "  \\         ||           \\______________ /      _-_       //\\__//  " << std::endl
		<< "   \\       ||------_-~~-_ ------------- \\ --/~   ~\\    || __/    " << std::endl
		<< "    \\  ~-----||====/~    |==================|       |/~~~~~      " << std::endl
		<< "       (_(__/  ./      /                     \\_\\      \\.          " << std::endl
		<< "                (_(___/                         \\_____)_)         " << std::endl << std::endl;
}
void Turtle::drawturtle1() {
	std::cout << "               __" << std::endl
		<< "    .,-;-;-,. /'_\\ " << std::endl
		<< "  _/_/_/_|_\\_\\ ) /" << std::endl
		<< "'-<_><_><_><_>=/\\ " << std::endl
		<< "` /_/====/_/-' \\_\\ " << std::endl
		<< "  ''     ''    ''" << std::endl << std::endl;

}
void Turtle::drawturtle2() {
	std::cout << "   _____   ____\n"
		<< " /       | |  o | \n"
		<< "|        |/ ___\\| \n"
		<< "|_________/       \n"
		<< "|_|_| |_|_| \n" << std::endl << std::endl;
}