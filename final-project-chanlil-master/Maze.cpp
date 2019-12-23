/*********************************************************************
** Program Filename: Maze.cpp
** Author: Lilian Chan
** Date: 3/16/2019
** Description: This is the implementation file for Maze
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Maze.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MazeLevel.hpp"
#include "MazePerson.hpp"
#include "IntrepidStudent.hpp"
#include "TA.hpp"
#include "Instructor.hpp"

using namespace std;

/*********************************************************************
** Function: Maze()
** Description: fills in default values for maze
** Parameters: ifstream& file
** Pre-Conditions: make the object
** Post-Conditions: fills in default values 
*********************************************************************/ 

Maze::Maze(ifstream& file){
	//cout << "Constructor called." << endl;
	srand (time(NULL));
	grade = 0; //still playing
	skills = 0;
	appease = 15; //random number above 10
	file >> level;
	file >> row;
	file >> col;
	
	current_floor = 0;
	stu = new IntrepidStudent;
	TA_1 = new TA;
	TA_2 = new TA;
	ins = new Instructor;
	whole_maze = new MazeLevel * [level];
	for (int i = 0; i < level; i++)
	{
		//cout << "Initalizing level " << i << " of " << level-1 << endl;
		whole_maze[i] = new MazeLevel(file, row, col);
	}
	randomize();
	//cout << "Level contents randomized" << endl;
	play_row = whole_maze[0] -> get_start_row();
	play_col = whole_maze[0] -> get_start_col();
	//cout << "play_row is " << play_row << ", play col is " << play_col << endl;
	MazeLocation* m1 = whole_maze[current_floor] -> get_location(play_row, play_col);
	m1 -> set_has_student(1);
	//cout << "Constructor exiting." << endl;
}

/*********************************************************************
** Function: ~Maze
** Description: deletes all dynamic memory
** Parameters: N/A
** Pre-Conditions: out of bounds or deleted
** Post-Conditions: delete dynamic memory
*********************************************************************/ 

Maze::~Maze(){
	delete stu;
	delete TA_1;
	delete TA_2;
	delete ins;
	for (int i = 0; i < level; i++)
		delete whole_maze[i];
	delete [] whole_maze;
}

/*********************************************************************
** Function: randomize
** Description: randomizes TAs and skills
** Parameters: N/A
** Pre-Conditions: go to new floor
** Post-Conditions: sets TAs and skills at random locations
*********************************************************************/ 

void Maze::randomize(){
	appease = 15; //random number above 10
	bool still_going = 1;
	
	while (still_going){
		int r1 = rand() % row;
		int c1 = rand() % col;
		MazeLocation* m1 = whole_maze[current_floor] -> get_location(r1, c1);
		char type1 = m1 -> get_display_character();
		if (type1 == ' '){
			m1 -> set_has_ta(1);
			TA_1_row = r1;
			TA_1_col = c1;
			still_going = 0;
		}
	}
		
	still_going = 1;	
	
	while (still_going){
		int r1 = rand() % row;
		int c1 = rand() % col;
		MazeLocation* m1 = whole_maze[current_floor] -> get_location(r1, c1);
		char type1 = m1 -> get_display_character();
		if (type1 == ' '){
			m1 -> set_has_ta(1);
			TA_2_row = r1;
			TA_2_col = c1;
			still_going = 0;
		}
	}
		
	still_going = 1;	
		
	while (still_going){
		int r1 = rand() % row;
		int c1 = rand() % col;
		MazeLocation* m1 = whole_maze[current_floor] -> get_location(r1, c1);
		char type1 = m1 -> get_display_character();
		if (type1 == ' '){
			m1 -> set_has_skill(1);
			skill_1_row = r1;
			skill_1_col = c1;
			still_going = 0;
		}
	}
		
	still_going = 1;	
			
	while (still_going){
		int r1 = rand() % row;
		int c1 = rand() % col;
		MazeLocation* m1 = whole_maze[current_floor] -> get_location(r1, c1);
		char type1 = m1 -> get_display_character();
		if (type1 == ' '){
			m1 -> set_has_skill(1);
			skill_2_row = r1;
			skill_2_col = c1;
			still_going = 0;
		}
	}
	
	still_going = 1;
	
	while (still_going){
		int r1 = rand() % row;
		int c1 = rand() % col;
		MazeLocation* m1 = whole_maze[current_floor] -> get_location(r1, c1);
		char type1 = m1 -> get_display_character();
		if (type1 == ' '){
			m1 -> set_has_skill(1);
			skill_3_row = r1;
			skill_3_col = c1;
			still_going = 0;
		}
	}
}

