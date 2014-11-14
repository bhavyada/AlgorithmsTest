/*
 ============================================================================
 Name        : TeslaStateMachine.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


char StateMachine(int input)
{
	static char state = 'A';
	switch (state)
	{
		case 'A':
		{
			if (2 == input)
			{
				state = 'C';
			}
			else if (3 == input)
			{
				state = 'B';
			}
			else
				return 'Z';
			break;
		}
		case 'B':
		{
			if (4 == input)
			{
				state = 'A';
			}
			else if (5 == input)
			{
				state = 'C';
			}
			else
				return 'Z';
			break;
		}
		case 'C':
		{
			if (1 == input)
			{
				state = 'A';
			}
			else if (6 == input)
			{
				state = 'B';
			}
			else
				return 'Z';
			break;
		}
		default:
			return 'Z';

	}
	return state;
}



int main(void)
{
	printf("%c\n", StateMachine(3));
	printf("%c\n", StateMachine(5));
	printf("%c\n", StateMachine(1));
	printf("%c\n", StateMachine(2));
	printf("%c\n", StateMachine(6));
	printf("%c\n", StateMachine(4));
	printf("%c\n", StateMachine(1));

	return EXIT_SUCCESS;
}
