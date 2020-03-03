#include "Enemy.h"

using namespace std;

void Enemy :: setmonster(int _level, int _attack, int _defense, int _speed, int _health) {
	level = _level;
	attack = _attack;
	defense = _defense;
	speed = _speed;
	health = _health;
}
void Enemy:: takedamage(int damage) {
	health -= damage;
}
void Enemy:: changedef(int _defense) {
	defense += _defense;
}
void Enemy:: changeattack(int _attack) {
	attack += _attack;
}
void Enemy:: changespeed(int _speed) {
	speed += _speed;
}
void Enemy:: enemystatus() {
	cout << "Current level is " << level << endl
		<< "Health remaining is " << health << endl
		<< "Attack is " << attack << endl
		<< "Defense is " << defense << endl
		<< "Speed is " << speed << endl << endl;
}


