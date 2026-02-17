//struct Node *createNode(int);
//void insert_at_begining(struct Node **,int);
//#ifndef INSERT_H
//#define INSERT_H

#include<stdio.h>
#include<stdlib.h>

// Define structure here so all files can access it
struct Node {
    int data;
    struct Node *next;
};


struct Node *createNode(int data);
void insert_at_begining(struct Node **head, int data);
void insertatend(struct Node **head,int data);
void insertatpos(struct Node **head,int data,int pos);



