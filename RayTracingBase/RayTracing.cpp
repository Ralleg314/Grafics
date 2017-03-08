
/* 
 * File:   RayTracing.cpp
 * Author: anna
 *
 * Created on 2 de enero de 2017, 19:43
 */

#include <cstdlib>
#include "RayTracing.h"
#include "stdio.h"


using namespace std;

// Metode per netejar la memòria
void cleanup() {
    delete scene;
}


// Metode Render

// Aquest metode, depenent si té activat o no GLUT, pinta pixels pinta pixels en la finestra GL usant GL_POINT o
// crea un fitxer anomenat resultat.ppm. En el cas de GLUT  es crida cada vegada que cal refrescar la pantalla. En el cas de no usar GLUT
// només s'executa un cop.

// Aquesta funcio transforma cada pixel a coordenades de mon i
// envia un raig des de la camera en aquella direccio cridant al metode CastRay
// i pel pintar la imatge final:
// 1) Neteja la pantalla per a visualitzar el nou frame
// 2) Envia un raig a l'escena per a cada pixel de la pantalla i utilitza el color retornat per a pintar el pixel
// 3) Actualitza la finestra GL fent flush de les intruccions GL, si es el cas. Sino, posa el color en un fitxer

//Precondicio:
// La Scene i la Camera han d'estar creades i inicialitzades

void Render()
{


#ifndef GLUT
    // Les seguents linieas permeten escriure en un fitxer, el output i
    // prescindir de glut para visualitzar la imatge
      std::ofstream out("resultat.ppm");
      std::streambuf *coutbuf = std::cout.rdbuf(); //salvar el buf antic
      std::cout.rdbuf(out.rdbuf()); //redireccio de  std::cout al out.txt!
      std::cout << "P3\n" << scene->cam->viewportX << " " << scene->cam->viewportY << "\n255\n";

#else
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Netejar la finestra OpenGL
    glBegin(GL_POINTS);	//S'activa el mode GL_POINTS. En aquest mode
                        // cada vertex especificat és un punt.
                        //Reference https://en.wikibooks.org/wiki/OpenGL_Programming/GLStart/Tut3 si us interessa.
#endif
    // algorisme de RayTracing

    // Recorregut de cada pixel de la imatge final
    int numSamples=1;

    for (int y = scene->cam->viewportY-1; y >= 0; y--) {
         for (int x = 0; x < scene->cam->viewportX; x++) {
            for(int i=0;i<numSamples;i++){
            float rnd = ((float) rand()) / (float) 2147483648;
            vec3 col(0, 0, 0);
            float u = float(x+rnd) / float(scene->cam->viewportX);//Normalizamos el vector
            float v = float(y+rnd) / float(scene->cam->viewportY);

            Ray r = scene->cam->getRay(u, v);
            col += scene->ComputeColor(r,0);


#ifdef GLUT
            float pixelX =  2*((x+0.5f)/scene->cam->viewportX)-1;
            float pixelY = 2*((y+0.5f)/scene->cam->viewportY)-1;

             glColor3f(col[0], col[1], col[2]);
             glVertex3f(pixelX, pixelY, 0.0f);
#else
             // Aquestes tres lineas permitirien fer una sortida en un ppm per ser visualitzat per un gimp o similar
             int ir = int(255.99*col[0]);
             int ig = int(255.99*col[1]);
             int ib = int(255.99*col[2]);
             std::cout << ir << " " << ig << " " << ib << "\n";
#endif
        }}
     }
#ifdef GLUT
    glEnd();
    glFlush();
#else

#endif

}



// Metode principal del programa

int main(int argc, char **argv) {

    // inicialitza l'escena: el constructor de l'escena s'encarrega de
    // crear els objectes i les llums
    scene = new Scene();

#ifdef GLUT

    //inicialitza OpenGL
	glutInit(&argc, argv);
    //Define la mida de la window GL especificada per la mida del viewport
    glutInitWindowSize(scene->cam->viewportX, scene->cam->viewportY);

    //Creacio de la window per pintar amb GL
	glutCreateWindow("RayTracer");
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	

    //Posa la funcio Render per a que la window GL cridi quan es refresca
	glutDisplayFunc(Render);
	atexit(cleanup);

    // Inicia el main loop per a poder refrescar l'escena
	glutMainLoop();
#else
    Render();
#endif

    return 0;
}
