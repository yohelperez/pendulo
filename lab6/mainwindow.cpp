#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);

    h_limit=1000;                   //Asigna el tamaño de la interfaz
    v_limit=500;

    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);
    ui->centralWidget->adjustSize();
    scene-> addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);



    srand (time(NULL)); //para el timer

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));







}

MainWindow::~MainWindow()//destructor
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()//actualiza la posicion dependiendo del timer para la colision
{
    for(int i=0;i<bars.size();i++){

        bars.at(i)->actualizar(v_limit);//actualiza en esferagraf

    }
}



void MainWindow::on_pushButton_clicked()//cuando se pulsa el boton
{
     timer->start(25);
     bars.push_back(new cuerpograf);
     bars.back()->actualizar(v_limit);   //la actualiza
     scene->addItem(bars.back());        //agrega el nuevo elemento .

}
