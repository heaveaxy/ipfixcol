#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "plugin_header.h"

static char* lstate[] = {
	"Unlocked",
	"Locked"
};

#define LS_CNT (sizeof(lstate) / sizeof(lstate[0]))

char *info()
{
	return "Decodes vendor-specific (VAS Experts) 'Locked' field.";
}

//int init(const char *params, void **conf);
//void close(void **conf);


void format(const plugin_arg_t *arg, int plain_numbers, char buffer[PLUGIN_BUFFER_SIZE], void *conf )
{
	if ( arg->val[0].uint64 == 0 )
		snprintf(buffer, 9, "Unlocked");
	else
		snprintf(buffer, 40, "Locked (%u)", arg->val[0].uint64);
}

void parse(char *input, char out[PLUGIN_BUFFER_SIZE], void *conf) {
	int val;
	for (val = 0; val < LS_CNT-1; val++) {
		if (!strcasecmp(input, lstate[val])) {
			snprintf(out, PLUGIN_BUFFER_SIZE, "%d", val);
			return;
		}
	}
	if ( !strncasecmp(input, lstate[LS_CNT-1], strlen(lstate[LS_CNT-1])) ) {
		char* str_ptr;
		char str_buf[30];

		/* Copying only symbols within brackets */
		str_ptr = strchr(input, '(')+1;
		int cnt = strchr(input, ')')-str_ptr;
		strncpy(str_buf, str_ptr, cnt);

		str_buf[cnt]='\0';

		/* Check for all symbols is digit */
		int i;
		for (i = 0; i < cnt; i++) {
			if (isdigit(str_buf[i]))
				snprintf(out, PLUGIN_BUFFER_SIZE, "%s", "");
				return;
		}
		snprintf(out, PLUGIN_BUFFER_SIZE, "%s", str_buf);
	}
}
