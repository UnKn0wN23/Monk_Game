#include <iostream>
#include <string>
#include <fstream>
#include "Dungeon.h"
#include "Monk.h"
#include "Rooms.h"
#include "Enemy.h"
using namespace std;


//printig out text files
void printTXT(string file){
	string line = "";
	ifstream inFile;
	inFile.open(file);
	if (inFile.is_open()){
		while (getline(inFile, line)){
			cout << line << endl;
		}
	}
	else{
		cout << "Error! File not found!" << endl;
	}
	inFile.close();
}


int main()
{
	int input;

	printTXT("Menu.txt");
	cout << "              [1]:Start Game      [2]:Exit\n" << endl;
	cout << "Input: ";
	cin >> input; //waits for input

	while (cin.fail() || input > 2 || input < 1) {
		cout << "Wrong Input!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input: ";
		cin >> input;
	}
	
	if (input == 1)
	{
		int diff;
		string monkN;
		string monkDis;

		system("CLS");//clears cmd
		printTXT("Menu.txt");
		cout << "Enter Monk's Name!" << endl;
		cout << "Name:";
		getline(cin>>ws, monkN);
		cout << "\nEnter Monk's Discription!" << endl;
		cout << "Discription:";
		getline(cin>>ws, monkDis);
		Monk hero(monkN, monkDis);
		system("CLS");
		printTXT("Difficulty.txt");
		cout << "Input: ";
		cin >> diff;

		while (cin.fail() || diff > 3 || diff < 1) {
			cout << "Wrong Input!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input: ";
			cin >> diff;
		}

		system("CLS");

		Dungeon d(diff);
		
		int dungeonRooms[15];

		for (int dungeonpos = 0; dungeonpos < (diff * 5); dungeonpos++) {
			dungeonRooms[dungeonpos] = d.getDungeonRoom(dungeonpos);
			Rooms r(dungeonRooms[dungeonpos], hero, diff);
		}
	}
	else if (input == 2)
	{
		exit(1);
	}
}