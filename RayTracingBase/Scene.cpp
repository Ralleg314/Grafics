#include "Scene.h"

Scene::Scene()
{
    // creacio de la camera
    vec3 lookfrom(13,2,3);
    vec3 lookat(1,0,0);
    float dist_to_focus = 10.0;
    float aperture = 0.1;
    int pixelsX = 600;
    int pixelsY = 400;
    cam = new Camera(lookfrom, lookat, vec3(0,1,0), 20, pixelsX, pixelsY, aperture, dist_to_focus);

   // TODO: Cal crear els objectes de l'escena
    RandomScene();

    // TODO: Cal afegir llums a l'escena (Fase 2)
    lights.push_back(new Light(vec3(2,8,10),vec3(0.4,0.4,0.4),vec3(0.5,0.5,0.5),vec3(1.0,1.0,1.0),0.05,0.0,0.01));
}

Scene::~Scene()
{
    for(unsigned int i = 0; i < objects.size(); ++i){
        if(objects[i]){
            if (dynamic_cast<Sphere*>(objects[i])){
                delete (Sphere *)(objects[i]);
            }else if(dynamic_cast<Cube*>(objects[i])){
                delete (Cube *)(objects[i]);
            }else if(dynamic_cast<Plane*>(objects[i])){
                delete (Plane *)(objects[i]);
            }else if(dynamic_cast<Triangle*>(objects[i])){
                delete (Triangle *)(objects[i]);
            }else if(dynamic_cast<BoundaryObject*>(objects[i])){
                delete (BoundaryObject *)(objects[i]);
            }
        }
    }
    delete cam;
}

// TODO: Metode que genera una escena random de numObjects de tipus esfera, a diferents posicions,
// amb diferents radis i diferents materials. S'usa drand48 per generar numeros random

void Scene::RandomScene() {

    objects.push_back(new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5, 0.5, 0.5))));
    objects.push_back(new Sphere(vec3(0,-100.5,-1), 100, new Lambertian(vec3(0.8, 0.8, 0.0))));
    //objects.push_back(new Sphere(vec3(1,-1,-1), 0.5, new Lambertian(vec3(0.8, 0.6, 0.2))));
    //objects.push_back(new Sphere(vec3(-1,-1,-1), 0.5, new Lambertian(vec3(0.6, 0.8, 0.2))));
    //objects.push_back(new Sphere(vec3(-1,0,-1), -0.45, new Lambertian(vec3(0.2, 0.6, 0.8))));
    //objects.push_back(new Plane(vec3(1,0,0),vec3(0,0,0),new Lambertian(vec3(0.1, 0.2, 0.5))));
    //objects.push_back(new Plane(vec3(0,1,0),vec3(0,0,0),new Lambertian(vec3(0.1, 0.2, 0.5))));
    //objects.push_back(new Plane(vec3(0,0,1),vec3(0,0,0),new Lambertian(vec3(0.1, 0.2, 0.5))));
    //objects.push_back(new Cube(vec3(-1,-1,-1),vec3(1,1,1),new Lambertian(vec3(0.1, 0.2, 0.5))));
    //objects.push_back( new BoundaryObject("../RayTracingBase/resources/peo1K.obj",new Lambertian(vec3(0.2, 0.6, 0.8))));

    //objects.push_back(new Triangle(vec3(2,1,0),vec3(0,0,0),vec3(5,3,1),new Lambertian(vec3(0.1, 0.2, 0.5))));

}

/*
** TODO: Metode que testeja la interseccio contra tots els objectes de l'escena (Fase 1)
**
** Si un objecte es intersecat pel raig, el parametre  de tipus IntersectInfo conte
** la informació sobre la interesccio.
** El metode retorna true si algun objecte es intersecat o false en cas contrari.
**
*/
bool Scene::hit(const Ray& raig, float t_min, float t_max, HitInfo& info) const {
    HitInfo temp;
    for(int i=0;i<objects.size();i++){
        if(objects[i]->hit(raig,t_min,t_max,temp)){
            if(info.t>temp.t){
                info=temp;
            }
        }
    }
    return info.t<std::numeric_limits<float>::infinity();

}

/*
** TODO: Funcio ComputeColor es la funcio recursiva del RayTracing.
** A modificar en la Fase 2 de l'enunciat per incloure Blinn-Phong  i ombres
** A modificar en la Fase 2 per a tractar reflexions
**
*/


vec3 Scene::ComputeColor (Ray &ray, int depth ) {
    vec3 white=vec3(1,1,1);
    vec3 blue=vec3(0.5,0.7,1);
    float t=0.5f*(ray.direction.y+1);
    HitInfo h;
    Ray scatterRay;
    vec3 scatterColor;
    vec3 color;


    /* TODO: Canviar aquesta assignacio pel color basat amb la il.luminacio basada amb Phong-Blinn segons
     * el material de l'objecte i les llums per la fase 2 de la practica
     * En aquestesta fase 2,  cal fer que tambe es tinguin en compte els rebots de les reflexions.

       Inicialment s'ha posat la direccio del raig per tenir un color diferents per a cada pixel pero
       hitInfo ha d'anar tenint el color actualitzat segons els rebots.
    */
     if(!this->hit(ray,0,1000,h)){
         color = t*blue+(1-t)*white;
     }else{
         color = this->blinnPhong(h.p,h.normal,h.mat_ptr,true);
         /*if(depth<10){
             h.mat_ptr->scatter(ray,h,scatterColor,scatterRay);
             color += scatterColor * this->ComputeColor(scatterRay,depth+1);
         }*/
     }

     return color;
}

void Scene::setAmbientLight(vec3 ambient){

}

vec3 Scene::blinnPhong(vec3 point, vec3 normal, const Material *material, bool ombra){
    vec3 I;
    vec3 Kd = material->diffuse;
    vec3 Ks = material->specular;
    vec3 Ka = material->ambient;
    vec3 Id = lights.at(0)->diffuse;
    vec3 Is = lights.at(0)->specular;
    vec3 Ia = lights.at(0)->ambient;
    vec3 L = normalize(lights.at(0)->position-point);
    vec3 V = normalize(cam->origin-point);
    vec3 H = normalize(L+V);
    int S = material->shiness;

    I = Ka*Ia+(Kd*Id)*dot(L,normal)+(Ks*Is)*(float)std::pow(dot(normal,H),S);
    return (Ks*Is)*dot(normal,H);
}
