/*
 ============================================================================
 Name        : binsearch.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int binsearch_nonrec(int arr[], int find, int len)
{
	int start = 0, end = len-1;
	while (end >= start)
	{
		int split = (start + end)/2;
		if (arr[split] == find) return split;
		else
		{
			if (arr[split] > find)
			{
				end = split - 1;
			}
			else	//if arr[split] < find
			{
				start = split + 1;
			}
		}

	}
	return -1;
}

int binsearch_rec (int arr[], int find, int len)
{
	int start = 0, end = len - 1;
	static int found = -1;
	if (start <= end)
	{
		int mid = end / 2;
		if (arr[mid] == find)
		{
			found = mid;
			return found;
		}
		else if (arr[mid] < find)
		{
			binsearch_rec(&(arr[mid]), find, len-mid);
		}
		else
		{
			binsearch_rec(&(arr[0]), find, mid);
		}
	}
	return found;
}

int main(void)
{
	int array[7] = {-3, 4, 4, 6, 21, 22, 22};
//	printf("found %d at %d\n",22, binsearch(array, 22, sizeof(array)/sizeof(array[0])));
	printf("NonRec found %d at %d\n",4 , binsearch_nonrec(array, 4, 7));
	printf("Recursive found %d at %d\n",4 , binsearch_rec(array, 4, 7));
	return EXIT_SUCCESS;
}
