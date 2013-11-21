/**ALVARO QUESADA PIMENTEL**/
#ifndef CIRCULO_H
#define CIRCULO_H
#include <GL/freeglut.h>
#include "Obstaculo.h"
#include "PV2D.h"
class Circulo: public Obstaculo
{
public:
	Circulo(GLdouble new_radio, PV2D new_centro,GLdouble new_radiopelota, bool new_visible): radio(new_radio), centro(new_centro), radioPelota(new_radiopelota),visible(new_visible){
		crearLados();
		if(visible){
			circuloRecubridor = new Circulo(radio+radioPelota,centro,0.0,false);
		}
	}
	 bool interseccionVSpelota(PV2D ,PV2D ,GLdouble &, PV2D &);
	 void draw();
	 void finalizar();
	 Obstaculo* getContorno(int );
	 int getTamContorno();

private:
	bool visible;
	PV2D centro;
	GLdouble radioPelota;
	GLdouble radio;
	PV2D lados[20];
	Obstaculo* circuloRecubridor;

	void crearLados();
};

#endif // !CIRCULO_H

