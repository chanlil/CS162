/*********************************************************************
** Program Filename: IntrepidStudent.hpp
** Author: Lilian Chan
** Date: 3/15/19
** Description: This is the implementation class for IntrepidStudent
** Input: int
** Output: options to choose a move
*********************************************************************/

#include "IntrepidStudent.hpp"
#include <iostream>
using namespace std;

/*********************************************************************
** Function: IntrepidStudent
** Description: constructor that sets up values
** Parameters: N/A
** Pre-Conditions: when making the object
** Post-Conditions: initializes values
*********************************************************************/ 

IntrepidStudent::IntrepidStudent(){
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

char IntrepidStudent::get_move(){
	bool still_going = 1;
	while (still_going){
		char choice;
		cout << "Press ‘W’ to move up,  ‘A’ to move left, ‘S’ to move down,"
			<< " ‘D’to move right, ‘P’ to demonstrate programming skills " 
				<< "and ‘U’ to climb a ladder." << endl;
		cin >> choice;
		choice = toupper (choice);
		if (choice == 'W' or choice == 'A' or choice == 'S' 
			or choice == 'D' or choice == 'P' or choice == 'U'){
			still_going = 0;
			return choice;
		}
		else	
			cout << "Invalid option" << endl;
	}	
}
	
/*********************************************************************
** Function: set_location
** Description: sets the location of the person
** Parameters: 2 ints
** Pre-Conditions: after every move
** Post-Conditions: sets a new location
*********************************************************************/ 
	
void IntrepidStudent::set_location(int x, int y){
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
	
int IntrepidStudent::get_row(){
	return row;
}
	
/*********************************************************************
** Function: get_col
** Description: gets the col of the person
** Parameters: N/A
** Pre-Conditions: when interacting with other persons or objects
** Post-Conditions: returns col
*************************** ******************************************/ 
	
int IntrepidStudent::get_col(){
	return col;
}
	
