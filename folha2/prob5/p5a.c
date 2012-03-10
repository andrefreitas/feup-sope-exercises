// PROGRAMA p5a.c 
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(void) 
{ 
  int fd; 
  char *text1="AAAAA"; 
  char *text2="BBBBB"; 
  fd = open("f1.txt",O_CREAT|O_EXCL|O_WRONLY,0600); 
  if(fd==-1){
	perror("failed to create");
	exit(1);
  }
  write(fd,text1,5); 
  write(fd,text2,5); 
  close(fd); 
  return 0; 
}