/*********************************************************************
** Function: reset_level
** Description: resets the level when the TA does their thing
** Parameters: N/A
** Pre-Conditions: TA makes players lose all their skills
** Post-Conditions: resets the level
*********************************************************************/ 

void Maze::reset_level(){
	cout << "Restarting Level" << endl;
	appease = 15; //random number above 10
	//reset skills
	skills = 0;
	//set current location to 0
	MazeLocation* m1 = whole_maze[current_floor] -> get_location(play_row, play_col);
	m1 -> set_has_student(0);
	//put player at beginning
	play_row = whole_maze[current_floor] -> get_start_row();
	play_col = whole_maze[current_floor] -> get_start_col();
	m1 = whole_maze[current_floor] -> get_location(play_row, play_col);
	m1 -> set_has_student(1);
	//check and reset skills and TAs
	for (int i = 0; i < row; i++){
		//cout << "Wiping row " << i << endl;
		for (int j = 0; j < col; j++){
			//cout << "Wiping col " << j << endl;
			MazeLocation* m2 = whole_maze[current_floor] -> get_location(i, j);
			bool skill_square = m2 -> has_skill();
			bool ta_square = m2 -> has_ta();
			if (skill_square){
				m2 -> set_has_skill(0);
			}
			
			if (ta_square){
				m2 -> set_has_ta(0);
			}
			
			
				
		}
	}
	randomize();
	cout << "Try again!" << endl;
}

/*********************************************************************
** Function: move_up_level
** Description: moves level
** Parameters: N/A
** Pre-Conditions: when climbing up a ladder
** Post-Conditions: makes the player advance to the next level
*********************************************************************/ 

void Maze::move_up_level(){
	current_floor++;
	randomize();
	appease = 15; //random number above 10
	MazeLocation* m1 = whole_maze[current_floor] -> get_location(play_row, play_col);
	play_row = whole_maze[current_floor] -> get_start_row();
	play_col = whole_maze[current_floor] -> get_start_col();
	m1 = whole_maze[current_floor] -> get_location(play_row, play_col);
	m1 -> set_has_student(1);
}


/*********************************************************************
** Function: display
** Description: displays current level
** Parameters: N/A
** Pre-Conditions: each turn
** Post-Conditions: couts a map 
*********************************************************************/ 

void Maze::display(){
	whole_maze[current_floor] -> display();
}

/*********************************************************************
** Function: transpose_stu_cardinal
** Description: Move student actor into one of four adjacent tiles
** Parameters: x; amount by which to displace in rows
**             y; amount by which to displace in columns
** Pre-Conditions: Must be valid move
** Post-Conditions: moves player, returns success or fail
*********************************************************************/
int Maze::transpose_stu_cardinal(int x, int y)
{
	//cout << "Test 1" << endl;
	int x_dest = play_row + x;
	int y_dest = play_col + y;
	if(x_dest < row && x_dest >=0 && y_dest < col && y_dest >= 0)
	{
		//cout << "Test 2" << endl;
		MazeLocation* destination = whole_maze[current_floor] -> get_location(x_dest, y_dest);
		char spot_to_move_to = destination -> get_display_character();
		//cout << "Test 3" << endl;
		if(spot_to_move_to != '#')
		{
			MazeLocation* source = whole_maze[current_floor] -> get_location(play_row, play_col);
			source->set_has_student(0);
			play_row = x_dest;
			play_col = y_dest;
			destination -> set_has_student(1);
			return 0;
		}
	}
	return 1;
}


/*********************************************************************
** Function: move_stu
** Description: allows student to choose a move
** Parameters: N/A
** Pre-Conditions: each turn
** Post-Conditions: moves player
*********************************************************************/ 

