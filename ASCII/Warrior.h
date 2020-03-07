#include "Character.h"
#include "EnemyClasses/Enemy.h"
#include "ItemManager.h"

class Warrior : public Character {
public:
	Warrior();
	Warrior(const Warrior* rhs);
	Warrior& operator=(const Warrior* rhs);
	void specialAttack(Enemy* enemy) ;
	void levelup() override;
	void subclassSpecial(Enemy* enemy, std::string& ability);
	void greentea(Enemy* enemy);

private:


};