#include "Rooms.h"
#include "Monk.h"
#include "Enemy.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


void roomVisual(string file)
{
	string line = "";
	ifstream inFile;
	inFile.open(file);
	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "Error! File not found!" << endl;
	}
	inFile.close();
}

void Rooms::emptyRoom(Monk &m) {
	roomVisual("E_Room.txt");
	cout << "Player Details: Name: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
	int input;
	cout << "Input: ";
	cin >> input;
	while (cin.fail() || input > 2 || input < 1) {
		cout << "Wrong Input!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input: ";
		cin >> input;
	}

	while(input != 2){
		if (input == 1 && m.getCurrentHP() != m.getMaxHP()) {
			m.setCurrentHP(m.getMaxHP());
			cin.clear();
			cin.ignore(256, '\n');
			system("CLS");
			roomVisual("E_Room.txt");
			cout << "Player Details: Name: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
			cout << "HP restored!" << endl;
			cout << "Input: ";
			cin >> input;
			
		}
		else if ((input == 1 && m.getCurrentHP() == m.getMaxHP())) {
			cout << "Unable to Use!" << endl;
			cout << "Already at Max HP!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input: ";
			cin >> input;
		}
		else if (cin.fail() || input > 2 || input < 1) {
			cout << "Wrong Input!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input: ";
			cin >> input;
		}
	}
	system("CLS");
}	

Enemy enemyGenerator(int difficulty) {

	srand(time(0));
	int randomEnemy = rand() % (2 + difficulty) + 1;
	if (randomEnemy == 1) {
		Enemy sl("Slime", 6, 3);
		return sl;
	}
	else if (randomEnemy == 2) {
		Enemy sp("Giant Spider", 8, 2);
		return sp;
	}
	else if (randomEnemy == 3) {
		Enemy g("Goblin", 10, 2);
		return g;
	}
	else if (randomEnemy == 4) {
		Enemy dk("Dark Knight", 20, 4);
		return dk;
	}
	else if (randomEnemy == 5) {
		Enemy bm("Behemoth", 40, 7);
		return bm;
	}
}

bool actionCheck() {
	srand(time(0));
	int randNum = rand() % 2;
	if (randNum == 0) {
		return false;
	}
	else {
		return true;
	}
}

