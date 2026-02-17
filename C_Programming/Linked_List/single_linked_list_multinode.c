/*#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
void main()
{
	struct Node *head=NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 40;
	head->next=NULL;
	head->next->head1;
	head1 = (struct Node*)malloc(sizeof(struct Node));
        head->data = 40;
        head->next=NULL;
	head2 = (struct Node*)malloc(sizeof(struct Node));
        head->data = 40;
        head->next=NULL;
	
	head3 = (struct Node*)malloc(sizeof(struct Node));
        head->data = 40;
        head->next=NULL;i	printf("%d",head->data);
}*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;

    // Create first node
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 40;
    head->next = NULL;

    // Create second node
    head1 = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 50;
    head1->next = NULL;
    head->next = head1;  // Link first node to second

    // Create third node
    head2 = (struct Node*)malloc(sizeof(struct Node));
    head2->data = 60;
    head2->next = NULL;
    head1->next = head2;  // Link second node to third

    // Create fourth node
    head3 = (struct Node*)malloc(sizeof(struct Node));
    head3->data = 70;
    head3->next = NULL;
    head2->next = head3;  // Link third node to fourth

    // Print linked list
    //struct Node *temp = head;
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");

    return 0;
}

