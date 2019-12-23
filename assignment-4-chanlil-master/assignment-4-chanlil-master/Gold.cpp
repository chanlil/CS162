/*********************************************************************
** Program Filename: gold.cpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the gold implementation file
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Gold.hpp"
//#include <iostream>
using namespace std;

/*********************************************************************
** Function: Gold()
** Description: sets values
** Parameters: N/A
** Pre-Conditions: create gold
** Post-Conditions: sets values
*********************************************************************/ 

Gold::Gold(){
	warning = "You see a glimmer nearby.";
	room_type = 4;
	//cout << "Gold constructor called" << endl;
}


/*********************************************************************
** Function: percept
** Description: shows warnings
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns warning 
*********************************************************************/ 

string Gold::percept(){
	return warning;	
}

/*********************************************************************
** Function: encounter
** Description: events that happen when you get into a room
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns event type
*********************************************************************/ 

int Gold::encounter(){
	return room_type;
}