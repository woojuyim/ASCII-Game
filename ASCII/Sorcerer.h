#include "Character.h"
#include <vector>

class Sorcerer : public Character{
public:
	Sorcerer();
	void specialAttack(Enemy* enemy) {}
	void subclassSpecial(Enemy* enemy, std::string& ability);

	void physicshw(Enemy* enemy);
	void mathAbility(Enemy* enemy);
	void levelup() override;

private:

};