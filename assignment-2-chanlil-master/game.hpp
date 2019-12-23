/*********************************************************************
** Program Filename: game.hpp 
** Author: Lilian Chan
** Date: 2/3/2019
** Description: This is the game class where all the other classes come 
together to create a game of go fish.
** Input: N/A 
** Output: N/A
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "hand.hpp"

class Game{
private:
	Deck* game_deck;
	Player* players[2]; //always size 2 
public:	
	Game();
	~Game();
	void start_game();
	void player_turn(int);
	void check_if_no_cards(int);
	int plyr_choice();
	int comp_choice(); //CHANGED
	int ask_for_card(int, int);
	void out_of_cards(int, int);
	int regular_play(int, int);
	void announce_winner();
};

#endif
