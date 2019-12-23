/*********************************************************************
** Program Filename: MazePerson.hpp
** Author: Lilian Chan
** Date: 3/15/19
** Description: This is the abstract class for all MazePersons
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef MAZEPERSON_HPP
#define MAZEPERSON_HPP

class MazePerson {
protected:
	int row;
	int col;
	//int skills;
public:
	virtual char get_move() = 0;
	virtual void set_location(int, int) = 0;
	virtual int get_row() = 0;
	virtual int get_col() = 0;
	//virtual void reset_skills() = 0;
	//virtual void increment_skills() = 0;
	//virtual int get_skills() = 0;
	//virtual bool check_grade(int) = 0;
};

#endif