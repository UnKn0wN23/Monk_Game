#include "Monk.h"
#include <string>
using namespace std;

Monk::Monk(string name, string description)
{
	monkName = name;
	monkDescription = description;
	setMaxHP(15);
	setCurrentHP(maxHP);
	setMonkAP(3);
}

string Monk::getName()
{
	return monkName;
}
void Monk::setName(string name)
{
	monkName = name;
}

string Monk::getDescription()
{
	return monkDescription;
}
void Monk::setDescription(string description)
{
	monkDescription = description;
}

int Monk::getMaxHP()
{
	return maxHP;
}
void Monk::setMaxHP(int newMaxHP)
{
	maxHP = newMaxHP;
}

int Monk::getMonkAP()
{
	return monkAP;
}
void Monk::setMonkAP(int newAP)
{
	monkAP = newAP;
}

int Monk::getCurrentHP()
{
	return currentHP;
}
void Monk::setCurrentHP(int newHP)
{
	currentHP = newHP;
}

