#include "Enemy.h"

Enemy::Enemy() {
	attack = 1;
	defense = 1;
	speed = 1;
	magicdefense = 1;
	health = 1;
	level = 1;
}
Enemy::~Enemy() {
	
}
Enemy::Enemy(const Enemy* other) {
	name = other->name;
	attack = other->attack;
	defense = other->defense;
	magicdefense = other->magicdefense;
	speed = other->speed;
	level = other->level;
	health = other->health;
}
Enemy& Enemy:: operator=(const Enemy* other) {
	if (this != other) {
		name = other->name;
		attack = other->attack;
		defense = other->defense;
		magicdefense = other->magicdefense;
		speed = other->speed;
		level = other->level;
		health = other->health;
	}
	return *this;
}
void Enemy :: setmonster(int _level, int _attack, int _defense, int _speed, int _health) {
	level = _level;
	attack = _attack;
	defense = _defense;
	speed = _speed;
	health = _health;
}
void Enemy:: takedamage(int damage) {
	sleep();
	if (damage < 0)
		damage = 0;
	std::cout << getName() + " took " << damage << " damage. \n";
	health -= damage;
}
void Enemy:: changedef(int _defense) {
	sleep();
	if (_defense > 0)
		std::cout << getName() << "'s defense increased by " << _defense << std::endl;
	else if (_defense < 0) 
		std::cout << getName() << "'s defense decreased by " << -_defense << std::endl;
	defense += _defense;
}
void Enemy:: changeattack(int _attack) {
	sleep();
	if (_attack > 0)
		std::cout << getName() << "'s attack increased by " << _attack << std::endl;
	else if (_attack < 0) 
		std::cout << getName() << "'s attack decreased by " << -_attack << std::endl;
	attack += _attack;
}
void Enemy:: changespeed(int _speed) {
	sleep();
	if (_speed > 0)
		std::cout << getName() << "'s speed increased by " << _speed << std::endl;
	else if (_speed < 0) 
		std::cout << getName() << "'s speed decreased by " << -_speed << std::endl;
	speed += _speed;
}
void Enemy::changemagicdef(int _magicdef) {
	sleep();
	if (_magicdef > 0)
		std::cout << getName() << "'s magic defense increased by " << _magicdef << std::endl;
	else if (_magicdef < 0)
		std::cout << getName() << "'s magic defense decreased by " << -_magicdef << std::endl;
	magicdefense += _magicdef;
}

void Enemy:: enemystatus() {
	std::cout << "Current level is " << level << std::endl
		<< "Health remaining is " << health << std::endl
		<< "Attack is " << attack << std::endl
		<< "Defense is " << defense << std::endl
		<< "Speed is " << speed << std::endl << std::endl;
}

void Enemy:: getAttacked(Character* user1) {
	sleep();
	std::cout << "You attacked the " + getName() << std::endl;
	takedamage(user1->getattack() - getdefense());
}

