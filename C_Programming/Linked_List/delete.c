#include"declare.h"


void deleteatbegining(struct Node** head) {
	if (*head == NULL) 
	{
        	printf("List is empty\n");
        	return;
    	}
    	struct Node* temp = *head;
    	*head = temp->next;
    	free(temp);
}

// Function to delete the last node of the singly linked list
void deleteatend(struct Node** head) {
	if (*head == NULL) 
	{
        	printf("List is empty\n");
        	return;
    	}
    	struct Node* temp = *head;
    	if (temp->next == NULL) 
	{
        	free(temp);
        	*head = NULL;
        	return;
    	}
    	while (temp->next->next != NULL) 
	{
        	temp = temp->next;
    	}
    	free(temp->next);
    	temp->next = NULL;
}

// Function to delete a node at a specific position in the singly linked list
void deleteatpos(struct Node** head, int position) 
{
	if (*head == NULL) 
	{
        	printf("List is empty\n");
        	return;
    	}
    	struct Node* temp = *head;
    	if (position == 0) 
	{
        	deleteatbegining(head);
        	return;
    	}
    	for (int i = 0; temp != NULL && i < position - 1; i++) 
	{
        	temp = temp->next;
    	}
    	if (temp == NULL || temp->next == NULL) 
	{
        	printf("Position out of range\n");
        	return;
    	}
    	struct Node* next = temp->next->next;
    	free(temp->next);
    	temp->next = next;
}
