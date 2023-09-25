#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
using namespace std;
float stx,edx,sty,edy,m;

void ploting(int x, int y)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3ub (128, 128, 128);
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glColor3ub(0,0,255);
  glVertex2i(x,y);
}

void Display(void)
{
m=(edy-sty)/(edx-stx);
float p = max(edy,edx)-min(edx,edy);
for(int i=1; i<p; i++)
{
    if (m>=1)
    {
        stx+=m;
        sty+=1;
        ploting(round(stx),sty);
    }
    else
    {
       stx+=1;
       sty+=m;
       ploting(stx, round(sty));
    }
}
glEnd();
glFlush();
}

void myInit (void)
{
   glClearColor(255,255,255,255);
   glPointSize(4.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


int main(int argc, char** argv)
{
    cout << "Enter 1st coordinates:";
    cin >> stx >> sty;
    cout << "Enter 2nd coordinate:";
    cin >> edx >> edy;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("My DDL implementation");
    glutDisplayFunc(Display);
    myInit ();
    glutMainLoop();
}
