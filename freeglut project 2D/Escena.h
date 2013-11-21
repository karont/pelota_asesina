/**ALVARO QUESADA PIMENTEL**/
#ifndef ESCENA_H
#define ESCENA_H
#include <GL/freeglut.h>
#include "PV2D.h"
#include "Controlador.h"
class Escena
{
public:
	Escena(){}
	Escena(GLdouble new_xRight,GLdouble new_xLeft,GLdouble new_yBot,GLdouble new_yTop):
		xRight(new_xRight),xLeft(new_xLeft),yBot(new_yBot),yTop(new_yTop),controlador(Controlador(getCentro())){}	

	/*
	Getters setters
	*/

	GLdouble getxRight()const;
	void setxRight(const GLdouble &);

	GLdouble getxLeft()const;
	void setxLeft(const GLdouble &);

	GLdouble getyBot()const;
	void setyTop(const GLdouble &);

	GLdouble getyTop()const;
	void setyBot(const GLdouble &);

	//devuelve el puento del centro de la pantalla
	PV2D getCentro() const;

	void redimensionar(const GLdouble &);

	void mover(const int &,const GLdouble &,const GLdouble &);

	void zoom(const GLdouble &);

	void draw(void);
	void step();
	void finalizar(void);
	PV2D transformarPuntoAVE(int,int);
	void zoomProgresivo(const GLdouble &fIncr,const int &i);
	void embaldosar(int);
private:	
	GLdouble xRight;
	GLdouble xLeft;
	GLdouble yBot;
	GLdouble yTop;
	Controlador controlador;
};

#endif // !ESCENA_H

