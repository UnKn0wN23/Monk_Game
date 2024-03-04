#include "Enemy.h"

Enemy::Enemy(string name, int hp, int ap)
{
	enemyName = name;
	enemyMaxHP = hp;
	enemyCurrentHP = enemyMaxHP;
	enemyAP = ap;
}

string Enemy::getName()
{
	return enemyName;
}

int Enemy::getEnemyMaxHP()
{
	return enemyMaxHP;
}

int Enemy::getEnemyCurrentHP()
{
	return enemyCurrentHP;
}
void Enemy::setEnemyCurrentHP(int newHP)
{
	enemyCurrentHP = newHP;
}

int Enemy::getEnemyAP()
{
	return enemyAP;
}