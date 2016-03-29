/*
FileHandler.h
Connor Rawls - 2016
*/

#include <fstream> 
#include <iostream>
#include <string>
#include <vector>
#include "Swimmer.h"


//function to get and parse data from a file
void readFile(std::vector<Swimmer> &s, std::string filename);

//function to read a text document roster and create blank swimmers from it
void readRosterFile(std::vector<Swimmer> &s, std::string filename);

//function to write data out to a file
void writeFile(std::vector<Swimmer> &s, std::string filename);