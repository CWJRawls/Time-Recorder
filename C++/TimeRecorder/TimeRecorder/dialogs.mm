/*
 dialogs.mm
 Connor Rawls - 2016
*/

#include "dialogs.h"
#include <iostream>
#import <Cocoa/Cocoa.h>

#include <string>

std::string rosterPath() {
    NSArray *URLs;
    NSOpenPanel * panel = [NSOpenPanel openPanel];
    [panel setAllowsMultipleSelection:NO];
    [panel setResolvesAliases:YES];
    [panel setTreatsFilePackagesAsDirectories:YES];
    [panel setMessage:@"Please choose a roster file."];
	[panel setLevel:NSFloatingWindowLevel];
    
    if([panel runModal] == NSModalResponseOK)
	{
		URLs = [panel URLs];
		
		NSURL *nsurl = [[panel URLs] objectAtIndex:0];
		
		std::string output([[nsurl path] UTF8String]);
		
		return output;
	}
	else
	{
		return "none";
	}
	
}

std::string getSavePath(std::string path_in)
{
	NSURL *URL;
	NSSavePanel * panel = [NSSavePanel savePanel];
	[panel setMessage:@"Choose a Location To Save"];
	[panel setLevel:NSFloatingWindowLevel];
	//[panel setAllowedFileTypes:{@"*.tme"}];
	int i = path_in.length();
	while(path_in[i] != '/' && i > -1)
	{i--;}
	std::string file;
	if(i > -1)
	{
		file = path_in.substr(i + 1, path_in.length());
	}
	
	[panel setNameFieldStringValue:@(file.c_str())];
	[panel setDirectoryURL:[NSURL fileURLWithPath:@(path_in.c_str())]];
	
	if([panel runModal] == NSModalResponseOK)
	{
		URL = [panel URL];
		
		std::string output([[URL path] UTF8String]);
		
		return output;
	}
	else
	{
		return "none";
	}
}

