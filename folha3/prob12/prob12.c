#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
void printUsage(int argc,char * argv[]){
	if(argc!=3){
		printf("usage: %s [dirname1] [dirname2]\n",argv[0]);
		exit(1);
	}	
	
}

int isFile(char * entryName){
	struct stat statBuf;
	lstat(entryName,&statBuf);
	return S_ISREG(statBuf.st_mode);

}
int main(int argc, char * argv[]){
	// (1) print the usage
	printUsage(argc,argv);
	
	// (2) open the dirs
	DIR *pDir1, *pDir2;
	pDir1=opendir(argv[1]);
	pDir2=opendir(argv[2]);
	
	// (3) For each regular file in the dirname1
	struct dirent *entry;
	while(entry=readdir(pDir1)){
		if (isFile(entry->d_name)){ 
			printf("%s\n",entry->d_name);	
			// Father don't need to wait	
			if (fork()==0){
				char pathToFile[100];
				strcpy(pathToFile,argv[1]);
				strcat(pathToFile,"/");
				strcat(pathToFile,entry->d_name);
				execlp("cp","cp",pathToFile,argv[2],NULL);
			}
		}
		
	}
	
	exit(0);
}
