// PROGRAMA p1.c 
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int global=1; 
int main(void) { 
  int local = 2; 
  if(fork() > 0) { 
    // I am the parent
    printf("PID = %d; PPID = %d\n", getpid(), getppid()); 
    global++; 
    local--; 
  } else { 
    // I am the child
    printf("PID = %d; PPID = %d\n", getpid(), getppid()); 
    global--; 
    local++; 
  } 
  printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local); 
  return 0; 
}
