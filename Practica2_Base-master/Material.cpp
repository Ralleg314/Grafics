#include "Material.h"

Material::Material()
{  diffuse=vec3(1.0f,0.0f,0.0f);}

Material::~Material()
{

}

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
    diffuse=vec3(1.0f,0.0f,0.0f);
    // 1. Per a passar els diferents atributs del shader declarem una estructura amb els identificadors de la GPU
     struct gl_Material{
        GLuint diffuse;
        GLuint specular;
        GLuint ambient;
        GLuint shiness;
     };

     gl_Material gl;

     // 2. obtencio dels identificadors de la GPU
     gl.diffuse = program->uniformLocation("BufferMaterial.diffuse");
     gl.specular = program->uniformLocation("BufferMaterial.specular");
     gl.ambient = program->uniformLocation("BufferMaterial.ambient");
     gl.shiness = program->uniformLocation("BufferMaterial.shiness");

     // 3. Bind de les zones de memòria que corresponen a la GPU a valors de les variables de la CPU

     glUniform3fv(gl.diffuse, 1, diffuse ); // vector3D és una variable de tipus vec3
     glUniform3fv(gl.specular, 1, specular ); // vector3D és una variable de tipus vec3
     glUniform3fv(gl.ambient, 1, ambient ); // vector3D és una variable de tipus vec3
     glUniform1f(gl.shiness, shiness); // unFloat és una variable de tipus GLfloat

}




