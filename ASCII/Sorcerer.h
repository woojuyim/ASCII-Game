#include "Character.h"
#include "ItemManager.h"
#include <vector>

class Sorcerer : public Character{
public:
	Sorcerer();
	Sorcerer(const Sorcerer* rhs);
	Sorcerer& operator=(const Sorcerer* rhs);
	void specialAttack(Enemy* enemy) {}
	void subclassSpecial(Enemy* enemy, std::string& ability);

	void physicshw(Enemy* enemy);
	void mathAbility(Enemy* enemy);
	void levelup() override;

private:

};