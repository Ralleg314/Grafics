#include "Material.h"

Material::Material(){
    ambient = vec3(0.2,0.2,0.2);
    diffuse = vec3(0.8,0.0,0.0);
    specular = vec3(1.0,1.0,1.0);
    shiness = 20.0;
}

Material::~Material()
{

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
     }gl_Material;

     // 2. obtencio dels identificadors de la GPU
     gl_Material.diffuse = program->uniformLocation("BufferMaterial.diffuse");
     gl_Material.specular = program->uniformLocation("BufferMaterial.specular");
     gl_Material.ambient = program->uniformLocation("BufferMaterial.ambient");
     gl_Material.shiness = program->uniformLocation("BufferMaterial.shiness");

     // 3. Bind de les zones de memòria que corresponen a la GPU a valors de les variables de la CPU

     glUniform3fv(gl_Material.diffuse, 1, diffuse ); // vector3D és una variable de tipus vec3
     glUniform3fv(gl_Material.specular, 1, specular ); // vector3D és una variable de tipus vec3
     glUniform3fv(gl_Material.ambient, 1, ambient ); // vector3D és una variable de tipus vec3
     glUniform1f(gl_Material.shiness, shiness); // unFloat és una variable de tipus GLfloat

}




