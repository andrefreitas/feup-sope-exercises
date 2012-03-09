#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int glob = 6; /* external variable in initialized data */
int main(void)
{
	int var; /* automatic variable on the stack */
	pid_t pid;
	var = 88;
	printf("before fork\n");
	if ( (pid = fork()) < 0) fprintf(stderr,"fork error\n");
	else if (pid == 0) { /* child */
	glob++; /* modify variables */
	var++; }
	else
	sleep(2); /* parent ; try to guarantee that child ends first*/
	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	exit(0);
}
