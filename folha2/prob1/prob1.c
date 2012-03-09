#include <termios.h>
#include <stdio.h>
#include <unistd.h>
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
	newterm.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON); 
	
	//(3) request password
	write(STDOUT_FILENO,"Enter password: ",16);

	//(4) update stdin settings to disable echo
	tcsetattr(fileno(stdin),TCSAFLUSH,&newterm);

	//(5) get password
	do{
		read(STDIN_FILENO,&c,1);
		password[i]=c;
                //write(fileno(stdout),'*',1); doesn't work
		write(STDOUT_FILENO,"*",1);
		i++;
	}while(c!='\n' & i<MAX_LENGTH);
	password[i]='\0';
	
	//(6) restore terminal settings
	tcsetattr(fileno(stdin),TCSAFLUSH,&oldterm);

	// (7) print password
	printf("\nYour password is: %s \n",password);
	
	exit(0);
}
