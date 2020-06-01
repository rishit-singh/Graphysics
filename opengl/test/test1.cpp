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
	glutInitDisplayMode(GLUT_SINGLE);

	ConfigureWindow("Test", new Coordinate(1000, 800), new Coordinate(100, 100));
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
	float vertex = 0.5;
	
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);

	for (float x = 0; x < 0.6; x += 0.1)
	{
		glVertex3f(vertex + x, 0, 0);
		glVertex3f(0, vertex + x, 0);
	}

	glEnd();

	glFlush();
}
