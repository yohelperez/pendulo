#ifndef CUERPO_H
#define CUERPO_H


class cuerpo
{
private:
    float px; //posicion en x
    float py;//posicion en y
    float r;//radio
    float alfa; //angulo
    float w; //velocidad angular
    float a; // aceleracion angular
    float g;// gravedad
    float dt; // delta de tiempo
    //float l; // longitud

public:

    cuerpo();
    ~cuerpo();
    void actualizar();
    float get_posX();
    float get_posY();
    float get_vel();
    float get_Radio();
    //void set_Vel(a_);
};

#endif // CUERPO_H
