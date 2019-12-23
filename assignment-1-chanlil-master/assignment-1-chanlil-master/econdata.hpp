/*********************************************************************
** Program Filename: econdata.hpp
** Author: Lilian Chan
** Date: 1/16/2019
** Description: This file contains definitions for econdata's
structures and prototypes. These include structs for economic 
information on states and their counties. The prototypes are for
allocating an array of states, an array of counties, reading data
into the two structs, and for freeing the data.   
** Input: None
** Output: None
*********************************************************************/

#ifndef ECONDATA_HPP
#define ECONDATA_HPP

#include <string>
#include <fstream>

struct county {
  std::string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
};

struct state {
  std::string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
  struct county* counties;
  int n_counties;
};

struct state* allocate_states(int);
void read_state_data(struct state*, int, std::ifstream&);
struct county* allocate_counties(int);
void read_county_data(struct county*, int, std::ifstream&);
void free_state_data(struct state*, int);
bool asc_med(const struct state &, const struct state &);
bool asc_2015(const struct state &, const struct state &);
bool change(const struct state &, const struct state &);
bool asc_med_2(const struct county &, const struct county &s12);
bool asc_2015_2(const struct county &, const struct county &);
bool asc_change_2(const struct county &, const struct county &);

#endif
