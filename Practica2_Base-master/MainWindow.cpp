
#include <QtWidgets>
#include "ui_mainwindow.h"

#include "GLWidget.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle(tr("Practica 2: GiVD 2016-2017"));
    resize(640, 640);


    glWidget = new GLWidget;


    setCentralWidget(glWidget);

    // connexio dels menus

    connect(this->ui->action_obre_fitxer, SIGNAL(triggered()), this, SLOT(newObjFromFile()));
    connect(this->ui->action_gouraud, SIGNAL(triggered()), glWidget, SLOT(activaGouraudShader()));
    connect(this->ui->action_phong, SIGNAL(triggered()), glWidget, SLOT(activaPhongShader()));
    connect(this->ui->action_toon, SIGNAL(triggered()), glWidget, SLOT(activaToonShader()));
    connect(this->ui->action_gouraud_tex, SIGNAL(triggered()), glWidget, SLOT(activaGouraudTex()));
    connect(this->ui->action_phong_tex, SIGNAL(triggered()), glWidget, SLOT(activaPhongTex()));
    connect(this->ui->action_bump_mapping, SIGNAL(triggered()), glWidget, SLOT(activaBumpMapping()));
    connect(this->ui->action_environmental_mapping, SIGNAL(triggered()), glWidget, SLOT(activaEnvMapping()));
    connect(this->ui->action_afegeix_llum_puntual, SIGNAL(triggered()), glWidget, SLOT(ensenyaMenuLight0()));

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newObjFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isNull())
        this->glWidget->newObj(fileName);

}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

