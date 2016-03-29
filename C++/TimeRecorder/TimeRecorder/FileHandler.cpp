/*
FileHandler.cpp
Connor Rawls - 2016
*/

#include "FileHandler.h"

void readRosterFile(std::vector<Swimmer> &s, std::string filename)
{
	std::ifstream file_in(filename);
	std::string line;
	while(std::getline(file_in, line))
	{
		std::string fname,lname,age;
		
		if(line.length() > 3)
		{
			int m = 0;
			for(int i = 0; i < line.length(); i++)
			{
				if(line[i] != '|' && line[i] != '\n')
				{
					if(m == 0)
					{
						fname += line[i];
					}
					else if(m == 1)
					{
						lname += line[i];
					}
					else if(m == 2)
					{
						age += line[i];
					}
				}
				else if(line[i] == '|')
				{
					m++;
				}
				
			}
			
			std::cout << "\nLoaded : " << fname << " " << lname;
			
			int chars = fname.length() + lname.length() + 1;
			
			while(chars < 32)
			{
				std::cout << "\t";
				chars += 4;
			}
			
			std::cout << "Age: " << age;
			
			Swimmer ns(fname, lname, stoi(age));
			
			s.push_back(ns);
			
			std::cout << "List Size: " << s.size();
		}
		
	}
	
	file_in.close();
	
}

void readFile(std::vector<Swimmer> &s, std::string filename)
{
	std::ifstream file_in(filename);
	std::string line,info,fname,lname,age;
	Swimmer swim("temp" , "temp", 0);
	while(std::getline(file_in, line))
	{
		//create a new Swimmer object
		if(line.compare("Swimmer\n") == 0)
		{
			std::getline(file_in, info);
			int i, m = 0;
			for(i = 0; i < info.length(); i++)
			{
				if(info[i] != '|' && info[i] != '\n')
				{
					if(m == 0)
					{
						fname += info[i];
					}
					else if(m == 1)
					{
						lname += info[i];
					}
					else
					{
						age += info[i];
					}
				}
				else if(info[i] == '|')
				{
					m++;
				}
			}
			Swimmer temp(fname, lname, std::stoi(age));
			swim = temp;
		}
		
		//detect records
		else if(line.compare("Records\n") == 0)
		{
			std::string num_recs;
			std::getline(file_in, num_recs);
			int num = std::stoi(num_recs);
			//get as many records as the file says there should be, with a check for end of file
			for(int i = 0; i < num && std::getline(file_in, line); i++)
			{
				int j = 0, k = 0;
				std::string s,d,t,da;
				while(line[j] != '\n')
				{
					if(line[j] != '|')
					{
						if(k == 0)
						{
							s += line[j];
						}
						else if(k == 1)
						{
							d += line[j];
						}
						else if(k == 2)
						{
							t += line[j];
						}
						else if(k == 3)
						{
							da += line[j];
						}
					}
					else if(line[j] == '|')
					{
						k++;
					}
				}
				
				Record r(std::stoi(s), std::stoi(d), t,da);
				swim.addTime(r);
			}
			//add swimmer to the vector
			s.push_back(swim);
		}
	}
	//close the file
	file_in.close();
}


//function to write the contents of the swimmer list to a file (if there is any)
void writeFile(std::vector<Swimmer> s, std::string filename)
{
	
}