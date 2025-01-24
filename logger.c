#define _POSIX_C_SOURCE 199309

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/types.h>
#include "logger.h"


static int setLevel = 3; // Default Level: All Active 


void handler(int sig, siginfo_t *si, void *ucontext)
{
	// Set the level based on value stored in signal
	if (si->si_value.sival_int >= 0 && si->si_value.sival_int <= 3)
		setLevel = si->si_value.sival_int;
}

void dLog(char* str, int level, ...)
{
	// Do not print if level is too high
	if (level > setLevel) return;
	

	// Substituting variables into string
	va_list args;
    	va_start(args, level);
    	for (const char *ptr = str; *ptr != '\0'; ++ptr) {
        	if (*ptr == '%' && (*(ptr + 1) != '\0')) 
		{
            		
			ptr++;
			switch (*ptr) 
			{
                		case 'd': 
                    			int i = va_arg(args, int);
                    			printf("%d", i);
                    			break;
               
                		case 'c': 
                    			char c = (char) va_arg(args, int);
                    			printf("%c", c);
                    			break;
                
                		case 's': 
                    			char *str = va_arg(args, char *);
                    			printf("%s", str);
                    			break;

                		default:
                    			putchar('%');
                    			putchar(*ptr);
                    			break;
            		}
        	} 
		
		else 
		{
            		putchar(*ptr);
        	}
    }

    va_end(args);
}


// Configure handler for SIGRTMIN
void initLogger()
{
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;

	if (sigaction(SIGRTMIN, &act, NULL) == -1)
	{
		perror("sigaction");
		exit(1);
	}
}
