#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <sys/resource.h>
int main(int argc, char* args[]){
        struct rusage ru; // resource usage
	struct timeval sUser,eUser,sSys,eSys; // time interval for cpu time computing
	int r,n,n2; // random number, limit and stop number
	int i=0; // index
	double realTime;
	struct timeval startTime, endTime; // for real time

	// start timers
	getrusage(RUSAGE_SELF,&ru); //get the usage struct
	sUser=ru.ru_utime; // user time
	sSys=ru.ru_stime; // sys time
	gettimeofday(&startTime, NULL);

 	// print usage
	if(argc==1) {
		printf("usage: ./prob8a num stopNum\n");
		exit(0);	
	}
	
	// some setups
	n=atoi(args[1]);
	n2=atoi(args[2]);
	srand(time(NULL));

	// number generation
	do{
		r=rand() % n;
		printf("i= %d : %d\n",i,r);
		i++;
	}while(r!=n2);

	// end timers
	gettimeofday(&endTime, NULL);
	getrusage(RUSAGE_SELF,&ru);
	eUser=ru.ru_utime; // user time
	eSys=ru.ru_stime; 
        
	// Print Results
	double tS=startTime.tv_sec*1000000+ (startTime.tv_usec);
	double tE = endTime.tv_sec*1000000  + (endTime.tv_usec);
	realTime=(tE-tS)/1000000.0;;	
	printf("\nreal time elapsed: %f s\n",realTime);

	tS=sUser.tv_sec+(sUser.tv_usec);
	tE=eUser.tv_sec+(eUser.tv_usec);
	double userTime=(tE-tS)/1000000.0;	
        printf("user cpu time : %f s \n",userTime);

	tS=sSys.tv_sec+sSys.tv_usec;
	tE=eSys.tv_sec+eSys.tv_usec;
	double sysTime=(tE-tS)/1000000.0;
        printf("system cpu time: %f s\n",sysTime);

	exit(0);
}
