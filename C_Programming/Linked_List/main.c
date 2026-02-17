#include<stdio.h>
#include<stdlib.h>
#include"declare.h"
//#include"delete.h"

/*struct Node
{
	int data;
	struct Node *next;
};*/


void printlist(struct Node *head)
{
	struct Node *temp = head;
	while(temp != NULL)
	{
		printf("%d ->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}


void main()
{
	struct Node *head=NULL;
	
	printf("Inserting a element at begining....\n");
	insert_at_begining(&head,10);
	insert_at_begining(&head,11);
	insert_at_begining(&head,12);
	printf("Printing List....\n");
	printlist(head);
	printf("Inserting a element at end....\n");
        insertatend(&head,13);
        printf("Printing List....\n");
        printlist(head);
	printf("Inserting a element at any pos....\n");
        insertatpos(&head,101,2);
        printf("Printing List....\n");
        printlist(head);
	printf("Delete  a element at begining....\n");
        deleteatbegining(&head);
        printf("Printing List....\n");
        printlist(head);
	printf("delete a element at end....\n");
        deleteatend(&head);
        printf("Printing List....\n");
        printlist(head);
printf("Inserting a element at any pos....\n");
        deleteatpos(&head,2);
        printf("Printing List....\n");
        printlist(head);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "insert.h"

void printlist(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    printf("Inserting elements at beginning....\n");
    insert_at_begining(&head, 10);
    insert_at_begining(&head, 20);
    insert_at_begining(&head, 30);

    printf("Printing List....\n");
    printlist(head);

    return 0;
}
*/
	
	
