#include "Character.h"
#include "EnemyClasses/Enemy.h"

class Warrior : public Character {
public:
	Warrior();
	void specialAttack(Enemy* enemy) ;
	void levelup() override;
	void subclassSpecial(Enemy* enemy, std::string& ability);
	void greentea(Enemy* enemy);

private:


};