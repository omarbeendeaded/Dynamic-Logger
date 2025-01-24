#define _POSIX_C_SOURCE 199309

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>

#define DISABLE -1
#define ERROR    0
#define WARNING  1
#define INFO     2
#define DEBUG    3

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Usage: rtSend PID level\n");
		exit(1);
	}
	
	// Get target program and value to send
	pid_t pid = atoi(argv[1]);
	union sigval sv;	


	int level;
	if      (strcmp("disable", argv[2]) == 0) level = DISABLE;
	else if (strcmp("error",   argv[2]) == 0) level = ERROR;
	else if (strcmp("warning", argv[2]) == 0) level = WARNING;
	else if (strcmp("info",    argv[2]) == 0) level = INFO;
	else if (strcmp("debug",   argv[2]) == 0) level = DEBUG;
	else    exit(1);

       	sv.sival_int = level;


	// Send signal
	if (sigqueue(pid, SIGRTMIN, sv) == -1) {
		perror("sigqueue");
	}
}
