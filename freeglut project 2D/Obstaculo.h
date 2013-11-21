/**ALVARO QUESADA PIMENTEL**/
#ifndef OBSTACULO_H
#define OBSTACULO_H
#include <GL/freeglut.h>
#include "PV2D.h"
class Obstaculo
{
public:
	virtual bool interseccionVSpelota(PV2D ,PV2D ,GLdouble &, PV2D &) = 0;
	virtual void draw() = 0;
	virtual void finalizar() = 0;
	virtual Obstaculo* getContorno(int ) = 0;
	virtual int getTamContorno() = 0;
};

#endif // !OBSTACULO_H

