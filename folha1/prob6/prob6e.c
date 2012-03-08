#include <stdio.h>
#include <stdlib.h> 
#include <errno.h>
#define BUF_LENGTH 256 
#define MAX 100
int main(void) 
{ 
  FILE *src, *dst; 
  char buf[BUF_LENGTH]; 
  if ( ( src = fopen( "infile.txt", "r" ) ) == NULL )  { 
	printf("Errno: %d\n",errno); 
	
	exit(1);   
  } 

  if ( ( dst = fopen( "outfile.txt", "w" ) ) == NULL ) { 
	printf("Errno: %d\n",errno); 
	perror("outfile.txt:");
    exit(2);
  } 

  while( ( fgets( buf, MAX, src ) ) != NULL ) { 
    fputs( buf, dst ); 
  } 

  fclose( src ); 
  fclose( dst ); 
  exit(0);  // zero é geralmente indicativo de "sucesso" 
}
