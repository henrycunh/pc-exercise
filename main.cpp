#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include "shapes.cpp"

#define WINDOW_TITLE "Exercise"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using std::cout;
using std::endl;

void render(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);	
	glOrtho(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0, 0.0, 1.0);

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);


	glutMainLoop();
}

int x = 150 , y = 150, vx = 1, vy = 1;

void render(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Polygon polygon(x, y, 5);
	polygon.draw(100);
	glutSwapBuffers();

}

void keyboard(unsigned char c, int x, int y){
	if(c == 27) exit(0);
}

void mouse(int button, int state, int x, int y){
	if( button == GLUT_RIGHT_BUTTON ) exit(0);
}

