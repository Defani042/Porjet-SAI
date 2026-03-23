#ifndef _LOG_C_
#define _LOG_C_
 
#include"log/log.h"

void creer_dossiers_log()
{
    if (mkdir("fich", 0777) == -1 && errno != EEXIST)
    {
        perror("mkdir fich");
    }

    if (mkdir("fich/log", 0777) == -1 && errno != EEXIST)
    {
        perror("mkdir fich/log");
    }
}

int creer_fichier_log()
{
    FILE *f;

    /* "a" = crée le fichier s'il n'existe pas, sinon ne le vide pas */
    f = fopen(LOG_FILE_PATH, "a");

    if (f == NULL)
    {
        fprintf(stderr, "Erreur création fichier log (%s)\n", LOG_FILE_PATH);
        return 0;
    }

    fclose(f);
    return 1;
}

#endif /*_LOG_C_*/