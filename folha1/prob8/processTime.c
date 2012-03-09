#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
// Modified by André Freitas
// Source: http://web.me.com/haroldsoh/tutorials/technical-skills/microsecond-timing-in-cc-wi.html
int main(int argc, char **argv) {
    int i;
    // ProcessTime example
    struct timeval startTime;
    struct timeval endTime;
    // Sys time
    struct timeval startSys,endSys;
    //structure for rusage
    struct rusage ru;
    // get the current time
    // - RUSAGE_SELF for current process
    // - RUSAGE_CHILDREN for *terminated* subprocesses
    getrusage(RUSAGE_SELF, &ru);
    startTime = ru.ru_utime;
    startSys= ru.ru_stime;
    // algorithm goes here
    for(i=0;i<100000; i++)
	printf("%d \n",i);
    // get the end time
    getrusage(RUSAGE_SELF, &ru);
    endTime = ru.ru_utime;
    endSys=ru.ru_stime;
    // calculate time in microseconds
    double tS = startTime.tv_sec + (startTime.tv_usec);
    double tE = endTime.tv_sec  + (endTime.tv_usec);
    double userTime=(tE-tS)/1000000.0;
    //-->
    tS =  startSys.tv_sec + ( startSys.tv_usec);
    tE =  endSys.tv_sec + ( endSys.tv_usec);
    double sysTime=(tE-tS)/1000000.0;
    printf("\nuser time: %fs ",userTime);
    printf("\nsys time: %fs ",sysTime);
    return 0;
}
