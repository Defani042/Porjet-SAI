#ifndef _GRILLE_C_
#define _GRILLE_C_

#include "noyau/grille.h"

grille creer_grille(int taille_x, int taille_y,double cell_size){
    grille g ;
    int i,j;
    /*remplissage du pointeur*/
    if ((g= (grille)malloc(sizeof(s_grille))) == NULL){
        fprintf(stderr,"Erreur malloc par la fonction creer_grille()\n");
        log_message(NOYAU ERR "Erreur malloc par la fonction creer_grille()");
        exit(EXIT_FAILURE);
    }
    /*remplissage des champs simple*/
    g->taille_x = taille_x;
    g->taille_y = taille_y;
    g->cell_size = cell_size;

    /*allocution du tableau*/
    if ((g->cellules = (cellule**)malloc(sizeof(cellule*)* taille_x)) == NULL){
        fprintf(stderr,"Erreur malloc par la fonction creer_grille()\n");
        log_message(NOYAU ERR "Erreur malloc par la fonction creer_grille()");
        exit(EXIT_FAILURE);
    }
    /*allocution des case du tableau*/
    for (i = 0; i < taille_x; i++) {
        if ((g->cellules[i] = (cellule*)malloc(sizeof(cellule)* taille_y)) == NULL){
            fprintf(stderr,"Erreur malloc par la fonction creer_grille()\n");
            log_message(NOYAU ERR "Erreur malloc par la fonction creer_grille()");
            exit(EXIT_FAILURE);
        }
        for (j = 0; j < taille_y; j++){
            g->cellules[i][j]->liste = NULL;
        }
          
    }
    log_message(NOYAU SUCC "Grille créée");
    return g;
}

void detruire_grille(grille g) {
    int i;
    if (g== NULL){
         return;
    }
    for (i = 0; i < g->taille_x; i++) {
        /*libère chaque ligne*/
        free(g->cellules[i]);
    }
    /*libère le tableau de pointeurs*/
    free(g->cellules); 
    /*libère la structure principale*/
    free(g);
    log_message(NOYAU SUCC "Grille libéré");
}

#endif /*_GRILLE_C_*/