#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc, char* args[]){
	int fileno;

	if(argc==1){
	 	printf("usage: ./prob3a [file] /*[outputfile]*/\n");
		exit(0);
	}
	// Openning file
	if((fileno=open(args[1],O_RDONLY))==-1){
		perror("source file: ");
		exit(1);
	}

	// redirecting output
	if(argc==3){
		int outno;
		if((outno=open(args[2],O_RDWR | O_CREAT,0777))==-1){
			perror("output file");
			exit(2);
		}
		dup2(outno,STDOUT_FILENO);
		
	}
	// printing in stdout
	char data[20];
	while(read(fileno, data,10)) write(STDOUT_FILENO,data,10);
	
	// closed file
	close(fileno);

	exit(0);
}
