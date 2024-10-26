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
  newNode->data = valor;
  newNode->next = (newNode->prev = newNode);
  return newNode;
}

int main(){
  struct Node* heap = Crear_Nodo(1);  
  return 0;
}
