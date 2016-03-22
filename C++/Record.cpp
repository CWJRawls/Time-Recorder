/*
Record.cpp
Connor Rawls - 2016
*/

#include "Record.h"

//CONSTRUCTORS
Record::Record(int ev, int di, string ti, string da)
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
	setDist(d);
	convertStringtoInts(ti);
	
	//set the time string from the converted integer values.
	time = "";
	time = mins;
	time += ":";
	time += secs;
	time += ".";
	time += milis;
	
}

//PRIVATE FUNCTIONS
void Record::convertStringtoInts(string t) 
{
	bool valid = true; //flag to avoid trying to parse invalid input
	int i;
	string temp;
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
				cout << "\nError with time input!";
				cout << "\nExpected a number . or :  instead found " << t[i] << ".";
				cout << "\nSetting time to default value";
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
		cout << "\nReceived a value for seconds of 60 or more.";
		cout << "\nPlease check to make sure you have entered data correctly";
	}
	
	if(milis > 99)
	{
		cout << "\nRecieved a miliseconds time of 100 or more.";
		cout << "\nPlease check to make sure you have entered data correctly";
	}
	
}

void Record::createEventString()
{
	event = distance;
	event += " ";
	event += stroke;
	
	string out = "Event = ";
	out += event;
	post(out);
}

//PUBLIC FUNCTIONS
void Record::setTime(string t)
{
	time = t;
	convertStringtoInts(time);
	
	string out = "Time = ";
	out += time;
	post(out);
	
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
	
	string out = "Stroke = ";
	out += stroke;
	post(out);
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
	
	string out = "Dist = ";
	out += distance;
	post(out);
	
}

void Record::setDate(string d)
{
	date = d;
	string out = "Date = ";
	out += d;
	post(out);
}

void Record::printData()
{
	if(e < 5)
	{
		cout << event << "\t" << time << "\t" << date;
	}
	else if(e == 5)
	{
		cout << event << "\t\t\t" << time << "\t" << date;
	}
	else
	{
		cout << event << "\t" << time << "\t" << date;
	}
}

//NON-MEMBER FUNCTIONS
bool sortTime(const Record &ra, const Record &rb) //method to help vector sorting of times
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
				else if
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