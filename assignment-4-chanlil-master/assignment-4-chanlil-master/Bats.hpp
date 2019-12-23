/*********************************************************************
** Program Filename: bats.hpp
** Author: Lilian Chan
** Date: 3/2/2019
** Description: this is the bats header file
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef BATS_HPP
#define BATS_HPP
#include "Event.hpp"
#include <string>

using namespace std;

class Bats : public Event{
	public:
		Bats();
		string percept();
		int encounter();
};
	
#endif
