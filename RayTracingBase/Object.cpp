#include "Object.h"



Object::Object(Material *const mat)
  {
    material = mat;
  }

Object::~Object()
{
    if (dynamic_cast<Lambertian *>(material))
        delete (Lambertian *)material;
}
