#include "Material.h"

Material::Material():
    diffuse(1.0f)
{}

Material::~Material()
{}

vec3 Material::RandomInSphere() const {
    vec3 p;
    /*do {
        p = 2.0f*vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
    } while (glm::length(p) >=  1.0f);*/
    return p;
}

/**
 * Passa el material de CPU a GPU
 * @brief Material::toGPU
 * @param program
 */
void Material::toGPU(QGLShaderProgram *program){
    // 1. Per a passar els diferents atributs del shader declarem una estructura amb els identificadors de la GPU
     struct{
        GLuint diffuse;
        GLuint specular;
        GLuint ambient;
        GLuint shiness;
     } gl;

     // 2. obtencio dels identificadors de la GPU
     gl.diffuse = program->uniformLocation("material.diffuse");
     gl.specular = program->uniformLocation("material.specular");
     gl.ambient = program->uniformLocation("material.ambient");
     gl.shiness = program->uniformLocation("material.shiness");

     // 3. Bind de les zones de memòria que corresponen a la GPU a valors de les variables de la CPU
     vec3 v1,v2,v3;
     float f;

     glUniform3fv(gl.diffuse, 1, v1 ); // vector3D és una variable de tipus vec3
     glUniform3fv(gl.specular, 1, v2 ); // vector3D és una variable de tipus vec3
     glUniform3fv(gl.ambient, 1, v3 ); // vector3D és una variable de tipus vec3
     glUniform1f(gl.shiness, f); // unFloat és una variable de tipus GLfloat

}




