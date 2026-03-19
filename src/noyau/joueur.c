#ifndef _JOUEUR_C_
#define _JOUEUR_C_

#include"noyau/joueur.h"


/*
R: création d'un joueur
E: 1 TAD position
S: 1 TAD joueur
A: Adrien
*/
joueur creer_joueur(position pos) {
    joueur j = NULL;
    if ((j = (joueur)malloc(sizeof(s_joueur))) == NULL)
	{
        fprintf(stderr,"Erreur malloc par la fonction creer_joueur()\n");
        exit(EXIT_FAILURE);
    }
    j->atk = ATK;
    j->jetpack = JET;
    j->niv = 0;
    j->xp = 0;
    j->vie = VIE;
    j->pos = pos;
    j->vit = DEFAULT;
    return j;
}

/*
R: libération d'un joueur en mémoire
E: 1 TAD joueur
S: vide
A: Adrien
*/
void liberer_joueur(joueur j){
    
    if(j != NULL){
        liberer_position(j->pos);
        free(j);
        j = NULL;
    }
}

/*
R: Déplacement d'un joueur dans l'espace
E: 1 TAD joueur et 3 double (les direction sur les axe X,Y et Z)
S: vide
A: Adrien
*/
void deplacement(joueur j,double dirx,double diry,double dirz){
    double nx,ny,nz,norme;
    if (j == NULL || j->pos == NULL) {
        fprintf(stderr, "Erreur : joueur ou position NULL dans deplacement()\n");
        return;
    }

    /*calcul de la norme */
    norme = sqrt(dirx*dirx + diry*diry + dirz*dirz);
    /*pas de déplacement on return*/
    if (norme == 0) {
        return;
    }
    /*normalisation*/
    nx = dirx / norme;
    ny = diry / norme;
    nz = dirz / norme;
    /*Déplacement*/
    j->pos->x += nx * j->vie;
    j->pos->y += ny * j->vie;
    j->pos->z += nz * j->vie;
}

/*
R: gestion de l'utilisation du jet pack
E: 1 TAD joueur 
S: vide
A: Adrien
*/
void utiliser_jetpack(joueur j){
    j->jetpack -= USE_JET_PACK;
}

#endif /*_JOUEUR_C_*/