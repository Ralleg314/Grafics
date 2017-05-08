#include "Light.h"

/**
 * @brief Light::Light
 * @param t
 */
Light::Light(LightType t) {
    this->diffuse=vec3();
    this->specular=vec3();
    this->ambient=vec3();
    this->attenuation=vec3();
    this->active=true;
    setTipusLight(t);
}




/**
 * @brief Light::getDiffuseIntensity
 * @return
 */
vec3 Light::getDiffuseIntensity() {
// TO DO: A canviar a la fase 1 de la practica 2

   return(vec3(1.0, 1.0, 1.0));
}

/**
 * @brief Light::setDiffuseIntensity
 * @param i
 */
void Light::setDiffuseIntensity(vec3 i) {
    // TO DO: A canviar a la fase 1 de la practica 2
    // el float que es reb ha de multiplicar els tres valors de la intensitat difusa de la Light

}
vec4 Light::getLightPosition() {
    // A canviar
    return this->position;
}

void Light::setLightPosition(vec4 v) {
    this->position=v;
}

/**
 * @brief Light::switchOnOff
 */
void Light::switchOnOff() {
    // TO DO: A canviar a la fase 1 de la practica 2
    // Si esta en on la posa a off i a l'inreves
    this->active=!this->active;
 }

/**
 * @brief Light::getIa
 * @return
 */
vec3 Light::getIa() const
{
    // TO DO: A canviar a la fase 1 de la practica 2

       return this->ambient;
}

/**
 * @brief Light::setIa
 * @param value
 */
void Light::setIa(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    // el float que es reb ha de multiplicar els tres valors de la intensitat difusa de la Light
    this->ambient*=value;
}



/**
 * @brief Light::getIs
 * @return
 */
vec3 Light::getIs() const
{
    // TO DO: A canviar a la fase 1 de la practica 2

       return this->specular;
}

/**
 * @brief Light::setIs
 * @param value
 */
void Light::setIs(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    // el float que es reb ha de multiplicar els tres valors de la intensitat difusa de la Light
    this->specular*=value;
}

/**
 * @brief Light::getCoeficients
 * @return
 */
vec3 Light::getCoeficients() const
{
       return this->attenuation;
}

/**
 * @brief Light::setCoeficients
 * @param value
 */
void Light::setCoeficients(const vec3 &value)
{
    this->attenuation=value;
}

/**
 * @brief Light::getEstaActivat
 * @return
 */
bool Light::getEstaActivat() const
{
    return this->active;
}

/**
 * @brief Light::setEstaActivat
 * @param value
 */
void Light::setEstaActivat(bool value)
{
    this->active=value;
}

/**
 * @brief Light::getTipusLight
 *
 */
LightType Light::getTipusLight() const
{
    if(this->position==vec4(0.0f)){
        return Direccional;
    }else if(this->angle==0.0f){
        return Puntual;
    }else{
        return Spot;
    }
}
/**
 * @brief Light::setTipusLight
 * @param value
 */
void Light::setTipusLight(const LightType &value)
{
    switch(value){
    case Puntual:
        this->position=vec4();
        break;
    case Direccional:
        this->direction=vec4();
        break;
    case Spot:
        this->position=vec4();
        this->angle=1.0f;
        break;
    }
}
