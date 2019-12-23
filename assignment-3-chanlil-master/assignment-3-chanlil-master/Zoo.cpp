/*********************************************************************
** Program Filename: Zoo.cpp
** Author: Lilian Chan
** Date: 2/16/2019
** Description: This is the implementation file for the zoo.
** Input: N/A
** Output: N/A
*********************************************************************/

#include <iostream>
#include "Zoo.hpp"
#include <cstdlib>
#include <ctime>
#include <stdio.h> 

using namespace std;

/*********************************************************************
** Function: Zoo()
** Description: This is the constructor for the zoo class
** Parameters: N/A
** Pre-Conditions: create a zoo
** Post-Conditions: fills in values
*********************************************************************/ 

Zoo::Zoo(){
	money = 100000;	
	days = 1;
	food_price = 50;
	mon_num = 0;
	ott_num = 0;
	slo_num = 0;
	monkeys = new Monkey[0];
	otters = new Otter[0];
	sloths = new Sloth[0];
	mon_mult = 1;
	slo_mult = 1;
	ott_mult = 1;
	randomizer = 1.0;
}

/*********************************************************************
** Function: ~Zoo
** Description: Destroys dynamically allocated arrays
** Parameters: N/A
** Pre-Conditions: End game
** Post-Conditions: Deletes arrays
*********************************************************************/ 

Zoo::~Zoo(){
	delete [] monkeys;
	delete [] sloths;
	delete [] otters;	
}

/*********************************************************************
** Function:set money
** Description: sets the money
** Parameters: int x
** Pre-Conditions: Buy something
** Post-Conditions: sets the money
*********************************************************************/
 
 void Zoo::set_money(double x){
	 money = x;
 } 
 
/*********************************************************************
** Function: get money
** Description: returns money
** Parameters: N/A
** Pre-Conditions: When making purchases and start of new day
** Post-Conditions: returns money
*********************************************************************/ 

double & Zoo::get_money(){
	return money;
}

/*********************************************************************
** Function: subtract mon
** Description: subtracts money
** Parameters: N/A
** Pre-Conditions: When making purchases 
** Post-Conditions: subtracts money
*********************************************************************/ 

void Zoo::subtract_mon(double fee){
	money -= fee;
}

/*********************************************************************
** Function: set days
** Description: This sets the amount of days
** Parameters: happens every round
** Pre-Conditions: new day
** Post-Conditions: sets new day
*********************************************************************/ 

void Zoo::set_days(int x){
	days = x;
}

/*********************************************************************
** Function: get_days
** Description: returns days
** Parameters: N/A
** Pre-Conditions: new day
** Post-Conditions: returns days
*********************************************************************/ 

int & Zoo::get_days(){
	return days;	
}

/*********************************************************************
** Function: new_day
** Description: increments days
** Parameters: N/A
** Pre-Conditions: new day
** Post-Conditions: increments days
*********************************************************************/ 

void Zoo::new_day(){
	days++;
	for (int i = 0; i < mon_num; i++){
		monkeys[i].increment_age();	
	}
	for (int i = 0; i < ott_num; i++){
		otters[i].increment_age();	
	}
	for (int i = 0; i < slo_num; i++){
		sloths[i].increment_age();	
	}
}

/*********************************************************************
** Function: Buy_ani
** Description: add an animal
** Parameters: N/A
** Pre-Conditions: buy an animal
** Post-Conditions: adds animal to array
*********************************************************************/ 

void Zoo::buy_ani(){
	cout << "Do you want to buy animals? Pick 1 for monkeys, 2 for sea"
		<< " otters, 3 for sloths, and 4 for none." << endl;
	int choice;
	cin >> choice;
	switch (choice) {
		case 1: 
			buy_mon();
			break;
		case 2:	
			buy_ott();
			break;
		case 3: 	
			buy_slo();	
			break;
		default:
			cout << "You did not buy any animals." << endl;
			break;
	}
	count_adu_bab();
}

/*********************************************************************
** Function: Buy_mon
** Description: add a monkey
** Parameters: N/A
** Pre-Conditions: buy an animal
** Post-Conditions: adds animal to array
*********************************************************************/ 

