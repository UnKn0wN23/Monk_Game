#include <iostream>
#include "Dungeon.h"



Dungeon::Dungeon(int difficulty)
{
	srand(time(0));
	if (difficulty == 1) {
		int availableRooms[5]{ 1, 2, 2, 3, 4 };
		for (int i = 0; i < 4; i++) {
			int randomPos = rand() % 4;
			int p = availableRooms[i];
			availableRooms[i] = availableRooms[randomPos];
			availableRooms[randomPos] = p;
		}

		for (int i = 0; i < 5; i++) {
			roomArray[i] = availableRooms[i];
		}
	}
	else if (difficulty == 2) {
		int availableRooms[10]{ 1, 1, 2, 2, 2, 2, 3, 3, 3, 4 };
		for (int i = 0; i < 9; i++) {
			int randomPos = rand() % 4;
			int p = availableRooms[i];
			availableRooms[i] = availableRooms[randomPos];
			availableRooms[randomPos] = p;
		}
		for (int i = 0; i < 10; i++) {
			roomArray[i] = availableRooms[i];
		}
	}
	else if (difficulty == 3) {
		int availableRooms[15]{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4 };
		for (int i = 0; i < 14; i++) {
			int randomPos = rand() % 4;
			int p = availableRooms[i];
			availableRooms[i] = availableRooms[randomPos];
			availableRooms[randomPos] = p;
		}
		for (int i = 0; i < 15; i++) {
			roomArray[i] = availableRooms[i];
		}
	}
	else {
		cout << "Error!" << endl;
	}
}

int Dungeon::getDungeonRoom(int roomNum)
{
	return roomArray[roomNum];
}
