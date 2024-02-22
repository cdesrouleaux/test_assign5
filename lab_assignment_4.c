#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	// temp moves through the linked list
	node * temp = (node*)malloc(sizeof(node));
	temp = head;
	
	int count = 0;
// simple counter
	while(temp != NULL)
	{
		temp = temp->next; 
		count++;
	}

	// free(temp);
	return count;
	
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function will return "abc"
// making 
char* toCString(node* head)
{
	node * temp = head;
	int l = length(head);
	char * str = (char*)malloc((l+1)*sizeof(char));
	int i = 0;

	while (temp != NULL)
	{
		str[i] = temp->letter;
		temp = temp->next;
		i++;
	}

	// free(temp);
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
// adds to the end of the linked list
void insertChar(node** pHead, char c) // ** b/c its a pointer pointing to another pointer
{
	// t moves through the linked list // temp holds a node with 2 parts data and next
	node * temp = (node*) malloc(sizeof(node));
	node * t = *pHead;
	temp->letter = c;
	temp->next = NULL;

	// checks initial condition and makes sure there there is a first node in the array
	if(*pHead == NULL)
		*pHead = temp;
	else
	{
		// loops through the linked list
		while(t->next != NULL) 
		{
			t = t->next;
		}

		// adds a new node to the end of the list
		t->next = temp;
	}
	// free(temp);

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{	
	// temp moves through the linked list
	node * temp = (node*) malloc(sizeof(node));
	temp = *pHead;

// deletes nodes starting from the rear of the linkedlist
	while(temp != NULL)
	{
		free(temp);
		// temp = *pHead;
		temp = temp->next;
	}

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}