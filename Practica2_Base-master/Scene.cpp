#include "Scene.h"

/**
 * @brief Scene::Scene
 */
Scene::Scene() {
    // Inicialització de la capsa minima
    capsaMinima.pmin = vec3(-1.0, -1.0,-1.0);
    capsaMinima.a = 2;
    capsaMinima.h = 2;
    capsaMinima.p = 2;
    lightAmbientGlobal = vec3(0.2, 0.2, 0.2);
}

/**
 * @brief Scene::~Scene
 */
Scene::~Scene() {
    elements.clear();
    lights.clear();
}

/**
 * @brief Scene::addObject
 * @param obj
 */
void Scene::addObject(Object *obj) {
    elements.push_back(obj);
    calculCapsaMinCont3DEscena();
}

/**
 * @brief Scene::draw
 */
void Scene::draw() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->draw();
    }
}

/**
 * @brief Scene::drawTexture
 */
void Scene::drawTexture() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->drawTexture();
    }
}

/**
 * @brief Scene::getLightActual
 * @return
 */
Light* Scene::getLightActual() {
    // TO DO OPCIONAL: A modificar si es vol canviar el comportament de la GUI
    // Ara per ara dona com a Light actual la darrera que s'ha inserit
    return (lights[lights.size()-1]);
}

/**
 * @brief Scene::setLightActual
 * @param l
 */
void Scene::setLightActual(Light* l){
    lights[lights.size()-1]=l;
}



/**
 * @brief Scene::lightsToGPU
 * @param program
 */
void Scene::lightsToGPU(QGLShaderProgram *program){
// TO DO: A implementar a la fase 1 de la practica 2
    int MAX=lights.size();
    struct gl_lights{
        GLuint position;
        GLuint direction;
        GLuint diffuse;
        GLuint specular;
        GLuint ambient;
        GLuint angle;
        GLuint attenuation;
    };
    gl_lights gl[MAX];



    for(int i = 0; i<MAX; i++){
        gl[i].position = program->uniformLocation(QString("conjunt[%1].position").arg(i));
        gl[i].direction = program->uniformLocation(QString("conjunt[%1].direction").arg(i));
        gl[i].diffuse = program->uniformLocation(QString("conjunt[%1].diffuse").arg(i));
        gl[i].specular = program->uniformLocation(QString("conjunt[%1].specular").arg(i));
        gl[i].ambient = program->uniformLocation(QString("conjunt[%1].ambient").arg(i));
        gl[i].angle = program->uniformLocation(QString("conjunt[%1].angle").arg(i));
        gl[i].attenuation = program->uniformLocation(QString("conjunt[%1].atteuation").arg(i));
    }


    for(int i = 0;i<MAX;i++){
        glUniform4fv(gl[i].position, 1, lights[i]->position);
        glUniform4fv(gl[i].direction, 1, lights[i]->direction);
        glUniform3fv(gl[i].diffuse, 1, lights[i]->diffuse);
        glUniform3fv(gl[i].specular, 1, lights[i]->specular);
        glUniform3fv(gl[i].ambient, 1, lights[i]->ambient);
        glUniform1f(gl[i].angle, lights[i]->angle);
        glUniform3fv(gl[i].attenuation, 1, lights[i]->attenuation);
    }

}

void Scene::addLight(Light *l) {
    lights.push_back(l);

}

/**
 * @brief Scene::setAmbientToGPU
 * @param program
 */
void Scene::setAmbientToGPU(QGLShaderProgram *program){
    // TO DO: A implementar a la fase 1 de la practica 2
    GLuint ambientGlobal = program->uniformLocation("ambientGlobal");
    glUniform3fv(ambientGlobal,1, this->lightAmbientGlobal);
}


void Scene::calculCapsaMinCont3DEscena()
{
    Capsa3D c;
    vec3 pmax;

    if (elements.size()==1) {
        capsaMinima = elements[0]->calculCapsa3D();
        pmax[0] = capsaMinima.pmin[0]+capsaMinima.a;
        pmax[1] = capsaMinima.pmin[1]+capsaMinima.h;
        pmax[2] = capsaMinima.pmin[2]+capsaMinima.p;
    } else {
        capsaMinima.pmin[0]=200;
        capsaMinima.pmin[1]=200;
        capsaMinima.pmin[2]=200;
        pmax[0] = -200;
        pmax[1] = -200;
        pmax[2] = -200;
    }

    for (unsigned int i=0; i<elements.size(); i++) {
       c = elements[i]->calculCapsa3D();

       if (capsaMinima.pmin[0]>c.pmin[0]) capsaMinima.pmin[0] = c.pmin[0];
       if (capsaMinima.pmin[1]>c.pmin[1]) capsaMinima.pmin[1] = c.pmin[1];
       if (capsaMinima.pmin[2]>c.pmin[2]) capsaMinima.pmin[2] = c.pmin[2];
       if (pmax[0]<c.pmin[0]+c.a) pmax[0] = c.pmin[0]+c.a;
       if (pmax[1]<c.pmin[1]+c.h) pmax[1] = c.pmin[1]+c.h;
       if (pmax[2]<c.pmin[2]+c.p) pmax[2] = c.pmin[2]+c.p;
    }
    capsaMinima.a = pmax[0]-capsaMinima.pmin[0];
    capsaMinima.h = pmax[1]-capsaMinima.pmin[1];
    capsaMinima.p = pmax[2]-capsaMinima.pmin[2];
}
