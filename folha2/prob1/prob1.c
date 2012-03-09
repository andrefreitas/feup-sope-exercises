#include <termios.h>
#include <stdio.h>
#define MAX_LENGTH 10
int main(){
	
	struct termios oldterm, newterm; // to retrieve settings
	char c; // for each character
	char password[MAX_LENGTH+1]; // to store password
	int i=0; // array index

	//(1) fetch stdin settings
	tcgetattr(fileno(stdin),&oldterm);
	newterm=oldterm;
	
	//(2) disable echo
	newterm.c_lflag &= ~ECHO;
	
	//(3) request password
	printf("Enter password: ");

	//(4) update stdin settings to disable echo
	tcsetattr(fileno(stdin),TCSAFLUSH,&newterm);

	//(5) get password
	do{
		c=fgetc(stdin);
		password[i]=c;
		fputc('*',stdout);
		i++;
	}while(c!='\n');
	password[i]='\0';
	
	//(6) restore terminal settings
	tcsetattr(fileno(stdin),TCSAFLUSH,&oldterm);

	// (7) print password
	printf("\nYour password is: %s \n",password);
	
	exit(0);
}