void Zoo::buy_mon(){
	cout << "Do you want to buy monkeys? Type 1 for yes, 0 for no." << endl;
	int choice;
	cin >> choice;
	if (choice == 1){
		cout << "How many? (max 2)" << endl;
		int num1;
		cin >> num1;
		switch(num1){
				case 1: 
					cout << "You bought one monkey" << endl;
					add_monkey(1095);
					subtract_mon(15000);
					break;
				case 2:
					cout << "You've bought two monkeys" << endl;
					add_monkey(1095);
					subtract_mon(15000);
					add_monkey(1095);
					subtract_mon(15000);
					break;
				default: 
					cout << "You didn't buy any." << endl;
					break;
		}
	}

	else
		cout << "You didn't buy monkeys." << endl;	
}

/*********************************************************************
** Function: Buy_ott
** Description: add an otter
** Parameters: N/A
** Pre-Conditions: buy an animal
** Post-Conditions: adds animal to array
*********************************************************************/ 

void Zoo::buy_ott(){
	cout << "Do you want to buy sea otters? Type 1 for yes, 0 for no." << endl;
	int choice;
	cin >> choice;
	if (choice == 1){
		cout << "How many? (max 2)" << endl;
		int num1;
		cin >> num1;
		switch(num1){
				case 1: 
					cout << "You bought one sea otter" << endl;
					add_otter(1095);
					subtract_mon(5000);
					break;
				case 2:
					cout << "You've bought two sea otters" << endl;
					add_otter(1095);
					subtract_mon(5000);
					add_otter(1095);
					subtract_mon(5000);
					break;
				default: 
					cout << "You didn't buy any." << endl;
					break;
		}
	}

	else
		cout << "You didn't buy any sea otters." << endl;		
}

/*********************************************************************
** Function: Buy_slo
** Description: add a sloth
** Parameters: N/A
** Pre-Conditions: buy an animal
** Post-Conditions: adds animal to array
*********************************************************************/ 

void Zoo::buy_slo(){
	cout << "Do you want to buy sloths? Type 1 for yes, 0 for no." << endl;
	int choice;
	cin >> choice;
	if (choice == 1){
		cout << "How many? (max 2)" << endl;
		int num1;
		cin >> num1;
		switch(num1){
			case 1: 
				cout << "You bought one sloth" << endl;
				add_sloth(1095);
				subtract_mon(2000);
				break;
			case 2:
				cout << "You've bought two sloths" << endl;
				add_sloth(1095);
				subtract_mon(2000);
				add_sloth(1095);
				subtract_mon(2000);
				break;
			default: 
				cout << "You didn't buy any." << endl;
				break;
		}
	}

	else
		cout << "You didn't buy any sloths." << endl;		
}

/*********************************************************************
** Function: food_rand()
** Description: lets the food price rise or fall
** Parameters: N/A
** Pre-Conditions: buy food
** Post-Conditions: raise or lower food prices
*********************************************************************/ 

void Zoo::food_rand(){
	srand(time(NULL)); 
	int food_mult = rand()%(125 - 75 + 1) + 75;
	randomizer = food_mult / 100.0;
	cout << "The food prices have changed by " << randomizer << "." << endl;
}

/*********************************************************************
** Function: Buy_food
** Description: allows you to buy food
** Parameters: N/A
** Pre-Conditions: buy food
** Post-Conditions: feeds animals, lose money
*********************************************************************/ 

void Zoo::buy_food(){
	cout << "Your animals are hungry! Feed them now!" << endl;
	if (mon_num != 0)
		mon_food();
	if (ott_num != 0)
		ott_food();
	if (slo_num != 0)
		slo_food();
	food_rand();
	food_price *= randomizer;
}

