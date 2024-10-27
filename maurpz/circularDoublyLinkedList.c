#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node * prev;
  struct Node * next;
};

void push (struct Node ** head, int value) {
  struct Node * temp = malloc(sizeof(struct Node));
  temp->value = value;
  if (!*head) {
    temp->next = temp;
    temp->prev = temp;
    *head = temp;
    return;
  }
  struct Node * current = *head;
  temp->next = current;
  temp->prev = current->prev;
  current->prev = temp;
  (temp->prev)->next = temp;
}

void printCircularList(struct Node * head) {
  struct Node * current = head;
  int flip = 0;
  while (flip < 1) {
    printf("%d ->",current->value);
    current = current->next;
    if (current == head){
      flip++;
    }
  }
}

int main () {
  struct Node * head = NULL;
  push(&head,2);
  push(&head,12);
  printCircularList(head);
  return 0;
}
