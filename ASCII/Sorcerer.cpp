#include "Sorcerer.h"
#include "EnemyClasses/Enemy.h"

Sorcerer::Sorcerer() {
	attack = 2;
	magic = 3;
	defense = 2;
	speed = 4;
	health = 23;
	className = "Sorcerer";
	abilities.push_back("Physics Homework");
}

void Sorcerer::subclassSpecial(Enemy* enemy, std::string& ability) {
	std::cout << "You used " << ability << "\n";
	if (ability == "Physics Homework") {
		physicshw(enemy);
	}
	else if (ability == "Math") {
		mathAbility(enemy);
	}
	else {
		throw std::exception("ITEM DOES NOT EXIST");
	}
}
void Sorcerer::physicshw(Enemy* enemy) {
	std::cout << "You threw your physics homework at the " + enemy->getName() << std::endl
		<< "Hundreds of papers hit " + enemy->getName() + " on the head. \n";
	int damage = (getmagic() - enemy->getmagicdefense()) * 2;
	enemy->takedamage(damage);
}


void Sorcerer::mathAbility(Enemy* enemy) {
	std::cout << "You showed the " + enemy->getName() + " how to solve 1 + 1! \n"
		<< "The " + enemy->getName() + " was enlightened! \n";
	int damage = (getmagic() - enemy->getmagicdefense()) * 3;
	enemy->takedamage(damage);
}

void Sorcerer::levelup() {
	srand((unsigned)time(0));
	int c = rand() % 2 + 1;
	experience -= 10;
	attack += 1;
	magic += rand() % 2 + 1;
	defense += rand() % 2;
	speed += rand() % 2;
	health += c;
	maxhealth += c;
	++level;
	if (level == 2) {
		std::cout << "You learned Math! \n";
		abilities.push_back("Math");
	}
}