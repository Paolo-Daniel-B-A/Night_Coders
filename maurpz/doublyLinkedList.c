#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node * prev;
  struct Node * next;
};


void insertNode(struct Node ** head, int value) {
  struct Node * temp = malloc(sizeof(struct Node));
  temp->value = value;
  if (!*head){
    temp->prev = NULL;
    temp->next = NULL;
    *head = temp;
    return;
  }
  struct Node * current = *head;
  current->prev = temp;
  temp->next = current;
  temp->prev = NULL;
  *head = temp;
}

void printList (struct Node * head) {
  struct Node * current = head;
  int flag = 0;
  while (current) {
    printf("%d ->",current->value);
    if ( !flag && current->next == NULL){
      printf("NULL->");
      flag = 1;
    }
    else if (flag){
      current = current->prev;
    }
    else {
      current = current->next;
    }
  }
}



int main () {
  struct Node * n1 = NULL;
  insertNode(&n1,2);
  insertNode(&n1,66);
  printList(n1);

  return 0;
}