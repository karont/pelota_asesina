/**ALVARO QUESADA PIMENTEL**/
#include "Triangulo.h"
#include "Circulo.h"
#include <cmath>

const double EPSILON = 0.00001; 
extern bool relleno;
extern bool dborde;

void Triangulo::draw(){
	glColor3f(1.0,0.0,0.0); 

	if(!relleno){
		glBegin ( GL_LINE_LOOP ) ;
			for(int i = 0; i<3; i++){
			
				glVertex2d( vertices[i].x, vertices[i].y );
			
			}
		glEnd () ;
	}
	
	else{
		glBegin ( GL_TRIANGLES ) ;
			for(int i = 0; i<3; i++){
			
				glVertex2d( vertices[i].x, vertices[i].y );
			
			}
		glEnd () ;
	}

	if(dborde){
		if(visible){
			for(int i = 0; i<6; i++){
				contorno[i]->draw();
			}
		}
	}
}

bool Triangulo::interseccionVSpelota(PV2D p, PV2D v,GLdouble &tIn, PV2D &normalIn){
	
		PV2D vnormal = v.normalIz().normalizar();;
		int dist[3]; int proy[3]; int sign[3];

		for(int i =0; i<3; i++){
			dist[i] = (vertices[i] - p) * vnormal;

			if(dist[i]>EPSILON) sign[i] = 1; 
			else if(dist[i]<EPSILON) sign[i] = -1;
			else sign[i] = 0;

			proy[i] = (vertices[i] - p) * v;
		
		}
		int sum = sign[0]+sign[1]+sign[2];
		if(abs(sum)==3) return false;

		int  nHits = 0; double hit[2]; PV2D n[2];
		int j;
		int num = 1, den = 1;
		for (int i = 0; i < 3; i++){
			j = (i+1)%3;

			if((sign[i]* sign[j]) < 0){
				num = (proy[i]*dist[j])-(proy[j]*dist[i]);
				den = (dist[j]-dist[i]);
				hit[nHits] = num/den;
				n[nHits] = normales[i];
				nHits++;
			}
		
		}

		if(nHits<2){
			for(int i=0; i<3;i++){
				if(sign[i] == 0){
					hit[nHits] = proy[i];
					n[nHits] = normalesV[i];
					nHits++;
				}
			}
		}

		int m = mini(hit);

		tIn = hit[m]; normalIn = n[m];
		return true;
	
}


int Triangulo::mini(double a[]){


	if(a[0] <= a[1]) return 0;
	else return 1;
}

void Triangulo::crearContorno(const GLdouble &radio){
	PV2D vect;
	PV2D cent;
	PV2D cent2;
	PV2D vert[3];
		for(int i = 0; i<3; i++){
			
			vect = vertices[(i+1)%3]-vertices[i];
			vect = vect/2;
			cent =  vect + vertices[i];
			vert[0] = cent; 
			cent2 = cent + (normales[i]*radio);
			vert[1] = cent2 + vect;
			vert[2] = cent2 - vect;

			contorno[i] = new Triangulo(vert[1],vert[0],vert[2],1,false);
			
		}

	for(int i = 0; i<3; i++){

		contorno[i+3] = new Circulo(radio,vertices[i],0.0,false);
		
	}

}
Obstaculo* Triangulo::getContorno(int i){
	return contorno[i];
}

int Triangulo::getTamContorno(){
	return 6;
}
void Triangulo::finalizar(){
	for(int i = 0; i<3; i++){
		delete contorno[i];
	}

}