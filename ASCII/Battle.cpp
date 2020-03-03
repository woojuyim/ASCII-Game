#include "Battle.h"

using namespace std;

BattleSystem::BattleSystem(Enemy& m, Character& user1) {
	this->m = m;
	this->user1 = user1;
	srand((unsigned)time(0));
}

void BattleSystem::attack() {
	//m.attack();
}

void BattleSystem::strike() {
	//m.strike();
}

void BattleSystem::run() {
	if (user1.getlevel() > m.getlevel()) {//enemy level)
		if (rand() % 100 < 90) {
			cout << "You have successfully ran away. \n\n";
			battle = false;
		}
		else
			cout << "You have failed at running away. \n\n";
	}
	else if (user1.getlevel() < m.getlevel()) {
		if (rand() % 100 < 50) {
			cout << "You have successfully ran away. \n\n";
			battle = false;
		}
		else
			cout << "You have failed at running away. \n\n";
	}
	else {
		if (rand() % 100 < 70) {
			cout << "You have successfully ran away. \n\n";
			battle = false;
		}
		else
			cout << "You have failed at running away. \n\n";
	}
}
void BattleSystem:: fight() {

	srand((unsigned)time(0));
	battle = true;
	cout << "You got into a battle!\n"
		<< "It's the " + m.getName() + "! \n";
	m.draw();
		
	cout << "The " + m.getName() + " is level " << m.getlevel() << endl
		<< "Calculating turn order... \n\n";
	if (calculateOrder())
		userTurn = true;
	else
		userTurn = false;
	while (battle) {
		if (userTurn) {
			string input, input2;
			cout << "Your turn! What would you like to do?\n";
			while (userTurn) {
				cout << "1. Fight      2. Item       3. Run\n";
				cin >> input;
				if (input == "fight" || input == "Fight" || input == "1") {
					while (userTurn) {
						cout << "1. Attack     2. Strike     3. Back\n";
						cin >> input2;
						if (input2 == "attack" || input2 == "Attack" || input2 == "1") {
							cout << "You attacked the " + m.getName() << endl;
							m.takedamage(user1.getattack() - m.getdefense());
							cout << "The " + m.getName() + " lost " << user1.getattack() - m.getdefense() << " HP. \n" << endl;
							userTurn = false;
						}
						else if (input2 == "strike" || input2 == "Strike" || input2 == "2") {
							cout << "You attempted to break open the turtle's shell with your hand! \n";
							if ((rand() % 100) < 70) {
								int _damage = (user1.getattack() - m.getdefense()) * 3;
								m.takedamage(_damage);
								m.changedef(-2);
								cout << "You chopped open the turtle's shell! The enemy took " << _damage << " damage. The turtle's defense decreased by 2. \n";
							}
							else {
								cout << "Your hand wasn't strong enough...You took one damage... \n";
								m.takedamage(1);
							}

							userTurn = false;
						}
						else if (input2 == "spy")
							m.enemystatus();
						else if (input2 == "back" || input2 == "Back" || input2 == "3")
							break;
						else
							cout << "Please input a valid command. \n";
					}
				}
				else if (input == "item" || input == "Item" || input == "2") {
					user1.items();
					userTurn = false;
				}
				else if (input == "run" || input == "Run" || input == "3") {
					run();
					break;
				}
				else
					cout << "Please input a valid command. \n";

			}
			userTurn = false;
		}

		else {
			cout << "It's the " + m.getName() + "'s turn. \n";
			if ((rand() % 100) < 30) {
				int _damage;
				srand((unsigned)time(0));
				if ((rand() % 100) < 40) {
					_damage = (m.getattack() - user1.getdefense()) * 3;
					if (_damage <= 0)
						_damage = 0;
					user1.takedamage(_damage);
					cout << "The " + m.getName() + " jumped 10 meters in the air and flattened you! You lost " << _damage << " HP \n\n"
						<< "You have " << user1.gethealth() << " HP left. \n" << endl;
				}
				else {
					cout << "The turtle slowly moved towards you...\n\n";
					m.changeattack(1);
				}
			}

			else {
				int _damage;
				_damage = m.getattack() - user1.getdefense();
				if (_damage <= 0)
					_damage = 0;
				user1.takedamage(_damage);
				cout << "The " + m.getName() + " drove at super speed and rammed in you! You lost " << _damage << " HP \n"
					<< "You have " << user1.gethealth() << " HP left. \n" << endl;
			}
			userTurn = true;
		}

		if (m.gethealth() <= 0) {
			battle = false;
			cout << "You have defeated the " + m.getName() + "! \n";
			gainExperience();
			if (rand() % 100 > 95) {
				user1.itemget("Mega Potion");
				cout << "You found a Mega Potion. \n";
			}

		}
		else if (user1.gethealth() <= 0) {
			battle = false;
			user1.gameover();
		}
	}
}

bool BattleSystem::calculateOrder() {
	//User is faster
	if (user1.getspeed() > m.getspeed())
		return true;
	//Enemy is faster
	else if (user1.getspeed() < m.getspeed())
		return false;		
	//Same Speed
	else {
		//Random
		if ((rand() % 2) == 0)
			return true;
		else
			return false;
	}
}

void BattleSystem::gainExperience() {
	int leveldiff = user1.getlevel() - m.getlevel();
	if (2 >= leveldiff || leveldiff >= -2) {
		int _experience = rand() % (leveldiff + 9) + 1;
		user1.increaseexp(_experience);
		cout << "You gained " << _experience << " experience points. \n\n";
	}
	else if (leveldiff >= 3) {
		int _experience = (rand() * 9) + 1;
		user1.increaseexp(_experience);
		cout << "You gained " << _experience << " experience points. \n\n";
	}
	else if (leveldiff <= -3) {
		int _experience = rand() % abs((leveldiff * 2) + 1);
		user1.increaseexp(_experience);
		cout << "You gained " << _experience << " experience points. \n\n";
	}
	if (user1.getexperience() >= 10) {
		user1.levelup();
		cout << "You gained a level up! \n";
		user1.status();
	}
}