/*********************************************************************
** Function: mon_food
** Description: allows you to buy food
** Parameters: N/A
** Pre-Conditions: buy food
** Post-Conditions: feeds animals, lose money
*********************************************************************/ 
void Zoo::mon_food(){
	cout << "What quality food do you want to buy for the monkeys?" << endl;
	cout << "Pick 1 for regular, 2 for cheap, 3 for premium food." << endl;
	int choice;
	cin >> choice;
	switch(choice){
		case 1:
			mon_mult = 2;
			break;
		case 2:
			mon_mult = 4;
			break;
		case 3:
			mon_mult = 1;
			break;
		default:
			cout << "That was an invalid choice, so you got regular food." << endl;
			mon_mult = 2;
			break;
	}
	double quality;
	if (mon_mult == 2)
		quality = 1.0;
	else if (mon_mult == 4)
		quality = 0.5;
	else if (mon_mult == 1)
		quality = 2.0;
	else
		quality = 1.0;
	
	subtract_mon(mon_num * food_price * 4.0 * quality);
}
/*********************************************************************
** Function: ott_food
** Description: allows you to buy food
** Parameters: N/A
** Pre-Conditions: buy food
** Post-Conditions: feeds animals, lose money
*********************************************************************/ 

void Zoo::ott_food(){
	cout << "What quality food do you want to buy for the sea otters?" << endl;
	cout << "Pick 1 for regular, 2 for cheap, 3 for premium food." << endl;
	int choice;
	cin >> choice;
	switch(choice){
		case 1:
			ott_mult = 2; //this determines how easily they get sick
			break;
		case 2:
			ott_mult = 4;
			break;
		case 3:
			ott_mult = 1;
			break;
		default:
			cout << "That was an invalid choice, so you got regular food." << endl;
			ott_mult = 2;
			break;
	}
	double quality;
	if (ott_mult == 2)
		quality = 1.0;
	else if (ott_mult == 4)
		quality = 0.5;
	else if (ott_mult == 1)
		quality = 2.0;
	else
		quality = 1.0;
	
	subtract_mon(ott_num * food_price * 2.0 * quality);
}
/*********************************************************************
** Function: slo_food
** Description: allows you to buy food
** Parameters: N/A
** Pre-Conditions: buy food
** Post-Conditions: feeds animals, lose money
*********************************************************************/ 

void Zoo::slo_food(){
	cout << "What quality food do you want to buy for the sloths?" << endl;
	cout << "Pick 1 for regular, 2 for cheap, 3 for premium food." << endl;
	int choice;
	cin >> choice;
	switch(choice){
		case 1:
			slo_mult = 2;
			break;
		case 2:
			slo_mult = 4;
			break;
		case 3:
			slo_mult = 1;
			break;
		default:
			cout << "That was an invalid choice, so you got regular food." << endl;
			slo_mult = 2;
			break;
	}
	double quality;
	if (slo_mult == 2)
		quality = 1.0;
	else if (slo_mult == 4)
		quality = 0.5;
	else if (slo_mult == 1)
		quality = 2.0;
	else
		quality = 1.0;
	
	subtract_mon(slo_num * food_price * quality);
}
/*********************************************************************
** Function: special
** Description: chooses a special event
** Parameters: N/A
** Pre-Conditions: New day
** Post-Conditions: Chooses an event function
*********************************************************************/ 

void Zoo::special(){
	srand(time(NULL)); 
	int event = 1 + (rand()%(4 - 1 + 1));
	bool still_going = 1;
	while (still_going){
		if (ott_num != 0 || slo_num != 0 || mon_num != 0){
			switch(event){
				case 1:
					cout << "There has been a boom in zoo attendance." << endl;
					boom();
					still_going = 0;
					break;
				case 2:
					count_adu_bab();
					if (adults == 0)
						break;	
					else{
						cout << "An animal is giving birth." << endl;
						birth();
						still_going = 0;
						break;
					}	
				case 3:
					cout << "An animal got sick! (It was rabies and two children were bitten)." << endl;
					sickness();
					still_going = 0;
					break;
				default:
					cout << "This is a boring day. Nothing happens." << endl;
					still_going = 0;
					break;
		}
	}
		else	
			cout << "Your zoo has no animals..." << endl;
			still_going = 0;	
	}
}

/*********************************************************************
** Function: sickness
** Description: give money or die
** Parameters: N/A
** Pre-Conditions: Special Event chose this event 
** Post-Conditions: Removes animal from array unless fee is paid
*********************************************************************/ 

