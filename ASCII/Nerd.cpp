#include "Nerd.h"

using namespace std;
Nerd::Nerd() {
	level = 1;
	attack = 0;
	defense = 0;
	speed = 100;
	health = 20;
}


void Nerd:: drawnerd() {
	cout << "        _    \n"
		<< "   ~0  (_|   \n"
		<< "  |(_~|^~~|  \n"
		<< "  TT/_ T\"T   \n\n";
}