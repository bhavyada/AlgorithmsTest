//============================================================================
// Name        : StringEditDistance.cpp
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

int Distance(char *strFrom, char *strTo)
{
	int dist = 0;
	int fromLen = strlen(strFrom);
	int **distArr = (int **)new int[fromLen + 1];

	int toLen = strlen(strTo);
	for (int i = 0; i < fromLen + 1; ++i)
	{
		distArr[i] = (int *)new int[toLen + 1];
		distArr[i][0] = i;
	}
	for (int j = 0; j < toLen + 1; ++j)
	{
		distArr[0][j] = j;
	}

	for (int i = 1; i < fromLen + 1; ++i)
	{
		for (int j = 1; j < toLen + 1; ++j)
		{
			if (strFrom[i - 1] == strTo[j - 1])
			{
				distArr[i][j] = distArr[i - 1][j - 1];
			}
			else
			{
				int rem = distArr[i][j - 1] + 1;
				int add = distArr[i - 1][j] + 1;
				int repl = distArr[i - 1][j - 1] + 1;

				int less = (rem < add) ? rem : add;
				distArr[i][j] = (less < repl) ? less : repl;
			}
		}
	}

	dist = distArr[fromLen][toLen];
	for (int i = 0; i < fromLen + 1; ++i)
	{
		delete(distArr[i]);
	}
	delete(distArr);

	return dist;
}

int main(void)
{
	char *fromStr = "Sunday";
	char *toStr = "Wednesday";
	printf("distance %s & %s: %d", fromStr, toStr, Distance(fromStr, toStr));
	return EXIT_SUCCESS;
}
