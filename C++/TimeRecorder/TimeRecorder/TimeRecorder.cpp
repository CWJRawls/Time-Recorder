/*
TimeRecorder
C++ implementation - Connor Rawls 2016
*/

using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include "Swimmer.h"
#include "Record.h"
#include "FileHandler.h"
#include "dialogs.h"

#define VERBOSE 1 //sets whether or not to post debugging

//boolean controlling exiting main loop
bool end_run = false;
//boolean controlling whether to close a team file
bool close_file = false;

string vNum = "0.1a\t build: 03222016";

string roster_filt = "txt"; //file type filter for opening roster files as well as saving time sheets.

string team_filt = "tme,txt"; //file type filter for opening and saving team time data



//forward declare functions
void post();
void displayStartingOptions();
void printOptionHelp();
int getIntegerInput(); //function for type checked integer input from cin
char getCharInput(); //function to get only the first char from cin
void printVNum(); //function to print the version number
string getRosterFile();

int main()
{
	cout << "+====================================+\n";
	cout << "| Welcome to the TimeRecorder System |\n";
	cout << "+====================================+\n\n";
	
	while(!end_run) //main application loop
	{
		displayStartingOptions();
		char o = getCharInput();
		std::string filename;
		switch(o)
		{
			case '1':
				filename = getRosterFile();
				std::cout << filename;
				break;
			case '2':
				//open an exoisting team
				break;
			case '3':
				printVNum();
				break;
			case '?':
				printOptionHelp();
				break;
			case 'X':
				end_run = true;
				break;
			case 'x':
				end_run = true;
				break;
			default:
				std::cout << "Unrecognized Command, try again";
				break;
		}
		
	}//end of main application loop
	
	return 1; //end of program
}

void post(string s)
{
	if(VERBOSE == 1)
	{
		cout << s;
	}
}

int getIntegerInput()
{
	string input = "";
	int num = 0;
	while(true) //yes I know this is infinite
	{
		getline(cin, input);
		
		//safe conversion from string to integer
		stringstream intstream(input);
		if(intstream >> num) //exit condition
		{
			break;
		}
		cout << "Invalid Number, try again\n";
	}
	
	return num;
}

char getCharInput()
{
	char char_in = '0';
	string input = "";
	while(true)
	{
		getline(cin, input);
		
		if(input.length() > 0)
		{
			char_in = input[0];
			break;
		}
		
		cout << "Nothing received, please try again";
	}
	
	return char_in;
}

void displayStartingOptions()
{
	cout << "\n\nStart Options\n";
	cout << "1. Create new team from roster text file\n2. Open an existing team";
	cout << "\n3. View program version\n?. Print options help\nX. exit program\n";
}

void printOptionHelp()
{
	cout << "Enter Command Number to see more information, or 0 to exit\n";
	int o = getIntegerInput();
	
	switch(o)
	{
		case 0:
			cout << "\nreturning to starting options";
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << "\nunknown command number, return to starting options";
			break;
	}
}

void printVNum()
{
	cout << "Version : " << vNum;
}

string getRosterFile()
{
	return rosterPath();
}






