/*********************************************************************
** Program Filename: IntrepidStudent.hpp
** Author: Lilian Chan
** Date: 3/15/19
** Description: This is the abstract class for IntrepidStudent
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef INTREPIDSTUDENT_HPP
#define INTREPIDSTUDENT_HPP

#include "MazePerson.hpp"

class IntrepidStudent : public MazePerson {
public:
	IntrepidStudent();
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