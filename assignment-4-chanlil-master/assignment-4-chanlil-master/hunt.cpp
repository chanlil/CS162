/*********************************************************************
** Program Filename: hunt.cpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: This is the implementation file for the game actions
** Input: User choices, ints
** Output: Game map, actions
*********************************************************************/

#include "hunt.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>

using namespace std;

/*********************************************************************
** Function: Hunt()
** Description: fills in values for game
** Parameters: N/A
** Pre-Conditions: create a hunt
** Post-Conditions: fills in values
*********************************************************************/ 

Hunt::Hunt(int x){
	
	srand (time(NULL));
	arrow = 3;
	size = x;
	//AI_playing = AI;
	alive = 1;
	gold = 0;
	wum_dead = 0;
	

	
	for (int i = 0; i < size; i++){
		vector<Room> row; //= new vector<Room>();
		for (int j = 0; j < size; j++) {
			//row.push_back(new Room());
			Room r; //Implicit initalization
			row.push_back(r);
		}	
		gameboard.push_back(row);	
	}
	

	
	event_fill();
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			gameboard[i][j].set_event(events[i * size + j]);
		}
	}	

	
	fill_backup();

	int still_going = 1;
	while (still_going == 1){
		//sets heroine's location
		int row1 = rand() % size;
		int col1 = rand() % size;
		int check =  gameboard[row1][col1].check_encounter();

		if (check == 0){

			still_going = 0;
			row = row1;
			col = col1;
			esc_row = row1;
			esc_col = col1;
		}
	}	
}

/*********************************************************************
** Function: fill_backup()
** Description: fills in values for backup the same as events
** Parameters: N/A
** Pre-Conditions: create a hunt
** Post-Conditions: fills in values
*********************************************************************/ 

void Hunt::fill_backup(){
	int _eventSize = size * size;
	int type;
	backup = new Event*[_eventSize];
	for (int i = 0; i < _eventSize; i++){
		type = events[i] -> encounter(); 
		if (type == 0)
			backup[i] = new Empty;
		else if (type == 1)
			backup[i] = new Wumpus;
		else if (type == 2)
			backup[i] = new Bats;
		else if (type == 3)
			backup[i] = new Pit;
		else if (type == 4)
			backup[i] = new Gold;
		else
			backup[i] = new Empty;
	}
	/*
	for (int i =0; i < size*size ; i++){
		cout << backup[i]->encounter() << endl;
	}*/
}

/*********************************************************************
** Function: event_fill
** Description: fills in events for each room
** Parameters: N/A
** Pre-Conditions: create a hunt
** Post-Conditions: fills in events
*********************************************************************/ 

void Hunt::event_fill(){

	events = new Event*[size * size];
	events[0] = new Gold;
	events[1] = new Bats;
	events[2] = new Bats;
	events[3] = new Pit;
	events[4] = new Pit;
	events[5] = new Wumpus;
	for (int i = 6; i < size * size; i++){
		events[i] = new Empty;
	}
	/*for (int j = 0; j < size * size; j++){
		cout << "before shuffle" << (events[j])->encounter() << endl;
	}*/
	
	
	
	random_shuffle(&events[0], &events[size*size]);
	
	/*
	for (int i = 0; i < size * size; i++){
		cout << "after shuffle" << events[i]->encounter()<< endl;
	}*/
	
}

/*********************************************************************
** Function: ~Hunt()
** Description: destroys dynamically allocated memory
** Parameters: N/A
** Pre-Conditions: out of range
** Post-Conditions: deletes memeory
*********************************************************************/ 

Hunt::~Hunt(){
	/*for (int i = 0; i < size * size; i++){
		delete events[i];
		delete backup[i];	
	}*/
	delete [] events;
	delete [] backup;
	
}

/*********************************************************************
** Function: print_board
** Description: prints the board so player can see
** Parameters: N/A
** Pre-Conditions: each turn
** Post-Conditions: prints board
*********************************************************************/ 

void Hunt::print_board(){
	//cout << "printing board"<< endl;
	for (int i = 0; i < size; i++){
		for (int top = 0; top < size; top++){
			cout << "___";
		}
		
		cout << endl;
		
		for (int j = 0; j < size + 1; j++){
			if (i == row and j == col)
				cout << "|* ";
			else
				cout << "|  ";
		}	
		cout << endl;		
	}
	for (int top = 0; top < size; top++){
			cout << "___";
	}
	cout << endl;
}

/*********************************************************************
** Function: move_shoot
** Description: allows user to choose to move or shoot
** Parameters: N/A
** Pre-Conditions: each turn
** Post-Conditions: goes to one function or the other
*********************************************************************/ 

