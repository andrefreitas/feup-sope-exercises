#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 

int main(int argc, char* argv[]){
	// print usage if needed
	if(argc!=2 && argc!=3){
		printf("usage: %s [filename]\n",argv[0]);
		exit(1);
	}
	
	// open the file
	int fileDes;
	if(argc==3){
	
		fileDes=open(argv[2],O_CREAT | O_RDWR, 0777);
		if(fileDes<0){
			perror("file ");
			exit(1);
		}
		dup2(fileDes,STDOUT_FILENO);
	}
	// do a fork
	if(fork()==0){
     		execlp("ls","ls","-laR",argv[1],NULL); 

	} else{
		printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]); 
	     
	     // Wait for the child
	     int terminationStatus;
	     wait(&terminationStatus);
	     printf("The child exit code was: %d\n", terminationStatus);
	     
	     // Evaluate the termination status
	     if(WIFEXITED(terminationStatus)){
	     	printf("Child exited normally\n");
	     }
	     if(WIFSIGNALED(terminationStatus)){
	     	printf("Child exited abnormally\n");
	     }
	
	}
	exit(0);
}
