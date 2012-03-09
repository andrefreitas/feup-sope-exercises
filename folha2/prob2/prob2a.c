#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* args[]){
	// usage
	if(argc==1) printf("usage: copy [source] [destination]\n");
	
	// open source and destination files
	FILE *src, *dest;
	src=fopen(args[1],"r");
	if(src==NULL){
		perror("source file: ");
		exit(1);
	}

	dest=fopen(args[2],"w");
	if(dest==NULL){
		perror("destination file: ");
		exit(2);
	}
	// copy content from source to destination
	char st[100];
	while(fgets(st,5,src)) fputs(st,dest);
	
	// close files
	fclose(src);
	fclose(dest);

	return 0;
}
