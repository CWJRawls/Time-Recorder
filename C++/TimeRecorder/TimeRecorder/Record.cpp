/*
Record.cpp
Connor Rawls - 2016
*/

#include "Record.h"

//CONSTRUCTORS
Record::Record(int ev, int di, std::string ti, std::string da)
{
	//set members that need no additional computing
	e = ev;
	d = di;
	time = ti;
	date = da;
	
	mins = 0;
	secs = 0;
	milis = 0;
	
	setStroke(e);
	setDistance
	
	
	(d);
	convertStringtoInts(ti);
	
	//set the time string from the converted integer values.
	time = "";
	time = mins;
	time += ":";
	time += secs;
	time += ".";
	time += milis;
	
}
/*
Record::Record(Record& other)
{
	//set members from other class
	e = other.cEvent();
	d = other.cDist();
	time = other.getTime();
	date = other.getDate();
	mins = other.cMin();
	secs = other.cSec();
	milis = other.cMili();
	event = other.getEvent();
	stroke = other.getStroke();
	distance = other.getDist();
} */

//PRIVATE FUNCTIONS
void Record::convertStringtoInts(std::string t) 
{
	bool valid = true; //flag to avoid trying to parse invalid input
	int i;
	std::string temp;
	for(i = 0; i < t.length() && valid; i++)
	{
		switch(t[i])
		{
			case ':': //found the separator between mins and secs
				mins = stoi(temp);
				break;
			case '.': //found the separator between secs and milis
				secs = stoi(temp);
				break;
			//Define all valid cases
			case '0':
				temp += t[i];
				break;
			case '1':
				temp += t[i];
				break;
			case '2':
				temp += t[i];
				break;
			case '3':
				temp += t[i];
				break;
			case '4':
				temp += t[i];
				break;
			case '5':
				temp += t[i];
				break;
			case '6':
				temp += t[i];
				break;
			case '7':
				temp += t[i];
				break;
			case '8':
				temp += t[i];
				break;
			case '9':
				temp += t[i];
				break;
			default:
				valid = false;
				std::cout << "\nError with time input!";
				std::cout << "\nExpected a number . or :  instead found " << t[i] << ".";
				std::cout << "\nSetting time to default value";
				break;
		}
		
		//reset temp at the end of the string if valid and not a seperator character
		if(i == t.length() - 1 && (t[i] != '.' && t[i] != ':') && valid)
		{
			milis = stoi(temp);
		}
	}
	
	if(!valid) //reset values for invalid data entry
	{
		mins = 0;
		secs = 0;
		milis = 0;
	}
	
	//remind users to double check entry for suspect values
	if(secs > 59)
	{
		std::cout << "\nReceived a value for seconds of 60 or more.";
		std::cout << "\nPlease check to make sure you have entered data correctly";
	}
	
	if(milis > 99)
	{
		std::cout << "\nRecieved a miliseconds time of 100 or more.";
		std::cout << "\nPlease check to make sure you have entered data correctly";
	}
	
}

void Record::createEventString()
{
	event = distance;
	event += " ";
	event += stroke;
	
	std::string out = "Event = ";
	out += event;
}

//PUBLIC FUNCTIONS
void Record::setTime(std::string t)
{
	time = t;
	convertStringtoInts(time);
	
	std::string out = "Time = ";
	out += time;
	
}

void Record::setStroke(int s)
{
	switch(s) //switch statement to match input option with string representation
	{
		case 1:
			stroke = "Freestyle";
			break;
		case 2:
			stroke = "Backstroke";
			break;
		case 3:
			stroke = "Breaststroke";
			break;
		case 4:
			stroke = "Butterfly";
			break;
		case 5:
			stroke = "I.M.";
			break;
	}
	
	std::string out = "Stroke = ";
	out += stroke;
	//post(out);
}

void Record::setDistance(int d)
{
	switch(d) //switch statement to match input option with string representation
	{
		case 1:
			distance = "25";
			break;
		case 2:
			distance = "50";
			break;
		case 3:
			distance = "100";
			break;
		case 4:
			distance = "200";
			break;
		default:
			distance = "???";
	}
	
	std::string out = "Dist = ";
	out += distance;
	//post(out);
	
}

void Record::setDate(std::string d)
{
	date = d;
	std::string out = "Date = ";
	out += d;
	//
	//post(out);
}

void Record::printData()
{
	if(e < 5)
	{
		std::cout << event << "\t" << time << "\t" << date;
	}
	else if(e == 5)
	{
		std::cout << event << "\t\t\t" << time << "\t" << date;
	}
	else
	{
		std::cout << event << "\t" << time << "\t" << date;
	}
}

/*function to return the value of the record as a string in the format of:
 integer stroke|integer distance|string time|string date
 */
std::string Record::getSaveData()
{
	std::string output = "";
	output += e;
	output += "|";
	output += d;
	output += "|";
	output += time;
	output += "|";
	output += date;
	
	return output;
	
}

/*
//Operators
bool Record::operator<(<#const Record &rb#>) //operator to help vector sorting of times
{
	if(e < rb.getSEvent())
	{
		return true;
	}
	else if(e == rb.getSEvent())
	{
		if(d < rb.getSDist())
		{
			return true;
		}
		else if(d == rb.getSDist())
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
*/