#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Cat.h"
#include "Guitarist.h"
#include "Juggler.h"
#include "Lucy.h"
#include "Turtle.h"
#include "Nerd.h"
#include <iostream>

using namespace std;

void catcombat(Character& user1) {

	Cat m;
	bool battle = true;
	bool myturn;
	cout << "You got into a battle!\n"
		<< "You met the Black Cat of Death! \n";
	int prob = rand() % 100;
	if (prob < 55)
		m.drawcat();
	else
		m.drawcat1();
	cout << "The Black Cat of Death is level " << m.getlevel() << endl
		<< "Calculating turn order... \n\n";
	if (user1.getspeed() > m.getspeed())
		myturn = true;
	else if (user1.getspeed() < m.getspeed())
		myturn = false;
	else {
		srand((unsigned)time(0));
		if ((rand() % 100) < 50)
			myturn = true;
		else
			myturn = false;
	}
	while (battle) {
		if (myturn) {
			string input, input2;
			cout << "Your turn! What would you like to do?\n";
			while (myturn) {
				cout << "1. Fight      2. Item       3. Run\n";
				cin >> input;
				if (input == "fight" || input == "Fight" || input == "1") {
					while (myturn) {
						cout << "1. Attack     2. Strike     3. Back\n";
						cin >> input2;
						if (input2 == "attack" || input2 == "Attack" || input2 == "1") {
							cout << "You attacked the Black Cat of Death. \n";
							m.takedamage(user1.getattack() - m.getdefense());
							cout << "The Black Cat of Death lost " << user1.getattack() - m.getdefense() << " HP. \n" << endl;
							myturn = false;
						}
						else if (input2 == "strike" || input2 == "Strike" || input2 == "2") {
							srand((unsigned)time(0));
							cout << "You attempted to beat the Black Cat of Death! \n";
							if ((rand() % 100) < 30) {
								int _damage = (user1.getattack() - m.getdefense()) * 3;
								m.takedamage(_damage);
								cout << "Your hit directly hit the Black Cat of Death! It whimpered and meowed softly... It took " << _damage << " damage \n";
							}
							else {
								cout << "The cat nimbly dodged the attack... \n";
							}

							myturn = false;

						}
						else if (input2 == "back" || input2 == "Back" || input2 == "3")
							break;
						else if (input2 == "spy")
							m.enemystatus();
						else
							cout << "Please input a valid command. \n";
					}
				}
				else if (input == "item" || input == "Item" || input == "2") {
					user1.items();
					myturn = false;

				}
				else if (input == "run" || input == "Run" || input == "3") {
					if (user1.getlevel() > m.getlevel()) {//enemy level)
						if (rand() % 100 < 70) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					else if (user1.getlevel() < m.getlevel()) {
						if (rand() % 100 < 20) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					else {
						if (rand() % 100 < 40) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					break;
				}
				else
					cout << "Please input a valid command. \n";

			}
			myturn = false;
		}

		else {
			cout << "It's the Black Cat of Death's turn. \n";
			srand((unsigned)time(0));
			if ((rand() % 100) < 30) {
				int _damage;
				srand((unsigned)time(0));
				if ((rand() % 100) < 30) {
					_damage = (m.getattack() - user1.getdefense()) * 3;
					if (_damage <= 0)
						_damage = 1;
					user1.takedamage(_damage);
					cout << "The Black Cat of Death scratched your face! You lost " << _damage << " HP \n";
					if (user1.gethealth() > 0)
						cout << "You have " << user1.gethealth() << " HP left. \n" << endl;
				}
				else
					cout << "The Black Cat of Death was overcome with tiredness to move. \n";
			}

			else {
				int _damage;
				_damage = m.getattack() - user1.getdefense();
				if (_damage <= 0)
					_damage = 0;
				user1.takedamage(_damage);
				cout << "The Black Cat of Death used its powers of die! You lost " << _damage << " HP \n";
				if (user1.gethealth() > 0)
					cout << "You have " << user1.gethealth() << " HP left. \n" << endl;
			}
			myturn = true;
		}

		if (m.gethealth() <= 0) {
			battle = false;
			cout << "You have defeated the Black Cat of Death! \n";
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
				int _experience = rand() % abs((leveldiff * 2)) + 1;
				user1.increaseexp(_experience);
				cout << "You gained " << _experience << " experience points. \n\n";
			}
			if (user1.getexperience() >= 10) {
				user1.levelup();
				cout << "You gained a level up! \n";
				user1.status();
			}
			int chance = rand() % 101;
			if (chance > 80) {
				user1.itemget("Potion");
				cout << "You found a Potion. \n";
			}
			if (chance < 5) {
				user1.itemget("Mega Potion");
				cout << "You found a Mega Potion. \n";
			}
		}

		if (user1.gethealth() <= 0) {
			battle = false;
			user1.gameover();
		}
	}
}

void lucycombat(Character& user1) {
	Lucy m;
	bool attract = false;
	bool battle = true;
	bool myturn;
	cout << "You got into a battle!\n"
		<< "It's Lucy!\n";
	m.drawlucy();
	cout << "Lucy is level " << m.getlevel() << endl
		<< "Calculating turn order... \n\n";
	if (user1.getspeed() > m.getspeed())
		myturn = true;
	else if (user1.getspeed() < m.getspeed())
		myturn = false;
	else {
		srand((unsigned)time(0));
		if ((rand() % 100) < 50)
			myturn = true;
		else
			myturn = false;
	}
	while (battle) {
		if (myturn) {
			string input, input2;
			cout << "Your turn! What would you like to do?\n";
			while (myturn) {
				cout << "1. Fight      2. Item       3. Run\n";
				cin >> input;
				if (input == "fight" || input == "Fight" || input == "1") {
					while (myturn) {
						cout << "1. Attack     2. Strike     3. Back\n";
						cin >> input2;
						if (input2 == "attack" || input2 == "Attack" || input2 == "1") {
							int r = (rand() % 10);
							if (attract && r < 5) {
								cout << "You were overcome with love to Lucy! \n";
								myturn = false;
								break;
							}
							cout << "You punched Lucy. \n";
							m.takedamage(user1.getattack() - m.getdefense());
							cout << "Lucy lost " << user1.getattack() - m.getdefense() << " HP. \n" << endl;
							myturn = false;
						}
						else if (input2 == "strike" || input2 == "Strike" || input2 == "2") {
							srand((unsigned)time(0));
							int r = (rand() % 10);
							if (attract && r < 5) {
								cout << "You were overcome with love to Lucy! \n";
								myturn = false;
								break;
							}
							cout << "You attempted to strike Lucy! \n";
							if ((rand() % 100) < 30) {
								int _damage = (user1.getattack() - m.getdefense()) * 3;
								m.takedamage(_damage);
								cout << "You critically slapped Lucy! The enemy took " << _damage << " damage \n";
							}
							else {
								cout << "You were too lovestruck by Lucy... \n";
							}

							myturn = false;

						}
						else if (input2 == "back" || input2 == "Back" || input2 == "3")
							break;
						else if (input2 == "spy")
							m.enemystatus();
						else
							cout << "Please input a valid command. \n";
					}
				}
				else if (input == "item" || input == "Item" || input == "2") {
					user1.items();
					myturn = false;

				}
				else if (input == "run" || input == "Run" || input == "3") {
					if (user1.getlevel() > m.getlevel()) {//enemy level)
						if (rand() % 100 < 70) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					else if (user1.getlevel() < m.getlevel()) {
						if (rand() % 100 < 20) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					else {
						if (rand() % 100 < 40) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					break;
				}
				else
					cout << "Please input a valid command. \n";

			}
			myturn = false;
		}

		else {
			cout << "It's Lucy's turn. \n";
			srand((unsigned)time(0));
			int random = rand() % 100;
			if (random < 20) {
				int _damage;
				srand((unsigned)time(0));
				_damage = (m.getattack() - user1.getdefense()) * 2;
				if (_damage <= 0)
					_damage = 0;
				user1.takedamage(_damage);
				cout << "Lucy critically stabbed you! You lost " << _damage << " HP \n";
				if (user1.gethealth() > 0)
					cout << "You have " << user1.gethealth() << " HP left. \n" << endl;
			}
			else if (random > 70 && attract == false) {
				cout << "Lucy used her charm on you. You may not be able to move. \n";
				attract = true;
			}
			else {
				int _damage;
				_damage = m.getattack() - user1.getdefense();
				if (_damage <= 0)
					_damage = 0;
				user1.takedamage(_damage);
				cout << "Lucy slapped you! You lost " << _damage << " HP \n";
				if (user1.gethealth() > 0)
					cout << "You have " << user1.gethealth() << " HP left. \n" << endl;
			}
			myturn = true;
		}

		if (m.gethealth() <= 0) {
			battle = false;
			cout << "You have defeated Lucy! \n";
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
			int chance = rand() % 101;
			if (chance > 30) {
				user1.itemget("Lucy");
				cout << "You captured Lucy! Just... she might be a bit volatile... \n";
			}
		}

		if (user1.gethealth() <= 0) {
			battle = false;
			user1.gameover();
		}
	}
}

void turtlecombat(Character& user1) {
	srand((unsigned)time(0));
	Turtle m;
	bool battle = true;
	bool myturn;
	cout << "You got into a battle!\n"
		<< "It's the Crazy Turtle! \n";
	m.draw();
	cout << "The Crazy Turtle is level " << m.getlevel() << endl
		<< "Calculating turn order... \n\n";
	if (user1.getspeed() > m.getspeed())
		myturn = true;
	else if (user1.getspeed() < m.getspeed())
		myturn = false;
	else {
		if ((rand() % 100) < 50)
			myturn = true;
		else
			myturn = false;
	}
	while (battle) {
		if (myturn) {
			string input, input2;
			cout << "Your turn! What would you like to do?\n";
			while (myturn) {
				cout << "1. Fight      2. Item       3. Run\n";
				cin >> input;
				if (input == "fight" || input == "Fight" || input == "1") {
					while (myturn) {
						cout << "1. Attack     2. Strike     3. Back\n";
						cin >> input2;
						if (input2 == "attack" || input2 == "Attack" || input2 == "1") {
							cout << "You attacked the Crazy Turtle. \n";
							m.takedamage(user1.getattack() - m.getdefense());
							cout << "The Crazy Turtle lost " << user1.getattack() - m.getdefense() << " HP. \n" << endl;
							myturn = false;
						}
						else if (input2 == "strike" || input2 == "Strike" || input2 == "2") {
							srand((unsigned)time(0));
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

							myturn = false;

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
					myturn = false;

				}
				else if (input == "run" || input == "Run" || input == "3") {
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
					break;
				}
				else
					cout << "Please input a valid command. \n";

			}
			myturn = false;
		}

		else {
			cout << "It's the Crazy Turtle's turn. \n";
			srand((unsigned)time(0));
			if ((rand() % 100) < 30) {
				int _damage;
				srand((unsigned)time(0));
				if ((rand() % 100) < 40) {
					_damage = (m.getattack() - user1.getdefense()) * 3;
					if (_damage <= 0)
						_damage = 0;
					user1.takedamage(_damage);
					cout << "The Crazy Turtle jumped 10 meters in the air and flattened you! You lost " << _damage << " HP \n\n"
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
				cout << "The Crazy Turtle drove at super speed and rammed in you! You lost " << _damage << " HP \n"
					<< "You have " << user1.gethealth() << " HP left. \n" << endl;
			}
			myturn = true;
		}

		if (m.gethealth() <= 0) {
			battle = false;
			cout << "You have defeated the Crazy Turtle! \n";
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
			int chance = rand() % 101;
			if (chance > 95) {
				user1.itemget("Mega Potion");
				cout << "You found a Mega Potion. \n";
			}

		}

		if (user1.gethealth() <= 0) {
			battle = false;
			
			user1.gameover();
		}
	}
}

void jugcombat(Character& user1) {
	srand((unsigned)time(0));
	Juggler m;
	bool battle = true;
	bool myturn;
	cout << "You got into a battle!\n"
		<< "It's a Juggler! \n";
	int prob = rand() % 100;
	if (prob < 60)
		m.drawjugman();
	else if (prob > 70)
		m.drawjugman1();
	else
		m.drawjugman2();
	cout << "The Juggler is level " << m.getlevel() << endl
		<< "Calculating turn order... \n\n";
	if (user1.getspeed() > m.getspeed())
		myturn = true;
	else if (user1.getspeed() < m.getspeed())
		myturn = false;
	else {
		if ((rand() % 100) < 50)
			myturn = true;
		else
			myturn = false;
	}
	while (battle) {
		if (myturn) {
			string input, input2;
			cout << "Your turn! What would you like to do?\n";
			while (myturn) {
				cout << "1. Fight      2. Item       3. Run\n";
				cin >> input;
				if (input == "fight" || input == "Fight" || input == "1") {
					while (myturn) {
						cout << "1. Attack     2. Strike     3. Back\n";
						cin >> input2;
						if (input2 == "attack" || input2 == "Attack" || input2 == "1") {
							cout << "You stole his balls and threw them back at him!\n";
							m.takedamage(user1.getattack() - m.getdefense());
							cout << "The Juggler lost " << user1.getattack() - m.getdefense() << " HP. \n" << endl;
							myturn = false;
						}
						else if (input2 == "strike" || input2 == "Strike" || input2 == "2") {
							srand((unsigned)time(0));
							if ((rand() % 100) < 30) {
								int _damage = (user1.getattack() - m.getdefense()) * 3;
								m.takedamage(_damage);
								cout << "You critically hit the Juggler! The Juggler took " << _damage << " damage. \n";
							}
							else {
								cout << "You slipped on one of his balls and missed... \n";
							}

							myturn = false;

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
					myturn = false;

				}
				else if (input == "run" || input == "Run" || input == "3") {
					if (user1.getlevel() > m.getlevel()) {//enemy level)
						if (rand() % 100 < 70) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					else if (user1.getlevel() < m.getlevel()) {
						if (rand() % 100 < 20) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					else {
						if (rand() % 100 < 50) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					break;
				}
				else
					cout << "Please input a valid command. \n";

			}
			myturn = false;
		}

		else {
			cout << "It's the Juggler's turn. \n";
			srand((unsigned)time(0));
			if ((rand() % 100) < 30) {
				int _damage;
				srand((unsigned)time(0));
				if ((rand() % 100) < 50) {
					_damage = (m.getattack() - user1.getdefense()) * 2;
					if (_damage <= 0)
						_damage = 0;
					user1.takedamage(_damage);
					cout << "The Juggler threw a knife at you! You lost " << _damage << " HP \n"
						<< "You have " << user1.gethealth() << " HP left. \n" << endl;
				}
				else {
					cout << "The Juggler is hoping to win the audition to perform at Lacey's Carnival to impress the kids.";
				}
			}

			else {
				int _damage;
				_damage = m.getattack() - user1.getdefense();
				if (_damage <= 0)
					_damage = 0;
				user1.takedamage(_damage);
				cout << "The Juggler threw his balls at you! You lost " << _damage << " HP \n"
					<< "You have " << user1.gethealth() << " HP left. \n" << endl;
			}
			myturn = true;
		}

		if (m.gethealth() <= 0) {
			battle = false;
			cout << "You have defeated the Juggler! \n";
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
			int chance = rand() % 101;
			if (chance > 70) {
				user1.itemget("Flying Bat");
				cout << "You found a Flying Bat. \n";
			}

		}

		if (user1.gethealth() <= 0) {
			battle = false;
			
			user1.gameover();
		}
	}
}

void guitarcombat(Character& user1) {

	Guitarist m;
	bool guitar = true;
	bool battle = true;
	bool myturn;
	cout << "You got into a battle!\n"
		<< "It's the Hippie Guitarist! \n";
	m.drawguitar();
	cout << "The Hippie Guitarist is level " << m.getlevel() << endl
		<< "Calculating turn order... \n\n";
	if (user1.getspeed() > m.getspeed())
		myturn = true;
	else if (user1.getspeed() < m.getspeed())
		myturn = false;
	else {
		srand((unsigned)time(0));
		if ((rand() % 100) < 50)
			myturn = true;
		else
			myturn = false;
	}
	while (battle) {
		if (myturn) {
			string input, input2;
			cout << "Your turn! What would you like to do?\n";
			while (myturn) {
				cout << "1. Fight      2. Item       3. Run\n";
				cin >> input;
				if (input == "fight" || input == "Fight" || input == "1") {
					while (myturn) {
						cout << "1. Attack     2. Strike     3. Back\n";
						cin >> input2;
						if (input2 == "attack" || input2 == "Attack" || input2 == "1") {
							cout << "You attacked the Hippie Guitarist. \n";
							m.takedamage(user1.getattack() - m.getdefense());
							cout << "The Hippie Guitarist lost " << user1.getattack() - m.getdefense() << " HP. \n" << endl;
							myturn = false;
						}
						else if (input2 == "strike" || input2 == "Strike" || input2 == "2") {
							srand((unsigned)time(0));
							if (guitar == false) {
								cout << "The strike failed. \n";
								break;
							}
							cout << "You attempted to hit the Hippie Guitarist with his guitar! \n";
							if ((rand() % 100) < 30) {
								int _damage = (user1.getattack() - m.getdefense()) * 3;
								m.takedamage(_damage);
								cout << "The guitarist took " << _damage << " damage! His guitar broke. The Hippie Guitarist started sobbing due to his lack of soul. \n\n";
								guitar = false;
							}
							else {
								cout << "The Hippie Guitarist had a firm grip on his guitar... \n\n";
							}

							myturn = false;

						}
						else if (input2 == "back" || input2 == "Back" || input2 == "3")
							break;
						else if (input2 == "spy")
							m.enemystatus();
						else
							cout << "Please input a valid command. \n";
					}
				}
				else if (input == "item" || input == "Item" || input == "2") {
					user1.items();
					myturn = false;
				}
				else if (input == "run" || input == "Run" || input == "3") {
					if (user1.getlevel() > m.getlevel()) {//enemy level)
						if (rand() % 100 < 70) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					else if (user1.getlevel() < m.getlevel()) {
						if (rand() % 100 < 20) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					else {
						if (rand() % 100 < 40) {
							cout << "You have successfully ran away. \n\n";
							battle = false;
						}
						else
							cout << "You have failed at running away. \n\n";
					}
					break;
				}
				else
					cout << "Please input a valid command. \n";

			}
			myturn = false;
		}

		else {
			cout << "It's the Hippie Guitarist's turn. \n";
			srand((unsigned)time(0));
			if (guitar == false) {
				cout << "The Hippie Guitarist continued to cry. \n";
				myturn = true;
				continue;
			}
			if ((rand() % 100) < 30) {
				int _damage;
				srand((unsigned)time(0));
				cout << "The Hippie Guitarist played a funky riff. \n";
				if ((rand() % 100) < 30) {
					_damage = (m.getattack() - user1.getdefense()) * 3;
					if (_damage <= 0)
						_damage = 1;
					user1.takedamage(_damage);
					cout << "You lost all your hearing by the sound. You lost " << _damage << " HP \n";
					if (user1.gethealth() > 0)
						cout << "You have " << user1.gethealth() << " HP left. \n" << endl;
				}
				else
					cout << "The melody was actually not too bad??? \n";
			}

			else {
				int _damage;
				_damage = m.getattack() - user1.getdefense();
				if (_damage <= 0)
					_damage = 0;
				user1.takedamage(_damage);
				cout << "The Hippie Guitarist whacked you on the head with his guitar! You lost " << _damage << " HP \n";
				if ((rand() % 100) < 50) {
					guitar = false;
					cout << "The guitar broke. The Hippie Guitarist started sobbing due to his lack of soul. \n";
				}
				if (user1.gethealth() > 0)
					cout << "You have " << user1.gethealth() << " HP left. \n" << endl;
			}
			myturn = true;
		}

		if (m.gethealth() <= 0) {
			battle = false;
			cout << "You have defeated the Hippie Guitarist! \n";
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
				int _experience = rand() % abs((leveldiff * 2)) + 1;
				user1.increaseexp(_experience);
				cout << "You gained " << _experience << " experience points. \n\n";
			}
			if (user1.getexperience() >= 10) {
				user1.levelup();
				cout << "You gained a level up! \n";
				user1.status();
			}
			int chance = rand() % 101;
			if (chance < 80) {
				user1.itemget("Guitar");
				cout << "You found a Guitar. \n";
			}
		}

		if (user1.gethealth() <= 0) {
			battle = false;
			
			user1.gameover();
		}
	}
}

void nerdcombat(Character& user1) {

	Nerd m;
	bool rage = false;
	bool battle = true;
	bool myturn;
	cout << "You got into a battle!\n"
		<< "Modern Day Nerd attacked you! \n";
	m.drawnerd();
	cout << "The Modern Day Nerd is level " << m.getlevel() << endl
		<< "Calculating turn order... \n\n";
	if (user1.getspeed() > m.getspeed())
		myturn = true;
	else if (user1.getspeed() < m.getspeed())
		myturn = false;
	else {
		srand((unsigned)time(0));
		if ((rand() % 100) < 50)
			myturn = true;
		else
			myturn = false;
	}
	while (battle) {
		if (myturn) {
			string input, input2;
			cout << "Your turn! What would you like to do?\n";
			while (myturn) {
				cout << "1. Fight      2. Item       3. Run\n";
				cin >> input;
				if (input == "fight" || input == "Fight" || input == "1") {
					while (myturn) {
						cout << "1. Attack     2. Strike     3. Back\n";
						cin >> input2;
						if (input2 == "attack" || input2 == "Attack" || input2 == "1") {
							cout << "You hit the anime bodypillow that the Modern Day Nerd was holding. \n"
								<< "The Modern Day Nerd became enraged due to the damage to his waifu. His attack rose by 10." << endl;
							m.changeattack(10);
							m.takedamage(user1.getattack() - m.getdefense());
							cout << "The Modern Day Nerd lost " << user1.getattack() - m.getdefense() << " HP. \n";
							rage = true;
							myturn = false;
						}
						else if (input2 == "strike" || input2 == "Strike" || input2 == "2") {
							srand((unsigned)time(0));
							cout << "You questioned the Modern Day Nerd's anime tastes. \n";
							int _damage = (user1.getattack() - m.getdefense()) * 3;
							m.takedamage(_damage);
							cout << "Your hit directly hit the heart of Modern Day Nerd! He took " << _damage << " damage \n";
							myturn = false;

						}
						else if (input2 == "back" || input2 == "Back" || input2 == "3")
							break;
						else if (input2 == "spy")
							m.enemystatus();
						else
							cout << "Please input a valid command. \n";
					}
				}
				else if (input == "item" || input == "Item" || input == "2") {
					user1.items();
					myturn = false;

				}
				else if (input == "run" || input == "Run" || input == "3") {
					cout << "You have failed at running away. \n\n";
					break;
				}
				else
					cout << "Please input a valid command. \n";

			}
			myturn = false;
		}

		else {
			cout << "It's the Modern Day Nerd's turn. \n";
			int _damage;
			srand((unsigned)time(0));
			if (rage) {
				cout << "The enraged Modern Day Nerd hits you on the head with his wood katana. \n";
				_damage = m.getattack() - user1.getdefense();
				if (_damage <= 0)
					_damage = 0;
				user1.takedamage(_damage);
				cout << "You took " << _damage << " damage. \n";
				if (user1.gethealth() > 0)
					cout << "You have " << user1.gethealth() << " HP left. \n" << endl;
			}
			else {
				int j = rand() % 100;
				if (j < 20) {
					cout << "The Modern Day Nerd roasted you with his anime knowledge. \n"
						<< "You felt bad for the The Modern Day Nerd so you took 1 damage for him. \n";
					user1.takedamage(1);
					if (user1.gethealth() > 0)
						cout << "You have " << user1.gethealth() << " HP left. \n" << endl;
				}
				else if (j > 70) {
					cout << "The Modern Day Nerd is thinking about what anime figures to buy next weekend. \n";
				}

				else {
					cout << "The Modern Day Nerd is looking up some anime images from the internet. \n";
				}
			}

			myturn = true;
		}

		if (m.gethealth() <= 0) {
			battle = false;
			cout << "You have defeated the Modern Day Nerd! \n";
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
				int _experience = rand() % abs((leveldiff * 2)) + 1;
				user1.increaseexp(_experience);
				cout << "You gained " << _experience << " experience points. \n\n";
			}
			if (user1.getexperience() >= 10) {
				user1.levelup();
				cout << "You gained a level up! \n";
				user1.status();
			}
			int chance = rand() % 101;
			if (chance > 70) {
				user1.itemget("Potion");
				cout << "You found a Potion in his secret stash. \n";
			}
		}

		if (user1.gethealth() <= 0) {
			battle = false;
			
			user1.gameover();
		}
	}
}

void forward(Character& user1) {
	srand((unsigned)time(0));
	while (user1.getMiles() > 1) {
		int prob;
		user1.changeMiles(-1);
		cout << user1.getMiles() << " miles left. \n";
		prob = rand() % 100;
		Turtle m;
		//30% enemy encounter 
		if ((rand() % 10) < 3) {
			if (prob <= 15)
				catcombat(user1);
			else if (prob > 15 && prob <= 25)
				lucycombat(user1);
			else if (prob > 25 && prob <= 40)
				turtlecombat(user1);
			else if (prob > 40 && prob < 60)
				jugcombat(user1);
			else if (prob > 60 && prob < 80)
				guitarcombat(user1);
			else
				nerdcombat(user1);
			break;
		}
	}
}
