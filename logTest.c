#include <stdio.h>

#include "logger.h"

int main(void)
{
	initLogger();

	char c;
	while (1)
	{
		printf("\nEnter q to quit or any other character to proceed: \n");
		c = getchar();
		if (c == 'q') break;

		LOG_ERROR("Error\n");
		LOG_WARNING("Warning\n");
		LOG_INFO("Info\n");
		LOG_DEBUG("Debug\n");
	}
}
