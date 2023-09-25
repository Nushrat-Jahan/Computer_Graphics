#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 0.0, 1.0);
glPointSize(15.0);

//Polygon
glBegin(GL_TRIANGLES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(320, 450);
glVertex2i(140,40);
glColor3f (1.0, 0.0, 1.0);
glVertex2i(320,140);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(320, 450);
glVertex2i(500,40);
glColor3f (1.0, 0.0, 1.0);
glVertex2i(320,140);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(140, 40);
glColor3f (1.0, 0.0, 1.0);
glVertex2i(610,285);
glVertex2i(385,300);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(500,40);
glColor3f (1.0, 0.0, 1.0);
glVertex2i(30, 285);
glVertex2i(255,300);
glEnd();
glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (300, 200);
glutCreateWindow ("This is the title");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
