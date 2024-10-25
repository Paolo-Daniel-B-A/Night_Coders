#include <stdio.h>
#include <stdlib.h> //usar malloc ->recerva de memoria
#include <assert.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};
