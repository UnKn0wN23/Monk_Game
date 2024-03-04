#pragma once
#include <string>
using namespace std;

class Monk {
private:
	int maxHP;
	int currentHP;
	int monkAP;
	string monkName;
	string monkDescription;

public:
	Monk(string name, string description);

	string getName();
	void setName(string name);

	string getDescription();
	void setDescription (string description);

	int getMaxHP();
	void setMaxHP(int newMaxHP);

	int getMonkAP();
	void setMonkAP(int newAP);

	int getCurrentHP();
	void setCurrentHP(int newHP);
};