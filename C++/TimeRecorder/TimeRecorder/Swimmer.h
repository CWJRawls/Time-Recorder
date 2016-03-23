/*
Swimmer.h
Connor Rawls - 2016
*/

#ifndef _SWIMMER
#define _SWIMMER

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Record.h"



class Record;

class Swimmer{
	private:
	int age, num_times;
	std::string fname, lname;
	std::vector<Record> times;
	
	//functions
	void sortTimes(); //function to sort the times by event/time if there are any
	
	public:
	Swimmer(std::string f, std::string l); //constructor
	Swimmer(std::string f, std::string l, int a); //alternate constructor
	
	void setFName(std::string f) {fname = f;} //change the first name of the swimmer
	void setLName(std::string l) {lname = l;} //change the last name of the swimmer
	void setAge(int a) {age = a;} //set the age of the swimmer
	void addTime(Record r); //add a time to the swimmer
	void removeTime(int r); //remove a time from the list
	int getNumTimes() {return times.size();} //function to get the number of times for writing to files
	//functions for sorting help
	std::string getFName() const {return fname;}
	std::string getLName() const {return lname;}
	//function for printing data to the screen
	void printData() {std::cout << lname << ", " << fname << " : " << age;}
};

bool sortSwimmer(const Swimmer &sa, const Swimmer &sb);

#endif