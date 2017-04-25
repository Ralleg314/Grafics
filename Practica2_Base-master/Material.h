#ifndef MATERIAL_H
#define MATERIAL_H

#include "Common.h"
#include <QGLShaderProgram>


// TO DO: A canviar a la fase 1 de la practica 2
// Classe que representa els materials d'un objecte
class Material {


public:
    Material();
    ~Material();

    vec3 diffuse;
    vec3 specular;
    vec3 ambient;
    float shiness;

    void toGPU(QGLShaderProgram *program);

protected:
    vec3 RandomInSphere() const;



};

#endif // MATERIAL_H
