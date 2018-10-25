#include <stdio.h>

int main(int arg, char* argc[]){
	int i = 0;
	int* j = 0;
	long  k = 0;
	double * q  = 0;
	char** l = 0;

	printf("Int: %d \n", sizeof(i));
	printf("Int*: %d \n", sizeof(j));
	printf("Long: %d \n", sizeof(k));
	printf("Double *: %d \n", sizeof(q));
	printf("Char**: %d \n", sizeof(l));

}

