#ifndef _LOG_H_
#define _LOG_H_
/*lib std*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

#include "config/config.h"

void creer_dossiers_log();

int creer_fichier_log();


#endif /*_LOG_H_*/