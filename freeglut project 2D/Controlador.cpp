/**ALVARO QUESADA PIMENTEL**/
#include "Controlador.h"
#include "PV2D.h"
#include <iostream>
const double EPSILON = 0.00001; 

extern bool rebotecentro;
void Controlador::draw(){

	pelota.draw();
	Lista<Obstaculo*> :: Iterador it = listTriangulos.principio();

	while(it != listTriangulos.final()){
		it.elem()->draw();
		it.avanza();
	}

}

void Controlador::step(){

	GLdouble tin = pelota.getVelocidad();;
	GLdouble tinaux = 1;

	PV2D normal = PV2D(0.0,0.0);
	PV2D normalaux = normal;
	bool intersec = false;

	Lista<Obstaculo*> :: Iterador it = listTriangulos.principio();

	if(!rebotecentro){

		int tam = 1;
		while(it != listTriangulos.final()){
		
			tam = it.elem()->getTamContorno();
			for(int i=0; i<tam; i++){

				if(it.elem()->getContorno(i)->interseccionVSpelota(pelota.getCentro(),pelota.getDireccion(), tinaux,normalaux)){

					if(tinaux < tin && tinaux >= 0){

						tin= tinaux;
						normal=normalaux;
						intersec = true;
				
					}
				}
			}
		
			it.avanza();
		}

	}

	else{

		
		while(it != listTriangulos.final()){
		
			if(it.elem()->interseccionVSpelota(pelota.getCentro(),pelota.getDireccion(), tinaux,normalaux)){

				if(tinaux < tin && tinaux >= 0){

					tin= tinaux;
					normal=normalaux;
					intersec = true;
				
				}
			}
		
			it.avanza();
		}
	}
	pelota.mover(tin);

	if(intersec){
		pelota.rebotar(normal);
	}
}

void Controlador::crearBordes(){

	Triangulo* superior = new Triangulo(PV2D(-100.0,480.0),PV2D(1100.0,480.0),PV2D(500.0,550.0),pelota.getRadio(),true);
	Triangulo* inferior = new Triangulo(PV2D(1100.0,10.0),PV2D(-100.0,10.0),PV2D(500.0,-50.0),pelota.getRadio(),true);
	Triangulo* izquierda = new Triangulo(PV2D(10.0,-100.0),PV2D(10.0,600.0),PV2D(-50.0,250.0),pelota.getRadio(),true);
	Triangulo* derecha = new Triangulo(PV2D(980.0,600.0),PV2D(980.0,-100.0),PV2D(1050.0,250.0),pelota.getRadio(),true);

	listTriangulos.ponDr(superior);
	listTriangulos.ponDr(inferior);
	listTriangulos.ponDr(derecha);
	listTriangulos.ponDr(izquierda);

}

void Controlador::añadirObstaculos(){
	
	Triangulo* t1 = new Triangulo(PV2D(centro.x-50,centro.y),PV2D(centro.x+50,centro.y),PV2D(centro.x,centro.y+100),pelota.getRadio(),true);
	listTriangulos.ponDr(t1);

	Triangulo* t2 = new Triangulo(PV2D(50.0,400.0),PV2D(50.0,200),PV2D(200.0,200.0),pelota.getRadio(),true);
	listTriangulos.ponDr(t2);

	Triangulo* t3 = new Triangulo(PV2D(800.0,250.0),PV2D(650.0,250.0),PV2D(700.0,50.0),pelota.getRadio(),true);
	listTriangulos.ponDr(t3);

	Circulo*  c1= new Circulo(50.0,PV2D(400.0,400.0),pelota.getRadio(),true);
	listTriangulos.ponDr(c1);

	Circulo*  c2 = new Circulo(100.0,PV2D(250.0,100.0),pelota.getRadio(),true);
	listTriangulos.ponDr(c2);

	Circulo*  c3 = new Circulo(75.0,PV2D(800.0,350.0),pelota.getRadio(),true);
	listTriangulos.ponDr(c3);
}

void Controlador::finalizar(){
	Lista<Obstaculo*> :: Iterador it = listTriangulos.principio();
	while(it != listTriangulos.final()){
		it.elem()->finalizar();
		delete it.elem();
		it.avanza();
	}
}