/*
 ============================================================================
 Name        : StringContextPrint.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char* testFunc(char *string)
{
//	printf ("%s", string);
	printf ("got to the testFunc\n");
	return string;
}



int main(void)
{
	char * string1 = "string1\n";
	char * string2 = "string2\n";
	printf(testFunc(string1));
	testFunc(string2);
	printf(testFunc(string1));
	testFunc(string2);
	return EXIT_SUCCESS;
}
