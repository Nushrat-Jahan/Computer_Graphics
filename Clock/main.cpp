//Nushrat Jahan
//18-36586-1

#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float x,y,i;
GLfloat hour=0.0,minuite=0.0,second=0.0;

void outersurface()
{
    glBegin(GL_TRIANGLE_FAN);
		glColor3ub(224,224,224);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.6*sin(i);
			y=0.6*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(102,178,255);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.5*sin(i);
			y=0.5*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
}

void clockhand()
{
    glRotatef(hour,0.0,0.0,-1.0);
	glColor3ub(224,224,224);
	glRectf(-.025,0,.025,.4);
	glRotatef(minuite,0.0,0.0,-1.0);
	glColor3ub(255,255,255);
	glRectf(-.025,0,.025,.6);
	glRotatef(second,0.0,0.0,-1.0);
	glColor3ub(0,0,0);
	glRectf(-.015,0,0.015,0.6);
	second+=0.1;
	minuite+=0.01;
	hour+=0.001;
}

void smallcircle()
{
    glBegin(GL_TRIANGLE_FAN);
		glColor3ub(255,255,255);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.06*sin(i);
			y=0.07*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
}

void Display()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
	outersurface();
    glPopMatrix();

	glPushMatrix();
	clockhand();
	glPopMatrix();

	glPushMatrix();
	smallcircle();
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutCreateWindow("Clock");
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMainLoop();
	return 0;
}
