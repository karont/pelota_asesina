/**ALVARO QUESADA PIMENTEL**/
#include "Circulo.h"
#include <cmath>
#include <iostream>

const double EPSILON = 0.00001; 
extern bool dborde;
extern bool relleno;
void Circulo::crearLados(){

	GLdouble cx = centro.x;
	GLdouble cy = centro.y;

	
		for(int i = 0; i < 20; i++) 
		{ 
			GLdouble theta = 2.0f * 3.1415926f * GLdouble(i) / GLdouble(20);//get the current angle 

			GLdouble x = radio * cos(theta);//calculate the x component 
			GLdouble y = radio * sin(theta);//calculate the y component 

			lados[i] = PV2D(x + cx,y + cy);
		}
}

void Circulo::draw(){

	glColor3f(1.0,0.0,0.0); 
	if(!relleno){
		glBegin(GL_LINE_LOOP); 
			for(int i = 0; i < 20; i++) 
			{ 

				glVertex2f(lados[i].x, lados[i].y);//output vertex 

			} 
		glEnd(); 

		if (dborde)if (visible)circuloRecubridor->draw();

		glBegin(GL_POINTS);
		 glVertex2d(centro.x,centro.y);
		glEnd();
	}
	else{
	glBegin(GL_POLYGON); 
		for(int i = 0; i < 20; i++) 
		{ 

			glVertex2f(lados[i].x, lados[i].y);//output vertex 

		} 
	glEnd(); 
	}
}
bool Circulo::interseccionVSpelota(PV2D p, PV2D v,GLdouble &tIn, PV2D &normalIn){
	v = v.normalizar();;
	GLdouble A = v*v;
	GLdouble B = 2*((p-centro)*v);
	GLdouble C = ((p-centro)*(p-centro)) - (radio*radio);

	GLdouble discriminante = B*B - 4*A*C;

	if (discriminante < EPSILON) return false;

	
	
	else if(discriminante > EPSILON){

		GLdouble tIn1 = (-B-sqrt(discriminante))/2*A;
		GLdouble tIn2 = (-B+sqrt(discriminante))/2*A;
		
			normalIn = ((p-centro)+v).normalizar();

		if(tIn1 >= tIn2) tIn = tIn2;
		else tIn = tIn1;

		/*std::cout<<"2 inter ****" <<tIn<< std::endl;
		std::cout<<"2 inter1 " <<tIn1<< std::endl;
		std::cout<<"2 inter2 " <<tIn2<< std::endl;*/
		return true;
	}

	else{
		tIn = (-B/(2*A));
		normalIn = ((p-centro)+v).normalizar();

		//std::cout<<"1 inter ----- " <<tIn<< std::endl;
		return true;
	}

}
int Circulo::getTamContorno(){
	return 1;
}

Obstaculo* Circulo::getContorno(int i){
	return circuloRecubridor;
}
void Circulo::finalizar(){
	
		delete circuloRecubridor;


}