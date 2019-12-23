/*********************************************************************
** Program Filename: deck.cpp
** Author: Lilian Chan
** Date: 2/1/2019
** Description: This is the implementation file for the deck class,
which contains an array of 52 cards.
** Input: N/A
** Output: N/A
*********************************************************************/
#include <iostream>
#include "deck.hpp"
#include <algorithm>

using namespace std;

/*********************************************************************
** Function: deck()  
** Description: This constructor creates an array with 52 cards, then
calls the shuffle function to shuffle it. 
** Parameters: N/A
** Pre-Conditions: Make a deck object
** Post-Conditions: Fills in deck object with default values. 
*********************************************************************/ 

Deck::Deck(){
	n_cards = 52;

	for(int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++){
			cards[i * 13 + j].set_rank(j);
			cards[i * 13 + j].set_suit(i);
		}
	}
	
	shuffle();
}

/*********************************************************************
** Function: shuffle()  
** Description: This shuffles the deck randomly. This is to emulate 
realistic shuffling.
** Parameters: N/A
** Pre-Conditions: Called by constructor.
** Post-Conditions: Shuffles the deck array. 
*********************************************************************/

void Deck::shuffle() {
	int location;
    srand(time(NULL));
	for(int j = 0; j < 32; j++)
	{
		for (int i = 0; i < n_cards; i++) {
			location = rand() % n_cards;
			Card temp = cards[location];
			cards[location] = cards[i];
			cards[i] = temp;
		}
	}
}

/*********************************************************************
** Function: draw_card
** Description: This draws a card object from the deck and adjusts 
the deck. 
** Parameters: N/A
** Pre-Conditions: Have a deck object 
** Post-Conditions: Returns a card and adjusts the deck accordingly. 
*********************************************************************/ 

Card Deck::draw_card(){
	/*if(n_cards == 0)
	{
		cout << "But the deck was empty..." << endl;
		Card sentinal;
		sentinal.set_rank(0);
		sentinal.set_suit(0);
		return  sentinal;
	}*/
	Card drawn_card;
	//cout << "Drawing n_cards-1: " << (n_cards - 1) << endl;
	drawn_card = cards[n_cards - 1];
	--n_cards;
	return drawn_card;  
}

/*********************************************************************
** Function: get_card 
** Description: This returns the ith instance of a card
** Parameters: int i
** Pre-Conditions: have a deck object
** Post-Conditions: returns the ith element of cards
*********************************************************************/ 

Card Deck::get_card(int i){
	return cards[i];
}
	 
/*********************************************************************
** Function: get_n_cards
** Description: This returns the number of cards in the deck
** Parameters: N/A
** Pre-Conditions: Have a deck
** Post-Conditions: Returns the n_cards
*********************************************************************/ 

int Deck::get_n_cards(){
	return n_cards;
}

/*********************************************************************
** Function: set_n_cards
** Description: This sets the n-cards in the deck
** Parameters: int new_num_cards
** Pre-Conditions: Have a deck
** Post-Conditions: Sets the n_cards
*********************************************************************/ 

void Deck::set_n_cards(int new_num_deck){
	n_cards = new_num_deck;
}
