#include "cuerpo.h"
#include "math.h"
#include "cmath"

cuerpo::cuerpo() // constructor
{
    px=0;
    py=0;
    r=10;
    alfa=0;
    w=0;
    a=0;
    dt=0;
    g=9.8;
    //l=100;

}

cuerpo::~cuerpo(){ //destructor

}

void cuerpo::actualizar(){ //actualiza las posiciones de la elipse con las ecuaciones de mto angular
    dt+= 0.001;
    alfa+= w*dt+(a*pow(dt,2)/2);
    a=g*cos(alfa);
    w+=a*dt;
    px=350*cos(alfa)+490;
    py=350*sin(alfa);


}

float cuerpo::get_posX(){ // retorna px
    return px;
}



float cuerpo::get_posY(){// retorna py
    return py;
}

float cuerpo::get_vel(){ // retorna w
    return w;
}

float cuerpo::get_Radio(){//retorna el radio
    return r;
}

