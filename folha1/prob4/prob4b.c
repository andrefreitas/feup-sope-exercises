#include <stdio.h> 
#include <stdlib.h>
int main(int argc, char* args[]){  
  int i,n,j;
  n=atoi(args[1]); // fetch how many times
  // printf("\n n: %d\n",n);
  for(j=0; j<n; j++){ 
	printf("Hello ");
  	for (i=2;i<argc;i++)
		printf("%s ",args[i]);
  	printf ("!\n");
   }
  return 0; 
}
