/*********************************************************************
** Program Filename: hunt.hpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: This is the header file for all the game's actions.
** Input: User choices, ints
** Output: Game map and actions
*********************************************************************/

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

#include "Room.hpp"
#include "Event.hpp"
#include "Wumpus.hpp"
#include "Bats.hpp"
#include "Pit.hpp"
#include "Gold.hpp"
#include "Empty.hpp"

using namespace std;

#ifndef HUNT_HPP
#define HUNT_HPP

class Hunt {
private:
	//int type;
	int size;
	int cave_info;
	int row;
	int col;
	vector <vector<Room> > gameboard;
	Event** events;
	Event** backup;
	int esc_row;
	int esc_col;
	int arrow;
	int wump_row;
	int wump_col;
	bool alive;
	bool wum_dead;
	bool gold;
	bool AI_playing;
	
public:
	Hunt(int);
	void event_fill();
	~Hunt();
	void fill_backup();
	void move_shoot();
	void print_board();
	void move();
	void shoot();
	void check_encounter();
	void bats();
	void check_percepts();
	void miss();
	int status();
	int lose(); //?
	int win(); //?
	void redo();
	
	
	//below are AI choices
	int AI_choice(int x);
	int AI_logic(string x);
};

#endif