// PROGRAMA p5b.c 
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(void) 
{ 
  int fd; 
  char *text1="CCCCC"; 
  char *text2="DDDDD"; 
  fd = open("f1.txt", O_WRONLY | O_APPEND,0600); 
   if(fd==-1){
	perror("can't write");
	exit(1);
  }
  getchar();
  write(fd,text1,5); 
  write(fd,text2,5); 
  close(fd); 
  return 0; 
     }
