#include <stdio.h>
#include <string.h>
extern char **environ;

int main(void){
	int i;
	for (i=0; *(environ+i);i++)
	{	if (strncmp(*(environ+i),"USER=",5)==0){
			printf("Hello %s !\n",*(environ+i)+5);
		}

	}
	return 0;
}
