#include <stdio.h>
#include <stdlib.h>
void h1(void){
	printf("Exit handler 1\n");
	exit(0);
}
void h2(void){
	printf("Exit handler 2\n");
}
int main(void){
	// abort(); // Aborta tudo, não deixa fazer mais nada
	atexit(h1);
	atexit(h2);
	atexit(h2);
	printf("Main Done!\n");
	exit(0);
}
