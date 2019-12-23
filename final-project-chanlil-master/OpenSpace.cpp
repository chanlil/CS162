/*********************************************************************
** Program Filename: OpenSpace.cpp
** Author: Lilian Chan
** Date: 3/12/2019
** Description: This is the implementation file for OpenSpace
** Input: N/A
** Output: N/A
*********************************************************************/

#include "OpenSpace.hpp"

/*********************************************************************
** Function: OpenSpace();
** Description: The constructor that sets up the variables
** Parameters: N/A
** Pre-Conditions: create the object
** Post-Conditions: fills in values
*********************************************************************/ 

OpenSpace::OpenSpace(){
	occupiable = 1;
	symbol = ' ';
	student = 0;
	TA = 0;
	instructor = 0;
	ladder = 0;
	skill = 0;
	start = 0;
}	

/*********************************************************************
** Function: bool is_occupiable();
** Description: returns if spot is occupiable 
** Parameters: N/A
** Pre-Conditions: when moving
** Post-Conditions: checks if student can move there
*********************************************************************/ 

bool OpenSpace::is_occupiable(){
	return occupiable;
}

/*********************************************************************
** Function: char get_display_character();
** Description: gets the character the spot is represented by
** Parameters: N/A
** Pre-Conditions: display map
** Post-Conditions: returns appropriate symbol
*********************************************************************/ 

char OpenSpace::get_display_character(){
	if (start == true)
		return '@';
	
	if (student == true)
		return '*';
	
	if (instructor == true)
		return '%';
	
	if (TA == true)
		return 'T';
	
	if (ladder == true)
		return '^';
	
	if (skill == true)
		return '$';
	
	else 
		return ' ';
}

/*********************************************************************
** Function: void set_display_character(char sym);
** Description: sets the char
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: sets symbol
*********************************************************************/ 

void OpenSpace::set_display_character(char sym){
	symbol = sym;
}

/*********************************************************************
** Function: void set_has_student(bool);
** Description: sets the student
** Parameters: bool stu
** Pre-Conditions: after moving to a new spot
** Post-Conditions: sets the student at a new place in map
*********************************************************************/ 

void OpenSpace::set_has_student(bool stu){
	student = stu;
}

/*********************************************************************
** Function: bool has_student();
** Description: checks if student is at location
** Parameters: N/A
** Pre-Conditions: checks if student is at a location
** Post-Conditions: returns if student is there
*********************************************************************/ 

bool OpenSpace::has_student(){
	return student;
}	

/*********************************************************************
** Function: void set_has_ta(bool);
** Description: sets the ta at a location
** Parameters:  bool ta1
** Pre-Conditions: when entering floor and each turn
** Post-Conditions: sets ta
*********************************************************************/ 

void OpenSpace::set_has_ta(bool ta1){
	TA = ta1;
}

/*********************************************************************
** Function: bool has_ta();
** Description:checks if ta is at location
** Parameters:N/A
** Pre-Conditions: move
** Post-Conditions: returns if ta is there
*********************************************************************/ 

bool OpenSpace::has_ta(){
	return TA;
}

/*********************************************************************
** Function: void set_has_instructor(bool);
** Description: sets instructor
** Parameters: bool in
** Pre-Conditions: create maze
** Post-Conditions: sets the instructor
*********************************************************************/ 

void OpenSpace::set_has_instructor(bool in){
	instructor = in;
}

/*********************************************************************
** Function: bool has_instructor();
** Description: checks if instructor is at a location
** Parameters: N/A
** Pre-Conditions: when moving
** Post-Conditions: returns instructor 
*********************************************************************/ 

bool OpenSpace::has_instructor(){
		return instructor;
}

/*********************************************************************
** Function: void set_has_ladder(bool);
** Description: sets ladder
** Parameters: bool la
** Pre-Conditions: when making maze
** Post-Conditions: set ladder
*********************************************************************/ 

void OpenSpace::set_has_ladder(bool la){
	ladder = la;
}	

/*********************************************************************
** Function: bool has_ladder();
** Description: check if ladder is there
** Parameters: N/A
** Pre-Conditions: when moving and trying to go up
** Post-Conditions: returns ladder
*********************************************************************/ 

bool OpenSpace::has_ladder(){
	return ladder;
}

/*********************************************************************
** Function: void set_has_skill(bool);
** Description: sets skill
** Parameters: bool sk
** Pre-Conditions: when going into new floor
** Post-Conditions: sets skills
*********************************************************************/ 

void OpenSpace::set_has_skill(bool sk){
	skill = sk;
}

/*********************************************************************
** Function: bool has_skill();
** Description: checks if skill is there
** Parameters: N/A
** Pre-Conditions: move
** Post-Conditions: returns skill
*********************************************************************/

bool OpenSpace::has_skill(){
	return skill;
}
 
/*********************************************************************
** Function: bool set_start(bool);
** Description: set start
** Parameters: bool st
** Pre-Conditions: when making maze
** Post-Conditions: set start
*********************************************************************/ 

void OpenSpace::set_start(bool st){
	start = st;
}

/*********************************************************************
** Function: bool has_start();
** Description: check if place is start
** Parameters: N/A
** Pre-Conditions: when making maze
** Post-Conditions: get start
*********************************************************************/ 

bool OpenSpace::has_start(){
	return start;
}