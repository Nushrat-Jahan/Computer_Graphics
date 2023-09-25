#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
glPointSize(15.0);

//Border Line
glBegin(GL_LINES);
glVertex2i(10, 240);
glVertex2i(630, 240);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(320, 470);
glVertex2i(320, 10);
glEnd();

//Quads
glBegin(GL_QUADS);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(380, 210);
glColor3f (0.0, 0.0, 1.0);
glVertex2i(520,210);
glColor3f (0.0, 1.0, 0.0);
glVertex2i(520,100);
glColor3f (15.0, 0.0, 5.0);
glVertex2i(380,100);
glEnd();

glBegin(GL_QUADS);
glColor3f (1.0, .71, .75);
glVertex2i(430,170);
glColor3f (1.0, 0.0, 0.0);
glVertex2i(580,170);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(580,50);
glColor3f (15.0, 0.0, 5.0);
glVertex2i(430,50);
glEnd();

//Double triangle
glBegin(GL_TRIANGLES);
glColor3f (1.0, 0.0, 0.0);
glVertex2i(60, 270);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(260, 270);
glColor3f (15.0, 0.0, 5.0);
glVertex2i(160, 350);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(60, 350);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(260, 350);
glColor3f (15.0, 0.0, 5.0);
glVertex2i(160, 430);
glEnd();

//Cross lines
glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(80, 210);
glVertex2i(240, 50);
glVertex2i(240, 210);
glVertex2i(80, 50);

//crossline border
glVertex2i(80, 210);
glVertex2i(80, 50);
glVertex2i(240, 50);
glVertex2i(240, 210);
glVertex2i(80, 50);
glVertex2i(240, 50);
glVertex2i(80, 210);
glVertex2i(240, 210);
glEnd();

//vertical hour glass
glBegin(GL_TRIANGLES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(380, 270);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(380, 430);
glColor3f (15.0, 0.0, 5.0);
glVertex2i(480, 350);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(580, 270);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(580, 430);
glColor3f (15.0, 0.0, 5.0);
glVertex2i(480, 350);
glEnd();

//Border drawing
glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(10, 10);
glVertex2i(630, 10);
glVertex2i(10, 10);
glVertex2i(10, 470);
glVertex2i(630, 10);
glVertex2i(630, 470);
glVertex2i(10, 470);
glVertex2i(630, 470);
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
