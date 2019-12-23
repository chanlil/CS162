/*********************************************************************
** Program Filename: TA.hpp
** Author: Lilian Chan
** Date: 3/15/19
** Description: This is the abstract class for TA
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef TA_HPP
#define TA_HPP

#include "MazePerson.hpp"

class TA : public MazePerson {
public:
	TA();
	char get_move();
	void set_location(int, int);
	int get_row();
	int get_col();
	//void reset_skills();
	//void increment_skills();
	//int get_skills();
	//bool check_grade(int);
};

#endif