GiV - P1
----------  
::

Abstract
^^^^^^^^
Se ha realizado el degradado del fondo en ComputeColor, y cada vez que no se hacia hit, se utilizaba de color este degradado
Se han implementado los hits de Esfera, Triangulo, Cubo, Plano y BoundaryObject; pero solo mostramos en la escena 4 esferas.
Para la Fase 2, se ha cambiado el algoritmo de RayTracing de forma que envie un numero aleatorio de rayos por pixel y se calcule el 
promedio de estos, tambien se ha realizado la raiz cuadrada del color resultante, esto se realiza dentro del algoritmo de RayTracking,
antes de pintar.
Se ha añadido la clase Light, y un array de Lights dentro de Scene, en el cual añadimos una luz puntual a las escena. La luz ambiental 
se añadira en el blinnPhong.
Se ha implementado el metodo blinnPhong en la classe Scene y este se usara luego para el ComputeColor.
Para realizar la recursividad del ComputeColor, se ha establecido un MAXDEPTH a 10 y se va incrementando el depth cada
vez que tenemos un hit.
Se ha implementado también el materiam Metal y el material Transparent.
La escena final resultante son dos esferas Lambertian, una esfera Transparente y una esfera Metal.

Features
^^^^^^^^

- Figures
    - [ Angel Bergantiños ] Plane
    - [ Angel Bergantiños y Sergi Hurtado ] Triangle
    - [ Angel Bergantiños ] Sphere
    - [ Angel y Sergi Hurtado ] Cube
    - [ Angel y Sergi Hurtado] Boundary Object
- Blinn-Phong
    - [ Sergi Hurtado ] Light
    - [ Angel Bergantiños y Sergi Hurtado ] Basic Blinn-Phong
    - [ Angel Bergantiños ] Recursive Blinn-Phong
- Material
    - [ Angel Bergantiños ] Metal
    - [ Angel Bergantiños ] Transparent
    - [ No se ha implementado ] Isotropic
    - [ No se ha implementado ] Volume

Extensions
^^^^^^^^^^
No se ha implementado ninguna extensión para la práctica.

Screenshots
^^^^^^^^^^^
*(NOTA: Capturas de pantalla de las pruebas que hayáis realizado)*
Provando BoundaryObject:
http://i.imgur.com/SFsyxOO.jpg

Provando escena final (2 esferas Lambertian, 1 esfera Metal, 1 esfera Transparente):
http://i.imgur.com/V5IIBA7.jpg

Additional Information
^^^^^^^^^^^^^^^^^^^^^^
Horas de dedicación
Aparte de las horas de practica en clase, se trabajaron mas horas fuera de las classes. Para realizar esta práctica se ha dedicado muchas mas horas en algunas partes que en otras:
La Fase 0 y 1 se dedico bastantes horas ya que no estabamos muy familiarizados con el codigo y hubo que leerlo y entenderlo bien. Aunque a la hora de implementar los hits de los objetos no fue muy dificil excepto en el 
caso de BoundaryObject, ya que disponiamos de la pagina web del campus que explicaba como realizar los hits de cada objeto.
La Fase 2 salio todo facil excepto a la hora de implementar el transparate, donde se dedico bastante tiempo ya que teniamos problemas a la hora de implementar la formula deel scatter.

Problemas principales
Nos han surgido varios problemas durante la realización de esta practica.
Uno de los problemas surgidos era que no entendiamos bien como se guardaba el boundary object y al leer el fichero como txt no entendiamos bien a que se referia cada numero, como consecuencia de esto, no sabiamos
leer bien el fichero, hasta que descubrimos que en las caras se guardaban los indices del vector vertexs,entonces se creo un vector de Triangulos donde se creaba un Triangulo por cada cara y se usaba el hit de triangulo.
Otro de los problemas surgidos fue a la hora de implementar el material Transparent, no sabiamos porque fallaba el scatter



