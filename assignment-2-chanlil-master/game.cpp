/*********************************************************************
** Program Filename: game.cpp
** Author: Lilian Chan
** Date: 2/3/2019
** Description: This is the implementation file for the game, which 
brings together all the classes to play a game of go fish.  
** Input: Cards you want to select.
** Output: Text to show you your cards and the state of the match. 
*********************************************************************/

#include "game.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*********************************************************************
** Function: Game()
** Description: This is the constructor for game that initializes 
the players and deck. 
** Parameters: N/A
** Pre-Conditions: Create a game
** Post-Conditions: initializes the game
*********************************************************************/ 

Game::Game(){
	game_deck = new Deck;
	//players = new Player[2];
	players[0] = new Player;
	players[1] = new Player;
	players[0] -> initialize_hand(game_deck);
	players[1] -> initialize_hand(game_deck);
}

/*********************************************************************
** Function: ~Game()
** Description: This si the destructor for the game, which deletes 
the deck
** Parameters: N/A
** Pre-Conditions: Create a game, then go out of bounds
** Post-Conditions: deletes the deck
*********************************************************************/ 

Game::~Game(){
	delete game_deck;
	delete players[0];
	delete players[1];
}

/*********************************************************************
** Function: start_game()
** Description: This is where it allows players to take turns and 
ends the game when there are no more cards. 
** Parameters: N/A
** Pre-Conditions: Create a game 
** Post-Conditions: Ends the game when necessary and allows players 
to take turns. 
*********************************************************************/ 

void Game::start_game(){
	int turn = 0;
	int human = 0;
	int computer = 1;
	while (game_deck -> get_n_cards() > 0 && players[0]->return_hand()->get_n_cards() > 0
		&& players[1]->return_hand()->get_n_cards() > 0){
		/*Below is the logically better one?*/
		/*!(game_deck -> get_n_cards() <= 0 
		&& players[0]->return_hand()->get_n_cards() <= 0 
			&& players[1]->return_hand()->get_n_cards() <= 0)*/

		//this is how it switches between the two players
		int turn_num = turn % 2 + 1;
	
		switch(turn_num){
			case 1:
				cout << "Player's Turn." << endl;
				player_turn(human);
				turn++;
				break;

			case 2:
				cout << "Computer's Turn." << endl;
				player_turn(computer);
				turn++;
				break;
	
			default: 
				cout << "An error occured when taking turns" << endl; 
				break;
		}
	}
	
	announce_winner();
}

/*********************************************************************
** Function: player_turn 
** Description: It walks each player through their turn, through 
calling functions that represent seeing if their or their opponent's
hand is empty. asking for cards, and going fish.
** Parameters: int plyr
** Pre-Conditions: Have a game object and start it
** Post-Conditions: Allows players to ask for cards
*********************************************************************/ 

void Game::player_turn(int plyr){
	bool turn_active = 1;
	int choice; 

	while(turn_active){
		check_if_no_cards(plyr);
		
		if (plyr == 0)
			choice = plyr_choice();

		else
			choice = comp_choice();
		
		turn_active = ask_for_card(plyr, choice);
		
		//after each time they ask, the hand is organized 
		//and checked for books. 
		players[plyr]->return_hand()->sort_cards();
		players[plyr]->check_for_book(); //prbl
	} 
}

/*********************************************************************
** Function: check_if_no_cards
** Description: This check if the player has no more cards, and if so,
makes them draw one.
** Parameters: int plyr_num 
** Pre-Conditions: There's a game object.
** Post-Conditions: Makes sure player has at least 1 card 
*********************************************************************/ 

void Game::check_if_no_cards(int plyr){
	if (players[plyr]->return_hand()->get_n_cards() == 0){
		if (plyr == 0){
			cout << "You're out of cards, so you drew another. ";
			cout << endl;

		}
 
		else {
			cout << "The computer is out of cards. It drew one.";
			cout << endl;
		}
		
		players[plyr]->return_hand()->set_card(game_deck -> draw_card());		
	}
} 

/*********************************************************************
** Function: plyr_choice
** Description: This allows the player to see and choose a card
** Parameters: N/A
** Pre-Conditions: It is the player's turn
** Post-Conditions: It allows players to ask for a card
*********************************************************************/ 

int Game::plyr_choice(){
	players[0]->return_hand()->display_cards();
	
	int valid = 0;
	int choice;
	
	while (valid == 0){
		cout << "Which card option do you want to ask for?" << endl;
		cin >> choice;
		if (choice < players[0]->return_hand()->get_n_cards() && 
			choice > -1){
			break;
		}
		
		cout << "Choice is invalid. Choose again." << endl;	
	}
	
	return choice;
}

