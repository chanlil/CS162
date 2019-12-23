/*********************************************************************
** Program Filename: econdata.cpp 
** Author: Lilian Chan
** Date: 1/16/2019
** Description: This file contains the functions for econdata. The 
functions are to create state and county structs, fill them, and free
their data. 
** Input: None
** Output: None
*********************************************************************/

#include "econdata.hpp"
#include <fstream>
#include <string>

using namespace std;

/*********************************************************************
** Function: allocate_states
** Description: Allocates an array of states. The size is specified 
by the user. 
** Parameters: s_num
** Pre-Conditions: Defined number of states
** Post-Conditions: Returns pointer to array of states.  
*********************************************************************/ 

struct state* allocate_states(int s_num){
	struct state* s_array = new struct state[s_num];

	return s_array; 
}

/*********************************************************************
** Function: read_state
** Description: Reads state data into state array.
** Parameters: *s_array, inputFile, i
** Pre-Conditions: Need to have an input file and a state array
** Post-Conditions: Fills in state array
*********************************************************************/ 

void read_state_data(struct state* s_array, int i, std::ifstream& inputFile){
	inputFile >> s_array[i].name >> s_array[i].unemployed_2007
		>> s_array[i].unemployed_2015 >> s_array[i].med_income 
		>> s_array[i].n_counties;
}

/*********************************************************************
** Function: allocate_counties
** Description: This allocates a county array.  
** Parameters: c_num
** Pre-Conditions: Have the number of counties.
** Post-Conditions: Returns a pointer to a county array.
*********************************************************************/ 

struct county* allocate_counties(int c_num){
	struct county* c_array = new struct county[c_num];
	 
	return c_array;
}

/*********************************************************************
** Function: read_county_data
** Description: This reads county data into the county array.
** Parameters: *c_array, c_num, inputFile 
** Pre-Conditions: Have a county array, number, and input file  
** Post-Conditions: Reads data into county array
*********************************************************************/ 

void read_county_data(struct county* c_array, int c_num, std::ifstream& inputFile){
	for (int i = 0; i < c_num; i++){
		inputFile >> c_array[i].name >> c_array[i].unemployed_2007
			>> c_array[i].unemployed_2015
			>> c_array[i].med_income;
	}
}

/*********************************************************************
** Function: free_state_data
** Description: Frees the dynamically allocated arrays
** Parameters: *s_array, s_num
** Pre-Conditions: Have a state array and state number
** Post-Conditions: Free all data
*********************************************************************/ 

void free_state_data(struct state* s_array, int s_num){
	for (int i = 0; i < s_num; i++)
		delete [] s_array[i].counties;
	
	delete [] s_array;
}

/*********************************************************************
** Function: asc_med
** Description: Sorts the median incomes in ascending order.
** Parameters: &s1, &s2
** Pre-Conditions: Be used in sort function.  
** Post-Conditions: Sorts the median incomes.
*********************************************************************/ 
    
bool asc_med(const struct state &s1, const struct state &s2){
	return s1.med_income < s2.med_income;
}

/*********************************************************************
** Function: asc_2015
** Description: Sorts 2015 unemployment rate in ascending order. 
** Parameters: &s3, &s4
** Pre-Conditions: Be used in sort function.
** Post-Conditions: Sorts 2015 unemployment rate.
*********************************************************************/ 

bool asc_2015(const struct state &s3, const struct state &s4){
	return s3.unemployed_2015 < s4.unemployed_2015;
}

/*********************************************************************
** Function: change
** Description: Sorts the change in unemployment.
** Parameters: &s5, &s6 
** Pre-Conditions: Be used in sort function.
** Post-Conditions: Sorts change in employment.
*********************************************************************/ 

bool change(const struct state &s5, const struct state &s6){
	return (s5.unemployed_2007 - s5.unemployed_2015) 
		> (s6.unemployed_2007 - s6.unemployed_2015);
}
		
/*********************************************************************
** Function: asc_med_2
** Description: Sorts median income of counties.
** Parameters: &c1, &c2
** Pre-Conditions: Be used with sort function.
** Post-Conditions: Sorts median incomes.
*********************************************************************/ 


bool asc_med_2(const struct county &c1, const struct county &c2){
	return c1.med_income < c2.med_income;
}	

/*********************************************************************
** Function: asc_2015_2
** Description: Sorts 2015 unemployment.
** Parameters: &c3, &c4
** Pre-Conditions: Be used in sort function
** Post-Conditions: Sorts 2015 unemployment.
*********************************************************************/ 


bool asc_2015_2(const struct county &c3, const struct county &c4){
	return c3.unemployed_2015 < c4.unemployed_2015;
}	

/*********************************************************************
** Function: asc_change_2
** Description: Sorts change in employment for counties.
** Parameters: &c5, &c6
** Pre-Conditions: Be used in sort function.
** Post-Conditions: Sorts change in employment. 
*********************************************************************/ 


bool asc_change_2(const struct county &c5, const struct county &c6){
	return (c5.unemployed_2007 - c5.unemployed_2015)
		 > (c6.unemployed_2007 - c6.unemployed_2015);
}		
 	


