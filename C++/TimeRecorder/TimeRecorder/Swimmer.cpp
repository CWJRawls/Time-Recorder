/*
Swimmer.cpp
Connor Rawls - 2016
*/

#include "Swimmer.h"


//definition of static data members
int Swimmer::sortPrime = Swimmer::sortAge;
int Swimmer::sortSecondary = Swimmer::sortName;
int Swimmer::sortTertiary = Swimmer::sortRecord;

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

bool Swimmer::hasTime(int t) //safeguard function to check that the index exists
{
	if(t < 0 || t >= times.size())
	{
		return false;
	}
	else
	{
		return true;
	}
}

Record Swimmer::getTime(int t) //get a copy of a time if it exists. If the index does not exist, returns blank record.
{
	if(t < 0 || t >= times.size())
	{
		Record r(1,1,"00:00.00","01/01/1970");
		return r;
	}
	else
	{
		return times[t];
	}
}

void Swimmer::printData()
{
	std::cout << lname << ", " << fname;
	
	int chars = lname.length() + fname.length() + 2;
	
	while(chars < 29)
	{
		std::cout << "\t";
		chars += 4;
	}
	
	std::cout <<" : " << age;
}

std::string Swimmer::getSaveData()
{
	//create and assemble an output string that matches the format fname|lname|age
	std::string output = fname;
	output += "|";
	output += lname;
	output += "|";
	output += std::to_string(age);
	
	return output;
}

bool operator<(const Swimmer &sa, const Swimmer &sb)
{
	int outcome;
	switch(Swimmer::sortPrime)
	{
		case 0:
			outcome = sa.getAge() - sb.getAge();
			if(outcome > 0)
				return false;
			else if(outcome < 0)
				return true;
			break;
		case 1:
			outcome = sa.getLName().compare(sb.getLName());
			if (outcome > 0)
				return false;
			else if(outcome == 0)
			{
				outcome = sa.getFName().compare(sb.getFName());
				
				if(outcome > 0)
					return false;
				else if(outcome < 0)
					return true;
			}
			else if(outcome < 0)
				return true;
			break;
		case 2:
			if(sb.numberOfTimes() == 0 && sa.numberOfTimes() != 0)
				return true;
			else if(sa.numberOfTimes() == 0 && sb.numberOfTimes() != 0)
				return false;
			break;
	}
	
	switch(Swimmer::sortSecondary)
	{
		case 0:
			outcome = sa.getAge() - sb.getAge();
			if(outcome > 0)
				return false;
			else if(outcome < 0)
				return true;
			break;
		case 1:
			outcome = sa.getLName().compare(sb.getLName());
			if (outcome > 0)
				return false;
			else if(outcome == 0)
			{
				outcome = sa.getFName().compare(sb.getFName());
				
				if(outcome > 0)
					return false;
				else if(outcome < 0)
					return true;
			}
			else if(outcome < 0)
				return true;
			break;
		case 2:
			if(sb.numberOfTimes() == 0 && sa.numberOfTimes() != 0)
				return true;
			else if(sa.numberOfTimes() == 0 && sb.numberOfTimes() != 0)
				return false;
			break;
	}
	
	switch(Swimmer::sortTertiary)
	{
		case 0:
			outcome = sa.getAge() - sb.getAge();
			if(outcome > 0)
				return false;
			else if(outcome < 0)
				return true;
			break;
		case 1:
			outcome = sa.getLName().compare(sb.getLName());
			if (outcome > 0)
				return false;
			else if(outcome == 0)
			{
				outcome = sa.getFName().compare(sb.getFName());
				
				if(outcome > 0)
					return false;
				else if(outcome < 0)
					return true;
			}
			else if(outcome < 0)
				return true;
			break;
		case 2:
			if(sb.numberOfTimes() == 0 && sa.numberOfTimes() != 0)
				return true;
			else if(sa.numberOfTimes() == 0 && sb.numberOfTimes() != 0)
				return false;
			break;
	}
	
	return false;
}