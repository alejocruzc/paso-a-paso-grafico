#ifndef PARTICULA_H
#define PARTICULA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <iostream>

using namespace std;

class particula : public QGraphicsItem
{
public:

   particula(float ini_px, float ini_py, float ini_r): px(ini_px), py(ini_py), r(ini_r){vx=5;vy=5;}  // Constructor para inicializar el radio, posicion y velocidad en x,y
   float getposx();    //Metodo para obtener la posicion en x
   float getposy();    //Metodo para obtener la posicion en y
   float getradio();   //Metodo para obtener el radio
   float getvelx();    //Metodo para obtener la velocidad en x
   float getvely();    //Metodo para obtener la velocidad en y

   void setposicion(float x, float y);  // Metodo para cambiar las coordenadas x,y de la particula
   void mover(float dt, float vertlim); // Metodo para actualizar posicion de la particula
   void setvelocidad(float velx, float vely); // Metodo para cambiar velocidad en x,y
   void colision (float horzlim, float vertlim); // Metodo para detectar choques de la particula con bordes

   QRectF boundingRect() const;

   void paint(QPainter *painter, const QStyleOptionGraphicsItem*option,QWidget*widget);


private:
    float px;  //Coordenada x
    float py;  //Coordenada y
    float r;   //Radio
    float vx;  //Velocidad en x
    float vy;  //Velocidad en y



    particula();
};

#endif // PARTICULA_H
