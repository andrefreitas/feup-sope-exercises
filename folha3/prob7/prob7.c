// PROGRAMA p7.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   char prog[20];
   sprintf(prog,"%s.c",argv[1]);
   // Recebe uma lista de argumentos
   if(execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL)==-1)
	printf("Erro no exec\n");
   exit(0);
}
