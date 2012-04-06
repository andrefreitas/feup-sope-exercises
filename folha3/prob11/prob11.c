#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// for file manipulation and forks
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	char cmd[100];
	do{
		
		printf("minish > ");
		gets(cmd);
		// (1) Find the first space
		char *space;
		int nspace;
		space=strchr(cmd,' ');
		char cmdBin[100];
		if(space!=NULL){
			nspace=space-cmd; // the difference is the index of the space
			strncpy(cmdBin, cmd, nspace);
			cmdBin[nspace]='\0';
		}
		else{
			strcpy(cmdBin,cmd);
		}
		// echo
		//printf("echo: %s \n",cmd);
		
		// execute the command
		if(fork()==0) execlp(cmdBin,cmd,NULL);
		// father must wait for the child
		else{ 
			int n;
			wait(&n);
		}
		
	} while(strcmp("quit",cmd)!=0);
	exit(0);
}
