#include <stdio.h>
#include <stdlib.h>

/*moteur du jeu*/
#include "moteur/affichage.h"
#include "moteur/controle.h"

/*log*/
#include "log/log.h"

/*noyau du jeu*/
#include "noyau/generateur_carte.h"
#include "noyau/carte_globale.h"

int main(int argc, char *argv[]){
    int res;
    /*creation du fichier de log*/
    creer_dossiers_log();
    res = creer_fichier_log();
    if(res == 0){
        fprintf(stderr,"ERREUR: le fichier de log n'a pas put se créer\n");
        exit(EXIT_FAILURE);
    }
    printf("Log OK");

    printf("Debut du jeux\n");
    carte_jeu = creer_carte_test();
    printf("Carte test créer\n");
    if(carte_jeu == NULL){
        printf("ERREUR la carte est NULL\n");
        exit(EXIT_FAILURE);
    }
    printf("Carte test OK\n");

    glutInit(&argc, argv);                
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);  
    glutCreateWindow("Projet SAI");
    glutFullScreen();
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutDisplayFunc(affichage);   
    glutIdleFunc(animer);
    glutKeyboardFunc(clavier_down);
    glutKeyboardUpFunc(clavier_up);
    glutMainLoop();
    exit(EXIT_SUCCESS);
}