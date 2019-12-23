/*********************************************************************
** Program Filename: Instructor.hpp
** Author: Lilian Chan
** Date: 3/15/19
** Description: This is the abstract class for instructor
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "MazePerson.hpp"

class Instructor : public MazePerson {
public:
	Instructor();
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