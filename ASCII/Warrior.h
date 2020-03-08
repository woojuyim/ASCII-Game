#include "Character.h"
#include "EnemyClasses/Enemy.h"
#include "ItemManager.h"

class Warrior : public Character {
public:
	Warrior();
	Warrior(const Warrior* rhs);
	Warrior& operator=(const Warrior* rhs);

	void levelup() override;

	//Special Attacks
	void specialAttack(Enemy* enemy) ;
	void subclassSpecial(Enemy* enemy, std::string& ability);

	//Abilities
	void greentea(Enemy* enemy);

private:


};