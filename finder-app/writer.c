
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <syslog.h>

void log_debug (char * , ...);
void report_error (char * , ...);

int main (int argc, char * argv [])
{
	openlog(NULL, 0, LOG_USER);
	bool hasFailed = true;
	
	if (argc == 1)
		report_error("No argumets specified. Shall be 2 ones");
	else if (argc == 2)
		report_error("String to be written is not specified");
	else
		hasFailed = false;
	
	if (hasFailed)
	{
		closelog();
		return 1;
	}
	
	char * writefile = argv[1];
	char * writestr = argv[2];

	log_debug("Writing %s to %s", writestr, writefile);
		
	FILE * file_ptr = fopen(writefile, "w");
	if (file_ptr == NULL)
	{
		report_error("Cannot open the file %s", writefile);
		hasFailed = true;	
	}
	else
	{
		fputs(writestr, file_ptr);
		fclose(file_ptr);
	}
	
	closelog();
	return 0;
}

void log_debug (char * message, ...)
{
	va_list args;
	va_start(args, message);
	syslog(LOG_DEBUG, message, args);
	va_end(args);
}

void report_error (char * message, ...)
{
	va_list args;
	va_start(args, message);
	
	fprintf(stderr, message, args);
	fprintf(stderr, "\n");
	syslog(LOG_ERR, message, args);
	
	va_end(args);
}

