/*********************************************************************
** Program Filename: gofish.cpp
** Author: Lilian Chan
** Date: 2/3/2019
** Description: This runs the whole go fish game
** Input: boolean for if you want to play again
** Output: Text to inform players how to play
*********************************************************************/

#include <iostream>
#include "game.hpp"
using namespace std;

int main(){
	bool a = 1;
	while (a == 1){
		Game game;
		game.start_game();
		//input and ouput
		cout << "Do you want to play again? Type 1 for yes, 0 for no." << endl;
		cin >> a;
	}

	return 0;
}
