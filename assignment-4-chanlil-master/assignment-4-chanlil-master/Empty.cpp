/*********************************************************************
** Program Filename: empty.cpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the empty implementation file
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Empty.hpp"
using namespace std;

/*********************************************************************
** Function: Empty()
** Description: sets values
** Parameters: N/A
** Pre-Conditions: create empty
** Post-Conditions: sets values
*********************************************************************/ 

Empty::Empty(){
	warning = "You smell an empty room.";
	room_type = 0;
}

/*********************************************************************
** Function: percept
** Description: shows warnings
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns warning 
*********************************************************************/ 

string Empty::percept(){
	return warning;	
}

/*********************************************************************
** Function: encounter
** Description: events that happen when you get into a room
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns event type
*********************************************************************/ 

int Empty::encounter(){
	return room_type;
}