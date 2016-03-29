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

string roster_file, team_file;


vector<Swimmer> swimmer_list;

//forward declare functions

/* Functions for Starting Menu */
void displayStartingOptions(); //displays the first menu when the user starts the program
void printOptionHelp(); //used for getting information about individual options in the first menu
string getRosterFile(); //used for obtaining the text file of the team roster to use
void getandOpenTeamFile(); //used for obtaining the team file to be used
void printVNum(); //function to print the version number

/* Functions for Main Menu */
void modifyTeam(); //function to view and modify swimmers/times
void printMainOptions(); //print options for viewing/modifying swimmers/times
void printSwimmerList(); //print an indexed list of swimmers

/* Functions for Swimmer Menu */
void swimmerMenu(Swimmer &s);//function for the menu level to modify a swimmer object

/* Utility Functions */
int getIntegerInput(); //function for type checked integer input from cin
char getCharInput(); //function to get only the first char from cin
bool confirmExit(); //function to confirm with the user that they would like to quit


/* MAIN FUNCTION */
int main()
{
	cout << "+====================================+\n";
	cout << "| Welcome to the TimeRecorder System |\n";
	cout << "+====================================+\n\n";
	
	while(!end_run) //main application loop
	{
		displayStartingOptions();
		char o = getCharInput();
		switch(o)
		{
			case '1':
				roster_file = getRosterFile();
				cout << roster_file;
				readRosterFile(swimmer_list, roster_file);
				cout << "\nList Size : " << swimmer_list.size();
				sort(swimmer_list.begin(), swimmer_list.end());
				modifyTeam();
				break;
			case '2':
				//open an existing team
				break;
			case '3':
				printVNum();
				break;
			case '?':
				printOptionHelp();
				break;
			case 'X':
				end_run = confirmExit();
				break;
			case 'x':
				end_run = confirmExit();
				break;
			default:
				std::cout << "Unrecognized Command, try again";
				break;
		}
		
	}//end of main application loop
	
	return 1; //end of program
}

/* UTILITY FUNCTIONS */

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

bool confirmExit()
{
	cout << "\nAre you sure you would like to exit? (y/n)\nAll unsaved data will be lost!\n";
	char o = getCharInput();
	
	//only check for a positive response.
	if(o == 'y' || o == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* STARTING FUNCTIONS */

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


/* MAIN MENU FUNCTIONS */

void printMainOptions()
{
	cout << "\n\n1. Add a Swimmer\n2. Edit a Swimmer\n3. Delete a Swimmer\n4. Change Date\n5. Save\n6. Save As\nP. Print Swimmer List\n?. Reprint Options\nX. Exit to starting menu\n";
}

void printSwimmerList()
{
	if(swimmer_list.size() > 0)
	{
		cout << "\n\nSWIMMER LIST-----------------------\n";
		for(int i = 0; i < swimmer_list.size(); i++)
		{
			int j = i + 1;
			cout <<"\n" << j << ". ";
			swimmer_list[i].printData();
		}
	}
	else
	{
		cout << "\nNo Swimmers in List!";
	}
}

void modifyTeam()
{
	bool exit = false;
	//Print all relevant information to the console
	printSwimmerList();
	printMainOptions();
	while(!exit)
	{
		//get char input from user
		char o = getCharInput();
	
		//decide what to do with the input
		switch(o)
		{
			case '1':
			break;
			case '2':
			break;
			case '3':
			break;
			case '4':
			break;
			case '5':
			break;
			case '6':
			break;
			case 'p':
				printSwimmerList();
				break;
			case 'P':
				printSwimmerList();
				break;
			case '?':
				printMainOptions();
				break;
			case 'x':
				exit = confirmExit();
				break;
			case 'X':
				exit = confirmExit();
				break;
			default:
				cout << "Unrecognized Command! Please Retry\n";
				printMainOptions();
				break;
		}
	}
}


/* SWIMMER MENU FUNCTIONS */

