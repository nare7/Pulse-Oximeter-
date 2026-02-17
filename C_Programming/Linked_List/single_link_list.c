#include<stdio.h>
#include<stdlib.h>
//struct Node *newNode = createNode(data);


//struct Node *createNode(int);
void insertatFirst(int);
void insertatPosition(int,int);
void insertatEnd(int);
void deleteatFirst(void);
void deleteatPosition(int);
void deleteatEnd(void);
void printList(void);
struct Node *createNode(int);

// Defining A Struct Node

struct Node
{
	int data;
	struct Node *next;
};


struct Node *head = NULL;


void main()
{
	printf("Insert at First.....\n");
	insertatFirst(10);
	insertatFirst(20);
	insertatFirst(30);
	printList();


	printf("Insert at any Postion....\n");
	insertatPosition(12,2);
	printList();

	printf("Insert at end ....\n");
	insertatEnd(30);
	printList();

	
	printf("Delete a node at first....\n");
	deleteatFirst();
	printList();

	printf("Delete a node at any Position....\n");
	deleteatPosition(1);
	printList();

	printf("Delete a node at end ......\n");
	deleteatEnd();
        printList();
}


struct Node *createNode(int data)
{
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("Memory Allocation Failed....!!!");
		exit(0);	
	}
	newNode -> data = data;
	newNode -> next = head;
	return newNode;
}


void insertatFirst(int data)
{
	struct Node *newNode = createNode(data);
	head = newNode;
}



void insertatPosition(int data, int pos)
{
	int i;
//	struct Node *newNode = createNode(data);
	if(pos == 0)
	{
		insertatFirst(data);
		return;
	}
	struct Node *temp = head;
	for(i=0;temp != NULL && i < pos - 1;i++)
	{
		temp = temp -> next;
	}
	if(temp == NULL)
	{
		printf("Position Out Of Range....\n");
	
	}
	struct Node *newNode = createNode(data);
	newNode -> next = temp -> next;
	temp -> next = newNode;
}



void insertatEnd(int data)
	{
		struct Node *temp = head;
	while(temp-> next != NULL)
	{
		temp = temp -> next;
	}
	struct Node *newNode = createNode(data);
	temp -> next = newNode;
	newNode -> data = data;
	newNode -> next = NULL;

}




void deleteatFirst()
{
	struct Node *temp = head;
	if(head == NULL)
	{
		printf("List is Empty....\n");
		
	}
	head = head -> next;
	temp -> next = NULL;
	free(temp);
}


void deleteatPosition(int pos)
{

	if(head == NULL)
	{
		printf("List is Empty....\n");
		
	}
	if(pos == 0)
	{	
		deleteatFirst();
		return;
	}
	int i;
	struct Node *temp = head;
	for(i=0;temp!=NULL && i < pos - 1;i++)
	{
		temp = temp -> next;
	}
	if(temp == NULL || temp -> next == NULL)
	{
		printf("Position Out of Range.....\n");
	}
	struct Node *delNode = temp -> next;
	temp -> next = delNode -> next;
	//temp -> next -> next = NULL;
	free(delNode);

}

	
	
void deleteatEnd()
{
	struct Node *temp = head;
	if(head == NULL)
	{
		printf("List is Empty....\n");
	}
	while(temp->next->next != NULL)
	{
		temp = temp -> next;
	}
	free(temp -> next);
	temp -> next = NULL;
	//free(temp -> next);

}

void printList()
{
	struct Node *temp = head;
	while(temp != NULL)
	{
		printf("%d -> ",temp->data);
		//printf("%p -> ",temp->next);
		temp = temp -> next;
	}
	printf("NULL\n");
}