/*********************************************************************
** Function: comp_choice
** Description: It allows the computer to randomly select a card
** Parameters: N/A 
** Pre-Conditions: It is the computer's turn
** Post-Conditions: It randomly chooses a card
*********************************************************************/ 

int Game::comp_choice(){
	int min = 0;
	int max = players[1]->return_hand()->get_n_cards() - 1;
	static bool first = true;
	if (first)
	{
		srand(time(NULL));
		first = false;
	}	
 
	int chosen_num = min + rand() % ((max + 1) - min);
	cout << "The computer wants a number." << endl;
	return chosen_num;
}

/*********************************************************************
** Function: ask_for_card 
** Description: This allows one player to ask another player for a card,
if the other player is out of cards, it sends it to the out_of_cards 
function. Otherwise, it sends it to the regular_play function.
** Parameters: int plyr, int choice
** Pre-Conditions: The player takes their turn
** Post-Conditions: It allows the player to ask for a card and
get it or go fish. 
*********************************************************************/ 

int Game::ask_for_card(int plyr, int choice){
	//this determines the other player
	int other;
	
	if (plyr == 0)
		other = 1;
	if (plyr == 1)
		other = 0;
	
	cout << "The requested card is of rank: ";
	cout << players[plyr]->return_hand()->get_card(choice).get_rank() << endl;

	
	if (players[other]->return_hand()->get_n_cards() == 0){ //Segfault
		//cout << "True" << endl;
		out_of_cards(plyr, players[plyr]->return_hand()->get_card(choice).get_rank());
		return 1;
	} 
	else {
		//cout << "False" << endl;
		bool returned_value = regular_play(plyr, players[plyr]->return_hand()->get_card(choice).get_rank());
		return returned_value;  
	}	
}

/*********************************************************************
** Function: out_of_cards
** Description: If the opposing player is out of cards, it makes the
other player draw cards until they have the one the player needs. 
** Parameters: p
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 

void Game::out_of_cards(int plyr, int choice){
	int other;
	if (plyr == 0)
		other = 1;
	if (plyr == 1)
		other = 0;

	bool not_done = 1;
	
	while (not_done){	
		cout << "A card must be drawn to get the requested card." << endl; 
		Card drawn_card = game_deck -> draw_card();
		players[other]->return_hand()->set_card(drawn_card); 
		
		//determines if other player is done drawing cards
		if (drawn_card.get_rank() == choice){
			cout << "The drawn card is the requested card" << endl; 
			//void exchnage_cards(Player, int);
			players[plyr]->exchange_cards(players[other], choice);	
			break;
		}	
		if (game_deck -> get_n_cards() == 0){
			cout << "The deck is out of cards." << endl;
			break;
		}		 
	} 
}

/*********************************************************************
** Function: regular_play
** Description: This is where the player asks the other for a card
** Parameters: int plyr, int choice
** Pre-Conditions: Nobody has run out of cards and the game can be 
played as normal
** Post-Conditions: The player either gets cards or goes fish.
*********************************************************************/ 

int Game::regular_play(int plyr, int choice){
	int other; 
	if (plyr == 0)
		other = 1;

	if (plyr == 1)
		other = 0;
	//this is to keep track if the player guessed right
	int starting_num = players[plyr]->return_hand()->get_n_cards();
	players[plyr]->exchange_cards(players[other], choice);

	//this is to go to the appropriate action depending if the player
	//guess right.
	int ending_num = players[plyr]->return_hand()->get_n_cards();
	
	//if player has to go fish
	if(ending_num == starting_num) {
		cout << "Player needs to go fish." << endl;
		int card_drawn = players[plyr]->go_fish(game_deck);
		if (card_drawn == choice){
			cout << "The player drew a " << choice; 
			cout << ". They can go again." << endl;
			return 1;	
		} 
		
		else {
			cout << "The turn has ended." << endl;
			return 0;
		}
	}   	
	
	//if player gets another turn
	if (ending_num != starting_num){
		cout << "Player gets to go again." << endl; 
		return 1;
	} 
}

/*********************************************************************
** Function: announce_winner
** Description: This announces the winner of the game aand their books
** Parameters: N/A
** Pre-Conditions: Finish a game
** Post-Conditions: Announces the winner  and their books 
*********************************************************************/ 

void Game::announce_winner(){
	if (players[0]->get_n_books() > players[1]->get_n_books()) {
		cout << "You win! Congrats!" << endl;
	} 
	
	else {
		cout << "The computer won!" << endl;	
	}	
}


