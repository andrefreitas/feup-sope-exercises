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
	int srcno=open(args[1],O_RDONLY);
	if(srcno==-1) {
		perror("source file");
		exit(1);
	}
	int destno=open(args[2],O_RDWR | O_CREAT,0777);
	if(destno==-1){
		perror("destination file");
		exit(2);
	}

	// copy content from source to destination
	char *c;
	while(read(srcno,c,5)) write(destno,c,5);

	
	// close files
	close(srcno); 
	close(destno);

	return 0;
}
