#include <stdio.h>
#include <stdlib.h> 
#define BUF_LENGTH 256 
#define MAX 100
int main(int argc, char* args[]) 
{ 
  FILE *src, *dst; 
  char buf[BUF_LENGTH]; 
  if (argc==1){
	printf("usage: ./prob6h file1 file2\n");
	exit(3);
	}

  if ( ( src = fopen( args[1], "r" ) ) == NULL )  {  	
	exit(1);   
  } 

  if ( ( dst = fopen( args[2], "w" ) ) == NULL ) { 	
    exit(2);
  } 

  while( ( fgets( buf, MAX, src ) ) != NULL ) { 
    fputs( buf, dst ); 
  } 

  fclose( src ); 
  fclose( dst ); 
  exit(0);  // zero é geralmente indicativo de "sucesso" 
}
