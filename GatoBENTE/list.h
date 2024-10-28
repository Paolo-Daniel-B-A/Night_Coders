#ifndef LIST_H
#define LIST_H

struct Node{
    int data;
    struct Node* next;
};


int length(struct Node* head);

struct Node* BuildOneTwoThree();

int Count(struct Node*, int);

int GetNth(struct Node*, int);

void CountTest();

void GetNthTest();

void DeleteList(struct Node**);

void DeleteListTest();

int Pop(struct Node**);

void PopTest();

#endif
