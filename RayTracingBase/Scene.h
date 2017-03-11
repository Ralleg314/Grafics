#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Ray.h"
#include "Hitable.h"
#include "Object.h"
#include "Sphere.h"
#include "Plane.h"
#include "Triangle.h"
#include "Cube.h"
#include "BoundaryObject.h"
#include "Lambertian.h"
#include "Camera.h"
#include "Material.h"

class Scene: public Hitable
{
public:
    Scene();

    virtual ~Scene();

    // Funcio que calcula la interseccio del raig r amb l'escena. Guarda la informacio
    // del punt d'interseccio més proper a t_min, punt que està entre t_min i t_max.
    // Retorna cert si existeix la interseccio, fals, en cas contrari
    virtual bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;

    // Funcio recursiva que calcula el color. Inicialment es
    // es crida a cada pixel. Tambe es crida en calcular les ombres o les reflexions.
    vec3 ComputeColor (Ray &ray, int depth );

    // Vector d'objectes continguts a l'escena
    std::vector<Object*> objects;

    // Camera: on está l'observador
    Camera *cam;

private:
    void RandomScene();

};

#endif // SCENE_H
