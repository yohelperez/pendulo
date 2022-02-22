#include "cuerpograf.h"
#include "QDebug"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */



cuerpograf::cuerpograf() : escala(1)//consrucyor
{
   //aqui se ponen los valores aleatoreos de cada cuerpo.
   //float posx, posy, velx , vely ,r, mass, K, e;
   // posx = 250;
   // posy = 50;
   // r = 30;
    esf = new cuerpo();
}

cuerpograf::~cuerpograf()//destructor
{
    delete esf;
}

QRectF cuerpograf::boundingRect() const
{
        return QRectF(-1*escala*esf->get_Radio(),-1*escala*esf->get_Radio(),2*escala*esf->get_Radio(),2*escala*esf->get_Radio());
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkMagenta);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
}

void cuerpograf::setEscala(float s)
{
    escala=s;
}

void cuerpograf::actualizar(float v_lim)
{
    esf->actualizar();//actualiza los datos de las  posiciones del cuerpo
    setPos(esf->get_posX(),(esf->get_posY()));// actualiza posiciones en la interfaz
}

cuerpo *cuerpograf::getEsf()
{
    return esf;
}
