//============================================================================
// Name        : BinaryTreeTraversal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Node
{
public:
	int Value;
	struct Node* Left;
	struct Node* Right;
	Node(int val, Node* l, Node* r) : Value(val), Left(l), Right(r) {}
};

class NodeStack
{
	public:
		NodeStack(void) : NodeStackIndex(0) {}
		void StackPush(Node *nodePtr)
		{
			if (NodeStackIndex < MAX_NODES) NodeStackArr[NodeStackIndex++] = nodePtr;
		}

		Node* StackPop(void)
		{
			if (NodeStackIndex > 0) return NodeStackArr[--NodeStackIndex];
			else return NULL;
		}
	private:
		static const int MAX_NODES = 50;
		Node* NodeStackArr[MAX_NODES];
		int NodeStackIndex;
};

class NodeQue
{
	public:
		NodeQue(void) : NodeQueHead(0), NodeQueTail(0), NodeQueCount(0) {}
		void QuePush(Node *nodePtr)
		{
			assert(NodeQueCount < MAX_NODES);
			if (NodeQueHead >= MAX_NODES) {NodeQueHead = 0;}
			NodeQueArr[NodeQueHead++] = nodePtr;
			++NodeQueCount;
		}

		Node* QuePull(void)
		{
			if (NodeQueCount <= 0) return NULL;
			--NodeQueCount;
			if (NodeQueTail >= MAX_NODES) {NodeQueTail = 0;}
			return NodeQueArr[NodeQueTail++];
		}
	private:
		static const int MAX_NODES = 50;
		Node* NodeQueArr[MAX_NODES];
		int NodeQueHead;
		int NodeQueTail;
		int NodeQueCount;
};


void DepthFirst(Node *head)
{
	NodeStack stack;
	if (head != NULL)
	{
		printf("%d ", head->Value);
		if (head->Right != NULL) stack.StackPush(head->Right);
		if (head->Left != NULL) DepthFirst(head->Left);
		Node* tmpNode = stack.StackPop();
		if (tmpNode != NULL) DepthFirst(tmpNode);
	}
}

void TopToBottom(Node *head)
{
	NodeQue saveQue;

	if (head == NULL) return;

	Node *currentNode = head;

	while(currentNode)
	{
		printf("%d ", currentNode->Value);
		if (currentNode->Left)
		{
			saveQue.QuePush(currentNode->Left);
		}
		if (currentNode->Right)
		{
			saveQue.QuePush(currentNode->Right);
		}
		currentNode = saveQue.QuePull();
	}
}

void BottomToTop(Node *head)
{
	NodeStack printStack;
	NodeQue saveQue;

	if (head != NULL) printStack.StackPush(head);
	else return;

	Node *currentNode = head;

	while(currentNode)
	{
		if (currentNode->Right)
		{
			printStack.StackPush(currentNode->Right);
			saveQue.QuePush(currentNode->Right);
		}
		if (currentNode->Left)
		{
			printStack.StackPush(currentNode->Left);
			saveQue.QuePush(currentNode->Left);
		}
		currentNode = saveQue.QuePull();
	}

	currentNode = printStack.StackPop();
	while (currentNode)
	{
		printf("%d ", currentNode->Value);
		currentNode = printStack.StackPop();
	}
}

void BinaryTreeMirror(Node *head)
{
	NodeStack memStack;

	Node *currentNode = head;
	while (currentNode)
	{
		Node *tempNode = currentNode->Right;
		currentNode->Right = currentNode->Left;
		currentNode->Left = tempNode;
		if (NULL != currentNode->Right)
		{
			memStack.StackPush(currentNode->Right);
		}
		if (NULL != currentNode->Left)
		{
			currentNode = currentNode->Left;
		}
		else
		{
			currentNode = memStack.StackPop();
		}
	}

	BottomToTop(head);
}


/********************************************************
									8
				4										17
		3				7					10						25
				      6								12
				   5     6

*********************************************************/

int main()
{
	Node *node5 = new struct Node(5, NULL, NULL);
	Node *node6s = new struct Node(6, NULL, NULL);
	Node *node6 = new struct Node(6, node5, node6s);
	Node *node7 = new struct Node(7, node6, NULL);
	Node *node3 = new struct Node(3, NULL, NULL);
	Node *node4 = new struct Node(4, node3, node7);
	Node *node12= new struct Node(12, NULL, NULL);
	Node *node10= new struct Node(10, NULL, node12);
	Node *node25= new struct Node(25, NULL, NULL);
	Node *node17= new struct Node(17, node10, node25);
	Node *node8 = new struct Node(8, node4, node17);

	printf("DepthFirst\n");
	DepthFirst(node8);
	printf("\n\n");
	printf("TopToBottom\n");
	TopToBottom(node8);
	printf("\n\n");
	printf("BottomToTop\n");
	BottomToTop(node8);
	printf("\n\n");
	printf("BinaryTreeMirror\n");
	BinaryTreeMirror(node8);

//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}