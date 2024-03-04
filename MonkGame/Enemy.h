#pragma once
#include <string>
using namespace std;

class Enemy{
private:
	string enemyName;
	int enemyMaxHP;
	int enemyAP;
	int enemyCurrentHP;

public:
	Enemy(string name, int hp, int ap);

	string getName();

	int getEnemyMaxHP();

	int getEnemyCurrentHP();
	void setEnemyCurrentHP(int newMaxHP);

	int getEnemyAP();
};