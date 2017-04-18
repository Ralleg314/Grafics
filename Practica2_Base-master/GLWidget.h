#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <math.h>
#include <Scene.h>
#include <Camera.h>
#include <QtWidgets>
#include <QGLWidget>
#include <QTime>

#define PROGRAM_VERTEX_ATTRIBUTE 0
#define PROGRAM_COLOR_ATTRIBUTE 1

class QGLShaderProgram;

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void newObj(QString fichero);
public slots:

    void activaToonShader();
    void activaPhongShader();
    void activaGouraudShader();
    void activaPhongTex();
    void activaGouraudTex();
    void activaBumpMapping();
    void activaEnvMapping();

    void ensenyaMenuLight0();
    void changePositionLight();
    void changeDirectionalLight();
    void changeSpotLight();
    void activateLight();
    void updateXPositionLight(int xposition);
    void updateYPositionLight(int yposition);
    void updateZPositionLight(int zposition);
    void updateLightIntensity(int intensity);
    void showAuxWindowPuntualLight(Light *light);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void setXRotation(int angle);
    void setYRotation(int angle);

    void qNormalizeAngle(double &angle);

    void Zoom (int positiu);
private:
    QWidget* auxWidget; // window for parameters

    Scene *scene;      // escena que conté els objectes i les llums
    Camera *camera;

    QPoint lastPos;   // per interactuar amb la camera

    QGLShaderProgram *program; // Per ars nomes es té un parell vertex-fragment
                               // Cal guardar-ne més d'un en la primera fase.

    void initShader(const char* vertexShaderFile, const char* fragmentShaderFile);
    void initShadersGPU();
    void updateShader();
    void updateShaderTexture();
};

#endif // GLWIDGET_H
