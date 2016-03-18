/*
Swimmer.h
Connor Rawls - 2016
*/

#include <iostream>
#include <string>
#include <vector>

class Record;

class Swimmer{
	private:
	int age, num_times;
	string fname, lname;
	std::vector<Record> times;
	
	//functions
	void sortTimes(); //function to sort the times by event/time if there are any
	
	public:
	Swimmer(string f, string l); //constructor
	Swimmer(string f, string l, int a); //alternate constructor
	
	void setFName(string f) {fname = f;} //change the first name of the swimmer
	void setLName(string l) {lname = l;} //change the last name of the swimmer
	void setAge(int a) {age = a;} //set the age of the swimmer
	void addTime(Record r); //add a time to the swimmer
	void removeTime(int r); //remove a time from the list
	int getNumTimes() {return times.size();} //function to get the number of times for writing to files
	
	
	
};