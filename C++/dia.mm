//
//  dia.cpp
//  DialogTstc++
//
//  Created by Frank Caggiano on 1/7/15.
//  Copyright (c) 2015 Frank Caggiano. All rights reserved.
//

#include "dia.h"
#include <iostream>
#import <Cocoa/Cocoa.h>

#include <string>

void path() {
    NSArray *URLs;
    NSOpenPanel * panel = [NSOpenPanel openPanel];
    [panel setAllowsMultipleSelection:NO];
    [panel setResolvesAliases:YES];
    [panel setTreatsFilePackagesAsDirectories:YES];
    [panel setMessage:@"Please choose an image file."];
    
    std::cout << "Hello, World!\n";
    
    [panel runModal];
    URLs = [panel URLs];
    
}