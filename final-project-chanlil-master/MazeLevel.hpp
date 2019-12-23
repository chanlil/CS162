/*********************************************************************
** Program Filename: MazeLevel.hpp
** Author: Lilian Chan
** Date: 3/15/2019
** Description: this is the header file for mazelevel
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef MAZELEVEL_HPP
#define MAZELEVEL_HPP
#include <fstream>
#include "MazeLocation.hpp"
#include "OpenSpace.hpp"
#include "Wall.hpp"
#include <vector>
using namespace std;

class MazeLevel {
	private:
		vector<vector<MazeLocation*> >locations;
		int rows;
		int cols;
		int start_row;
		int start_col;
	public:
		MazeLevel(ifstream&, int, int);
		void fill(ifstream&);
		~MazeLevel();
		MazeLocation* get_location(int, int);
		int get_start_row();
		int get_start_col();
		void display();
};

#endif