//============================================================================
// Name        : SubstringDistance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Problem: Implement a function which gets the edit distance of two input strings. There are three types of edit operations: insertion, deletion and substitution. Edit distance is the minimal number of edit operations to modify a string from one to the other.
//For example, the edit distance between “Saturday” and “Sunday” is 3, since the following three edit operations are required to modify one into the other:
//1.       Saturday -> Sturday (deletion of ‘a’)
//2.       Sturday -> Surday (deletion of ‘t’)
//3.       Surday -> Sunday (substitution of ‘n’ for ‘r’)
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int DistanceInit(char *strFrom, char *strTo)
{
	int fromLen = strlen(strFrom);
	bool fromUseFlag[fromLen] = malloc((fromLen / 8) + 1);
	int toLen = strlen(strTo);
	bool toUseFlag[toLen] = malloc((toLen / 8) + 1);

	char* compString = (fromLen > toLen) ? strFrom : strTo;
}

int main(void)
{
	return EXIT_SUCCESS;
}
