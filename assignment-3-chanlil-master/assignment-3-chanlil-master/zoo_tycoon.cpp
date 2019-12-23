/*********************************************************************
** Program Filename: zoo_tycoon.cpp
** Author: Lilian Chan
** Date: 2/17/2019
** Description: This implements the entire zoo game
** Input: User choices and decisions, ints
** Output: Results of the game, ints, etc.
*********************************************************************/

#include<iostream>
#include"Monkey.hpp"
#include"Sloth.hpp"
#include"Otter.hpp"
#include"Zoo.hpp"

using namespace std;

int main(){
	int keep_playing = 1;
	Zoo game;
	int choice;
	int status = 1;
	
	while(keep_playing == 1){
		game.count_adu_bab();
		game.display_info();
		game.buy_ani();
		game.buy_food();
		game.special();
		game.add_earnings();
		game.new_day();
		int status = game.bankrupt();
		
		if(status == 0){
			keep_playing = 0;
			cout << "You went bankrupt. All your animals were "
				<< "released into the streets of New York." << endl;
			break;
		}
		
		cout << "Do you want to quit? Press 0 for yes, 1 for no." << endl;
		cin >> choice;
		if (choice == 0)
			keep_playing = 0;	
	}
}