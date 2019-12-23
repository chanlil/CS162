/*********************************************************************
** Program Filename: Maze.hpp
** Author: Lilian Chan
** Date: 3/16/2019
** Description: This is the header file for Maze
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef MAZE_HPP
#define MAZE_HPP
#include "MazeLevel.hpp"
#include "MazePerson.hpp"
#include "IntrepidStudent.hpp"
#include "TA.hpp"
#include "Instructor.hpp"

using namespace std;

class Maze {
private:
	//dimensions of the whole maze
	int level;
	int row;
	int col;
	
	//to track character
	int play_row;
	int play_col;
	int skills;
	IntrepidStudent * stu;
	
	//to track "Storm Troopers"
	int appease; //TAs are appeased if this is below 10
	int TA_1_row;
	int TA_2_row;
	int TA_1_col;
	int TA_2_col;
	TA * TA_1;
	TA * TA_2;
	
	//to track skills
	int skill_1_row;
	int skill_2_row;
	int skill_3_row;
	int skill_1_col;
	int skill_2_col;
	int skill_3_col;
	
	//to track "Darth Vader"
	int instructor_row;
	int instructor_col;
	Instructor * ins;

	//keep track of factors
	int current_floor;
	int grade; // 0 is neutral, 1 is win, 2 is lose
	MazeLevel ** whole_maze;
	
public:	//grade checks now incorportated in maze itself
	Maze(ifstream &);
	~Maze();//include destructors for maze people
	void randomize();
	void reset_level(); 
	void move_up_level();
	void display();
	void move_stu();
	int transpose_stu_cardinal(int, int);
	void TAs_moving();
	void move_TA(TA *, int num); //called by TA moving for each TA
	void check_surroundings();
	void TA_encounter(); //called by check_surroundings
	void instructor_encounter();
	//void skill_encounter();
	int return_grade();
	void increment_appease();
	void appease_reset();
	//bool check_appease();
};

#endif