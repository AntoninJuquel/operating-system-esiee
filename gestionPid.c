#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "gestionPid.h"

void print_pid(char *ch)
{
  printf("pid: %5d - %s\n", getpid(), ch);
}

void print_ppid(char *ch)
{
  printf("ppid: %5d - %s\n", getppid(), ch);
}

void print_all(char *ch)
{
  print_pid(ch);
  print_ppid(ch);
}