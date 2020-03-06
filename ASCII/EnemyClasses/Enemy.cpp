#include "Enemy.h"

Enemy::Enemy() {

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
	if (damage < 0)
		damage = 0;
	std::cout << getName() + " took " << damage << " damage. \n";
	health -= damage;
}
void Enemy:: changedef(int _defense) {
	if (_defense > 0)
		std::cout << getName() << "'s defense increased by " << _defense << std::endl;
	else if (_defense < 0) 
		std::cout << getName() << "'s defense decreased by " << -_defense << std::endl;
	defense += _defense;
}
void Enemy:: changeattack(int _attack) {
	if (_attack > 0)
		std::cout << getName() << "'s attack increased by " << _attack << std::endl;
	else if (_attack < 0) 
		std::cout << getName() << "'s attack decreased by " << -_attack << std::endl;
	attack += _attack;
}
void Enemy:: changespeed(int _speed) {
	if (_speed > 0)
		std::cout << getName() << "'s speed increased by " << _speed << std::endl;
	else if (_speed < 0) 
		std::cout << getName() << "'s speed decreased by " << -_speed << std::endl;
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
}

