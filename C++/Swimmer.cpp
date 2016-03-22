/*
Swimmer.cpp
Connor Rawls - 2016
*/

#include "Swimmer.h"
#include "Record.h"

Swimmer::Swimmer(string f, string l) //constructor 1
{
	fname = f;
	lname = l;
	age = 0;
}

Swimmer::Swimmer(string f, string l, int a) //constructor 2
{
	fname = f;
	lname = l;
	age = a;
}

void Swimmer::sortTimes() //function to sort times if there are any
{
	if(times.size() > 1) //check for more than one
	{
		std::sort(times.begin(), times.end(), sortTimes);
		post("Records Sorted");
	}
	else
	{
		post("Not enough records to sort");
	}
}

void Swimmer::addTime(Record r) //add a time to the vector and sort
{
	times.push_back(r);
	sortTimes();
	post("Time Added");
}

void Swimmer::removeTime(int r) //remove a time and then sort
{
	times.erase(times.begin() + r);
	sortTimes();
	post("Time Removed");
}

bool sortSwimmer(const Swimmer &sa, const Swimmer &sb)
{
	int a = sa.getLName().compare(sb.getLName());
	
	if(a < 0)
	{
		return true;
	}
	else if(a == 0)
	{
		a = sa.getFName().compare(sb.getFName());
		
		if(a < 0)
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