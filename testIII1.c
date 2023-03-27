// un programme qui se dédouble (fork) puis pour lequel chacun des deux processus ouvre le fichierTest.txt, y lit une ligne et ferme le fichier.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "gestionFichiers.h"

int main(int argc, char *argv[])
{
  int pid;
  int status;

  pid = fork();
  if (pid == 0)
  {
    int fd = open("./fichierTest.txt", O_RDONLY);
    char* res = litLigne(fd);
    printf("Je suis le fils, j'ai lu : %s\n\n", res);
    close(fd);
  }
  else
  {
    int fd = open("./fichierTest.txt", O_RDONLY);
    char* res = litLigne(fd);
    printf("Je suis le père, j'ai lu : %s\n\n", res);
    close(fd);
    wait(&status);
  }
  return 0;
}