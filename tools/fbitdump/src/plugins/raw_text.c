#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "plugin_header.h"

#define CHAR_PLACEHOLDER '#'

char *info()
{
	return "Outputs sequence of bytes as text.";
}

//int init(const char *params, void **conf);
//void close(void **conf);


void format(const plugin_arg_t *arg, int plain_numbers, char buffer[PLUGIN_BUFFER_SIZE], void *conf )
{
	char text[PLUGIN_BUFFER_SIZE] = "";
	int buf_size = 0;

	// check for buffer overflow
	if (arg->val[0].blob.length > PLUGIN_BUFFER_SIZE) {
		//Skipping
		fprintf(stderr, "* WARNING! Text field size exceed size of text buffer (%d). Skipping...\n", PLUGIN_BUFFER_SIZE);
		snprintf(buffer, 6, "WARN!\0");
		return;
	} else {
		buf_size = arg->val[0].blob.length;
	}
	strncpy(text, arg->val[0].blob.ptr, buf_size);

	// check for non-printable characters exists
	int i = 0;
	for (i = 0; i < strlen(text); i++)
		if (!isprint(text[i])) {
			fprintf(stderr, "* WARNING! Text field contains non printable characters replaced by \'%c\'\n", CHAR_PLACEHOLDER);
			text[i] = CHAR_PLACEHOLDER;
		}
	text[buf_size]='\0';
	snprintf(buffer, PLUGIN_BUFFER_SIZE, "%s", text);
}

//void parse(char *input, char out[PLUGIN_BUFFER_SIZE], void *conf);
