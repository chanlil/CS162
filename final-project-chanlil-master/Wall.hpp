/*********************************************************************
** Program Filename: Wall.hpp
** Author: Lilian Chan
** Date: 3/12/2019
** Description: This is the header file for Wall
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef WALL_HPP
#define WALL_HPP
#include "MazeLocation.hpp"

class Wall : public MazeLocation {
	public: 
		Wall();
		bool is_occupiable();
		char get_display_character();
		void set_display_character(char);
		void set_has_student(bool);
		bool has_student();
		void set_has_ta(bool);
		bool has_ta();
		void set_has_instructor(bool);
		bool has_instructor();
		void set_has_ladder(bool);
		bool has_ladder();
		void set_has_skill(bool);
		bool has_skill();
		void set_start(bool);
		bool has_start();
};

#endif