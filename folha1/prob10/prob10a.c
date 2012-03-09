#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void){
	char input[101];
	char *token;
	printf("> ");
	fgets(input, 100, stdin);
	//printf("%s\n",input);
	token=strtok(input," ");
	while(token!=NULL){
		printf("%s\n",token);
		token=strtok(NULL," ");
	}
	return 0;
}
