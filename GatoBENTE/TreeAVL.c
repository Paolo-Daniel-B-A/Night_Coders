#include <stdio.h>
#include <stdlib.h>
#include "TreeAVL.h"

struct TreeAVL* NewNode(int valor){
  struct TreeAVL* newNode = malloc(sizeof(struct TreeAVL));
  newNode->data = valor;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->padre = NULL;
  return newNode;
}

struct TreeAVL* InsertBST(struct TreeAVL* root, int valor){
  if(root==NULL) return root = NewNode(valor);

  if(valor <= root->data){
    root->left = InsertBST(root->left, valor);
    root->left->padre = root;
  }
  else if(valor > root->data){
    root->right = InsertBST(root->right, valor);
    root->right->padre = root;
  }
  return root;
}

int Height(struct TreeAVL* rootTemp){
  if(rootTemp == NULL) return -1;
  int ladoLeft = Height(rootTemp->left) + 1;
  int ladoRight = Height(rootTemp->right) + 1;
  if(ladoLeft > ladoRight) return ladoLeft;
  else return ladoRight;
}

int BalanceFactor(struct TreeAVL* nodeTemp){
  if(nodeTemp)
    return Height(nodeTemp->right)-Height(nodeTemp->left);
  return 0;
}

int main(){
  //CASO 1:

  // struct TreeAVL* root = 0;
  // root = InsertBST(root, 10);
  // root = InsertBST(root, 4);
  // root = InsertBST(root, 5);
  // root = InsertBST(root, 8);
  // root = InsertBST(root, 6);
  // root = InsertBST(root, 45);
  // root = InsertBST(root, 12);
  // root = InsertBST(root, 42);

  //CASO 2:
  
  struct TreeAVL* root = NewNode(5);
  InsertBST(root, 4);
  InsertBST(root, 6);

  printf("1.- %d \n",root->data);
  //printf("2.- %d",root->left->data);
  printf("altura: %d \n", Height(root));
  return 0;
}




























