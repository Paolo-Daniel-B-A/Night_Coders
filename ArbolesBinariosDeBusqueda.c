#include <stdio.h>
#include <stdlib.h> //para liberar memoria

struct Node{
  int data;
  struct Node* right;
  struct Node* left;
};

struct Node* CrearNodo(int data){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}

void Insert(struct Node** headTemp, int valor){
  struct Node* newNode = CrearNodo(valor);
  struct Node* CopiaNodoActual = *headTemp;
  
  if(CopiaNodoActual==NULL){
    *headTemp = newNode;
    return;
  }
  else{
    if(valor <= newNode->data){
      Insert(&CopiaNodoActual->left, valor);
    }
    else if(valor > newNode->data){
      Insert(&CopiaNodoActual->right, valor);
    }
  }
}

int main(){
  struct Node* head = CrearNodo(5);
  Insert(&head, 3);
  return 0;
}
