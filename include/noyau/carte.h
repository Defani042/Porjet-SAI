#ifndef _CARTE_H_
#define _CARTE_H_

#include <stdio.h>
#include <stdlib.h>


#include "noyau/joueur.h"
#include "noyau/objet.h"

typedef struct s_carte
{
    objet liste_objets;
    joueur j;
}s_carte;

typedef s_carte * carte;


carte creer_carte(objet liste_objets, joueur j);

void liberer_carte(carte c);

carte creer_carte_vide();


#endif /*_CARTE_H_*/