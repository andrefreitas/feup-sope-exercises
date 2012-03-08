#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char* args[]){
	int r,n,n2;
	int i=0;
	if(argc==1) {
		printf("usage: ./prob8a num stopNum\n");
		exit(0);	
	}
	n=atoi(args[1]);
	n2=atoi(args[2]);
	srand(time(NULL));
	do{
		r=rand() % n;
		printf("i= %d : %d\n",i,r);
	}while(r!=n2);
	exit(0);
}
