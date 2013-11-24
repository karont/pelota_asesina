/**ALVARO QUESADA PIMENTEL**/
#include "PV2D.h"
#include <cmath>
bool PV2D::esCero(){

	if(x == 0.0 && y == 0.0) return true;
	return false;
}

PV2D PV2D::operator+(const PV2D &p){
		
	return PV2D(x+p.x,y+p.y);
}
PV2D PV2D::operator-(const PV2D &p){
		
	return PV2D(x-p.x,y-p.y);
}
double PV2D::operator*(const PV2D &p){
		
	return (x*p.x)+(y*p.y);
}
PV2D PV2D::operator/(const int &a){
		
	return PV2D(x/a,y/a);
}
PV2D PV2D::operator*(const GLdouble &a){
		
	return PV2D(x*a,y*a);
}
PV2D PV2D::normalIz(){

	return PV2D(-y,x);
}

PV2D PV2D::normalDr(){

	return PV2D(y,-x);
}

PV2D PV2D::normalizar(){
	
	return PV2D((1/(sqrt(pow(x,2)+pow(y,2))))*x,(1/(sqrt(pow(x,2)+pow(y,2))))*y);
}