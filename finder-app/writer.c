
#include <stdbool.h>
#include <stdio.h>
#include <syslog.h>

int main (int argc, char * argv [])
{
	openlog(NULL, 0, LOG_USER);
	bool hasFailed = false;
	
	if (argc == 1)
	{
		fprintf(stderr, "No argumets specified. Shall be 2 ones\n");
		syslog(LOG_ERR, "No argumets specified. Shall be 2 ones");
		hasFailed = true;
	}
	
	if (hasFailed)
	{
		closelog();
		return 1;
	}
	
	char * writefile = argv[1];
	char * writestr = argv[2];

	syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
		
	FILE * file_ptr = fopen(writefile, "w");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Cannot open the file %s\n", writefile);
		syslog(LOG_ERR, "Cannot open the file %s", writefile);
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
