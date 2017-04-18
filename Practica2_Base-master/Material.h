#ifndef MATERIAL_H
#define MATERIAL_H

#include <QGLShaderProgram>

// TO DO: A canviar a la fase 1 de la practica 2
// Classe que representa els materials d'un objecte
class Material {


public:
    Material();

    void toGPU(QGLShaderProgram *program);

};

#endif // MATERIAL_H