void Maze::move_stu(){
	increment_appease();
	bool still_going = 1;
	char choice; 
	while (still_going){
		choice = stu -> get_move();	
	
		cout << "the choice is " << choice << endl;	
		switch(choice){	
			case 'W':
				still_going = transpose_stu_cardinal(-1,0);
				break;
			
			case 'A': 	
				still_going = transpose_stu_cardinal(0,-1);
				break;
	
		
			case 'S':
				still_going = transpose_stu_cardinal(1,0);
				break;
	
	
			case 'D': 
				still_going = transpose_stu_cardinal(0,1);
				/*cout << "got to choice d" << endl;
				if (play_col != col - 1){
					MazeLocation* m1 = whole_maze[current_floor] 
						-> get_location(play_row, play_col - 1);
						cout << "got to getting m1" << endl;
					char spot_to_move_to = m1 -> get_display_character();
					cout << "got to getting display char" << endl;
					if (spot_to_move_to != '#'){
						cout << "setting ne locations" << endl;
						m1 = whole_maze[current_floor] 
							-> get_location(play_row, play_col);
						m1 -> set_has_student(0);
						play_col++; 
						cout << "setting truw at new location" << endl;
						m1 = whole_maze[current_floor] 
							-> get_location(play_row, play_col);
						m1 -> set_has_student(1);
						still_going = 0;
					}
				}*/
				break;
			
	
			case 'P': {
				if (skills > 0){
					appease_reset();
					still_going = 0;
				}
				else {
					cout << "You have no skills! Choose again." << endl;
				}
				break;
			}
	
			case 'U': {
				MazeLocation* m1 = whole_maze[current_floor] 
					-> get_location(play_row, play_col);
				bool can_go_up = m1 -> 	has_ladder();
				if (can_go_up){
					move_up_level();
					still_going = 0;
				}	
				break;
			}	
		
			default: {
				cout << "There's an error. Please choose again." << endl;
				break;
			}	
		}	
	}
}

/*********************************************************************
** Function: TA_moving
** Description: moves both TAs
** Parameters: N/A
** Pre-Conditions: each turn
** Post-Conditions: moves each TA
*********************************************************************/ 

void Maze::TAs_moving(){
	
	move_TA(TA_1, 1);
	move_TA(TA_2, 2);
}

/*********************************************************************
** Function: move_TA
** Description: moves each TA
** Parameters: N/A
** Pre-Conditions: called by TA_moving
** Post-Conditions: moves a TA
*********************************************************************/ 

void Maze::move_TA(TA * moving_ta, int num){
	bool still_going = 1;
	int * TA_row;
	int * TA_col;
	if (num == 1){
		TA_row = & TA_1_row;
		TA_col = & TA_1_col;
	}
	else {
		TA_row = & TA_2_row;
		TA_col = & TA_2_col;
	}
	while (still_going){
		char choice = moving_ta -> get_move();	
	
		if (choice == 'W'){
			if (*TA_row != 0){
				MazeLocation* m1 = whole_maze[current_floor] 
					-> get_location(*TA_row - 1, *TA_col);
				char spot_to_move_to = m1 -> get_display_character();
				if (spot_to_move_to != '#'){
					m1 = whole_maze[current_floor] 
						-> get_location(*TA_row, *TA_col);
					m1 -> set_has_ta(0);
					(*TA_row)--; 
					m1 = whole_maze[current_floor] 
						-> get_location(*TA_row, *TA_col);
					m1 -> set_has_ta(1);
					still_going = 0;
				}
			}
		}
	
		else if (choice == 'A'){
			if (*TA_col != 0){
				MazeLocation* m1 = whole_maze[current_floor] 
					-> get_location(*TA_row, *TA_col - 1);
				char spot_to_move_to = m1 -> get_display_character();
				if (spot_to_move_to != '#'){
					m1 = whole_maze[current_floor] 
						-> get_location(*TA_row, *TA_col);
					m1 -> set_has_ta(0);
					(*TA_col)--; 
					m1 = whole_maze[current_floor] 
						-> get_location(*TA_row, *TA_col);
					m1 -> set_has_ta(1);
					still_going = 0;
				}
			}
		}
	
		
		else if (choice == 'S'){
			if (*TA_row != row - 1){
				MazeLocation* m1 = whole_maze[current_floor] 
					-> get_location(*TA_row + 1, *TA_col);
				char spot_to_move_to = m1 -> get_display_character();
				if (spot_to_move_to != '#'){
					m1 = whole_maze[current_floor] 
						-> get_location(*TA_row, *TA_col);
					m1 -> set_has_ta(0);
					(*TA_row)++; 
					m1 = whole_maze[current_floor] 
						-> get_location(*TA_row, *TA_col);
					m1 -> set_has_ta(1);
					still_going = 0;
				}
			}
		}
	
	
		else if (choice == 'D'){
			if (*TA_col != col - 1){
				MazeLocation* m1 = whole_maze[current_floor] 
					-> get_location(*TA_row, *TA_col - 1);
				char spot_to_move_to = m1 -> get_display_character();
				if (spot_to_move_to != '#'){
					m1 = whole_maze[current_floor] 
						-> get_location(*TA_row, *TA_col);
					m1 -> set_has_ta(0);
					(*TA_col)++; 
					m1 = whole_maze[current_floor] 
						-> get_location(*TA_row, *TA_col);
					m1 -> set_has_ta(1);
					still_going = 0;
				}
			}
		}
	}
}

