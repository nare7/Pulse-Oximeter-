#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};

void main()
{
	struct Node *head;
	
	struct Node *node1 = NULL;
	struct Node *node2 = NULL;
	struct Node *node3 = NULL;
        struct Node *node4 = NULL;

	node1 = (struct Node*)malloc(sizeof(struct Node));
	node2 = (struct Node*)malloc(sizeof(struct Node));
	node3 = (struct Node*)malloc(sizeof(struct Node));
        node4 = (struct Node*)malloc(sizeof(struct Node));

	head = node1;
	node1 -> data = 10;
	node2 -> data = 20;
	node3 -> data = 30;
        node4 -> data = 40;

	node1->prev = NULL;
	node1->next =node2;

	node2 -> prev = node1;
	node2 -> next = node3;
	
	node3-> prev = node2;
	node3 -> next = node4;
	
	node4 -> prev = node3;
	node4 ->next = NULL;

	struct Node *temp = head;
	while(temp != NULL)
	{
		printf("%d -> ",temp->data);
		temp = temp -> next;
	}
	printf("NULL...!\n");
	struct Node *temp1 = temp;
	temp1 = node4;	
	//strut Node *sai = temp;
	while(temp1 !=NULL)
	{
		printf("%d -> ",temp1->data);
		temp1 = temp1 -> prev;
	}
	printf("NULL....");
}



