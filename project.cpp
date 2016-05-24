#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "units.h"
#include <iterator>

using namespace std;

vector <string> Unit::names;

void Unit::init()
{
	ifstream file("roman_names.txt");
	ifstream filetwo("animal_names");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	copy(istream_iterator<string>(filetwo),
		istream_iterator<string>(),
		back_inserter(animal_names));
	file.close();
	filetwo.close();
}

Hero::Hero()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_hp = totalHp = 150 + rand() % 75;
	_attackPower = 20 + rand() % 30;
	_defencePower = 50 + rand() % 30;
	_luck = 10 + rand() % 20;
}

Glad::Glad()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_hp = totalHp = 70 + rand() % 50;
	_attackPower = 20 + rand() % 30;
	_defencePower = 40 + rand() % 20;
}

Animal::Animal() 								//nazwy jeszcze
{
	static int amountOfAnimalNames = (init, animal_names.size());
	_name = animal_names[rand() % amountOfAnimalNames];
	_hp = totalHp = 100 + rand() % 50;
	_attackPower = 40 + rand() % 70;
	_defencePower = 10 + rand() % 30;
}

int Glad::hitChance()
{
	int value;
	value = 20 + rand() % 80;
	return value;
}

void Hero::victoryAward()
{
	int heal = (totalHp)/5;

	if(_hp>(totalHp - heal))
		_hp=totalHp;

	else
		_hp+=(totalHp)/5;
}

void Encounter::yourHero(string sentence)
{
	cout<<"Your hero's name is "<<sentence<<"!"<<endl;
}

bool Unit::areYouDead(int value)
{
	if(value<=0)
		return 0;
	else return 1;
}
void Glad::powerup(int value, int maxhp, int attack, int def)
{
	switch(value)
	{
		case 2:
		{
			maxhp+=maxhp/10;
			attack+=attack/10;
			def+=def/10;
		} break;

		case 3:
		{
			maxhp+=maxhp/5;
			attack+=attack/5;
			def+=def/5;
		} break;
	}
}