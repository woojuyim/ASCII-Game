#include "Lucy.h"

using namespace std;
Lucy::Lucy() {
	level = 4;
	attack = rand() % 5 + 1;
	defense = rand() % 2;
	speed = 10;
	health = rand() % 4 + 6;
}

void Lucy::drawlucy() {
	cout << "    ,-,  " << endl
		<< "   (('')) " << endl
		<< "  __/  \\__ " << endl
		<< "   /____\\ " << endl
		<< "    _| \\_" << endl << endl;
}