void Rooms::fightRoom(Monk &m, int difficulty) {
	Enemy e = enemyGenerator(difficulty);
	roomVisual("F_Room.txt");
	cout << "	You entered a room with " << e.getName() << " inside! You have to defeat it before you can move forward!\n" << endl;
	cout << "Player Details: Name: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
	cout << "Monster Details: Name: " << e.getName() << " | HP: " << e.getEnemyCurrentHP() << "/" << e.getEnemyMaxHP() << " | AP: " << e.getEnemyAP() << "\n" << endl;
	int turn = 0;
	
	do {
		if (turn == 0) {
			cout << "		It is " << e.getName() << " turn!\n" << endl;
			if (e.getEnemyCurrentHP() > round(e.getEnemyMaxHP() * 0.75)) {
				cout << e.getName() << " tries to attack you!" << endl;
				if (actionCheck()) {
					m.setCurrentHP(m.getCurrentHP() - e.getEnemyAP());
					cout << e.getName() << " hit you for " << e.getEnemyAP() << " damage!" << endl;
				}
				else {
					cout << e.getName() << " tried to attack you, but missed!" << endl;
				}
			}
			else {
				srand(time(0));
				int action = rand() % 4;
				if (action < 2) {
					cout << e.getName() << " tries to attack you!" << endl;
					if (actionCheck()) {
						m.setCurrentHP(m.getCurrentHP() - e.getEnemyAP());
						cout << e.getName() << " hit you for " << e.getEnemyAP() << " damage!" << endl;
					}
					else {
						cout << e.getName() << " tried to attack you, but missed!" << endl;
					}
				}
				else if (action >= 2) {
					cout << e.getName() << " tries to heal itself!" << endl;
					if (actionCheck()) {
						e.setEnemyCurrentHP(e.getEnemyCurrentHP() + 1);
						cout << e.getName() << " healed itself for 1 HP!" << endl;
					}
					else {
						cout << e.getName() << " tried to heal itself, but failed!" << endl;
					}
				}
			}
			system("pause");
			system("CLS");
			roomVisual("F_Room.txt");
			cout << "Player Details: Name: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
			cout << "Monster Details: Name: " << e.getName() << " | HP: " << e.getEnemyCurrentHP() << "/" << e.getEnemyMaxHP() << " | AP: " << e.getEnemyAP() << "\n" << endl;
			turn = 1;
		}

		if (turn == 1 && m.getCurrentHP() > 0) {
			int input;
			cout << "		It is your turn!\n" << endl;
			cout << "	[1]:Attack      [2]:Deffence (restore 1 HP)" << endl;
			cout << "Input: ";
			cin >> input;
			while (cin.fail() || input > 2 || input < 1) {
				cout << "Wrong Input!" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Input: ";
				cin >> input;
			}
			while (input == 2 && m.getCurrentHP() == m.getMaxHP()) {
				cout << "Unable to heal! Character already at full health!" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Input: ";
				cin >> input;
			}

			if (input == 1) {
				cout << "You try to attack " << e.getName() << endl;
				if (actionCheck()) {
					e.setEnemyCurrentHP(e.getEnemyCurrentHP() - m.getMonkAP());
					cout << "You hit " << e.getName() << " for " << m.getMonkAP() << " damage!" << endl;
				}
				else {
					cout << "You tried to hit " << e.getName() << ", but you missed!" << endl;
				}
			}
			else if (input == 2 && m.getCurrentHP() != m.getMaxHP()){
				cout << "You try to heal yourself!" << endl;
				if (actionCheck()) {
					m.setCurrentHP(m.getCurrentHP() + 1);
					cout << "You have restored 1 HP!"<< endl;
				}
				else {
					cout << "You tried to heal, but failed!" << endl;
				}
			}
			turn = 0;
			system("pause");
			system("CLS");
			roomVisual("F_Room.txt");
			cout << "Player Details: Name: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
			cout << "Monster Details: Name: " << e.getName() << " | HP: " << e.getEnemyCurrentHP() << "/" << e.getEnemyMaxHP() << " | AP: " << e.getEnemyAP() << "\n" << endl;
		}
	} while (e.getEnemyCurrentHP() > 0 && m.getCurrentHP() > 0);
	
	if (e.getEnemyCurrentHP() <= 0) {
		cout << "	You have defeated " << e.getName() << "! Now you can move to the next room!" << endl;
		system("pause");
		system("CLS");
	}
	else if (m.getCurrentHP() <= 0) {
		system("CLS");
		roomVisual("Death.txt");
		exit(1);
	}
}


void Rooms::upgradeRoom(Monk &m) {
	roomVisual("U_Room.txt");
	cout << "Player Details: Name: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
	int input;
	bool upgrade = true;
	cout << "Input: ";
	cin >> input;
	while (input > 3 || cin.fail() || input < 1) {
		cout << "Wrong Input!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Input: ";
		cin >> input;
	}

	while (input != 3) {
		if (input == 1 && upgrade) {
			m.setMaxHP(m.getMaxHP() + 5);
			m.setCurrentHP(m.getCurrentHP() + 5);
			upgrade = false;
			cin.clear();
			cin.ignore(256, '\n');
			system("CLS");
			roomVisual("U_Room.txt");
			cout << "Player Details: Name: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
			cout << "Your HP has been increased!" << endl;
			cout << "Input: ";
			cin >> input;
		}
		else if (input == 2 && upgrade) {
			m.setMonkAP(m.getMonkAP() + 2);
			upgrade = false;
			cin.clear();
			cin.ignore(256, '\n');
			system("CLS");
			roomVisual("U_Room.txt");
			cout << "Player Details: Name: " << m.getName() << " | HP: " << m.getCurrentHP() << "/" << m.getMaxHP() << " | AP: " << m.getMonkAP() << "\n" << endl;
			cout << "Your Attack has been increased!" << endl;
			cout << "Input: ";
			cin >> input;
		}
		else if (cin.fail() || input > 3 || input < 1) {
			cout << "Wrong Input!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input: ";
			cin >> input;
		}
		else {
			cout << "Upgrade Room can be used only once!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Input: ";
			cin >> input;
		}
	}
	system("CLS");
}


void Rooms::treasureRoom() {
	roomVisual("T_Room.txt");
	exit(1);
}


Rooms::Rooms(int roomID, Monk &player, int difficulty) {

	if (roomID == 1) {
		emptyRoom(player);
	}
	else if (roomID == 2) {
		fightRoom(player, difficulty);
	}
	else if (roomID == 3) {
		upgradeRoom(player);
	}
	else if (roomID == 4) {
		treasureRoom();
	}
}

