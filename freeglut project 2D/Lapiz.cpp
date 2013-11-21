/**ALVARO QUESADA PIMENTEL**/
#include "Lapiz.h"
#include <math.h>
#define M_PI (3.1415926535897932384626433832795)

Lapiz::Lapiz(void)
{
	pos.x=0.0;
	pos.y=0.0;
	dir = 0;
}


void Lapiz::turn(const GLdouble &a)	{

	dir+=a;
}

void Lapiz::forward(const GLdouble &dist,const bool &draw){
	PV2D new_pos;
	new_pos.x += pos.x+dist*cos(M_PI*dir/180);
	new_pos.y += pos.y+dist*sin(M_PI*dir/180);

	if(draw)
		{
		glClear( GL_COLOR_BUFFER_BIT );
			 glBegin(GL_LINES);
				glVertex2d(pos.x, pos.y);
				glVertex2d(new_pos.x, new_pos.y);
         glEnd();
		 glFlush();
		glutSwapBuffers();
		}
	pos = new_pos;
	
}

void Lapiz::moveTo(const PV2D &p,const bool &draw){
	pos.x = p.x;
	pos.y = p.y;
}

void Lapiz::turnTo(const GLdouble &a){

	dir = a;
}  

PV2D Lapiz::getpos(void) const{
	return pos;
}

GLdouble Lapiz::getdir(void) const{
	return dir;
}