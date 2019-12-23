/*********************************************************************
** Program Filename: bats.cpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the bats implementation file
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Bats.hpp"
using namespace std;

/*********************************************************************
** Function: Bats()
** Description: sets values
** Parameters: N/A
** Pre-Conditions: create bat
** Post-Conditions: sets values
*********************************************************************/ 

Bats::Bats(){
	warning = "You hear wings flapping.";
	room_type = 2;
}

/*********************************************************************
** Function: percept
** Description: shows warnings
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns warning 
*********************************************************************/ 

string Bats::percept(){
	return warning;	
}

/*********************************************************************
** Function: encounter
** Description: events that happen when you get into a room
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns event type
*********************************************************************/ 

int Bats::encounter(){
	return room_type;
}