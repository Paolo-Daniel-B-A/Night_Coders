#include <stdio.h>
#include <stdlib.h> //usar malloc ->recerva de memoria
#include <assert.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* Crear_Nodo(int valor){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = valor;
  newNode->next = (newNode->prev = newNode);
  return newNode;
}

void Insert_Nodo(struct Node** headTemp, int valor){
  struct Node* newNodo = Crear_Nodo(valor);
  struct Node* temp = *headTemp;
  if(temp==temp->next){
    temp->next = newNodo;
    newNodo->prev = temp;
    newNodo->next = temp;
    temp->prev = newNodo;
    return;
  }
  newNodo->next = *headTemp;
  newNodo->prev = temp->prev->prev;
  temp->prev->next = newNodo; 
  temp->prev = newNodo;

}

void Insert_Posicion(struct Node** headTemp, int valor, int posicion){
  struct Node* newNodo = Crear_Nodo(valor);
  struct Node* temp = *headTemp;
  struct Node* temp_2 = *headTemp;
  if(temp == temp->next){
    newNodo->next = temp;
    newNodo->prev = temp;
    temp->next = newNodo;
    temp->prev = newNodo;
    return;
  }
  for(int i=0; i<(posicion-1); i++){
    temp_2 = temp_2->next;
    temp = temp->next;
  }
  temp_2=temp_2->next;

  newNodo->next = temp_2;
  newNodo->prev = temp;
  temp->next = newNodo;
  temp_2->prev = newNodo;
  
}

void Borrar_LDEC(struct Node** headTemp){
  struct Node* CopiaNodoActual = *headTemp;
  struct Node* nextNode;
  
  do{
    nextNode = CopiaNodoActual->next;
    printf("%d - ",CopiaNodoActual->data);
    free(CopiaNodoActual);
    CopiaNodoActual=nextNode;
    //temp=temp->next;
  }while(CopiaNodoActual!=*headTemp);
  
  *headTemp = NULL;
  //free(temp);
}

void Imprimir_LDEC(struct Node* headRef){
  
  if(headRef==NULL){
    printf("Lista vacia.\n");
    return;
  }
  struct Node* temp = headRef->prev;
  while(headRef!=temp){
    printf("%d - ", headRef->data);
    headRef=headRef->next;
  }
  printf("%d - ", headRef->data);
  return;
}

int main(){
  struct Node* head = Crear_Nodo(1);  
  
  Insert_Nodo(&head, 2);
  Insert_Nodo(&head, 3);
  //Insert_Nodo(&head, 4);

  printf("%d", head->data);
  printf("%d", head->next->data);
  printf("%d", head->next->next->data);
  printf("%d", head->next->next->next->data);
  printf("%d", head->next->next->next->next->data);
  Imprimir_LDEC(head);
  Insert_Posicion(&head, 5, 3);
  printf("pos: \n");
  Imprimir_LDEC(head);
  Borrar_LDEC(&head);
  printf("borr:\n");
  Imprimir_LDEC(head);
  return 0;
}




