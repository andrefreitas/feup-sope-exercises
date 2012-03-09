#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void){
	char input[101];
	char *token;
	char *tokens[40];
	int i=0, n=0, j;
	// Read Input
	printf("Wellcome to FEUP Shell :D. Type \"exit\" to close\n");
	while(1){
	printf("> ");
	fgets(input, 100, stdin);
	if(strcmp(input,"exit\n")==0) break;

	// Parse Tokens
	token=strtok(input," ");
	while(token!=NULL){
		//printf("%s\n",token);
		tokens[i]=token;
		token=strtok(NULL," ");
		i++; n++;
	}

	// Print tokens
	for (i=0; i<n; i++){
		int breakpoint=0;
		for (j=0; *(tokens[i]+j)!=NULL; j++){
			if(*(tokens[i]+j)!=';' & *(tokens[i]+j)!='|')
			printf("%c",*(tokens[i]+j));
			else {
				printf("\n");
				breakpoint=1;
			}
		
		}
		if(!breakpoint & (i+1)<n) printf(" ");
		
	}
	}
	return 0;
}
