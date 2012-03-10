#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* args[]){
	FILE *grades;
	// File creation
	if((grades=fopen("grades.txt","w"))==NULL){
		perror("grades.txt");
		exit(1);
	}
	
	// Get grades
	char name[100];
	char grade[3];
	int i=0;
	printf("(type \"0\" to exit)\n");
	while(1){
		printf("\n[%d] Student name: ",i++);
		gets(name);
		if(name[0]=='0') break;
		printf("Grade: ");
		gets(grade);
		fflush(stdin);
		fprintf(grades,"%s : ",name);
		fprintf(grades,"%s\n----------------------\n",grade);
		
	}

	// Close file
	fclose(grades);

	exit(0);
}
