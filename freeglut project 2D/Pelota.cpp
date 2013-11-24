/*ALVARO QUESADA PIMENTEL*/
#include "Pelota.h"
#include <cmath>

const int PI = 3.14159265358979323846 ;
extern bool relleno;

void Pelota::draw(){

	glColor3f(0.0,0.0,1.0); 

	if(!relleno){
		glBegin(GL_LINE_LOOP); 
			for(int i = 0; i < 20; i++) 
			{ 

				glVertex2f(contorno[i].x, contorno[i].y);//output vertex 

			} 
		glEnd(); 

		glBegin(GL_POINTS);
		 glVertex2d(centro.x,centro.y);
		glEnd();
	}
	else{
		glBegin(GL_POLYGON); 
			for(int i = 0; i < 20; i++) 
			{ 

				glVertex2f(contorno[i].x, contorno[i].y);//output vertex 

			} 
		glEnd(); 
	}
}

PV2D Pelota::getDireccion(){
	return direccion;
}

void Pelota::setVelocidad(int new_velocidad){
	velocidad = new_velocidad;
}
void Pelota::mover(GLdouble t){

	centro = centro + (direccion)*t;

	for(int i = 0; i<20;i++){
		contorno[i] = contorno[i]+(direccion)*t;
	}

}

PV2D Pelota::getCentro(){
	return centro;
}

void Pelota::rebotar(PV2D nuevadirecion){

	double a = direccion*nuevadirecion;

	direccion = direccion - nuevadirecion*a*2;
}

int Pelota::getVelocidad(){
	return velocidad;
}

void Pelota::crearContorno(){

	GLdouble cx = centro.x;
	GLdouble cy = centro.y;

	
		for(int i = 0; i < 20; i++) 
		{ 
			GLdouble theta = 2.0f * 3.1415926f * GLdouble(i) / GLdouble(20);//get the current angle 

			GLdouble x = radio * cos(theta);//calculate the x component 
			GLdouble y = radio * sin(theta);//calculate the y component 

			contorno[i] = PV2D(x + cx,y + cy);
		}
}

GLdouble Pelota::getRadio(){
	return radio;
}