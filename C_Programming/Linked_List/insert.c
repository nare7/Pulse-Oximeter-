//#include<stdio.h>
#include"insert.h"
//#include<stdlib.h>

struct Node *createNode(int data)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("Memory Allocation Failed....\n");
		return NULL;
	}
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}

void insert_at_begining(struct Node **head,int data)
{

	struct Node *newNode = createNode(data);
	newNode->next = *head;
	*head=newNode;
}

void insertatend(struct Node** head, int data) 
{
	struct Node *newNode = createNode(data);
    	if (*head == NULL) 
	{
        	*head = newNode;
	
        	return;
    	}
    	struct Node* temp = *head;
    	while (temp->next != NULL) 
	{
        	temp = temp->next;
    	}
    	temp->next = newNode;
}
void insertatpos(struct Node **head,int data,int pos)
{
	int count = 0;
	if(pos==0)
	{
		insert_at_begining (head, data);
		return;
	}
	
	struct Node *newNode = createNode(data);
	struct Node *temp=*head;
	while(temp!=NULL && count<pos-1)
	{
		temp=temp->next;
		count++;
	}
	newNode -> next = temp->next;
	temp->next= newNode;
}
		

/*
#include "insert.h"

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed....\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_at_begining(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
*/