void Zoo::sickness(){
	bool still_going = 1;
	
	while (still_going){
		srand(time(NULL)); 
		int animal = choose_animal();
		int age;
			switch(animal){
				case 1:
					//checks if there are monkeys
					if (mon_num == 0)
						break;
					else{
						still_going = 0;
						cout << "A monkey got sick, which is terrible." << endl;
						int sick_mon = (rand()%(mon_num));	
						age = monkeys[sick_mon].get_age();
						if(age < 30){
							cout << "A baby monkey got sick." << endl;
							if (money >= 15000)
								subtract_mon(15000);
							else
								kill_monkey(sick_mon);
						}	
						else{
							cout << "Pay the bills for the monkey." << endl;
								if (money >= 7500)
									subtract_mon(7500);
								else
									kill_monkey(sick_mon);
						}	
					}
					break;
					
				case 2:
					//checks if there are sea otters
					if (ott_num == 0)
						break;
					else{
						still_going = 0;
						cout << "A sea otter got sick, which is terrible." << endl;
						int sick_ott = rand()%(ott_num);	
						age = otters[sick_ott].get_age();
						if(age < 30){
							cout << "A baby sea otter got sick." << endl;
							if (money >= 5000)
								subtract_mon(5000);
							else
								kill_otter(sick_ott);
						}	
						else{
							cout << "Pay the bills for the sea otter." << endl;
								if (money >= 2500)
									subtract_mon(2500);
								else
									kill_otter(sick_ott);
						}	
					}
					break;
				
				case 3:
					//checks if there are sloths
					if (slo_num == 0)
						break;
					else{
						still_going = 0;
						cout << "A sloth got sick, which is terrible." << endl;
						int sick_slo = rand()%(slo_num);	
						age = sloths[sick_slo].get_age();
						if(age < 30){
							cout << "A baby sloth got sick." << endl;
							if (money >= 15000)
								subtract_mon(15000);
							else
								kill_sloth(sick_slo);
						}	
						else{
							cout << "Pay the bills for the sloth." << endl;
								if (money >= 7500)
									subtract_mon(7500);
								else
									kill_sloth(sick_slo);
						}	
					}
					break;	
			}	
	}
}
	
/*********************************************************************
** Function: choose animal
** Description:  chooses an animal to get sick
** Parameters: N/A
** Pre-Conditions: Special event chose it
** Post-Conditions: returns a number that corresponds to an animal
*********************************************************************/ 
	
int Zoo::choose_animal(){
	int total_pool = mon_mult + slo_mult + ott_mult;
	srand(time(NULL)); 
	int cho_ani = (rand()%(total_pool - 1 + 1)) + 1;
	if (cho_ani < mon_mult + 1)
		return 1;
	if (cho_ani > total_pool - slo_mult)
		return 3;
	else	
		return 2;
}	
	
/*********************************************************************
** Function: birth
** Description: an animal gives birth and adds to array
** Parameters: N/A
** Pre-Conditions: Special event chose it
** Post-Conditions: adds to array
*********************************************************************/ 

void Zoo::birth(){
	bool still_going = 1;
	while (still_going){
		srand(time(NULL)); 
		int animal = rand()%(3 - 1 + 1) + 1;
			switch(animal){
				case 1:
					//checks if there are adult monkeys
					if (mon_adults == 0)
						break;
					else{
						cout << "A baby monkey fell out of the sky into your zoo." << endl;
						add_monkey(0);
						still_going = 0;
					}
					break;
					
				case 2:
				//checks if there are adult sea otters
					if (ott_adults == 0)
						break;
					else{
						cout << "A baby sea otter was summoned from the underworld." << endl; 
						add_otter(0);
						add_otter(0);
						still_going = 0;
					}
					break;
				
				case 3:
					//checks if there are sloths
					if (slo_adults == 0)
						break;
					else{
						cout << "A sloth hatched an egg." << endl;
						add_sloth(0);
						add_sloth(0);
						add_sloth(0);
						still_going = 0;
					}
					break;	
				default:
					break;
			}	
	}
}

/*********************************************************************
** Function: boom
** Description: earns bonus based on monkeys
** Parameters: N/A
** Pre-Conditions: special event
** Post-Conditions: adds more money based on monkeys
*********************************************************************/ 

