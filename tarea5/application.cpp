#include "application.h"
#include "ui_application.h"


application::application(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::application)
{
    ui->setupUi(this);

    srand(time(NULL));
    timer=new QTimer(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,ANCHO,ALTO);

    ui->graphicsView->setScene(scene);

    scene->addRect(scene->sceneRect());

    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height()+100);

    partic = new particula(100,100,20);
    scene->addItem(partic);
    partic->mover(DT,ALTO);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actual_scene()));

}

application::~application()
{
    delete ui;
    delete partic;
    delete timer;
    delete scene;
}

void application::on_START_clicked()
{
   timer->start(40);
}

void application::actual_scene()
{
    partic->mover(DT,ALTO);
    partic->colision(ANCHO,ALTO);

}




