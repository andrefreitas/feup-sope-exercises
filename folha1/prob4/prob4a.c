#include <stdio.h> 
int main(int argc, char* args[]){  
  int i;
  printf("Hello "); 
  for (i=1;i<argc;i++)
	printf("%s ",args[i]);
  printf ("!\n");
  return 0; 
}
