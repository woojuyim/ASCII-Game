#include "ItemManager.h"
#include "Enemy.h"

class Warrior : public Character {
public:
	Warrior();
	Warrior(const Warrior* rhs);
	Warrior& operator=(const Warrior* rhs);

	//Levelup
	void levelup() override;

	//Special Attacks
	void subclassSpecial(Enemy* enemy, std::string& ability);

	//Abilities
	void greentea(Enemy* enemy);
	void guavatea(Enemy* enemy);


private:


};