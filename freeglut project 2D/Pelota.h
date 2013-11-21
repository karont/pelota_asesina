/**ALVARO QUESADA PIMENTEL**/
#ifndef PELOTA_H
#define PELOTA_H
#include <GL/freeglut.h>
#include "PV2D.h"
class Pelota
{
public:
	Pelota();
	Pelota(GLdouble new_radio, PV2D new_centro):radio(new_radio),centro(new_centro),direccion(PV2D(0.0,0.0)){
	centro.x=centro.x-200;
	centro.y=centro.y;
	crearContorno();
	direccion = PV2D(5.0,2.0).normalizar();
	velocidad = 3;
	direccion = direccion * velocidad;
	}

	int getVelocidad();

	void setVelocidad(int);
	PV2D getCentro();
	void mover(GLdouble);
	void draw();
	void rebotar(PV2D);
	void setDireccion(PV2D);
	PV2D getDireccion();

	GLdouble getRadio();
	
private: 
	GLdouble radio;
	PV2D centro;
	PV2D direccion;
	int velocidad;
	PV2D contorno[20];
	
	void crearContorno();
};

#endif // !PELOTA_H

