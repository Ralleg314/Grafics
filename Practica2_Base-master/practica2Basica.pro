#-------------------------------------------------
#
# Project created by QtCreator 2012-02-07T16:04:09
#
#-------------------------------------------------

QT       += core gui opengl
QT       += widgets

TARGET = practica2Basica
TEMPLATE = app

SOURCES +=\
    Common.cpp \
    cara.cpp \
    readfile.cpp \
    Scene.cpp \
    Camera.cpp \
    Light.cpp \
    Object.cpp \
    Material.cpp \
    MainWindow.cpp \
    Main.cpp \
    GLWidget.cpp

HEADERS  += \
    vec.h \
    mat.h \
    Common.h \
    cara.h \
    readfile.h \
    Scene.h \
    Camera.h \
    Light.h \
    Object.h \
    Material.h \
    MainWindow.h \
    GLWidget.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    vshader1.glsl \
    fshader1.glsl

RESOURCES += resources.qrc

DISTFILES +=
