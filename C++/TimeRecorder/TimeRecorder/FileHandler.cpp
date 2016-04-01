/*
FileHandler.cpp
Connor Rawls - 2016
*/

#include "FileHandler.h"

void readRosterFile(std::vector<Swimmer> &s, std::string filename)
{
	std::ifstream file_in(filename); //open the file
	std::string line; //string to hold the current line
	while(std::getline(file_in, line)) //while we haven't reached the end of the file
	{
		std::string fname,lname,age; //strings for basic parts of swimmer constructor
		
		if(line.length() > 5)//make sure that the current line has enough characters to hold single chars separated by |
		{
			int m = 0; //controller for adding data to strings
			for(int i = 0; i < line.length(); i++) //assign chars to the correct strings loop
			{
				if(line[i] != '|' && line[i] != '\n') //exclude | and newlines
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
			
			int chars = fname.length() + lname.length() + 1; //check on length of line for printing to console
			
			std::cout << "\nLoaded : " << fname << " " << lname; //print the created swimmer name
			
			
			
			while(chars < 27) //use tabs to unify spacing
			{
				std::cout << "\t";
				chars += 4;
			}
			
			std::cout << "Age: " << age; //print the age
			
			Swimmer ns(fname, lname, stoi(age));
			
			s.push_back(ns); //add to the vector
		}
		
	}
	
	file_in.close(); //close the file
	
}

void readFile(std::vector<Swimmer> &s, std::string filename)
{
	std::ifstream file_in(filename);
	std::string line,info,fname,lname,age;
	Swimmer swim("temp" , "temp", 0);
	int i = 0;
	while(std::getline(file_in, line))
	{
		std::cout << "\nPass: " << i;
		i++;
		
		//create a new Swimmer object
		if(line.compare("Swimmer") == 0)
		{
			fname = "";
			lname = "";
			age = "";
			std::getline(file_in, info); //get next line which should hold fname|lname|age
			int i, m = 0;//iterator and controller for which string to write to
			for(i = 0; i < info.length(); i++)
			{
				if(info[i] != '|' && info[i] != '\n') //exclude '|' and newlines
				{
					if(m == 0)//writing to fname
					{
						fname += info[i];
					}
					else if(m == 1)//writing to lname
					{
						lname += info[i];
					}
					else //writing to age
					{
						age += info[i];
					}
				}
				else if(info[i] == '|')//move to the next string on '|'
				{
					m++;
				}
			}
			Swimmer temp(fname, lname, std::stoi(age)); //create swimmer with data read from line
			swim = temp; //set our swimmer to be equal to our temporary swimmer
		}
		
		//detect records
		else if(line.compare("Records") == 0)
		{
			std::string num_recs;//string for holding the next line
			std::getline(file_in, num_recs); //get next line which should hold the number of times
			int num = std::stoi(num_recs); //convert the line to an integer
			//get as many records as the file says there should be, with a check for end of file
			for(int i = 0; i < num && std::getline(file_in, line); i++)
			{
				int j = 0, k = 0; //iterator, string controller
				std::string s,d,t,da; //strings to hold portions of data
				while(j < line.length()) //while we are not at the end of the line
				{
					if(line[j] != '|')
					{
						if(k == 0) //write to stroke string
						{
							s += line[j];
						}
						else if(k == 1) //write to distance string
						{
							d += line[j];
						}
						else if(k == 2) //write to time string
						{
							t += line[j];
						}
						else if(k == 3) //write to date string
						{
							da += line[j];
						}
					}
					else if(line[j] == '|') //move to next string
					{
						k++;
					}
				}
				
				Record r(std::stoi(s), std::stoi(d), t,da); //create record with obtained data
				swim.addTime(r); //add the time to the swimmer
			}
			
			std::cout << "\nAdding : ";
			swim.printData();
			//add swimmer to the vector
			s.push_back(swim);
			std::cout << "\nList Size: " << s.size();
		}
	}
	//close the file
	file_in.close();
}


//function to write the contents of the swimmer list to a file (if there is any)
void writeTeamFile(std::vector<Swimmer> &s, std::string filename)
{
	//open the file
	std::ofstream file_out(filename);
	std::cout << "\nSaving to : " << filename;
	for(int i = 0; i < s.size(); i++)
	{
		file_out << "Swimmer\n"; //place Swimmer Header
		file_out << s[i].getSaveData() << "\n";
		file_out << "Records\n"; //place Record Header
		file_out << s[i].getNumTimes() << "\n";
		std::cout << "\nSaving : " << s[i].getFName() << " " << s[i].getLName();
		std::cout << "\nNumber of Times: " << s[i].getNumTimes();
		//loop to add times if there are any
		for(int j = 0; j < s[i].getNumTimes() && s[i].getNumTimes() > 0; j++)
		{
			file_out << s[i].getTime(j).getSaveData() << "\n";
		}
		
	}
	
	std::cout << "\nFile save complete!\n";
	
	file_out.close();
	
}