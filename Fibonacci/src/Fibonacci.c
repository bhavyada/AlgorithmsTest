/*
 ============================================================================
 Name        : Fibonacci.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void FibReg(int len)
{
	int i = 0, j = 1, temp = 0;
	int count;
	for (count = 0; count < len; ++count)
	{
		printf("%d\t", j);
		temp = j;
		j = j + i;
		i = temp;
	}
}

int FibRec(int len)
{
	if (len <= 0) return -1;
	else if (1 == len || 2 == len) {return 1;}
	else
	{
		return (FibRec(len - 1) + FibRec(len - 2));
	}
}

int main(void)
{
	//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	FibReg(10);
	int i;
	for (i = 0; i < 11; ++i)
	{
		printf("%d\t", FibRec(i));
	}
	FibRec(10);
	return EXIT_SUCCESS;
}
