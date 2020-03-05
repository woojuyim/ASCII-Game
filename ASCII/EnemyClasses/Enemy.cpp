#include "Enemy.h"

Enemy::Enemy() {
	name = "Enemy";
	level = 1;
	attack = 1;
	defense = 1;
	speed = 1;
	health = 1;
}
Enemy::~Enemy() {
	
}
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
	std::cout << "Current level is " << level << std::endl
		<< "Health remaining is " << health << std::endl
		<< "Attack is " << attack << std::endl
		<< "Defense is " << defense << std::endl
		<< "Speed is " << speed << std::endl << std::endl;
}

void Enemy:: getAttacked(Character* user1) {
	std::cout << "You attacked the " + getName() << std::endl;
	takedamage(user1->getattack() - getdefense());
	std::cout << "The " + getName() + " lost " << user1->getattack() - getdefense() << " HP. \n" << std::endl;
}

