/*
Swimmer.cpp
Connor Rawls - 2016
*/

#include "Swimmer.h"

Swimmer::Swimmer(std::string f, std::string l) //constructor 1
{
	fname = f;
	lname = l;
	age = 0;
}

Swimmer::Swimmer(std::string f, std::string l, int a) //constructor 2
{
	fname = f;
	lname = l;
	age = a;
}

void Swimmer::sortTimes() //function to sort times if there are any
{
	if(times.size() > 1) //check for more than one
	{
		std::sort(times.begin(), times.end());
		//post("Records Sorted");
	}
	else
	{
		//post("Not enough records to sort");
	}
}

void Swimmer::addTime(Record r) //add a time to the vector and sort
{
	times.push_back(r);
	sortTimes();
	//post("Time Added");
}

void Swimmer::removeTime(int r) //remove a time and then sort
{
	times.erase(times.begin() + r);
	sortTimes();
	//post("Time Removed");
}

bool operator<(const Swimmer &sa, const Swimmer &sb)
{
	if(sa.getAge() < sb.getAge())
	{
		return true;
	}
	else if(sa.getAge() == sb.getAge())
	{
		if(sa.getLName().compare(sb.getLName()) < 0)
		{
			return true;
		}
		else if(sa.getLName().compare(sb.getLName()) == 0)
		{
			if(sa.getFName().compare(sb.getFName()) < 0)
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

bool operator>(const Swimmer &sa, const Swimmer &sb)
{
	if(sa.getAge() > sb.getAge())
	{
		return true;
	}
	else if(sa.getAge() == sb.getAge())
	{
		if(sa.getLName().compare(sb.getLName()) < 0)
		{
			return true;
		}
		else if(sa.getLName().compare(sb.getLName()) == 0)
		{
			if(sa.getFName().compare(sb.getFName()) < 0)
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