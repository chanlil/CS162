/*********************************************************************
** Program Filename: MazeLevel.cpp
** Author: Lilian Chan
** Date: 3/15/2019
** Description: this is the implementation file for mazelevel
** Input: N/A
** Output: N/A
*********************************************************************/

#include <iostream>
#include <fstream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <vector>
#include "MazeLevel.hpp"
#include "MazeLocation.hpp"
using namespace std;

/*********************************************************************
** Function: MazeLevel()
** Description: constructor for maze
** Parameters:ifstream& file, int rowz, int colz
** Pre-Conditions: create MazeLevel
** Post-Conditions: creates the maze from data given
*********************************************************************/ 

MazeLevel::MazeLevel(ifstream& file, int rowz, int colz){
	srand (time(NULL));
	rows = rowz;
	cols = colz;
	//fill in 2d vector
	for (int i = 0; i < rows; i++){
		vector<MazeLocation*>row;
		for (int j = 0; j < cols; j++){
			MazeLocation* m;
			row.push_back(m);
		}
		locations.push_back(row);
	}
	
	fill(file);
}

/*********************************************************************
** Function: fill
** Description: fills maze with file data
** Parameters: ifstream& file
** Pre-Conditions: create MazeLevel
** Post-Conditions: creates the maze from data given
*********************************************************************/ 

void MazeLevel::fill(ifstream& file){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			char loca_type;
			file.get(loca_type);
			if (loca_type == ' '){
				locations[i][j] = new OpenSpace;
			}	
			
			else if (loca_type == '@'){
				locations[i][j] = new OpenSpace;
				locations[i][j] -> set_start(1);
				locations[i][j] -> set_has_student(1);
				//rows == i;
				//cols == j;
				start_row = i;
				start_col = j;
			}	
			
			else if (loca_type == '^'){
				locations[i][j] = new OpenSpace;
				locations[i][j] -> set_has_ladder(1);
			}
			
			else if (loca_type == '%'){
				locations[i][j] = new OpenSpace;
				locations[i][j] -> set_has_instructor(1);
			}
			
			else if (loca_type == '#'){
				locations[i][j] = new Wall;
			}
			
			else{
				j = j - 1;
			}
			
			if (file.eof())
				return;
		}
		//cout << endl;
	}
}


/*********************************************************************
** Function: ~MazeLevel()
** Description: destroys dynamically allocated memory
** Parameters: N/A
** Pre-Conditions: go out of bounds or destroy
** Post-Conditions: deletes dynamically allocated memory
*********************************************************************/ 

MazeLevel::~MazeLevel(){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			delete locations[i][j];
		}
	}
}

/*********************************************************************
** Function: get_location
** Description: returns MazeLocation pointer
** Parameters: 2 ints
** Pre-Conditions: when player moves or TA moves
** Post-Conditions: returns pointer 
*********************************************************************/ 

MazeLocation* MazeLevel::get_location(int row_num, int col_num){
	return locations[row_num][col_num];
}

/*********************************************************************
** Function: start_row
** Description: returns starting point
** Parameters: N/A
** Pre-Conditions: new floor
** Post-Conditions: returns starting row
*********************************************************************/ 

int MazeLevel::get_start_row(){
	return start_row;
}

/*********************************************************************
** Function: start_col
** Description: returns starting point
** Parameters: N/A
** Pre-Conditions: new floor
** Post-Conditions: returns starting col
*********************************************************************/ 

int MazeLevel::get_start_col(){
	return start_col;
}

/*********************************************************************
** Function: display
** Description: displays maze
** Parameters: N/A
** Pre-Conditions: every turn
** Post-Conditions: displays maze
*********************************************************************/ 

void MazeLevel::display(){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			char rep = locations[i][j] -> get_display_character();
			cout << rep;
		}
		cout << endl;
	}		
}

