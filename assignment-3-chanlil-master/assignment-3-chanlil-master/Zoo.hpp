/*********************************************************************
** Program Filename: Zoo.hpp
** Author: Lilian Chan
** Date: 2/16/2019
** Description: This is the header file for the zoo.
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP
#include "Animal.hpp"
#include "Monkey.hpp"
#include "Otter.hpp"
#include "Sloth.hpp"

class Zoo{
	private:
		Monkey* monkeys;
		Otter* otters;
		Sloth* sloths;
		int mon_num;
		int ott_num;
		int slo_num;
		double money;
		int days;
		int adults;
		int babies;
		int mon_babies;
		int mon_adults;
		int ott_babies;
		int ott_adults;
		int slo_babies;
		int slo_adults;
		int ani_num;
		double food_price;
		int mon_mult;
		int slo_mult;
		int ott_mult;
		double randomizer;
	public:
		//Zoo functions
		Zoo();
		~Zoo();
		void set_money(double);
		double & get_money();
		void subtract_mon(double);
		void set_days(int);
		int & get_days();
		void new_day();
		void buy_ani();
		void buy_mon();
		void buy_slo();
		void buy_ott();
		void food_rand();
		void buy_food();
		void mon_food();
		void ott_food();
		void slo_food();
		void special();
		void sickness();
		int choose_animal();
		void birth();
		void boom();
		void count_adu_bab();
		int bankrupt();
		void display_info();
		void add_earnings();
		
		//monkey
		int get_num_monkey();
		//Monkey & get_monkey(int);
		void add_monkey(int);
		void kill_monkey(int);
		//void display_monkey(int);
		
		//sloth
		int get_num_sloth();
		//Sloth & get_sloth(int);
		void add_sloth(int);
		void kill_sloth(int);
		//void display_sloth(int);
		
		//sea_otter
		int get_num_otter();
		//Monkey & get_otter(int);
		void add_otter(int);
		void kill_otter(int);
		//void display_otter(int);
};

#endif

