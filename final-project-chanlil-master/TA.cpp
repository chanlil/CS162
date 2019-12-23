/*********************************************************************
** Program Filename: Instructor.hpp
** Author: Lilian Chan
** Date: 3/15/19
** Description: This is the implementation class for instructor
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Instructor.hpp"
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>   
#include <time.h> 
using namespace std;

/*********************************************************************
** Function: TA
** Description: constructor that sets up values
** Parameters: N/A
** Pre-Conditions: when making the object
** Post-Conditions: initializes values
*********************************************************************/ 

Instructor::Instructor(){
	srand (time(NULL));
	row = 1;
	col = 1;
}

/*********************************************************************
** Function: get_move 
** Description: gets the direction character wants to go
** Parameters: N/A
** Pre-Conditions: every turn
** Post-Conditions: returns direction
*********************************************************************/ 

char Instructor::get_move(){ //never used
	int choice = rand() % 4;   
	switch (choice){
		case 0:
			return 'W';
			break;
		case 1:
			return 'S';
			break;
		case 2:
			return 'A';
			break;
		case 3:
			return 'D';
			break;
		default:
			cout << "This is the default move" << endl;
			return 'W';
			break;
	}		
}
	
/*********************************************************************
** Function: set_location
** Description: sets the location of the person
** Parameters: 2 ints
** Pre-Conditions: after every move
** Post-Conditions: sets a new location
*********************************************************************/ 
	
void Instructor::set_location(int x, int y){
	row = x;
	col = y;
}
	
/*********************************************************************
** Function: get_row
** Description: gets the row of the person
** Parameters: N/A
** Pre-Conditions: when interacting with other persons or objects
** Post-Conditions: returns row
*************************** ******************************************/ 
	
int Instructor::get_row(){
	return row;
}
	
/*********************************************************************
** Function: get_col
** Description: gets the col of the person
** Parameters: N/A
** Pre-Conditions: when interacting with other persons or objects
** Post-Conditions: returns col
*************************** ******************************************/ 
	
int Instructor::get_col(){
	return col;
}
	
