#include <stdio.h>
#include <string.h>
#include "plugin_header.h"

char *info()
{
	return "Decodes vendor-specific (vaasexperts) 'Locked' field.";
}

//int init(const char *params, void **conf);
//void close(void **conf);


void format(const plugin_arg_t *arg, int plain_numbers, char buffer[PLUGIN_BUFFER_SIZE], void *conf )
{
	char text[PLUGIN_BUFFER_SIZE] = "";
	if ( arg->val[0].uint64 == 0 )
		snprintf(buffer, 9, "Unlocked");
	else
		snprintf(buffer, 40, "Locked (mark=%d)", arg->val[0].uint64);
}

//void parse(char *input, char out[PLUGIN_BUFFER_SIZE], void *conf);
