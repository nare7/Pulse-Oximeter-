#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
    	struct Node* next;
};

int main() 
{
	struct Node* head = NULL;
    	struct Node* temp = NULL;
    	struct Node* newNode = NULL;
    	struct Node* prev = NULL;
    	int choice, value, position, count;
    
    	while(1) {
        	printf("\n----- Linked List Operations -----\n");
      		printf("1. Insert at Beginning\n");
        	printf("2. Insert at End\n");
     	        printf("3. Insert at Position\n");
       	        printf("4. Delete from Beginning\n");
       	        printf("5. Delete from End\n");
        	printf("6. Delete from Position\n");
        	printf("7. Display List\n");
        	printf("8. Exit\n");
        	printf("Enter choice: ");
        	scanf("%d", &choice);
        
        switch(choice) 
	{
            
            // ===== INSERT AT BEGINNING =====
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                
                // Create new node
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = value;
                newNode->next = head;
                head = newNode;
                
                printf("Node inserted at beginning\n");
                break;
            
            // ===== INSERT AT END =====
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                
                // Create new node
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = value;
                newNode->next = NULL;
                
                // If list is empty
                if(head == NULL) {
                    head = newNode;
                } else {
                    // Traverse to last node
                    temp = head;
                    while(temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
                
                printf("Node inserted at end\n");
                break;
            
            // ===== INSERT AT POSITION =====
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (1 for first): ");
                scanf("%d", &position);
                
                // Create new node
                newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = value;
                
                // Insert at first position
                if(position == 1) {
                    newNode->next = head;
                    head = newNode;
                    printf("Node inserted at position 1\n");
                } else {
                    // Traverse to position-1
                    temp = head;
                    count = 1;
                    while(temp != NULL && count < position - 1) {
                        temp = temp->next;
                        count++;
                    }
                    
                    if(temp == NULL) {
                        printf("Invalid position\n");
                        free(newNode);
                    } else {
                        newNode->next = temp->next;
                        temp->next = newNode;
                        printf("Node inserted at position %d\n", position);
                    }
                }
                break;
            
            // ===== DELETE FROM BEGINNING =====
            case 4:
                if(head == NULL) {
                    printf("List is empty\n");
                } else {
                    temp = head;
                    head = head->next;
                    printf("Deleted: %d from beginning\n", temp->data);
                    free(temp);
                }
                break;
            
            // ===== DELETE FROM END =====
            case 5:
                if(head == NULL) {
                    printf("List is empty\n");
                } else if(head->next == NULL) {
                    // Only one node
                    printf("Deleted: %d from end\n", head->data);
                    free(head);
                    head = NULL;
                } else {
                    // Traverse to second last node
                    temp = head;
                    while(temp->next->next != NULL) {
                        temp = temp->next;
                    }
                    printf("Deleted: %d from end\n", temp->next->data);
                    free(temp->next);
                    temp->next = NULL;
                }
                break;
            
            // ===== DELETE FROM POSITION =====
            case 6:
                printf("Enter position to delete (1 for first): ");
                scanf("%d", &position);
                
                if(head == NULL) {
                    printf("List is empty\n");
                } else if(position == 1) {
                    // Delete first node
                    temp = head;
                    head = head->next;
                    printf("Deleted: %d from position 1\n", temp->data);
                    free(temp);
                } else {
                    // Traverse to position-1
                    temp = head;
                    count = 1;
                    while(temp != NULL && count < position - 1) {
                        temp = temp->next;
                        count++;
                    }
                    
                    if(temp == NULL || temp->next == NULL) {
                        printf("Invalid position\n");
                    } else {
                        prev = temp->next;
                        temp->next = prev->next;
                        printf("Deleted: %d from position %d\n", prev->data, position);
                        free(prev);
                    }
                }
                break;
            
            // ===== DISPLAY LIST =====
            case 7:
                if(head == NULL) {
                    printf("List is empty\n");
                } else {
                    printf("List: ");
                    temp = head;
                    while(temp != NULL) {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                    }
                    printf("NULL\n");
                }
                break;
            
            // ===== EXIT =====
            case 8:
                // Free all nodes before exit
                while(head != NULL) {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
