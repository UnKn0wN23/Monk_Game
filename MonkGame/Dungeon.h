#pragma once
#include <string>
using namespace std;

class Dungeon
{
private:
	int roomArray[15];
public:
	Dungeon(int difficulty);

	int getDungeonRoom(int roomNum);
};