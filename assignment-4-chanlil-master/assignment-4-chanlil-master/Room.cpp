/*********************************************************************
** Program Filename: Room.cpp
** Author: Lilian Chan
** Date: 3/1/2019
** Description: This is the implementation file for room
** Input: N/A
** Output: N/A
*********************************************************************/

#include "Room.hpp"
#include <iostream>

using namespace std;


/*********************************************************************
** Function: Room()
** Description: Fills in room values
** Parameters: N/A
** Pre-Conditions: Create a room
** Post-Conditions: fills in values
*********************************************************************/ 
Room::Room(){
	person_here = 0;
	room_event = NULL;
	gold = 0;
	wumpus = 0;
	option = 0;
}

/*********************************************************************
** Function:~Room()
** Description: Destroys all dynamic memeory
** Parameters: N/A
** Pre-Conditions: Go out of bounds
** Post-Conditions: Destroy dynamically allocated memeory
*********************************************************************/ 
Room::~Room(){
	delete room_event;
}

/*********************************************************************
** Function: get_event
** Description: returns the event pointer
** Parameters: N/A
** Pre-Conditions: accessing an event 
** Post-Conditions: returns the pointer
*********************************************************************/ 

Event* Room::get_event(){
	return room_event;
}

/*********************************************************************
** Function: set_event
** Description: this sets the room's event
** Parameters: Event *
** Pre-Conditions: Make map and swapping
** Post-Conditions: set event
*********************************************************************/ 
	
void Room::set_event(Event* new_event){
	
	room_event = new_event;
}

/*********************************************************************
** Function: is_person_here
** Description: This checks if room has person
** Parameters: N/A
** Pre-Conditions: print map
** Post-Conditions: returns bool
*********************************************************************/ 

bool Room::is_person_here(){
	return person_here;	
}

/*********************************************************************
** Function: set_person
** Description: sets person
** Parameters: bool
** Pre-Conditions: when moving
** Post-Conditions: changes location
*********************************************************************/ 

void Room::set_person(bool status){
	//cout << "got to beginning of set person" << endl;
	person_here = status;
	//cout << "got to end of set person" << endl;
}

/*********************************************************************
** Function: is_gold_here
** Description: This checks if room has gold
** Parameters: N/A
** Pre-Conditions: print map
** Post-Conditions: returns bool
*********************************************************************/ 

bool Room::is_gold_here(){
	return gold;	
}

/*********************************************************************
** Function: set_gold
** Description: sets gold
** Parameters: bool
** Pre-Conditions: when making map
** Post-Conditions: sets gold
*********************************************************************/ 

void Room::set_gold(bool status){
	gold = status;
}

/*********************************************************************
** Function: is_wumpus_here
** Description: This checks if room has wumpus
** Parameters: N/A
** Pre-Conditions: go into room
** Post-Conditions: returns bool
*********************************************************************/ 

bool Room::is_wumpus_here(){
	return wumpus;	
}

/*********************************************************************
** Function: set_wumpus
** Description: sets wumpus 
** Parameters: bool
** Pre-Conditions: when awake or making map
** Post-Conditions: sets wumpus
*********************************************************************/ 

void Room::set_wumpus(bool status){
	wumpus = status;
}

/*********************************************************************
** Function: set_empty
** Description: sets empty
** Parameters: N/A
** Pre-Conditions: when killed wumpus or get gold
** Post-Conditions: sets empty
*********************************************************************/ 

void Room::set_empty(){
	delete room_event;
	room_event = new Empty;
}

/*********************************************************************
** Function: swap_event
** Description: This swaps the events of two of teh rooms
** Parameters: Room
** Pre-Conditions: If wumpus moves
** Post-Conditions: Swaps events
*********************************************************************/ 

void Room::swap_events(Room other){
	Event * temp = other.get_event();
	other.set_event(room_event);
	room_event = temp;
}

/*********************************************************************
** Function: check warnings
** Description: this checks warnings of adjacent rooms
** Parameters: N/A
** Pre-Conditions: move to new room
** Post-Conditions: returns warnings
*********************************************************************/ 

string Room::check_warnings(){
	return room_event->percept();
}

/*********************************************************************
** Function: check_encounter
** Description: checks event in room
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns event
*********************************************************************/ 

int Room::check_encounter(){
	return room_event->encounter();	
}

/*********************************************************************
** Function: delete_event
** Description: delete event
** Parameters: reset
** Pre-Conditions: when killed
** Post-Conditions: deletes
*********************************************************************/ 

void Room::delete_event(){
	delete room_event;
}