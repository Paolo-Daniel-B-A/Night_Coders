#include <stdio.h>
#include <stdlib.h> //usar malloc ->recerva de memoria
#include <assert.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* Crear_Nodo(int valor){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = vainsertAt(&heap, 0, 1);lor;
  newNode->next = (newNode->prev = newNode);
  return newNode;
}
