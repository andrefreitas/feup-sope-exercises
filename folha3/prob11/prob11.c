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
	int stdout_save = dup(STDOUT_FILENO);
	do{
		
		printf("minish > ");
		gets(cmd);
		
		// (1) Find the first space
		// Example: ls -l, the cmd should be only "ls"
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
		
		// (2) Evaluate if it has the -o parameter
		// Example: ls -l -o saida.txt, the cmd should be "ls" and the cmd "ls -l"
		char *fileParameter;
		fileParameter=strstr(cmd,"-o");
		if(fileParameter!=NULL){
			int nParam=fileParameter-cmd;
			int fileDes;
			fileDes=open(fileParameter+3,O_CREAT | O_RDWR,0777);
			dup2(fileDes,STDOUT_FILENO);
			char aux[100];
			strncpy(aux,cmd,nParam);
			memset(&cmd[0], 0, sizeof(cmd));
			strcpy(cmd,aux);
		}
	
		
		// (3) execute the command
		if(fork()==0) execlp(cmdBin,cmd,NULL);
		// father must wait for the child
		else{ 
			int n;
			wait(&n);
			dup2(stdout_save,STDOUT_FILENO);
		}
		
	} while(strcmp("quit",cmd)!=0);
	exit(0);
}
