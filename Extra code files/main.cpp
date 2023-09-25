#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (255.0, 0.0, 0.0);
    glPointSize(4.0);
    glBegin(GL_POLYGON);
    glVertex2i(15, 15);
    glVertex2i(620, 15);
    glVertex2i(620, 15);
    glVertex2i(620, 500);
    glVertex2i(560, 500);
    glVertex2i(80, 4000);
    glVertex2i(15, 320);
    glVertex2i(15, 180);
    glEnd();

    glColor3f (255.0, 255.0, 0.0);
    glPointSize(4.0);
    glBegin(GL_POLYGON);
    glVertex2i(270, 380);
    glVertex2i(270, 100);
    glVertex2i(370, 100);
    glVertex2i(370, 380);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(270, 100);
    glVertex2i(270, 80);
    glVertex2i(290, 80);
    glVertex2i(290, 60);
    glVertex2i(360, 60);
    glVertex2i(360, 80);
    glVertex2i(370, 80);
    glVertex2i(370, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(370, 140);
    glVertex2i(460, 140);
    glVertex2i(460, 320);
    glVertex2i(400, 320);
    glVertex2i(400, 340);
    glVertex2i(370, 340);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(460, 120);
    glVertex2i(549, 120);
    glVertex2i(600, 180);
    glVertex2i(600, 300);
    glVertex2i(585, 320);
    glVertex2i(460, 320);
    glEnd();

   glBegin(GL_POLYGON);
    glVertex2i(270, 140);
    glVertex2i(270, 320);
    glVertex2i(55, 320);
    glVertex2i(40, 300);
    glVertex2i(40, 180);
    glVertex2i(65, 140);
    //glVertex2i(500, 60);
    glEnd();


    glFlush ();
    }
    void myInit (void)
    {
        glClearColor(1.0, 0.0, 0.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    }
    int main(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize (640, 480);
        glutInitWindowPosition (100, 150);
        glutCreateWindow ("my first attempt");
        glutDisplayFunc(myDisplay);
        myInit ();
        glutMainLoop();
    }
