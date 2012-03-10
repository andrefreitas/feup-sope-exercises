#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* args[]){
	typedef struct{
		char name[50];
		int grade;
	}gradeSt;

	FILE *grades;
	// File creation needs to ben in binary mode "b"
	if((grades=fopen("gradesbin","wb"))==NULL){
		perror("gradesbin");
		exit(1);
	}
	
	// Get grades
	gradeSt g;
	char student[100];
	char note[3];
	int i=0;
	printf("(type \"0\" to exit)\n");
	while(1){
		printf("\n[%d] Student name: ",i++);
		gets(student);
		if(student[0]=='0') break;
		printf("Grade: ");
		gets(note);
		// put in the struct
		strcpy(g.name,student);
		g.grade=atoi(note);
		fwrite(&g,sizeof(gradeSt),1,grades);
	}

	// Close file
	fclose(grades);

	exit(0);
}
