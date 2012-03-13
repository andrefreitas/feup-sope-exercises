#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <wait.h> 
int main(void){
	int status;
	int pidChild;
	if(fork()==0){
		// child
		printf("Hello ");
	}
	else {
		// parent
		pidChild=wait(&status);
		printf("world!\n");
		printf("The child PID was: %d\n",pidChild);
	}
	exit(0);
}
