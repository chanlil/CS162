/*********************************************************************
** Program Filename: pit.cpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the pit implementation file
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Pit.hpp"
using namespace std;

/*********************************************************************
** Function: Pit()
** Description: sets values
** Parameters: N/A
** Pre-Conditions: create pit
** Post-Conditions: sets values
*********************************************************************/ 

Pit::Pit(){
	warning = "You feel a breeze.";
	room_type = 3;
}

/*********************************************************************
** Function: percept
** Description: shows warnings
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns warning 
*********************************************************************/ 

string Pit::percept(){
	return warning;	
}

/*********************************************************************
** Function: encounter
** Description: events that happen when you get into a room
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns event type
*********************************************************************/ 

int Pit::encounter(){
	return room_type;
}