void Hunt::move_shoot(){
	bool still_going =1;
	int choice;
	while (still_going){
		cout << "Do you want to move (press 1) or shoot (press 2)?" << endl;
		cin >> choice;
		switch (choice){
			case 1:
				still_going = 0;
				move();
				break;
			case 2:
				still_going = 0;
				shoot();
				break;
			default:
				cout << "Invalid choice." << endl;	
				break;
		}
	}
}

/*********************************************************************
** Function: move
** Description: allows user to move on gameboard
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Hunt::move(){
	/*cout << "Where do you want to move?" << endl;
	
	cin >> choice;*/
	int choice;
	bool still_going = 1;
	while (still_going){
		cout << "Do you want to move up (press 1), down (press 2), left (press 3), or right (press 4)?" << endl; 
		cin >> choice;
		switch (choice){
			//cout << "got to switch cases" << endl;
			case 1:
				if (row == 0)
					cout << "You can't go any further tht way!" << endl;
				else {
					//cout << "got to else" << endl;
					still_going = 0;
					//cout << "got to still_going" << endl;
					gameboard[row][col].set_person(false);
					//cout << "got to set current false" << endl;
					row = row - 1;
					//cout << "got to decrementing" << endl;
					gameboard[row][col].set_person(true);
					//cout << "got to set new true" << endl;
					
				}
				break;
			case 2:
				if (row == size - 1)
					cout << "You can't go any further that way!" << endl;
				else {
					//cout << "got to else" << endl;
					still_going = 0;
					gameboard[row][col].set_person(false);
					row++;
					gameboard[row][col].set_person(true);
					
				}
				break;
			case 3:
				if (col == 0)
					cout << "You can't go any further tht way!" << endl;
				else {
					//cout << "got to else" << endl;
					still_going = 0;
					gameboard[row][col].set_person(0);
					col--;
					gameboard[row][col].set_person(1);
					
				}
				break;		
			case 4:
				if (col == size - 1)
					cout << "You can't go any further tht way!" << endl;
				else {
					//cout << "got to else" << endl;
					still_going = 0;
					gameboard[row][col].set_person(0);
					col++;
					gameboard[row][col].set_person(1);
						
				}
				break;		
			default:
				cout << "Invalid choice." << endl;	
				break;		
		}
	}
	
	check_encounter();
	check_percepts();
}

/*********************************************************************
** Function: shoot
** Description: shoots arrow
** Parameters: N/A
** Pre-Conditions: make choice
** Post-Conditions: shoots arrow
*********************************************************************/ 
void Hunt::shoot(){
	/*cout << "Where do you want to shoot?" << endl;
	
	cin >> choice;*/
	
	int choice;
	bool still_going = 1;
	while (still_going){
		cout << "Do you want to shoot up (press 1), down (press 2), left (press 3), or right (press 4)?" << endl; 
		arrow--;
		cin >> choice;
		//cout << choice << endl;
		//bool shot = 0;
		//int shot_row;
		//int shot_col;
		switch (choice){
			case 1:
				//cout << "case 1" << endl;
				if (row == 0)
					cout << "You can't go any further tht way!" << endl;
				else {
					still_going = 0;
					for (int i = row; i > -1; i--){ 
						int status = gameboard[i][col].check_encounter();
						if (status == 1){
							//shot = 1;	
							gameboard[i][col].set_empty();
							wum_dead = 1;
						}
					}
					cout << "we fired it" << endl;
					if (!wum_dead)
						miss();
				}
				break;
				
			case 2:
				if (row == size - 1)
					cout << "You can't go any further tht way!" << endl;
				else {
					still_going = 0;
					for (int i = row; i < size; i++){ 
						int status = gameboard[i][col].check_encounter();
						if (status == 1){
							//shot = 1;	
							gameboard[i][col].set_empty();
							wum_dead = 1;
						}
					}
					if (!wum_dead)
						miss();
				}
				break;
				
			case 3:
				if (col == 0)
					cout << "You can't go any further tht way!" << endl;
				else {
					still_going = 0;
					for (int i = col; i > -1; i--){ 
						int status = gameboard[row][i].check_encounter();
						if (status == 1){	
							gameboard[row][i].set_empty();
							wum_dead = 1;
						}
					}
					if (!wum_dead)
						miss();
				}
				break;
				
			case 4:
				if (col == size - 1)
					cout << "You can't go any further tht way!" << endl;
				else {
					still_going = 0;
					for (int i = col; i < size; i++){ 
						int status = gameboard[row][i].check_encounter();
						if (status == 1){
							//shot = 1;	
							gameboard[row][i].set_empty();
							wum_dead = 1;
						}
					}
					if (!wum_dead)
						miss();
				}
				break;		
				
			default:
				cout << "Invalid choice." << endl;	
				break;
		}
	}
	if (arrow == 0 && wum_dead == 0){
		cout << "You ran out of arrows! The Wumpus eats you!." << endl;
		alive = 0;
	}
}


