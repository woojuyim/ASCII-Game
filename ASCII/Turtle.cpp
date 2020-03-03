#include "Turtle.h"

using namespace std;
Turtle::Turtle() {
	name = "Turtle";
	level = 2;
	attack = rand() % 1 + 1;
	defense = rand() % 2 + 2;
	speed = 10;
	health = rand() % 4 + 4;
}
void Turtle::battle(Character &user1) {

}

void Turtle::draw() {
	srand((unsigned)time(0));
	int prob = rand() % 100;
	if (prob < 60)
		drawturtle();
	else if (prob > 70)
		drawturtle1();
	else
		drawturtle2();
}

void Turtle::drawturtle() {
	cout << "                             __-------___                        " << endl
		<< "                         -~~               ~~-                   " << endl
		<< "                      -~                    /~-_                  " << endl
		<< "   /^\\__/^\\          /  \\                  /     \\               " << endl
		<< " /|  O|| O|        /      \\_______________/        \\              " << endl
		<< "| |___||__|      /       /               \\          \\            " << endl
		<< "|          \\   /      /                   \\          \\          " << endl
		<< "|   (_______) /______/                       \\_________ \\         " << endl
		<< "|         / /        \\                       /            \\       " << endl
		<< " \\         \\^\\\\        \\                   /               \\    //" << endl
		<< "  \\         ||           \\______________ /      _-_       //\\__//  " << endl
		<< "   \\       ||------_-~~-_ ------------- \\ --/~   ~\\    || __/    " << endl
		<< "    \\  ~-----||====/~    |==================|       |/~~~~~      " << endl
		<< "       (_(__/  ./      /                     \\_\\      \\.          " << endl
		<< "                (_(___/                         \\_____)_)         " << endl << endl;
}
void Turtle::drawturtle1() {
	cout << "               __" << endl
		<< "    .,-;-;-,. /'_\\ " << endl
		<< "  _/_/_/_|_\_\\ ) /" << endl
		<< "'-<_><_><_><_>=/\\ " << endl
		<< "` /_/====/_/-' \\_\\ " << endl
		<< "  ''     ''    ''" << endl << endl;

}
void Turtle::drawturtle2() {
	cout << "   _____   ____\n"
		<< " /       | |  o | \n"
		<< "|        |/ ___\\| \n"
		<< "|_________/       \n"
		<< "|_|_| |_|_| \n" << endl << endl;
}