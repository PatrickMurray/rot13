#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef __NetBSD__
#include <bsd/stdlib.h>
#endif

int   main(int, char**);
char* rot13(char*);
