/**ALVARO QUESADA PIMENTEL**/
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Escena.h"
#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
#include <thread>
using namespace std;

bool autom = false;
bool rebotecentro = false;
bool dborde = false;
bool relleno = false;
// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

int const timer = 20;
// Viewport size
GLdouble WIDTH= 1000.0, HEIGHT= 500.0;

// Scene visible area size
GLdouble xLeft= 0.0, xRight= 1000.0, yBot= 0.0, yTop= 500.0;
//Escena
Escena  miescena = Escena(xRight,xLeft,yBot,yTop);

//Incremento de la escena
GLdouble increX = 10.0, increY = 10.0;
// Scene variables


void intitGL(){

	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0); 

	glPointSize(4.0);
	glLineWidth(2.0);

	// Viewport
    glViewport(0, 0, (GLint)WIDTH, (GLint)HEIGHT);
	//cout<<miescena.centro().x<<endl;
	//cout<<miescena.centro().y<<endl;
	// Model transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Scene Visible Area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(miescena.getxLeft(), miescena.getxRight(), miescena.getyBot(), miescena.getyTop()); 

 }


void display(void){

	glClear( GL_COLOR_BUFFER_BIT );
  // Scene rendering
  
	//glbegin(gl_points);
	// glvertex2d(miescena.getcentro().x,miescena.getcentro().y);
	//glend();
 
  //glRectd(250.0-50.0,125-50.0,250.0+50,125.0+50.0);
	 miescena.draw();

 	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight){
  //Resize Viewport
  WIDTH= newWidth;
  HEIGHT= newHeight;
  GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
  glViewport ( 0, 0, WIDTH, HEIGHT ) ;

	//redimensiona
  miescena.redimensionar(RatioViewPort);
 
}

void zoomProgresivo(GLdouble factor, int nIter){
	 
	GLdouble fIncr = (factor - 1)/(GLdouble) nIter;
	for (int i=0;i<=nIter;i++){
		miescena.zoomProgresivo(fIncr,i);
		display();

		std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );
	}

}
void stepauto(int a){
	miescena.step();
	if (autom)glutTimerFunc(timer,stepauto,0);
}
void key(unsigned char key, int x, int y){
 

  switch (key) {
  case 27:  /* Escape key */
    //continue_in_main_loop = false; // (**)
	glutLeaveMainLoop (); //Freeglut's sentence for stopping glut's main loop (*)
    break;
  case 'h':
		cout<< "Pulsa 'a' para avanzar la pelota paso a paso"<<endl;
		cout<< "Pulsa 's' para activar/desactivar el movimiento automatico"<<endl;
		cout<< "Pulsa 'd' para activar/desactivar el rebote con el centro"<<endl;
		cout<< "Pulsa 'f' para activar/desactivar el relleno de los poligonos"<<endl;
		cout<< "Pulsa 'g' para activar/desactivar el dibujo del contorno de los obstaculos"<<endl;
		cout<< "Pulsa '+' para aumentar el zoom"<<endl;
		cout<< "Pulsa '-' para desaumentar el zoom"<<endl;
		cout<< "Pulsa 'q' para aumentar el zoom progresivamente "<<endl;
		cout<< "Pulsa 'w' para desaumentar el zoom progresivamente "<<endl;
		//cout<< "Pulsa 'e' para embaldosar la escena"<<endl;
		//cout<< "Pulsa 'r' para desembaldosar la escena"<<endl;

	 break;
	 case 's':
		autom = !autom;
		if (autom)glutTimerFunc(timer,stepauto,0);
	break;
	case 'a':
		miescena.step();
	break;
	case 'd':
		rebotecentro = !rebotecentro;
	break;

	case 'f':
		relleno = !relleno;
	break;
	case 'g':
		dborde = !dborde;
	break;
	 
	case 'q':
		zoomProgresivo(1.1, 10);
	break;
	case 'w':
		zoomProgresivo(0.9, 10);
	break;

  case '+' :
		miescena.zoom(1.1);
    break ;

  case '-' :
		miescena.zoom(0.9);
    break ;
  }//switch

}

void spKey( int key, int x, int y){
 

  switch (key) {

  case GLUT_KEY_LEFT:
	  miescena.mover(1,increX,increY);
    break ;

  case GLUT_KEY_RIGHT :
	  miescena.mover(2,increX,increY);
    break ;
  
  case GLUT_KEY_DOWN :
	  miescena.mover(3,increX,increY);
    break ;
  case GLUT_KEY_UP:
	  miescena.mover(4,increX,increY);
    break ;
  }//switch

}
void mousekey(int button, int state, int x, int y)
{

	
	
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_UP)
		{
			//miescena.selecionarCuadrado(miescena.transformarPuntoAVE(x,y));
		
		}

		break;
	}
	

}



int main(int argc, char *argv[]){
  cout<< "Starting console..." << endl;

  int my_window; //my window's identifier


  cout<<"Pulsa 'h' para ver la ayuda"<<endl;
  /*while(ANGULO<=0 || ANGULO>60){
	   cout<<"Vuelva a introducir un angulo mayor que 0 y menor o igual que 60"<<endl;
	   cin>>ANGULO;
  }*/
  //Initialization
  glutInitWindowSize((GLint)WIDTH, (GLint)HEIGHT);
  glutInitWindowPosition (140, 140);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
  glutInit(&argc, argv);

  //Window construction
  my_window = glutCreateWindow( "Freeglut 2D-project" );
    
  //Callback registration
  glutReshapeFunc(resize);
  glutKeyboardFunc(key);
  glutSpecialFunc(spKey);
  glutMouseFunc(mousekey);
  glutDisplayFunc(display);



  //OpenGL basic setting
  intitGL();


  // Freeglut's main loop can be stopped executing (**)
  //while ( continue_in_main_loop )
  //  glutMainLoopEvent();

  // Classic glut's main loop can be stopped after X-closing the window,
  // using the following freeglut's setting (*)
  glutSetOption ( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ) ;
    

  // Classic glut's main loop can be stopped in freeglut using (*)
  glutMainLoop(); 
  
  miescena.finalizar();
  // We would never reach this point using classic glut
  system("PAUSE"); 
   
  return 0;
}
