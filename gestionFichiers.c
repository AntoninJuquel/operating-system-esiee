#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "gestionFichiers.h"

char * litLigne(int fd)
{
    int i;
    int nbr;
    char buf[TAILLEBUF];
    char * s;

    for(nbr = 0 ; nbr < TAILLEBUF ; nbr++){
        int rc = read(fd, buf+nbr,1);
        if( rc == 0  ){ /*  fin de fichier */
            return NULL;
        }
        if(rc== -1){/* erreur */
            perror("erreur de lecture dans litLigne");
            return NULL;
        }

        if(buf[nbr]=='\n')break;
    } 

    s=(char*)malloc(nbr+1);
    if(s==NULL){
        perror("alocation issue in litLigne");
        return NULL;
    }

    for(i=0;i<nbr;i++)
        s[i]=buf[i];
    s[i] = '\0';
    return s;
}

/* retourne -1 en cas d'echec, taille de la chaine sinon */
int ecritLigne(char* chaine,int fd)
{

    int size_s = strlen(chaine);
    int nbw=0;
    int tmp;

    while(nbw!=size_s){
        tmp = write(fd,chaine+nbw,size_s-nbw);
        if(tmp==-1){
            perror("write issue in ecritLigne");
            return -1;
        }
        nbw+=tmp;
    }
    tmp = write(fd,"\n",1);/* on ne met pas le \n dans chaine car ne marcherait pas avec une chaine statique */
    if(tmp==-1){
        perror("write issue in ecritLigne");
        return -1;
    }
    return nbw;

}
