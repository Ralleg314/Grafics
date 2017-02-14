TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    figura.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    figura.h

