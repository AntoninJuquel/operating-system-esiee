#include <sys/types.h>
#include <unistd.h>

#include "gestionPid.h"

int main()
{
  int x = fork();
  if (x == 0)
    print_all("fils");
  else
    print_all("père");
  return 0;
}