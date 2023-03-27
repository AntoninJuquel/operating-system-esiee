// Écrire un source C qui se dédouble (fork) et pour lequel :
// le fils se recouvre (execv) par un nouveau processus qui exécute le programme testIB1

#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#include "gestionPid.h"

int main()
{
  int x = fork();
  if (x == 0)
  {
    execv("./testIB1", NULL);
  }
  else
  {
    wait(NULL);
    print_all("Je suis le père");
  }
  return 0;
}
