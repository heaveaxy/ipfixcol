ACLOCAL_AMFLAGS = -I m4

pluginsdir = $(datadir)/fbitdump/plugins

plugins_LTLIBRARIES = httprt.la http_status_code.la sip_method.la dns_rcode.la tls_csuites.la tls_version.la tls_csuites_array.la voip_type.la voip_rtpcodec.la smtp_statuscode.la smtp_command.la mac.la multiplier.la raw_int64.la raw_text.la raw_int16.la skat_locked.la skat_hosttype.la skat_method.la

httprt_la_SOURCES= httprt.c
httprt_la_LDFLAGS= -shared -module -avoid-version

http_status_code_la_SOURCES= http_status_code.c
http_status_code_la_LDFLAGS= -shared -module -avoid-version

sip_method_la_SOURCES= sip_method.c
sip_method_la_LDFLAGS= -shared -module -avoid-version

dns_rcode_la_SOURCES= dns_rcode.c
dns_rcode_la_LDFLAGS= -shared -module -avoid-version

tls_csuites_la_SOURCES= tls_csuites.c tls_values.h
tls_csuites_la_LDFLAGS= -shared -module -avoid-version

tls_csuites_array_la_SOURCES= tls_csuites_array.c tls_values.h
tls_csuites_array_la_LDFLAGS= -shared -module -avoid-version

tls_version_la_SOURCES= tls_version.c tls_values.h
tls_version_la_LDFLAGS= -shared -module -avoid-version

voip_type_la_SOURCES= voip_type.c
voip_type_la_LDFLAGS= -shared -module -avoid-version

voip_rtpcodec_la_SOURCES= voip_rtpcodec.c
voip_rtpcodec_la_LDFLAGS= -shared -module -avoid-version

smtp_statuscode_la_SOURCES= smtp_statuscode.c
smtp_statuscode_la_LDFLAGS= -shared -module -avoid-version

smtp_command_la_SOURCES= smtp_command.c
smtp_command_la_LDFLAGS= -shared -module -avoid-version

mac_la_SOURCES= mac.c
mac_la_LDFLAGS= -shared -module -avoid-version

multiplier_la_SOURCES= multiplier.c
multiplier_la_LDFLAGS= -shared -module -avoid-version

raw_int64_la_SOURCES= raw_int64.c
raw_int64_la_LDFLAGS= -shared -module -avoid-version

raw_text_la_SOURCES= raw_text.c
raw_text_la_LDFLAGS= -shared -module -avoid-version

raw_int16_la_SOURCES= raw_int16.c
raw_int16_la_LDFLAGS= -shared -module -avoid-version


skat_locked_la_SOURCES= skat_locked.c
skat_locked_la_LDFLAGS= -shared -module -avoid-version
skat_hosttype_la_SOURCES= skat_hosttype.c
skat_hosttype_la_LDFLAGS= -shared -module -avoid-version
skat_method_la_SOURCES= skat_method.c
skat_method_la_LDFLAGS= -shared -module -avoid-version

EXTRA_DIST = plugin_header.h
