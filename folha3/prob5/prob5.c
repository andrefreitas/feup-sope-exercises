#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
int main(void){
// the parent wait the child, that wait its child to write
// must use wait or the print order is "random"
	int status;
	if(fork()>0){
	// Parent
		wait(&status);
		printf("friends\n");
	}
	else{
	// Child
		if (fork()>0){
		// Child Parent
			wait(&status);
			printf("my ");
		}
		else{
		// Child child
			printf("Hello ");
		}
	}
	exit(0);
}
