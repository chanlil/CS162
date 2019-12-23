/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the wumpus implementation file
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Wumpus.hpp"
using namespace std;

/*********************************************************************
** Function: Wumpus
** Description: sets values
** Parameters: N/A
** Pre-Conditions: create wumpus
** Post-Conditions: sets values
*********************************************************************/ 

Wumpus::Wumpus(){
	warning = "You smell a terrible stench.";
	room_type = 1;
}

/*********************************************************************
** Function: percept
** Description: shows warnings
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns warning 
*********************************************************************/ 

string Wumpus::percept(){
	return warning;	
}

/*********************************************************************
** Function: encounter
** Description: events that happen when you get into a room
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns event type
*********************************************************************/ 

int Wumpus::encounter(){
	return room_type;
}