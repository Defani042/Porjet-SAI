#ifndef _LOG_C_
#define _LOG_C_
 
#include"log/log.h"

static FILE *log_file = NULL;

/*
R: création des dossier de log
E: rien
S: rien
A: Adrien
*/
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

/*
R: création des dossier de log
E: rien
S: 1 si ok sinon 0
A: Adrien
*/
int creer_fichier_log()
{
    FILE *f;

    /* Crée les dossiers avant le fichier */
    creer_dossiers_log();

    /* "a" = append : crée le fichier s'il n'existe pas */
    f = fopen(LOG_FILE_PATH, "a");
    if (f == NULL)
    {
        fprintf(stderr, "Erreur création fichier log (%s)\n", LOG_FILE_PATH);
        return 0;
    }

    fclose(f);
    return 1;
}

/*
R: création des dossier et des fichier log et init de log_file
E: rien
S: rien
A: Adrien
*/
void log_init()
{
    /* Assure que le fichier existe */
    if (!creer_fichier_log())
        return;

    log_file = fopen(LOG_FILE_PATH, "a");
    if (!log_file)
    {
        fprintf(stderr, "Erreur ouverture fichier log (%s)\n", LOG_FILE_PATH);
    }
}


/*
R: écriture dans les fichier de log
E: une chaine de caractere
S: rien
A: Adrien
*/
void log_message(const char *msg)
{
    if (!log_file)
        return;

    fprintf(log_file, "%s\n", msg);
    fflush(log_file); /* écrit immédiatement */
}

/*
R: fermeture du fichier
E: rien
S: rien
A: Adrien
*/
void log_close()
{
    if (log_file)
    {
        fclose(log_file);
        log_file = NULL;
    }
}

#endif /*_LOG_C_*/