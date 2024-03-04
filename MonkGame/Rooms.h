#pragma once
#include "Monk.h"
#include <string>

using namespace std;


class Rooms
{
public:
	Rooms(int roomID, Monk &m, int difficulty);
	void emptyRoom(Monk &m);
	void fightRoom(Monk &m, int difficulty);
	void upgradeRoom(Monk &m);
	void treasureRoom();
};

