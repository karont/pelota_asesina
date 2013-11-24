/**ALVARO QUESADA PIMENTEL**/
#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "PV2D.h"
#include "Obstaculo.h"

/*      
          Z
          * 
         * *
        *   *
       *     *
	  *       *	
	 *         *	
  X	************* Y
	           
*/
class Triangulo: public Obstaculo
{
public: 

	Triangulo(PV2D x, PV2D y, PV2D z, GLdouble radio, bool new_visible){
	vertices[0]= x;
	vertices[1]= y;	
	vertices[2]= z;
	visible = new_visible;
	normales[0]= (y-x).normalDr().normalizar();
	normales[1]= (z-y).normalDr().normalizar();
	normales[2]= (x-z).normalDr().normalizar();

	PV2D baricentro = ((y-x)+(z-y)+(x-z))/3;
	normalesV[0]=x-baricentro;
	normalesV[1]=y-baricentro;
	normalesV[2]=z-baricentro;

	if(visible) crearContorno(radio);

	}

	

	void draw();
	bool interseccionVSpelota(PV2D ,PV2D ,GLdouble &, PV2D &);
	void finalizar();
	Obstaculo* getContorno(int );
	int getTamContorno();

private:
	PV2D vertices[3];
	PV2D normales[3];
	PV2D normalesV[3];
	PV2D baricentro;
	bool visible;
	Obstaculo* contorno[6];
	int mini(double[]);
	void crearContorno(const GLdouble &);

};
#endif // !TRIANGULO_H
