#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node * left;
  struct Node * rigth;
} Node;

void insertNumber (Node ** head, int element) {
  printf("1");
  Node * temp = malloc(sizeof(Node));
  temp->value = element;
  temp->left = NULL;
  temp->rigth = NULL;
  temp->value = element;
  if (!*head) {
    *head = temp;
    return;
  }
  printf("2");
  Node * current = *head;
  int i = 0;
  while(!current) {
    printf("%d\n", i);
    if (element > current->value) {
      if (!current->rigth) {
        current->rigth = temp;
        return;
      }
      current = current->rigth;
    }
    if (!current->left) {
      current->left = temp;
      return;
    }
    current = current->left;
    i++;
  }
   printf("3");
  
}

char tab ='\t';
void mostrarArbol (struct Node * head) {
  if (head){
    mostrarArbol(head->left);
    mostrarArbol(head->rigth);
    printf("%s%d\n",head->value,'_');
  }
  else {
    return;
  }
} 

int size(Node * root) {
  if (root) {
    return 0;
  }
  int right = size(root->rigth);
  int left = size(root->left);
  return right + left;
}

int maximo (int a, int b) {
  if (a>=b) return a;
  return b;
}

int maxDeep(Node * root) {
  if(!root) return 0;
  return 1 + maximo(maxDeep(root->left),maxDeep(root->rigth));
}

void inOrder (Node * root) {
  if (!root) return;
  inOrder(root->left);
  printf("%d",root->value);
  inOrder(root->rigth);
}


int main() {
  Node * root = NULL;
  insertNumber(&root,5);
  insertNumber(&root,11);
  printf("%d primer elemento del arbol\n",root->rigth->value);
  return 0;
}