#include "particula.h"


    float particula::getposx()
    {
      return px;

    }

    float particula::getposy()
    {
      return py;

    }

    float particula::getvelx()
    {

      return vx;
    }

    float particula::getvely()
    {
        return vy;

    }

    float particula::getradio()
    {
        return r;
    }


    void particula::setvelocidad(float velx, float vely)
    {
          vx= velx;
          vy= vely;

    }

    void particula::setposicion(float x, float y)
    {
          px=x;
          py=y;

    }

    void particula::mover(float dt, float vertlim)
    {
        px+=vx*dt;
        py+=vy*dt;
        setPos(getposx(),vertlim-getposy());
    }


    void particula::colision(float horzlim, float vertlim)
    {

        if(getposx()<getradio()|| getposx()>horzlim-getradio())
        {
         setvelocidad(-1*getvelx(),getvely());
        }
        if(getposy()<getradio()||getposy()>vertlim-getradio())
        {
             setvelocidad(getvelx(),-1*getvely());
        }

    }

    QRectF particula::boundingRect() const
    {

       return QRectF(-1*r,-1*r,2*r,2*r);
    }

    void particula::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
    {
        painter->setBrush(Qt::darkRed);              // Pinta la particula de rojo
        painter->drawEllipse(boundingRect());        // Dibuja una figura eliptica y la encierra en un rectangulo

    }
