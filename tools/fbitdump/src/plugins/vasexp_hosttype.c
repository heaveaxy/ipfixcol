#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "plugin_header.h"

static char *htypes[] = {
	"",
	"HTTP",
	"CNAME",
	"SNI",
	"QUIC"
	"Unknown"
};

#define HT_CNT (sizeof(htypes) / sizeof(htypes[0]))

char *info()
{
	return "Decodes vendor-specific (VAS Experts) 'Host Type' field.";
}

//int init(const char *params, void **conf);
//void close(void **conf);

void format(const plugin_arg_t *arg, int plain_numbers, char buffer[PLUGIN_BUFFER_SIZE], void *conf )
{
	char val = arg->val[0].int8;
	if ( val >=1 && val <=4 ) {
		snprintf(buffer, PLUGIN_BUFFER_SIZE, htypes[val]);
	} else {
		snprintf(buffer, PLUGIN_BUFFER_SIZE, "%s (%d)", htypes[5], val);
	}
}

void parse(char *input, char out[PLUGIN_BUFFER_SIZE], void *conf) {
	int val;
	for (val = 1; val < HT_CNT-1; val++) {
		if (!strcasecmp(input, htypes[val])) {
			snprintf(out, PLUGIN_BUFFER_SIZE, "%d", val);
			return;
		}
	}
	if ( !strncasecmp(input, htypes[HT_CNT-1], strlen(htypes[HT_CNT-1])) ) {
		char* str_ptr;
		char str_buf[5];

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
