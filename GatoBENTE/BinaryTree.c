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

int MinValueWhile(struct Node* rootTemp){
  if(rootTemp == NULL) return 0;
  while(rootTemp->left != NULL){
    rootTemp = rootTemp->left;
  }
  return rootTemp->data;
}

int MaxValueWhile(struct Node* rootTemp){
  if(rootTemp == NULL) return 0;
  while(rootTemp->right != NULL){
    rootTemp = rootTemp->right;
  }  
  return rootTemp->data;
}

void PrintTree(struct Node* rootTemp){
  if(rootTemp == NULL) return;
  printf("%d \n",rootTemp->data);
  //if(rootTemp->left == NULL) printf("NULL -");
  //else PrintTree(rootTemp->left);//printf("%d ",rootTemp->left->data);
  //if(rootTemp->right == NULL) printf("NULL -");
  //else PrintTree(rootTemp->right);//printf("%d ",rootTemp->right->data);

  PrintTree(rootTemp->left);
  PrintTree(rootTemp->right);
}

void PrintIn_Orden(struct Node* rootTemp){
  if(rootTemp == NULL) return;
  PrintIn_Orden(rootTemp->left);
  printf("%d ",rootTemp->data);
  PrintIn_Orden(rootTemp->right);
}

void PrintPost_Orden(struct Node* rootTemp){
  if(rootTemp == NULL) return;
  PrintPost_Orden(rootTemp->left);
  PrintPost_Orden(rootTemp->right);
  printf("%d ",rootTemp->data);
}

void PrintPre_Orden(struct Node* rootTemp){
  if(rootTemp == NULL) return;
  printf("%d ",rootTemp->data);
  PrintPre_Orden(rootTemp->left);
  PrintPre_Orden(rootTemp->right);
}

int sumador = 0;

int HasPathSum(struct Node* rootTemp, int suma){
  if(rootTemp == NULL) return 0;
  //int sumador = 0; 
  sumador = sumador + rootTemp->data;
  if(rootTemp->left == NULL) HasPathSum(rootTemp->right, suma);
  HasPathSum(rootTemp->left, suma);
  return sumador;
}

void BorrarTree(struct Node** root){
  if(*root == NULL) return ;
  BorrarTree(&((*root)->left));
  BorrarTree(&((*root)->right));
  //free(*root);
  *root=NULL;
}

void BorrarDato(struct Node** rootTemp, int valor){
  if(*rootTemp == NULL) return;
  if(valor < (*rootTemp)->data) BorrarDato(&((*rootTemp)->left),valor);
  else if(valor > (*rootTemp)->data) BorrarDato(&((*rootTemp)->right),valor);
  else{
    if((*rootTemp)->left == NULL && (*rootTemp)->right == NULL){
      *rootTemp = NULL;
    }
    //falta la asignacion del herencia
    else if((*rootTemp)->left != NULL || (*rootTemp)->right != NULL){
      if((*rootTemp)->left == NULL) *rootTemp = (*rootTemp)->right;
      else *rootTemp = (*rootTemp)->left;
    }
    else{
      //buscar al sucesor de rootTemp ????
      int minval = MinValue((*rootTemp)->right);
      (*rootTemp)->data = minval;
      BorrarDato(&((*rootTemp)->right), minval);
    }
  }
  return ;
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
  printf("Min while dato: %d \n", MinValueWhile(rootTree));
  printf("Max dato: %d \n", MaxValue(rootTree));
  printf("Max while dato: %d \n", MaxValueWhile(rootTree));
  //PrintTree(rootTree);
  printf("\n In-Orden: ");
  PrintIn_Orden(rootTree);
  printf("\n Pos-Orden: ");
  PrintPost_Orden(rootTree);
  printf("\n Pre-Orden: ");
  PrintPre_Orden(rootTree);
  printf("suma es: %d \n",HasPathSum(rootTree, 1));
  printf("inicio de borrado. \n");
  //BorrarTree(&rootTree);
  printf("fin borrado. \n");
  PrintIn_Orden(rootTree);
  printf("borrar nodo 3:\n");
  BorrarDato(&rootTree, 3);
  BorrarDato(&rootTree, 2);
  PrintIn_Orden(rootTree);
  return 0;
}










