/*
Record.h
Connor Rawls - 2016
*/

#ifndef _RECORD
#define _RECORD

#include <string>
#include <iostream>


class Record{
	private:
	std::string event, stroke, distance,time,date;
	int e,d; // integer representations preserved for sorting purposes
	int mins,secs,milis;
	
	void convertStringtoInts(std::string t); //function to fill integer storage of time from string input
	void createEventString();
	
	public:
	Record(int ev, int di, std::string ti, std::string da);//constructor
	//Record(Record& other); // copy constructor
	void setTime(std::string t);
	void setStroke(int s);
	void setDistance(int d);
	void setDate(std::string d);
	//sorting helper functions
	int getSEvent() const {return e;} //returns the stroke
	int getSDist() const {return d;}
	int getMin() const {return mins;}
	int getSec() const {return secs;}
	int getMili() const {return milis;}
	//functions to help the copy constructor
	int cEvent() {return e;}
	int cDist() {return d;}
	int cMin() {return mins;}
	int cSec() {return secs;}
	int cMili() {return milis;}
	//functions for data presentation
	void printData();
	//functions to present time as a string for timesheets
	std::string getTime() {return time;}
	std::string getDate() {return date;}
	std::string getEvent() {return event;}
	std::string getStroke() {return stroke;}
	std::string getDist() {return distance;}
	//function for saving data into file
	std::string getSaveData();
	//Operators
	friend bool operator<(const Record &ra, const Record &rb)
	{
		if(ra.getSEvent() < rb.getSEvent())
		{
			return true;
		}
		else if(ra.getSEvent() == rb.getSEvent())
		{
			if(ra.getSDist() < rb.getSDist())
			{
				return true;
			}
			else if(ra.getSDist() == rb.getSDist())
			{
				if(ra.getMin() < rb.getMin())
				{
					return true;
				}
				else if(ra.getMin() == rb.getMin())
				{
					if(ra.getSec() < rb.getSec())
					{
						return true;
					}
					else if(ra.getSec() == rb.getSec())
					{
						if(ra.getMili() < rb.getMili())
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}

	
};

//bool sortTimes(const Record &ra, const Record &rb); //sort function for records in the vector

#endif