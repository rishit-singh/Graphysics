#include <iostream>
#include <GL/glut.h>
#include "../../algorithms.h"
#include "../../cartesianobj.h"
#include "../../cartesian.h"

void Render();
void ConfigureWindow(char*, Coordinate*, Coordinate*);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	ConfigureWindow("Test", new Coordinate(1920, 1080), new Coordinate(100, 100));
	glutDisplayFunc(Render);
	
	glutMainLoop();
	
	return 0;
}

void ConfigureWindow(char* title, Coordinate* c, Coordinate* c1)
{
	glutInitWindowSize(c->X, c->Y);
	glutInitWindowPosition(c1->X, c1->Y);
	glutCreateWindow(title);
}

void Render()
{
	float vertex = 0.3;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);

	glVertex2d(-vertex, -vertex);
	glVertex2d(-vertex, 0);
	glVertex2d(0, 0);	
	glVertex2d(0, -vertex); 

	glEnd();
	glFlush();
}