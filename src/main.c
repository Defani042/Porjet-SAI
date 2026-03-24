#include <stdio.h>
#include <stdlib.h>

#include "moteur/affichage.h"
#include "moteur/controle.h"

int main(int argc, char *argv[]){
    glutInit(&argc, argv);                
    initialisation();
    glutMainLoop();
    exit(EXIT_SUCCESS);
}