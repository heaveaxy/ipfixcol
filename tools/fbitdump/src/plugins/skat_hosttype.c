#include <stdio.h>
#include <string.h>
#include "plugin_header.h"

char *info()
{
	return "Decodes vendor-specific (vaasexperts) 'Host Type' field.";
}

//int init(const char *params, void **conf);
//void close(void **conf);

void format(const plugin_arg_t *arg, int plain_numbers, char buffer[PLUGIN_BUFFER_SIZE], void *conf )
{
	char htype[10];
	switch ( arg->val[0].int8 ) {
		case 1:
			strcpy(htype, "HTTP");
		break;
		case 2:
			strcpy(htype, "CNAME");
		break;
		case 3:
			strcpy(htype, "SNI");
		break;
		case 4:
			strcpy(htype, "QUIC");
		break;
		default:
			strcpy(htype, "Unknown");
		break;
	}
	snprintf(buffer, strlen(htype), htype);
}

//void parse(char *input, char out[PLUGIN_BUFFER_SIZE], void *conf);
