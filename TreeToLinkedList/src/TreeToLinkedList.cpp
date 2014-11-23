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
#include <iostream>
#include <stdlib.h>


struct Node
{
	int value;
	Node *prev;
	Node *next;
};

Node link9 = {15, NULL, NULL};
Node link8 = {10, NULL, NULL};
Node link7 = {4, NULL, NULL};
Node link6 = {12, &link8, &link9};
Node link5 = {5, NULL, NULL};
Node link4 = {5, &link7, NULL};
Node link3 = {2, NULL, NULL};
Node link2 = {8, &link5, &link6};
Node link1 = {3, &link3, &link4};
Node link0 = {5, &link1, &link2};

Node *Head = NULL;

void PrintLinkedList(struct Node* head)
{
	while (head != NULL)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}


void TreeToLinkedList(Node *treeLink, Node **head, Node **tail)
{
	if (NULL == treeLink) {return;}

	Node *newTail = NULL;
	Node *newHead = NULL;
	if (treeLink->prev != NULL)
	{
		TreeToLinkedList(treeLink->prev, &newHead, &newTail);
		newTail->next = treeLink;
		*head = newHead;
	}
	else
	{
		if (*head == NULL) *head = treeLink;
	}

	newHead = NULL;
	newTail = NULL;
	if (treeLink->next != NULL)
	{
		TreeToLinkedList(treeLink->next, &newHead, &newTail);
		treeLink->next = newHead;
		*tail = newTail;
	}
	else
	{
		*tail = treeLink;
	}
}

int main(void)
{
	Node *head = NULL;
	Node *tail = NULL;
	TreeToLinkedList(&link0, &head, &tail);
	PrintLinkedList(head);
	return EXIT_SUCCESS;
}
