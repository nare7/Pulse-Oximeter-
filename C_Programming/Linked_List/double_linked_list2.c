#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};




void printList(struct Node *head)
{
	if(head == NULL)
	{
		printf("list is empty\n");
	}
	struct Node *temp = head;
	while(temp != NULL)
	{
		printf("%d ->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	
	struct Node *temp1 = head;
	while(temp1->next !=NULL)
	{
		temp1=temp1->next;
	}

	while(temp1 != NULL)
	{
		printf("%d ->", temp1->data);
		temp1 = temp1->prev;
	}
	printf("NULL\n");
	
}



/**************************************************************************************/
struct Node* createNode(int data)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if(newNode == NULL)	
	{	
		printf("memory allocation is failed\n");
		return NULL;
	}
	newNode -> data= data;
	newNode ->prev= NULL;
	newNode->next=NULL;
	return newNode;
}



/**************************************************************************************/

void insert_at_first(struct Node **head, int data)
{
	struct Node *newNode = createNode(data);
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	struct Node *temp= *head;
	newNode->next = *head;
	temp->prev = newNode;
	*head = newNode;
	
}	


/**************************************************************************************/

void insert_at_end(struct Node **head, int data)
{
	struct Node *newNode = createNode(data);
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	struct Node *temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode ->prev = temp;
	//newNode ->next = NULL;
}


/**************************************************************************************/
	
void insert_at_position(struct Node **head, int data, int pos)
{
	struct Node *newNode = createNode(data);
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	int count =1;
	struct Node *temp = *head;

	if(pos == 0)
	{
		newNode -> next = *head;
		temp->prev = newNode;
		return;
	}
	
	while(temp != NULL && count < pos-1)
	{
		temp = temp->next;
		count++;
	}
	//newNode ->prev = temp;
	newNode ->next = temp->next;
	temp->next->prev = newNode;
	newNode ->prev = temp;
	temp->next = newNode;
}


/**************************************************************************************/
	
void delete_from_first(struct Node **head)
{
	struct Node *temp = *head;
	if(*head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp= temp->next;
	free(*head);
	temp->prev = NULL;
	*head= temp;
}	


/**************************************************************************************/
	
	
void delete_from_position(struct Node **head, int pos)
{
	struct Node *temp = *head;
	
	if(*head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	int count =1;

	if(pos == 0)
	{
		temp =temp->next;
		free(*head);
		*head = temp;
		return;
	}
	while(temp != NULL && count < pos-1)
	{
		temp = temp->next;
		count++;
	}
	if(temp ==NULL || temp-> next == NULL)
	{
		printf("out of range\n");
		return;
	}
	struct Node *next_node = temp->next->next;
	free(temp->next);
	temp->next = next_node;
	next_node->prev = temp;
}
	
/**************************************************************************************/


void delete_from_end(struct Node **head)
{
			
	if(*head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct Node *temp = *head;
	
	if(temp->next == NULL)
	{
		free(temp);
		*head = NULL;
	}
	
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next= NULL;
}
	

void main()
{
	struct Node *head = NULL;
	
	int n, data, i;
	printf("enter the list size\n");
	scanf("%d", &n);
	
	printf("enter the %d values\n", n);
	for(i=0; i<n; i++)
	{	
		scanf("%d", &data);
		insert_at_first(&head, data);
	}
	printList(head);
	
	insert_at_end(&head, 22);
	printf("insert at end\n");
	printList(head);


	insert_at_position(&head, 33, 2);
	printf("insert at position\n");
	printList(head);

	delete_from_first(&head);
	printf("delete from first\n");
	printList(head);
	
	delete_from_position(&head, 2);
	printf("delete from position\n");
	printList(head);

	delete_from_end(&head);
	printf("delete from end\n");
	printList(head);

} 