void Zoo::boom(){
	if (mon_num == 0)
		cout << "There was a boom, but the customers were dissapointed by your lack of monkeys." << endl;
	
	else {
		cout << "Extra money is always good!" << endl;
		
		for (int i = 0; i < mon_num; i++){
			srand(time(NULL)); 
			double bonus = rand()%(500 - 250 + 1) + 250;
			money += bonus;
		}	
	}
}

/*********************************************************************
** Function: count_adu_bab
** Description: counts adults and babies
** Parameters: N/A
** Pre-Conditions: Every new day
** Post-Conditions: updates numbers
*********************************************************************/ 

void Zoo::count_adu_bab(){
	//resets the count
	adults = 0;
	babies = 0;
	mon_babies = 0;
	mon_adults = 0;
	slo_babies = 0;
	slo_adults = 0;
	ott_babies = 0;
	ott_adults = 0;
	
	for (int i = 0; i < mon_num; i++){
		int m_age = monkeys[i].get_age();
		if (m_age < 30){
			mon_babies++;
			babies++;
		}	
		if (m_age >= 1095){
			mon_adults++;
			adults++;
		}	
	}
	
for (int i = 0; i < ott_num; i++){
		int o_age = otters[i].get_age();
		if (o_age < 30){
			ott_babies++;
			babies++;
		}	
		if (o_age >= 1095){
			ott_adults++;
			adults++;
		}	
	}			
	
for (int i = 0; i < slo_num; i++){
		int s_age = sloths[i].get_age();
		if (s_age < 30){
			slo_babies++;
			babies++;
		}	
		if (s_age >= 1095){
			slo_adults++;
			adults++;
		}	
	}	
}

/*********************************************************************
** Function: bankrupt
** Description: checks if bankrupt
** Parameters: N/a
** Pre-Conditions: every new day
** Post-Conditions: ends game if no money
*********************************************************************/ 

int Zoo::bankrupt(){
	if (money < 0)
		return 0;
	else 
		return 1;
}

/*********************************************************************
** Function: display info
** Description: displays animals' information and money
** Parameters: N/A
** Pre-Conditions: new day
** Post-Conditions: displays info
*********************************************************************/ 

void Zoo::display_info(){
	cout << "Your bank account has $" << money << endl;
	cout << "You have the following animals: " << endl;
	cout << "Total adults: " << adults << endl;
	cout << "Total babies: " << babies << endl;
	
	cout << "Total monkeys: " << mon_num << endl;
	cout << "Monkey adults: " << mon_adults << endl;
	cout << "Monkey babies: " << mon_babies << endl;
	
	cout << "Total sea otters: " << ott_num << endl;
	cout << "Sea otter adults: " << ott_adults << endl;
	cout << "Sea otter babies: " << ott_babies << endl;
	
	cout << "Total sloths: " << slo_num << endl;
	cout << "Sloth adults: " << slo_adults << endl;
	cout << "Sloth babies: " << slo_babies << endl;
}

/*********************************************************************
** Function: add_earnings
** Description: allows you to count up earnings for the day
** Parameters: N/A
** Pre-Conditions: end of day
** Post-Conditions: updates teh money
*********************************************************************/ 

void Zoo::add_earnings(){
	count_adu_bab();
	money += (mon_babies * 3000 + (mon_num - mon_babies) * 1500);
	money += (ott_babies * 500 + (ott_num - ott_babies) * 250);
	money += (slo_babies * 200 + (slo_num - slo_babies) * 100);
}

/*********************************************************************
** Function: get_num_monkey
** Description: returns the number
** Parameters: N/A
** Pre-Conditions: change the array
** Post-Conditions: returns the number
*********************************************************************/ 

int Zoo::get_num_monkey(){
	return mon_num;
}

/*********************************************************************
** Function: add monkey
** Description: adds animal to array 
** Parameters: N/A
** Pre-Conditions: buy or birth
** Post-Conditions: add to array
*********************************************************************/ 

void Zoo::add_monkey(int age){
	mon_num++;
	Monkey * new_array = new Monkey[mon_num];
	for (int i = 0; i < mon_num - 1; i++){
		new_array[i].set_age(monkeys[i].get_age());
	}
	new_array[mon_num - 1].set_age(age);
	
	delete[] monkeys;
	monkeys = new_array;
	
	/*for (int i = 0; i < mon_num; i++)
		new_array[i].set_age(monkeys[i].get_age());
	*/
	
	//monkeys = new Monkey[mon_num];
	
	
	
	
}

