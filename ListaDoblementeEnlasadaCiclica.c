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

void Insert_Nodo(struct Node** headTemp, int valor){
  struct Node* newNodo = Crear_Nodo(valor);
  struct Node* temp = *headTemp;
  if(temp==temp->next){
    temp->next = newNodo;
    newNodo->prev = temp;
    newNodo->next = temp;
    temp->prev = newNodo;
  }
}

int main(){
  struct Node* head = Crear_Nodo(1);  
  Insert_Nodo(&head, 2);
  printf("%d", head->data);
  printf("%d", head->next->data);
  printf("%d", head->next->next->data);
  //Imprimir(heap);
  return 0;
}




