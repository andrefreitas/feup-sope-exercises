#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char *user;
	user=getenv("USER_NAME");
	if (user!=NULL)
		printf("Hello %s\n",user);
	return 0;
}
