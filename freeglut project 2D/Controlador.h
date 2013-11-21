/**ALVARO QUESADA PIMENTEL**/
#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <GL/freeglut.h>
#include "Pelota.h"
#include "PV2D.h"
#include "Lista.h"
#include "Triangulo.h"
#include "Obstaculo.h"
#include "Circulo.h"

class Controlador
{
public:
	Controlador();
	Controlador(PV2D new_centro):centro(new_centro), pelota(Pelota(20.0,new_centro)){

	crearBordes();

	añadirObstaculos();
	
	};

	void draw();
	void step();
	void finalizar();
	
private:
	Pelota pelota;
	PV2D centro;
	Lista<Obstaculo*> listTriangulos;
	void crearBordes();
	void añadirObstaculos();
};

#endif // !CONTROLADOR_H

