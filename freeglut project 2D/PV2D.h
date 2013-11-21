/**ALVARO QUESADA PIMENTEL**/
#ifndef PV2D_H
#define PV2D_H
#include <GL/freeglut.h>
class PV2D
{
public:
	PV2D(void):x(0.0),y(0.0){};

	PV2D(GLdouble new_x, GLdouble new_y): x(new_x),y(new_y){};
	GLdouble x;
	GLdouble y;

	bool esCero();
	PV2D normalizar();
	PV2D normalIz();
	PV2D normalDr();
	PV2D operator+(const PV2D & );
	PV2D operator-(const PV2D & );
	double operator*(const PV2D & );
	PV2D operator/(const int & );
	PV2D operator*(const GLdouble & );

};

#endif // !PUNTO_H

