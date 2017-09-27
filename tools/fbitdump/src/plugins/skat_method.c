#include <stdio.h>
#include <string.h>
#include "plugin_header.h"

char *info()
{
	return "Decodes vendor-specific (vaasexperts) 'Method' field.";
}

//int init(const char *params, void **conf);
//void close(void **conf);

void format(const plugin_arg_t *arg, int plain_numbers, char buffer[PLUGIN_BUFFER_SIZE], void *conf )
{
	char method[10];
	switch ( arg->val[0].int8 ) {
		case 1:
			strcpy(method, "GET");
		break;
		case 2:
			strcpy(method, "POST");
		break;
		case 3:
			strcpy(method, "PUT");
		break;
		case 4:
			strcpy(method, "DELETE");
		break;
		default:
			strcpy(method, "Unknown");
		break;
	}
	snprintf(buffer, strlen(method), method);
}

//void parse(char *input, char out[PLUGIN_BUFFER_SIZE], void *conf);
