#include "Cat.h"

using namespace std;
Cat::Cat() {
	level = 2;
	attack = rand() % 2 + 1;
	defense = rand() % 2;
	speed = rand() % 4;
	health = rand() % 3 + 4;
}

void Cat::drawcat1() {
	cout << "   (""`-''-/"").___..--''""`-._ " << endl
		<< "   `6_ 6  )   `-.  (     ).`-.__.`) " << endl
		<< "  (_Y_.)'  ._   )  `._ `. ``-..-' " << endl
		<< "   _..`--'_..-_/  /--'_. ' ,' " << endl
		<< "  (  ),-''  (  ),'   ((.-'	 " << endl << endl;
}

void Cat::drawcat(){
	cout << "          (`.          " << endl
		<< "           ) )        " << endl
		<< "	  ( ( "			<< endl
		<< "	   \\ \\ "			<< endl
		<< "	    \\ \\ "		<< endl
		<< "	  .-'  `-. "		<< endl
		<< "	 /        `. "			<< endl
		<< "	(      )    `-._ ,    _" << endl
		<< "	 )   ,'         (.\\--'( " << endl
		<< "	 \\  (         ) /      \\ " << endl
		<< "	  \\  \\_(     / (    <6 (6 " << endl
		<< "	   \\_)))\   (   `._  .:Y)__ " << endl
		<< "	    '''  \\   `-._.'`---^_))) " << endl
		<< "	          `-._ )))       ``` " << endl
		<< "	               ```           " << endl << endl;
}