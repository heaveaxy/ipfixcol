#include <stdio.h>
#include <string.h>
#include "plugin_header.h"


char *info()
{
	return "Outputs raw numeric values of unsigned int 16-byte data type";
}

int init(const char *params, void **conf);
void close(void **conf);


void format(const plugin_arg_t *arg, int plain_numbers, char buffer[PLUGIN_BUFFER_SIZE], void *conf )
{
	snprintf(buffer, PLUGIN_BUFFER_SIZE, "%u", arg->val[0].uint16);
}

void parse(char *input, char out[PLUGIN_BUFFER_SIZE], void *conf)
{
	strncpy(out, input, PLUGIN_BUFFER_SIZE);
}
