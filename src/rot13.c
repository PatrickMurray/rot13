#include "rot13.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif


int main(int argc, char** argv)
{
	int    fd;
	char   buffer[BUFFER_SIZE];
	size_t ret;
	char*  cipher;
	
	setprogname(argv[0]);
	
	if (argc == 1)
	{
		fd = STDIN_FILENO;
	}
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			fprintf(stderr, "%s: unable to open file: %s\n", getprogname(), strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		cipher = rot13(buffer);
		printf("%s", cipher);
		free(cipher);
		bzero(buffer, BUFFER_SIZE);
	}
	
	if (ret == -1)
	{
		fprintf(stderr, "%s: read error: %s\n", getprogname(), strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	if (argc > 1)
	{
		close(fd);
	}
	
	return EXIT_SUCCESS;
}

char* rot13(char* message)
{
	char*         cipher;
	size_t        len;
	size_t        i;
	unsigned char byte;
	unsigned char offset;
	
	if ((cipher = strdup(message)) == NULL)
	{
		fprintf(stderr, "%s: unable to allocate memory\n", getprogname());
		exit(EXIT_FAILURE);
	}
	
	len    = strlen(message);
	offset = 0;
	
	for (i = 0; i < len; i++)
	{
		byte = message[i];
		if (65 <= byte && byte <= 90)
		{
			offset = 65;
		}
		else if (97 <= byte && byte <= 122)
		{
			offset = 97;
		}
		
		if (offset)
		{
			cipher[i] = (byte - offset + 13) % 26 + offset;
			offset = 0;
		}
	}
	
	return cipher;
}
