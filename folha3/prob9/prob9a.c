#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 

int main(int argc, char *argv[], char *envp[]) 
{ 
   pid_t pid; 
   if (argc != 2) { 
     printf("usage: %s dirname\n",argv[0]); 
     exit(1); 
   } 
   pid=fork(); 
   if (pid > 0) {
     printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]); 
     
     // Wait for the child
     int terminationStatus;
     wait(&terminationStatus);
     printf("The child exit code was: %d\n", terminationStatus);
     
     
     }
   else if (pid == 0){ 
	 char *cmds[]={"ls","-laR",argv[1]};
     execve("/bin/ls",cmds,envp); 
     printf("Command not executed !\n"); 
     exit(1); 
   } 
   exit(0); 
}
