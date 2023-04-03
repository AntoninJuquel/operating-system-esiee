/*
Le serveur A :

    lit des messages depuis une source (étape 1),
    analyse leur contenu (étape 2),
    et en fonction de cette analyse choisit ou non de les transmettre au serveur B via un "canal de transmission" (étape 3).

Symétriquement, le serveur B :

    écoute les messages envoyés par le serveur A sur le "canal de transmission" (étape 1),
    analyse leur contenu (étape 2),
    et en fonction de cette analyse choisit ou non de les transmettre à une certaine destination (étape 3).
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include "gestionFichiers.h"

int main()
{
    char *buf;
    int tube[2], fd;
    pipe(tube);
    pid_t pid = fork();
    if (pid != 0)
    {
        // Processus père

        fd = open("./source.txt", O_RDONLY);
        buf = litLigne(fd);
        ecritLigne(buf, tube[1]);

        close(fd);
        close(tube[1]);
        free(buf);

        wait(NULL);
    }
    else
    {
        // Processus fils

        fd = open("./destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        buf = litLigne(tube[0]);
        ecritLigne(buf, fd);
        printf("%s (%ld octets lus)\n", buf, strlen(buf));

        close(fd);
        close(tube[0]);
        free(buf);
    }
    return 0;
}