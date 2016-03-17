/*
FileHandler.h
Connor Rawls - 2016
*/

#include <fstream> 
#include <iostream>
#include <string>

//function to get and parse data from a file
void readFile(Swimmer* s, string filename);

//function to read a text document roster and create blank swimmers from it
void readRosterFile(Swimmer* s, string filename);

//function to write data out to a file
void writeFile(Swimmer* s, int size, string filename);