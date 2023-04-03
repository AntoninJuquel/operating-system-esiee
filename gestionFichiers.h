#ifndef _GESTION_FICHIERS_H_
#define _GESTION_FICHIERS_H_

#define TAILLEBUF 8191

/* attention, realise une allocation dynamique de la chaine retournée
 * penser à libérer la mémoire !
 */
char *litLigne(int fd);

/* prend une chaine de caractère, et l'écrit dans fd suivi d'un retour à la ligne
 * retourne -1 en cas d'echec */
int ecritLigne(char *chaine, int fd);

#endif
