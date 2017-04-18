#ifndef Light_H
#define Light_H

#include <Common.h>

// Tipus de Lights
enum LightType {Puntual, Direccional, Spot};

// Classe que representa els atributs d'una Light
class Light {
    public:
        Light(LightType l);

        vec4 getLightPosition();
        void setLightPosition(vec4 v);

        void switchOnOff();

        vec3 getIa() const;
        void setIa(const vec3 &value);

        vec3 getDiffuseIntensity();
        void setDiffuseIntensity(vec3 i);

        vec3 getIs() const;
        void setIs(const vec3 &value);

        vec3 getCoeficients() const;
        void setCoeficients(const vec3 &value);

        bool getEstaActivat() const;
        void setEstaActivat(bool value);

        LightType getTipusLight() const;
        void setTipusLight(const LightType &value);


};

#endif // Light_H
