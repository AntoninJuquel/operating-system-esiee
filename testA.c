#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "gestionFichiers.h"

int main()
{
	int fd = open("./fichierTest.txt", O_RDONLY);
	char *res = litLigne(fd);
	printf("%s\n", res);
	close(fd);
	free(res);

	return 0;
}