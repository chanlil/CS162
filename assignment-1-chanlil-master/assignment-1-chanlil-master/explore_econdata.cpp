/*********************************************************************
** Program Filename: explore_econdata.cpp
** Author: Lilian Chan
** Date: 1/16/2019
** Description: This file allows users to input a file of economic 
data, then they can interact with the data. There's a menu of various
options to select from, which allows users to find highs and lows of
the data and sort the data.   
** Input: A file with state and county economic data and integers.
** Output: Various options and analysis of the state and county data.
*********************************************************************/

#include <iostream> 
#include <fstream>
#include <string> 
#include <algorithm> 
#include "econdata.hpp"

using namespace std; 

int main(int argc, char* argv[])
{
	//variables  
	ifstream file;
	int num_states; 
	int status;
	int option;	

	//checks if file can be opened 
	file.open(argv[1]);
	if (file.fail()){
		cout << "Failed to open file." << endl;
		
		return 1;
	}
	
	//fills in arrays
	file >> num_states;

	struct state *states = allocate_states(num_states);

	for (int i = 0; i < num_states; i++){
		read_state_data(states, i, file);
		states[i].counties = allocate_counties(states[i].n_counties);
		read_county_data(states[i].counties, states[i].n_counties,
			 file); 
	}
	
	//variable to allow people to keep going or quit
	status = 1;

	do{
		//print out options
		cout << "What information would you like?" << endl; 
		cout << "1: State with highest median household income" << endl; 
		cout << "2: State with lowest median household income" << endl;
		cout << "3: State with highest unemployment in 2015" <<endl;
		cout << "4: State with lowest unemployment in 2015" << endl; 
		cout << "5: States sorted by change in unemployment" << endl;
		cout << "6: States sorted on median household income" << endl; 
		cout << "7: State's county information" << endl;
		cout << "8: Quit this program" << endl;
	
		//choose an option
		cin >> option;
		
		if (option == 8){
			//free arrays
			free_state_data(states, num_states);	
			
			return 0;	
		}	
		
		//variables to declare if options 1-7 were chosen
		switch (option){
			case 1: //code for highest median income 
				sort(states, states + num_states, asc_med);
				
				cout << "The state with the highest median income is "
					<< states[num_states - 1].name << endl;		

				break;

			case 2: //code for lowest median income
				sort(states, states + num_states, asc_med);
	
				cout << "The state with the lowest median income is "
					<< states[0].name << endl;
				
				break;
			
			case 3: //highest 2015 unemployment 
				sort(states, states + num_states, asc_2015);

				cout << "The state with the highest 2015 unemployment is " 
					<< states[num_states - 1].name << endl;
				
				break;

			case 4: //lowest 2015 unemployment   
				sort(states, states + num_states, asc_2015);

				cout << "The state with the lowest 2015 unemployment is "
					<< states[0].name << endl; 
				
				break;

			case 5: //states sorted by change in employment
				sort(states, states + num_states, change);
			
				cout << "The states sorted in order by change in employment"
					 << " from 2007 to 2015 are: " <<endl; 
				
				for (int i = 0; i < num_states; i++){
					cout << states[i].name << endl;
				}	
			
				break;				
		
			case 6: //states sorted by med income
				sort(states, states + num_states, asc_med);

				cout << "The states sorted in order by median household income are: " 
					<< endl;

				for (int i = 0; i < num_states; i++){
					cout << states[i].name << endl;
				}	 

				break;

			case 7: //county info
				cout << "Choose a state: " << endl;
				
				for (int i = 0; i < num_states; i++){
					cout << i << ": " << states[i].name << endl;
				}


				// Check if state is valid
				int state_choice;
 
				do{	
					cin >> state_choice;
					
					if (state_choice < 0 or (state_choice > num_states - 1))
						cout << "Choose a valid option" <<endl;
				} while (state_choice < 0 or state_choice > (num_states - 1));
	
				//county median incomes
				sort(states[state_choice].counties, states[state_choice].counties
					 + states[state_choice].n_counties, asc_med_2);
				
				cout << "The county with the highest median income is "
					<< states[state_choice].counties[states[state_choice].n_counties - 1].name << endl;				
				cout << "The county with the lowest median income is "
					<< states[state_choice].counties[0].name  << endl;				
					
				//county 2015 unemployments
				sort(states[state_choice].counties, states[state_choice].counties
					 + states[state_choice].n_counties, asc_2015_2);
				
				cout << "The county with the highest 2015 unemployment is "
					<< states[state_choice].counties[states[state_choice].n_counties - 1].name << endl;				
				cout << "The county with the lowest 2015 unemployment is "
					<< states[state_choice].counties[0].name  << endl;				
				
				//counties in order by unemployment change 
				sort(states[state_choice].counties, 
					states[state_choice].counties + states[state_choice].n_counties, asc_change_2);
				
				cout << "The counties sorted in order from change in employment are: " << endl; 
					
				for (int i = 0; i < states[state_choice].n_counties; i++)
					cout << states[state_choice].counties[i].name << endl; 	
					
				//counties in order by median income	
				sort(states[state_choice].counties, states[state_choice].counties
					 + states[state_choice].n_counties, asc_med_2);
				
				cout << "The counties sorted in order by median income are: " << endl;
						
				for (int i = 0; i < states[state_choice].n_counties; i++)
					cout << states[state_choice].counties[i].name << endl;
			
				break;

			default:
				cout << "Not a valid option." << endl;
			
				break; 
		} 
	
		//ask if user wants to continue the program
		do{
			cout <<  "Do you want to continue? Enter 1 for yes and 0 for no." << endl;
			
			cin >> status;

			if(status != 1 and status != 0)
				cout << "Enter a valid value" <<endl; 
		} while (status != 1 and  status != 0); 
	} while (status ==  1);
	
	free_state_data(states, num_states);
	
	return 0;
}
