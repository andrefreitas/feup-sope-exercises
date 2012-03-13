#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <wait.h> 
int main(void){
	if(fork()==0){
		// child
		printf("world!\n");
	}
	else {
		// parent
		printf("Hello ");
	}
	exit(0);
}
