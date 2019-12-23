/*********************************************************************
** Program Filename: game.cpp
** Author: Lilian Chan
** Date: 3/16/2019
** Description: This is the file that combines of the Escape from 
CS 162 files for the user to play the game
** Input: use choices, chars, ints
** Output: the game instructions, visualizations, and questions
*********************************************************************/

#include "Maze.hpp"
#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char* argv[]){
	ifstream file;
	file.open(argv[1]);
	if (file.fail()){
		cout << "Failed to open file." << endl;
		
		return 1;
	}
	
	bool still_going = 1;
	int grade = 0;
	Maze * game = new Maze(file);
	
	while (still_going == 1){
		game -> display();
		game -> move_stu();
		//cout << "Checking surroundings" << endl;
		game -> check_surroundings();
		//game -> display();
		//cout << "Moving TAs" << endl;
		game -> TAs_moving();
		//cout << "Re-checking surroundings" << endl;
		game -> check_surroundings();
		//game -> increment_appease();
		//cout << "Checking win condition" << endl;
		grade = game -> return_grade();
		if (grade == 1){
			cout << "You won!" << endl;
			still_going = 0;	
		}	
		if (grade == 2){
			cout << "You lost!" << endl;
			ifstream resetFile;
			resetFile.open(argv[1]);
			if (resetFile.fail()){
				cout << "Failed to open resetFile." << endl;
				
				return 1;
			}
			delete game;
			game = new Maze(resetFile);	
		}	
	}
	
	delete game; 
	
	return 1;
	
}