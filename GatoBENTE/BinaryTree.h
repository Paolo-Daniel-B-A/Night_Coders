#ifndef BINARYTREE_H_
#define BINARYTREE_H_

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* CrearNode(int);

struct Node* Buil123();

struct Node* Insertar(struct Node*, int);

int Size(struct Node*);

int MaxDepth(struct Node*);

int MinValue(struct Node*);

int MaxValue(struct Node*); 

int MinValueWhile(struct Node*);

int MaxValueWhile(struct Node*);

void PrintTree(struct Node*);

void PrintIn_Orden(struct Node*);

void PrintPost_Orden(struct Node*);

void PrintPre_Orden(struct Node*);

int HasPathSum(struct Node*, int);

void BorrarTree(struct Node**);

#endif


