/*
Record.h
Connor Rawls - 2016
*/

#include <string>
#include <iostream>


class Record{
	private:
	string event, stroke, distance,time,date;
	int e,d; // integer representations preserved for sorting purposes
	int mins,secs,milis;
	
	void convertStringtoInts(string t); //function to fill integer storage of time from string input
	void createEventString();
	
	public:
	Record(int ev, int di, string ti, string da);//constructor
	void setTime(string t);
	void setStroke(int s);
	void setDistance(int d);
	void setDate(string d);
	//sorting helper functions
	int getSEvent() {return e;}
	int getSDist() {return d;}
	int getMin() {return mins;}
	int getSec() {return secs;}
	int getMili() {return milis;}
	//functions for data presentation
	void printData();
	//function to present time as a string for file storage
	string getTime() {return time;}
	string getDate() {return date;}

	
};

bool sortTimes(const Record &ra, const Record &rb); //sort function for records in the vector