/*********************************************************************
** Function: kill monkey
** Description: removes animal from array
** Parameters: int x
** Pre-Conditions: can't pay for treatment
** Post-Conditions: removes a sepcific monkey
*********************************************************************/ 

void Zoo::kill_monkey(int dead){
	Monkey copy_array[mon_num];
	
	for (int i = 0; i < dead; i++){
		copy_array[i].set_age(monkeys[i].get_age());
	}
	
	for (int i = dead + 1; i < mon_num; i++)
		copy_array[i - 1].set_age(monkeys[i].get_age());
	
	mon_num--;
	delete [] monkeys;
	monkeys = new Monkey[mon_num];
	
	for (int i = 0; i < mon_num; i++){
		monkeys[i].set_age(copy_array[i].get_age());
	}
}
	
/*********************************************************************
** Function: get_num_otter
** Description: returns the number
** Parameters: N/A
** Pre-Conditions: change the array
** Post-Conditions: returns the number
*********************************************************************/ 

int Zoo::get_num_otter(){
	return ott_num;
}

/*********************************************************************
** Function: add otter
** Description: adds animal to array 
** Parameters: N/A
** Pre-Conditions: buy or birth
** Post-Conditions: add to array
*********************************************************************/ 

void Zoo::add_otter(int age){
	ott_num++;
	Otter * new_array = new Otter[ott_num];
	for (int i = 0; i < ott_num - 1; i++){
		new_array[i].set_age(otters[i].get_age());
	}
	new_array[ott_num - 1].set_age(age);
	
	delete[] otters;
	otters = new_array;
}

/*********************************************************************
** Function: kill otter
** Description: removes animal from array
** Parameters: int x
** Pre-Conditions: can't pay for treatment
** Post-Conditions: removes a sepcific monkey
*********************************************************************/ 

void Zoo::kill_otter(int dead){
	Otter copy_array[ott_num];
	
	for (int i = 0; i < dead; i++)
		copy_array[i].set_age(otters[i].get_age());
	
	for (int i = dead + 1; i < ott_num; i++)
		copy_array[i - 1].set_age(otters[i].get_age());
	
	ott_num--;
	delete [] otters;
	otters = new Otter[ott_num];
	
	for (int i = 0; i < ott_num; i++){
		 otters[i].set_age(copy_array[i].get_age());
	}
}
	
/*********************************************************************
** Function: get_num_sloth
** Description: returns the number
** Parameters: N/A
** Pre-Conditions: change the array
** Post-Conditions: returns the number
*********************************************************************/ 

int Zoo::get_num_sloth(){
	return slo_num;
}

/*********************************************************************
** Function: add sloth
** Description: adds animal to array 
** Parameters: N/A
** Pre-Conditions: buy or birth
** Post-Conditions: add to array
*********************************************************************/ 

void Zoo::add_sloth(int age){
	slo_num++;
	Sloth * new_array = new Sloth[slo_num];
	for (int i = 0; i < slo_num - 1; i++){
		new_array[i].set_age(sloths[i].get_age());
	}
	new_array[slo_num - 1].set_age(age);
	
	delete[] sloths;
	sloths = new_array;
}

/*********************************************************************
** Function: kill sloth
** Description: removes animal from array
** Parameters: int x
** Pre-Conditions: can't pay for treatment
** Post-Conditions: removes a sepcific monkey
*********************************************************************/ 

void Zoo::kill_sloth(int dead){
	Sloth copy_array[slo_num];
	
	for (int i = 0; i < dead; i++)
		copy_array[i].set_age(sloths[i].get_age());
	
	for (int i = dead + 1; i < slo_num; i++)
		copy_array[i - 1].set_age(sloths[i].get_age());
	
	slo_num--;
	delete [] sloths;
	sloths = new Sloth[slo_num];
	
	for (int i = 0; i < slo_num; i++){
			sloths[i].set_age(copy_array[i].get_age());
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