/*********************************************************************
** Function: check_encounter
** Description: checks whats in the room
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: give event
*********************************************************************/ 

void Hunt::check_encounter(){
	int type = gameboard[row][col].check_encounter();
	switch(type){
		case 0:
			cout << "This room is empty." << endl;
			break;
			
		case 1:
			cout << "You walked into Wumpus's room! You got eaten!" << endl;
			alive = 0;
			break;
			
		case 2:
			cout << "You get carried off by a giant bat! (OR maybe you're just tiny?" << endl;
			bats();
			break;
			
		case 3:
			cout << "You fell down a pit deep enough to get to China." << endl;
			alive = 0;
			break;
			
		case 4:
			cout << "You found the gold! You can afford college now!" << endl;
			gold = 1;
			gameboard[row][col].set_empty();
			break;
			
		default:
			cout << "Something's wrong with the room's event." << endl;
			break;
	}
}

/*********************************************************************
** Function: bats
** Description: moves playter to random spot
** Parameters: N/A
** Pre-Conditions: go in bat room
** Post-Conditions: teleport
*********************************************************************/ 

void Hunt::bats(){
	gameboard[row][col].set_person(0);
	row = rand() % size;
	col = rand() % size;
	gameboard[row][col].set_person(1);
	//check_encounter();
}

/*********************************************************************
** Function: check percept
** Description: checks warnings of surrrounding rooms
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions:give warnings
*********************************************************************/ 

void Hunt::check_percepts(){
	string warn1 = "There is a wall nearby";
	string warn2 = "There is a wall nearby";
	string warn3 = "There is a wall nearby";
	string warn4 = "There is a wall nearby";
	cout << "__Warnings__" << endl;
	if (row > 0)
		warn1 = gameboard[row - 1][col].check_warnings();
	if (row < size - 1)
		warn2 = gameboard[row + 1][col].check_warnings();
	if (col > 0)	
		warn3 = gameboard[row][col - 1].check_warnings();
	if (col < size - 1)
		warn4 = gameboard[row][col + 1].check_warnings();
	
	cout << warn1 << endl << warn2 << endl << warn3 << endl << warn4 << endl;
}

/*********************************************************************
** Function: miss
** Description: miss arrow conditions
** Parameters: n/a
** Pre-Conditions: shoot and miss arrow
** Post-Conditions: wumpus moves or kills you
*********************************************************************/ 

void Hunt::miss(){
	cout << "You missed!" << endl;
	int wump_row;
	int wump_col;
	int chance = rand() % 4;
	if (chance == 0){
		cout << "You got killed because the Wumpus woke up." << endl;
		alive = 0;
	}
	else{
		//Shuffle the wumpus!
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++){
				int type = gameboard[i][j].check_encounter();
				if (type == 1)
					wump_row = i;
					wump_col = j;
			}			
		}	
		gameboard[wump_row][wump_col].set_event(new Empty);
		int still_going = 1;
		while (still_going == 1){
			//cout << "while boye" << endl;
			//sets wumpus's location
			int row1 = rand() % size;
			int col1 = rand() % size;
			int check =  gameboard[row1][col1].check_encounter();
			if (check == 0){
				gameboard[row1][col1].set_event(new Wumpus);
				still_going = 0;
			}
		}
	}
	
}

/*********************************************************************
** Function: status
** Description: checks if win or dead
** Parameters: n/a
** Pre-Conditions: move
** Post-Conditions: checks status
*********************************************************************/ 

int Hunt::status(){
	if (wum_dead == 1 && gold == 1 && row == esc_row && col == esc_col)
		return 1;
	else if (alive == 0)
		return 2;
	else 
		return 0;
}

/*********************************************************************
** Function: redo
** Description: starts from beginning
** Parameters: N/A
** Pre-Conditions: dead
** Post-Conditions: restarts game
*********************************************************************/ 

void Hunt::redo(){
	//1. Reset values
	arrow = 3;
	alive = 1;
	gold = 0;
	wum_dead = 0;
	//2.
	
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			gameboard[i][j].delete_event();
			gameboard[i][j].set_event(backup[i * size + j]);
		}
	}
	row = esc_row;
	col = esc_col;
}
