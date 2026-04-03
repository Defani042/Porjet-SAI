#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "GL/gl.h"
#include "GL/glut.h"
#include "GL/freeglut_ext.h" 

#define PATH_TEXTURE_ENNEMI "fich/textures/Personnage/Antho.bmp"

extern GLuint texture_ennemi;

void initialisation_texture();

GLuint load_texture(const char* filename);

#endif /*_TEXTURE_H_*/