#include "ItemManager.h"
#include "Enemy.h"

class Sorcerer : public Character{
public:
	Sorcerer();
	Sorcerer(const Sorcerer* rhs);
	Sorcerer& operator=(const Sorcerer* rhs);

	//Levelup
	void levelup() override;

	//Special Attacks
	void subclassSpecial(Enemy* enemy, std::string& ability);

	//Abilities
	void physicshw(Enemy* enemy);
	void mathAbility(Enemy* enemy);

private:

};