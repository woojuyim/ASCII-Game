#include "Guitarist.h"

using namespace std;

Guitarist :: Guitarist() {
	level = 2;
	attack = 1;
	defense = 1;
	speed = 2;
	health = 7;
}

void Guitarist:: drawguitar() {
	cout << "  O   \n"
		<< " /|\\  \n"
		<< " (o-\"= " << endl
		<< " / \\   \n\n";
}