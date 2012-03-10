#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc, char* args[]){
	int fileno;

	if(argc==1){
	 	printf("usage: ./prob3a [file]\n");
		exit(0);
	}
	// Openning file
	if((fileno=open(args[1],O_RDONLY))==-1){
		perror("source file: ");
		exit(1);
	}
	
	// printing in stdout
	char data[20];
	while(read(fileno, data,10)) write(STDOUT_FILENO,data,10);
	
	// closed file
	close(fileno);

	exit(0);
}
