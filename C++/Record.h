/*
Record.h
Connor Rawls - 2016
*/

#include <string>


class Record{
	private:
	string event, distance,time,date;
	int e,d; // integer representations preserved for sorting purposes
	int mins,secs,milis;
	
	void convertStringtoInts(string t); //function to fill integer storage of time from string input
	
	public:
	Record(int e, int d, string t, string d);//constructor
	void setTime(string t);
	void setStroke(int s);
	void setDistance(int d);
	//sorting helper functions
	int getSEvent();
	int getSDist();
	int getMin();
	int getSec();
	int getMili();
	//functions for data presentation
	void printData();
	//function to present time as a string for file storage
	string getTime() {return time;}
	string getDate() {return date;}

	
};

bool sortTimes(const Record &ra, const Record &rb); //sort function for records in the vector