GiV - P2
----------  


Abstract
^^^^^^^^
Se han implementado las classes Material y Llum y sus respectivos metodos para pasarlas a la GPU. Estas classes se usan en Scene como un array de Llums y un array de Objectes que tienen este Material.
La componente difusa del Material que usan todos los objetos se ha definido de color roja, asi que nuestro objeto sin texturas aplicadas tendra un color rojo.
También se implemento los demas metodos para pasar a GPU la camara y las texturas.
Se ha implementado en GLWidget un array con todos los programas disponibles para que sea mas fácil cambiar de shader y de textura.
Se han implementado también todos los movimientos de la camara con el ratón.
Se ha realizado el Gouraud, el Phong Shading y el Toon Shading creando los archivos glsl y creando y linkeando los respectivso programas.
Se ha realizado las transparencias, con el atributo alpha en la classe Material, que tendra la información del nivel de transparencia del este material
Se han implementado las texturas y el BumpMapping, se han tenido que crear archivos glsl para texturas y BumpMapping y se han implementado todos los metodos de Object que hacen posible la creacion de texturas y el paso de texturas a GPU.



Features
^^^^^^^^

- FASE 1
    - [ Sergi Hurtado ] classe Material
    - [ Sergi Hurtado ] classe Llum
    - [ Angel Bergantiños ] Gouraud
    - [ Angel Bergantiños ] Phong Shading
    - [ Angel Bergantiños y Sergi Hurtado ] Toon Shading
    - [ Angel Bergantiños ] Objectes transparents
    
- FASE 2
    - [ Angel Bergantiños ] Camara
    - [ Angel Bergantiños ] Textures
    - [ Angel Bergantiños y Sergi Hurtado ] Efectes de relleu amb textures

    
Extensions
^^^^^^^^^^
No se ha implementado ninguna extensión para la práctica.


Screenshots
^^^^^^^^^^^
Gouraud:
http://i.imgur.com/Jwpt9xv.png

Phong Shading:
http://i.imgur.com/kjJmUhf.png

Toon Shading:
http://i.imgur.com/pH8sycZ.png

Gouraud Texture:
http://i.imgur.com/Gd4g4ZL.png

Phong Texture:
http://i.imgur.com/Pm4aXqj.png

BumpMapping:
http://i.imgur.com/7ryjFSJ.png


Additional Information
^^^^^^^^^^^^^^^^^^^^^^
Horas de dedicación
Aparte de las horas de practica en clase, se trabajaron mas horas fuera de las classes. Para realizar esta práctica se ha dedicado muchas mas horas en algunas partes que en otras:
En la fase 1, al principio costo bastante entender como se hacia todo el proceso de pasar de CPU a GPU, pero una vez entendido se realizaron bastante rapido los metodos para pasar a GPU. En la parte de los shaders, se le dedicaron bastantes horas, pero una vez logramos sacar el Gouraud los demas ya salieron mas fácil.
En la fase 2, se le dedico menos horas, ya que salio todo bastante fácil excepto a la hora de realizar el Bump Mapping, en el cual se dedicaron bastantes mas horas, ya que no comprendiamos al principio como usar las dos texturas a la vez en los archivos glsl.

Problemas principales
Surgieron basantes problemas a la hora de implementar los shaders, ya que no sabiamos muy bien como linkear el programa que se iba a utilizar para ese shader en concreto y aun no entendiamos muy bien como se realizaba el paso de CPU a GPU.
Pero sobretodo el problema principal por el que tardamos tanto fue que teniamos mal la cabecera del primer shader que intentabamos implementar:
    #define IN varying
    #define OUT varying
Pero una vez lo entendimos y logramos realizar el primer shader, los demas shaders al igual que el resto de la practica resulto mucho mas fácil. Se realizo un array de programas dentro de GLWidget en el initShadersGPU para que fuese mas cómodo a la hora de cambiar de shader o texture.
Otro problema con el que nos encontramos fue a la hora de implementar el Bump Mapping, ya que no sabiamos como usar dos texturas a la vez en el framgent shader, ni como pasarlas. Al final logramos implementarlo pasandolas en el drawTexture:
    program->setUniformValue("texture", 0);
    program->setUniformValue("normals", 1);
y en el glsl ya no costo tanto porque era muy parecido al Phong que habiamos implementado antes.

