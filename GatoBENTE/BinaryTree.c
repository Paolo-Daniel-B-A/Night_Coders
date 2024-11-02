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

int Size(struct Node* rootTemp){
  if(rootTemp == NULL){
    return 0;
  }
  return 1+Size(rootTemp->left)+Size(rootTemp->right);
}

struct Node* Imprimir(struct Node* rootTemp){
  return 0;
}

int MaxDepth(struct Node* rootTemp){
  if(rootTemp==NULL) return 0;
  int maxIzq = 1+MaxDepth(rootTemp->left);
  int maxDer = 1+MaxDepth(rootTemp->right);
  if(maxIzq > maxDer) return maxIzq;
  else return maxDer;
}

int MinValue(struct Node* rootTemp){
  if(rootTemp == NULL) return 0;
  if(rootTemp->left== NULL) return rootTemp->data;
  return MinValue(rootTemp->left);
}

int MaxValue(struct Node* rootTemp){
  if(rootTemp == NULL) return 0;
  if(rootTemp->right == NULL) return rootTemp->data;
  return MaxValue(rootTemp->right);
}

int main(){
  struct Node* rootTree = Buil123();
  Insert(rootTree, 5);
  printf("%d\n",rootTree->data);
  printf("%d\n",rootTree->data);
  printf("%d\n",rootTree->left->data);

  printf("alturamax: %d \n",MaxDepth(rootTree));
  printf("Total nodos: %d \n", Size(rootTree));
  printf("Min dato: %d \n", MinValue(rootTree));
  printf("Min dato: %d \n", MaxValue(rootTree));
  return 0;
}









