/*
 ============================================================================
 Name        : TreeToLinkedList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/************************************************************
 *
 *             ------------5------------
 *      -------3-------           ------8-------
 *      2           ---5          5           --12--
 *                  4                        10    15
 *
 ************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct LinkStr
{
	int data;
	struct LinkStr *prev;
	struct LinkStr *next;
};

struct LinkStr link9 = {15, NULL, NULL};
struct LinkStr link8 = {10, NULL, NULL};
struct LinkStr link7 = {4, NULL, NULL};
struct LinkStr link6 = {12, &link8, &link9};
struct LinkStr link5 = {5, NULL, NULL};
struct LinkStr link4 = {5, &link7, NULL};
struct LinkStr link3 = {2, NULL, NULL};
struct LinkStr link2 = {8, &link5, &link6};
struct LinkStr link1 = {3, &link3, &link4};
struct LinkStr link0 = {5, &link1, &link2};

struct LinkStr *Head = NULL;

//struct LinkStr * TreeToLinkedList(struct LinkStr *treeLink, struct LinkStr **current)
//{
//	if (NULL != treeLink->prev)
//	{
//		treeLink->prev = TreeToLinkedList(treeLink->prev, current);
//		//		temp = TreeToLinkedList(treeLink->prev, current);
//	}
//
//	//	if (*current == NULL)
//	//	{
//	//		(*current) = treeLink;
//	//		Head = *current;
//	////		treeLink->prev = NULL;
//	//	}
//	//	else
//	//	{
//	//		(*current)->next = treeLink;
//	//	}
//
//	(*current) = treeLink;
//	if (*current == NULL)
//	{
//		Head = *current;
//	}
//	else
//	{
//		(*current)->prev->next = treeLink;
//	}
//
//	if (NULL != treeLink->next)
//	{
//		(*current)->next = TreeToLinkedList(treeLink->next, current);
//	}
//
//	return treeLink;
//}




//does not work
void TreeToLinkedList(struct LinkStr *treeLink, struct LinkStr **current)
{
	struct LinkStr *temp = treeLink;
	if (NULL != treeLink->prev)
	{
		TreeToLinkedList(treeLink->prev, current);
	}

	temp->prev = *current;
	if(*current != NULL)
	{
		(*current)->next = temp;
	}
	printf("%d\t", (*current)->data);

	*current = temp;

	if (NULL != treeLink->next)
	{
		TreeToLinkedList(treeLink->next, current);
	}
}

int main(void)
{
//
//	TreeToLinkedList(&link0, &Head);
//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//
//	struct LinkStr *ptr;
//	for (ptr = Head; ptr != NULL; ptr = ptr->next)
//	{
//		printf("%d\t", ptr->data);
//	}

	return EXIT_SUCCESS;
}
