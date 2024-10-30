#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

struct Node* CrearNode(int valor){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = valor;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* Buil123(){
  struct Node* root = CrearNode(2);
  struct Node* hijoLeft = CrearNode(1);
  struct Node* hijoRight = CrearNode(3);
  
  root->left = hijoLeft;
  root->right = hijoRight;

  return root;
}

struct Node* Insert(struct Node* rootTemp, int valor){
  if(rootTemp==NULL){
    return rootTemp = CrearNode(valor);
  }
  if(valor <= rootTemp->data){
    rootTemp->left = Insert(rootTemp->left, valor);
  }
  else if(valor > rootTemp->data){
    rootTemp->right = Insert(rootTemp->right, valor);
  }
  return rootTemp;
}

struct Node* Size(struct Node* rootTemp){
  if(rootTemp == NULL){
    return;
  }

}

int main(){
  return 0;
}

