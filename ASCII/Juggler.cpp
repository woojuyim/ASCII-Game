#include "Juggler.h"

using namespace std;
Juggler::Juggler() {
	level = 1;
	attack = rand() % 3 + 1;
	defense = 1;
	speed = rand() % 4;
	health = rand() % 2 + 3;
}
void Juggler::drawjugman1() {
	cout << "    o  \n"
		<< "       o   \n"
		<< "  o O    \n"
		<< " `\\/Y\\/~  \n"
		<< "___/_\\____  \n" << endl;
}
void Juggler::drawjugman2() {
	cout << "     o     \n"
		<< "        o   \n"
		<< "  o  O      \n"
		<< "  `--| \\o  \n"
		<< "    /<'      \n"
		<< "    \\ \\    \n\n";
}
void Juggler::drawjugman() {
	cout << "        /   \n"
		<< "o      o   \n"
		<< " \\         \n"
		<< "     0    o  \n "
		<< "  / # \\ /  \n"
		<< "  +  #  +   \n"
		<< "   /   \\    \n"
		<< " =       =  \n\n";
}