/*********************************************************************
** Function: check_surroundings
** Description: check student's surroundings
** Parameters: N/A
** Pre-Conditions: checks squares adjacent to student and on student square
** Post-Conditions: sends to different fucntions if things encountered
*********************************************************************/ 

void Maze::check_surroundings(){
	bool TA_near = 0;
	bool instructor_near = 0;
	
	//check spot player is in
	MazeLocation* m1 = whole_maze[current_floor] 
		-> get_location(play_row, play_col);
	bool is_ta_near = m1 -> has_ta();
	bool is_instructor_here = m1 -> has_instructor();
	bool is_skill_here = m1 -> has_skill();
		
	if (is_ta_near){
		TA_near = 1;
	}
	
	if (is_instructor_here){
		instructor_near = 1;
	}
	
	if (is_skill_here){
		skills++;
		m1 -> set_has_skill(0);
		cout << "Skill acquired! Total: " << skills << endl;
	}
		
	//check spot above
	if (play_row != 0){
		m1 = whole_maze[current_floor] 
			-> get_location(play_row - 1, play_col);
		is_ta_near = m1 -> has_ta();
		is_instructor_here = m1 -> has_instructor();
		
		if (is_ta_near){
			TA_near = 1;
		}
	
		if (is_instructor_here){
			instructor_near = 1;
		}
	}
	
	//check spot below
	if (play_row != row - 1){
		m1 = whole_maze[current_floor] 
			-> get_location(play_row + 1, play_col);
		is_ta_near = m1 -> has_ta();
		is_instructor_here = m1 -> has_instructor();
	
		if (is_ta_near){
			TA_near = 1;
		}
	
		if (is_instructor_here){
			instructor_near = 1;
		}
	}
	
	//check spot left
	if (play_col != 0){
		m1 = whole_maze[current_floor] 
			-> get_location(play_row, play_col - 1);
		is_ta_near = m1 -> has_ta();
		is_instructor_here = m1 -> has_instructor();
	
		if (is_ta_near){
			TA_near = 1;
		}
	
		if (is_instructor_here){
			instructor_near = 1;
		}
	}
	
	//check spot right
	if (play_col != col - 1){
		m1 = whole_maze[current_floor] 
			-> get_location(play_row, play_col + 1);
		is_ta_near = m1 -> has_ta();
		is_instructor_here = m1 -> has_instructor();
	
		if (is_ta_near){
			TA_near = 1;
		}
	
		if (is_instructor_here){
			instructor_near = 1;
		}
	}
	
	//uses info to send student to correct function
	if (instructor_near){
		instructor_encounter();
	}
	
	if (TA_near){
		TA_encounter();
	}
}

/*********************************************************************
** Function: TA_encounter 
** Description: Checks if TA is appeased. If not, level resets.
** Parameters: N/A
** Pre-Conditions: TA near
** Post-Conditions: level resets if requirements not met
*********************************************************************/ 

void Maze::TA_encounter(){
	if (appease >= 10){
		cout << "The wild TA attacked!" << endl;
		reset_level();
	}
	else {
		cout << "The TA ignores you because they have better things to do."
			<< endl;
	}
}

/*********************************************************************
** Function: instructor_encounter
** Description: checks skills, returns grade
** Parameters: N/A
** Pre-Conditions: go near instructor
** Post-Conditions: returns grade and win/lose
*********************************************************************/ 

void Maze::instructor_encounter(){
	if (skills > 2){
		grade = 1;
		cout << "You did well, young Padawan." << endl;
	}
	else {
		grade = 2;
		cout << "Everyone's dissapointed in you." << endl;
	}
}

/*********************************************************************
** Function: return_grade
** Description: determines the student's grade
** Parameters: N/A
** Pre-Conditions: after every turn
** Post-Conditions: depending on whether class is still in progress, 
the student passed, or failed, it will return a different int.
*********************************************************************/ 

int Maze::return_grade(){
	return grade;
}

/*********************************************************************
** Function: increment_appease
** Description: increment appease
** Parameters: N/A
** Pre-Conditions: every turn
** Post-Conditions: increment appease
*********************************************************************/ 

void Maze::increment_appease(){
	appease++;
}

/*********************************************************************
** Function: appease_reset
** Description: when appease gets renewed
** Parameters: N/A
** Pre-Conditions: press 'P'
** Post-Conditions: resets the counter
*********************************************************************/ 

void Maze::appease_reset(){
	appease = 0;
	skills--;
}

