#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "genericLinkedList.h"


//Returns a pointer to the element
genericListElement* createEl(void* data, size_t size, printData print){
  genericListElement* e = malloc(sizeof(genericListElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void* dataPointer = malloc(size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  memmove(dataPointer, data, size);
  e->data = dataPointer;
  e->size = size;
  e ->print = print;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(genericListElement* start){
  genericListElement* current = start;
  while(current != NULL){
    current -> print(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
genericListElement* insertAfter(genericListElement* el, void* data, size_t size, printData print){
  genericListElement* newEl = createEl(data, size, print);
  genericListElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(genericListElement* after){
  genericListElement* delete = after->next;
  genericListElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

//Returns the number of elements in a linked list.
int length (genericListElement* list) {
	int length = 0;
	genericListElement* currEl = list;
	while (currEl != NULL) {
		length++;
		currEl = currEl -> next;
	}
	return printf("Number of elements in linked list %d \n", length);
}
	
//Push a new element onto the head of a list.
//Update the list reference using side effects.	
void push(genericListElement** list, void* data, size_t size, printData print){
	genericListElement* newEl = createEl(data, size, print);
	newEl -> next = *list;
	*list = newEl;
}

//Pop an element from the head of a list.
//Update the list reference using side effects.
genericListElement* pop(genericListElement** list) {
	genericListElement *head = *list;
	if (head) {
		*list = head -> next;
	}
	return head;
}

 
//Enqueue a new element onto the head of the list. 
void enqueue(genericListElement** list, void* data, size_t size, printData print){
	genericListElement *newEl = createEl(data, size, print);
	newEl -> next = *list;
	*list = newEl;
}

//Dequeue an element from the tail of the list.
genericListElement* dequeue(genericListElement* list) {
genericListElement *temp = list;	
while((temp -> next) -> next != NULL) {
	temp = temp -> next;
}
genericListElement *tail = temp -> next;
temp -> next = NULL;
return tail;
}

