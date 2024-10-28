#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int length(struct Node* head){
  int count = 0;
  while(head){
    count++;
    head = head->next;
  }
  return count;
}
//segunda parte
struct Node* BuildOneTwoThree(){
  struct Node* head = malloc(sizeof(struct Node));
  head->data = 1;
  head->next = malloc(sizeof(struct Node));

  head->next->data = 2;
  head->next->next = malloc(sizeof(struct Node));

  head->next->next->data = 3;
  head->next->next->next = NULL;

  return head;
}

int Count(struct Node* lista, int d){
 //copia
  struct Node* temp;
  int contador=0;
  while(temp){
    if(temp->data==d)
      contador++;
    temp=temp->next;
  }
  return contador;
}
void CountTest(){
  struct Node* myList = BuildOneTwoThree();
  int count = Count(myList, 2);
  printf("%d", count);
}

int GetNth(struct Node* head, int index){
  assert(head);
  assert(0<= index);
  assert(index<length(head));
 
  while(head && index){
    index--;
    head = head->next;
  }
 
  return head->data;
}

void GetNthTest() {
  struct Node* myList = BuildOneTwoThree(); // build {1, 2, 3}
  int lastNode = GetNth(myList, 2); // returns the value 3
}

void PrintList(struct Node* head) {
  if (head == NULL) {
    printf("La lista está vacía.\n");
    return;
  }

  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void DeleteList(struct Node** headPtr){
  /*while(*headPtr){
    struct Node* current = *headPtr;
    *headPtr = (*headPtr)->next;
    free(current);
  }*/
  struct Node* current;
  while(*headPtr){
    current = *headPtr;
    *headPtr = (*headPtr)->next;
    free(current);
  }
}

void DeleteListTest(){
  struct Node* mylist = BuildOneTwoThree();
  DeleteList(&mylist); //Lista que esta llena.
  //DeleteList(0); //Lista vacia
}

int Pop(struct Node** headRef){
  assert(headRef);
  assert(*headRef);
  
  struct Node* current;
  current = *headRef;
  *headRef = (*headRef)->next;
  
  int data = current->data;
  free(current);
  return data;
}

void PopTest(){
  struct Node* head = BuildOneTwoThree();
  int a = Pop(&head);
  int b = Pop(&head);
  int c = Pop(&head);
  int len = length(head);
}

void InsertNth(struct Node** headRef, int index, int data){
  assert(index <= length(*headRef));
  
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  
  struct Node** current = headRef;
  while(*current){
    current = &((*current)->next);
    //*current = *headRef;
    //*headRef = (*headRef)->next;
  }
  
}

void InsertNthTest(){
  struct Node* head =NULL;
  InsertNth(&head, 0, 13);
  InsertNth(&head, 0, 13);
  InsertNth(&head, 0, 13);
  
  DeleteList(&head);
}

int main(){
  //struct Node* list =BuildOneTwoThree();
  //CountTest();
  //GetNthTest();
  //printf("inicio \n");
  //PrintList(list);
  //DeleteList(&list);
  //printf("final \n");
  //PrintList(list);
  //DeleteListTest();
  PopTest();
  return 0;
}
