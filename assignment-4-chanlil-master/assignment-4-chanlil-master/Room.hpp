/*********************************************************************
** Program Filename: Room.hpp
** Author: Lilian Chan
** Date: 3/1/2019
** Description: This is the room class, which is what the gameboard's 
made of.
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP
#include "string"
#include "Event.hpp"
#include "Empty.hpp"

using namespace std;

class Room{
private:
	bool person_here;
	Event* room_event;
	bool gold;
	bool wumpus;
	int option;
	
public:
	Room();
	~Room();
	Event* get_event(); 
	void set_empty();
	void set_event(Event *);
	bool is_person_here();
	void set_person(bool);
	bool is_gold_here();
	void set_gold(bool);
	bool is_wumpus_here();
	void set_wumpus(bool);
	void swap_events(Room);
	string check_warnings();
	int check_encounter();
	void delete_event();
};

#endif