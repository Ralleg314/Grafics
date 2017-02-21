#ifndef RayTracer_h

#define RayTracer_h

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>

// Linia a comentar si es vol extreure un fitxer resultat.ppm i no via glut
#define GLUT


#ifdef GLUT
#include <GL/glut.h> //OpenGL Utility Toolkits
#else
// Si directament e vol escriure en un fitxer i no passar per glut
#endif

#include "Scene.h"


Scene *scene;


void Render();

#endif

