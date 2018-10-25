#include <stdio.h>
#include "tests.h"
#include "genericLinkedList.h"

void printChar(void *data){
  printf("%c\n", *(char*)data); 
}

void printStr(void *data){
  printf("%s\n", data); 
}

void printInt(void *data){
  printf("%d\n", *(int*)data); 
}

void printFloat(void *data){
  printf("%f\n", *(float*)data); 
}

void runTests(){
  printf("Tests running...\n");
  
  //testing insert after with an int 
  int num = 500;
  insertAfter(j, &num, sizeof(int), &printInt);
  traverse(j);
  print("\n");

    
  //testing traverse with a string
  char str[] = "Testing traverse with a string";
  genericListElement *l2 = insertAfter(j, &str, sizeof(str), &printStr);
    
  traverse(j);
  length(j); 

   
  //testing traverse with a float
  float z = 50.00;
  insertAfter(j2, &z, sizeof(z), &printFloat);
    
  traverse(j);
  length(j); 
  
  //testing enqueue
  float k = 15;
  enqueue(&j, &k, sizeof(float), &printFloat);
  traverse(j);
  printf("\n");
    
    
  printf("\n");
    
  printf("\nTests complete.\n");
}
