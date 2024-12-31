
#include <stdbool.h>
#include <stdio.h>

int main (int argc, char * argv [])
{
	bool hasFailed = false;
	if (argc == 1)
	{
		fprintf(stderr, "No argumets specified. Shall be 2 ones\n");
		hasFailed = true;
	}
	
	if (hasFailed)
		return 1;
	
	char * writefile = argv[1];
	char * writestr = argv[2];
	
	FILE * file_ptr = fopen(writefile, "w");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Cannot open the file %s", writefile);
		hasFailed = true;	
	}
	else
	{
		fputs(writestr, file_ptr);
		fclose(file_ptr);
	}
	
	return hasFailed;
}
