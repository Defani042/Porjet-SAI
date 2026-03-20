#ifndef CONTROLE_C
#define CONTROLE_C

#include "moteur/controle.h"

int touches[256] = {0};

/*
R: Permet d'avancer
E: rien
S: rien 
A: Gaultier
*/
void avancer(){
    eyeX--;
    xO--;
}

/*
R: Permet d'aller à gauche
E: rien
S: rien 
A: Gaultier
*/
void gauche(){
    eyeY--;
    yO--;
}

/*
R: Permet de reculer
E: rien
S: rien 
A: Gaultier
*/
void reculer(){
    eyeX++;
    xO++;
}

/*
R: Permet d'aller à droite
E: rien
S: rien 
A: Gaultier
*/
void droite(){
    eyeY++;
    yO++;
}

/*
R: Permet de monter
E: rien
S: rien 
A: Gaultier
*/
void haut(){
    eyeZ++;
    zO++;
}

/*
R: Permet de descendre
E: rien
S: rien 
A: Gaultier
*/
void bas(){
    eyeZ--;
    zO--;
}

/*
R: Permet de mettre à jour le tableau de touches actives
E: la touche et les coordonnées de la souris
S: rien
A: Gaultier
*/
void clavier_down(unsigned char touche, int x, int y) {
    (void)x; /*pour le warning de non use */
    (void)y; /*pour le warning de non use */
    touches[touche] = 1;
}

/*
R: Permet de reset le tableau de touches actives
E: la touche et les coordonnées de la souris
S: rien
A: Gaultier
*/
void clavier_up(unsigned char touche, int x, int y) {
    (void)x; /*pour le warning de non use */
    (void)y; /*pour le warning de non use */
    touches[touche] = 0;
}

/*
R: Permet de gerer toutes les touches du clavier
E: la touche et les coordonnées de la souris
S: rien
A: Gaultier
*/
void update() {

    if (touches['z'] || touches['Z'])
        avancer();

    if (touches['s'] || touches['S'])
        reculer();

    if (touches['q'] || touches['Q'])
        gauche();

    if (touches['d'] || touches['D'])
        droite();

    if (touches[' '])
        haut();

    if (touches['c'] || touches['C'])
        bas();
}

/*
R: Permet de gerer toutes les touches de la souris
E: la touche , l'etat et les coordonnées de la souris
S: rien
A: Gaultier
*/
void gerer_souris(int bouton, int etat, int x, int y){
    /*printf pour le warning de non use */
    printf("Bouton: %d, Etat: %d, X: %d, Y: %d\n", bouton, etat, x, y);
}

#endif /*CONTROLE_C*/