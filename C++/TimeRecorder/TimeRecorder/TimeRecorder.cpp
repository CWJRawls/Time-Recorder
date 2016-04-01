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

string date = "01/01/1970";


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
void findAndOpenSwimmer(); //ask for an index number and move to the menu for modifying that swimmer
void addSwimmer(); //function for adding a new Swimmer to the list while asking the user for string input
void removeSwimmer(); //function for removing a Swimmer from the list.
void printDate(); //function to print the current date
void changeDate(); //function to change the current date;
string getSaveFileName(); //temporary function on OS X to get around uneditable text field issue when saving.

/* Functions for Swimmer Menu */
void swimmerMenu(int s);//function for the menu level to modify a swimmer object

/* Utility Functions */
int getIntegerInput(); //function for type checked integer input from cin
char getCharInput(); //function to get only the first char from cin
string getStringInput();//function to get the whole line w/o newline char from cin
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
				team_file = roster_file.substr(0,roster_file.length() - 3);
				team_file += "tme";
				cout << roster_file;
				readRosterFile(swimmer_list, roster_file);
				sort(swimmer_list.begin(), swimmer_list.end());
				modifyTeam();
				break;
			case '2':
				team_file = getRosterFile();
				cout << team_file;
				readFile(swimmer_list, team_file);
				sort(swimmer_list.begin(), swimmer_list.end());
				modifyTeam();
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

string getStringInput()
{
	string input = "";
	getline(cin, input);
	while(input.length() == 0) //detect user just hitting enter
	{
		cout << "Nothing received, please try again";
		getline(cin, input);
	}
	
	return input;
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
	cout << "\n\n1. Add a Swimmer\n2. Edit a Swimmer\n3. Delete a Swimmer\n4. Change Date\n5. Save\n6. Save As\nD. Print Date\nP. Print Swimmer List\n?. Reprint Options\nX. Exit to starting menu\n";
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
		cout << "\n";
	}
	else
	{
		cout << "\nNo Swimmers in List!";
	}
}

void modifyTeam()
{
	std::string path = "";
	cout << "\n\nPlease enter the date for times being entered (mm/dd/yyyy)\n";
	date = getStringInput();
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
				addSwimmer();
				break;
			case '2':
				findAndOpenSwimmer();
				break;
			case '3':
				removeSwimmer();
				break;
			case '4':
				changeDate();
				break;
			case '5':
				cout << "\nNow Saving....\n";
				writeTeamFile(swimmer_list, team_file);
				break;
			case '6':
				path = getSaveFileName();
				path = getSavePath(team_file);
				if(path.compare("none") == 0)
					break;
				writeTeamFile(swimmer_list, path);
				printMainOptions();
				break;
			case 'd':
				printDate();
				break;
			case 'D':
				printDate();
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


void findAndOpenSwimmer()
{
	cout << "\nEnter the number of the Swimmer to modify:\n";
	int c = getIntegerInput();
	c -= 1;
	
	if(c >= swimmer_list.size() || c < 0)
	{
		cout << "\nError!\nNumber Entered Does not match any swimmers!\n";
	}
	else
	{
		swimmerMenu(c);
	}
}

void addSwimmer()
{
	cout << "\n\nADDING A SWIMMER:\n\nPlease enter the swimmer's first name:\n";
	string f = getStringInput();
	if(f.length() == 1 && f.compare("0") == 0)
	{
		//break out of the function
		cout << "\nFunction escape code found! Returning to menu.\n";
	}
	else //continue as normal
	{
		cout << "\nPlease enter the swimmer's last name:\n";
		string l = getStringInput();
		cout << "\nPlease enter the swimmer's age:\n";
		int a = getIntegerInput();
	
		Swimmer temp(f, l, a);
	
		swimmer_list.push_back(temp);
	
		cout << "\nAdded " << f << " " << l << " to the list\n";
		
		sort(swimmer_list.begin(), swimmer_list.end());
		printSwimmerList();
	}
}

void removeSwimmer()
{
	cout << "\nREMOVING A SWIMMER\n\nPlease enter the index of the swimmer to remove. Enter 0 to cancel\n";
	int index = getIntegerInput();
	index -= 1;
	
	if(index < 0)
	{
		cout << "\nOperation cancelled, returning to menu\n";
		printMainOptions();
	}
	else if(index > swimmer_list.size() - 1)
	{
		cout << "\nInvalid input, returning to menu\n";
		printMainOptions();
	}
	else
	{
		//confirm user intent to delete data
		cout << "You are erasing : ";
		swimmer_list[index].printData();
		cout << "\nAre you sure? (y/n)\t";
		//wait for confirmation input
		char o = getCharInput();
		
		//delete if confirmed
		if(o == 'y' || o == 'Y')
		{
			swimmer_list.erase(swimmer_list.begin() + index);
			cout << "\nSwimmer erased.\n";
			printSwimmerList();
		}
		else
		{
			cout << "\nSwimmer delete cancelled.\n";
		}
		
	}
}

void printDate()
{
	cout << "\nCurrent date in use: " << date << "\n";
}

void changeDate()
{
	cout << "\nCHANGING DATE\nPlease enter a new date (mm/dd/yyyy)\n";
	date = getStringInput();
	cout << "\nDate set to: " << date << "\n";
}

string getSaveFileName()
{
	int start = team_file.length();
	int end = team_file.length() - 4;
	while(team_file[start - 1] != '/' && start > -1)
	{start--;}
	int npos = end - start;
	cout << "\nfirst slash at " << start << " period at " << end;
	cout << "\nCurrent file name is " << team_file.substr(start, npos);
	cout << "\nWould you like to change the file name? (y/n)\n";
	char c = getCharInput();
	string output = team_file;
	if(c == 'y' || c == 'Y')
	{
		cout << "\nPlease Enter the new name\n";
		output = getStringInput();
		output += ".tme";
		
		team_file = team_file.substr(0,start);
		team_file += output;
	}
	
	return team_file;
}

/* SWIMMER MENU FUNCTIONS */

void swimmerMenu(int s)
{
	Swimmer & swim = swimmer_list[s]; //get a reference to the object we want to change
	
	swim.printData();
	//do stuff to the swimmer object
}
