/*********************************************************************
** Program Filename: play_game.cpp
** Author: Lilian Chan
** Date: 3/3/2019
** Description: This is the play game file where all the parts are put 
together.
** Input: user choices, ints
** Output: gameboard, actions
*********************************************************************/

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include "hunt.hpp"
#include <stdio.h>    
#include <stdlib.h> 

using namespace std;

int main(int argc, char* argv[])
{
	
	//cout << "start of main"<< endl;
	int size = atoi(argv[1]);
	while (size < 4){
		cout << "This is too small. Pick a bigger size." << endl;
		cin >> size;	
	}
	//cout << "got to checking if size is right"<< endl; 
	
	bool still_going = 1;
	int status = 0;
	
	
	
	Hunt * game;
	game = new Hunt(size);
	
	//cout << "created the game object"<< endl;
	
	while (still_going){
			game->print_board();
			game->move_shoot();
			status = game->status();
			if (status == 1) {
				cout << "You win!" << endl;
				still_going = 0;
			}
			if (status == 2){
				cout << "Do you want to start from scratch (press 1), from the beginning (press 2), or quit (press 3)?" << endl;
				int choice2;
				cin >> choice2;
				
				switch(choice2){
					case 1:
						cout << "You have chosen to start over! How big should it be?" << endl;
						cin >> size;
						while (size < 4){
							cout << "This is too small. Pick a bigger size" << endl;
							cin >> size;	
						}
						delete game;
						game = new Hunt(size);
						break;
						
					case 2:
						cout << "You have chosen to redo the game!" << endl;	
						game->redo();
						break; 
					
					case 3:
						cout << "See you next time!" << endl;
						still_going = 0;
						break;
						
					default:
						cout << "See you next time!" << endl;
						still_going = 0;
						break;
				}					
			}	
	}
	delete game;
	
	return 0;
}