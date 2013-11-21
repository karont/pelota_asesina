/**ALVARO QUESADA PIMENTEL**/
#include "Escena.h"
#include <cmath>
#include <iostream>
extern GLdouble WIDTH, HEIGHT;

GLdouble Escena::getxRight()const{
	return xRight;
}
void Escena::setxRight(const GLdouble &x){
	xRight = x;
}

GLdouble Escena::getxLeft()const{
	return xLeft;
}
void Escena::setxLeft(const GLdouble &x){
	xLeft = x;
}

GLdouble Escena::getyTop()const{
	return yTop;
}
void Escena::setyBot(const GLdouble &y){
	yBot = y;
}

GLdouble Escena::getyBot()const{
	return yBot;
}
void Escena::setyTop(const GLdouble &y){
	yTop = y;
}

PV2D Escena::getCentro() const{

	 PV2D center = PV2D((xRight+xLeft)/2.0, (yTop+yBot)/2.0);
	return center;
}

void Escena::redimensionar(const GLdouble &RatioViewPort) {
		
	//Resize Scene Visible Area 
  //Se actualiza el área visible de la escena
  //para que su ratio coincida con ratioViewPort
  GLdouble SVAWidth = xRight-xLeft;
  GLdouble SVAHeight = yTop-yBot;
  GLdouble SVARatio = SVAWidth/SVAHeight;
  if (SVARatio >= RatioViewPort) {
	 // Increase SVAHeight
     GLdouble newHeight= SVAWidth/RatioViewPort;
	 GLdouble yMiddle= ( yBot+yTop )/2.0;
     yTop = yMiddle + newHeight/2.0;
     yBot = yMiddle - newHeight/2.0;
     }
  else {
     //Increase SVAWidth
     GLdouble newWidth= SVAHeight*RatioViewPort;
     GLdouble xMiddle= ( xLeft+xRight )/2.0;
	 xRight= xMiddle + newWidth/2.0;
     xLeft=  xMiddle - newWidth/2.0;
  }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft,xRight,yBot, yTop);
  glutPostRedisplay();
}

void Escena::mover (const int &dir,const GLdouble &increX,const GLdouble &increY){
	switch (dir)
	{
	//izquierda
	case 1:
		xLeft += increX;
		xRight += increX;
		break;
	//derecha
	case 2:
		xLeft -= increX;
		xRight -= increX;
		break;
	//Arriba
	case 3:
		yBot += increY;
		yTop += increY;
		break;
	//Abajo
	case 4:
		yBot -= increY;
		yTop -= increY;
		break;
	default:
		break;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xLeft,xRight,yBot, yTop);
	glutPostRedisplay();
}

void Escena::zoom(const GLdouble &f){
	GLdouble ancho = (xRight-xLeft)/f;
	GLdouble alto = (yTop-yBot)/f;

	PV2D centro = getCentro();
	xRight = centro.x+(ancho/2.0);
	xLeft = centro.x-(ancho/2.0);
	yTop = centro.y+(alto/2.0);
	yBot = centro.y-(alto/2.0);


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft,xRight,yBot, yTop);
  glutPostRedisplay();
}

void Escena::draw(void){

	controlador.draw();
}

void Escena::step(){
	controlador.step();
	glutPostRedisplay();
}

PV2D Escena::transformarPuntoAVE(int x, int y){
		
		GLdouble new_ancho = WIDTH/(xRight-xLeft);
		GLdouble new_alto = HEIGHT/(yTop-yBot);

		return PV2D((x/new_ancho)+xLeft,yTop-(y/new_alto));


}

void Escena::finalizar(void){
	controlador.finalizar();
}

void Escena::zoomProgresivo(const GLdouble &fIncr,const int &i){

	GLdouble faux = 1 + fIncr*i;
	GLdouble ancho = (xRight-xLeft)/faux;
	GLdouble alto = (yTop-yBot)/faux;

	PV2D centro = getCentro();
	xRight = centro.x+(ancho/2.0);
	xLeft = centro.x-(ancho/2.0);
	yTop = centro.y+(alto/2.0);
	yBot = centro.y-(alto/2.0);


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft,xRight,yBot, yTop);


}
void Escena::embaldosar (int nCol){

	GLdouble SVAratio = (xRight-xLeft) / (yTop-yBot);
	GLdouble w = (GLdouble)WIDTH/(GLdouble) nCol;

	GLdouble h = w/SVAratio;
	for(GLint c = 0; c<nCol;c++){
		GLdouble currentH = 0;
		while((currentH) < HEIGHT){
			glViewport((GLint)(c*w),(GLint)currentH, (GLint)w, (GLint)h);
			draw();
			currentH +=h;

		}

	}

}
