/*********************************************************************
** Program Filename: MazeLocation.hpp
** Author: Lilian Chan
** Date: 3/12/2019
** Description: This is the parent class for walls and openspace
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef MAZELOCATION_HPP
#define MAZELOCATION_HPP

class MazeLocation{
	protected:
		bool occupiable;
		char symbol;
		bool student;
		bool TA;
		bool instructor;
		bool ladder;
		bool skill;
		bool start;
	public:
		virtual bool is_occupiable() = 0;
		virtual char get_display_character() = 0;
		virtual void set_display_character(char) = 0;
		virtual void set_has_student(bool) = 0;
		virtual bool has_student() = 0;
		virtual void set_has_ta(bool) = 0;
		virtual bool has_ta() = 0;
		virtual void set_has_instructor(bool) = 0;
		virtual bool has_instructor() = 0;
		virtual void set_has_ladder(bool) = 0;
		virtual bool has_ladder() = 0;
		virtual void set_has_skill(bool) = 0;
		virtual bool has_skill() = 0;
		virtual void set_start(bool) = 0;
		virtual bool has_start() = 0;

	
};

#endif