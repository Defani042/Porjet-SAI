#ifndef _COLLISION_H_
#define _COLLISION_H_

#include <stdlib.h>
#include <stdio.h>

#include "grille.h"


#include "noyau/carte.h"
int collision_hitbox(
    double x1, double y1, double z1,
    double w1, double h1, double l1,
    int centered1,

    double x2, double y2, double z2,
    double w2, double h2, double l2,
    int centered2
);

objet detecter_collision_generique(grille g, double px, double py, double pz, double w, double h, double l, int centered);

objet detecter_collision_joueur(grille g, joueur j);

objet detecter_collision_ennemi(grille g, ennemi e);

#endif /* _COLLISION_H_ */