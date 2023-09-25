#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position = 0.0f;
GLfloat speed = 0.1f;
GLfloat positionroket=0.0f;
GLfloat speedroket = 0.1f;
GLfloat positionbullet=0.0f;
GLfloat speedbullet = 0.2f;


void update(int value) {

    if(position < -1.90)
        position = 0.0f;

    position -= speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}

void updatebullet(int value) {
    if(positionbullet > 1.0)
        positionbullet = 1.2f;
    positionbullet += speedbullet;
	glutPostRedisplay();

	glutTimerFunc(100, updatebullet, 0);
}

void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
		    updatebullet(positionbullet);
		}
		if (state == GLUT_UP)
		{
		    positionbullet=0.0f;
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'l':
        if(positionroket < -.70)
            {
               positionroket = positionroket;
	           glutPostRedisplay();
            }
    else  positionroket-=0.05;
    break;

case 'r':

       if(positionroket > .90)
        {
          positionroket = positionroket;
	      glutPostRedisplay();
        }
    else positionroket+=0.05;
    break;

    glutPostRedisplay();
	}
}

void enemy()
{
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.2f, 0.65f);
      glVertex2f( -.1f,  0.8f);
      glVertex2f( 0.0f, 0.65f);
      glEnd();
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(-0.9f, 0.55f);
      glVertex2f( -.8f,  0.7f);
      glVertex2f( -.7f, 0.55f);
      glEnd();
      glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f(0.9f, 0.65f);
      glVertex2f( .8f,  0.8f);
      glVertex2f( .7f, 0.65f);
      glEnd();

}
void Plane()
{
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.2f, -.3f);
      glVertex2f( -.1f,  0.0f);
      glVertex2f( 0.0f, -0.3f);
      glEnd();
      glBegin(GL_QUADS);
      glColor3f(1.0f, 0.7f, 0.4f);
      glVertex2f(-0.2f, -.3f);
      glVertex2f( 0.0f,  -.3f);
      glVertex2f( 0.0f, -.7f);
      glVertex2f( -.2f, -.7f);
      glEnd();
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-.2f, -.3f);
      glVertex2f( -.3f,  -.4f);
      glVertex2f( -.2f, -.4f);
      glEnd();
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.0f, -.3f);
      glVertex2f( .1f,  -.4f);
      glVertex2f( 0.0f, -.4f);
      glEnd();
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-.2f, -.5f);
      glVertex2f( -.3f,  -.7f);
      glVertex2f( -.2f, -.7f);
      glEnd();
      glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.0f, -.5f);
      glVertex2f(0.1f,  -.7f);
      glVertex2f( 0.0f, -.7f);
      glEnd();
      glBegin(GL_POLYGON);
      glColor3f(1.0f, 0.0f, 0.02f);
      glVertex2f(-.2f, -.7f);
      glVertex2f(-.3f, -.8f);
      glVertex2f(-.1f,  -.95f);
      glVertex2f( .1f, -.8f);
      glVertex2f( 0.0f, -.7f);
      glEnd();
}

void Bullet()
{
      glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2f(-.14f, 0.0f);
      glVertex2f(-.14f, 0.08f);
      glVertex2f(-.05f,  0.08f);
      glVertex2f( -.05f, 0.0f);
      glEnd();
}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

glPushMatrix();
glTranslatef( 0.0f,position, 0.0f);
    enemy();
glPopMatrix();
glTranslatef(positionroket,0.0f, 0.0f);
glPushMatrix();
glPushMatrix();
    Plane();
glPopMatrix();
glPushMatrix();
glTranslatef(0.0f,positionbullet,0.0f);
    Bullet();
glPopMatrix();
glPopMatrix();
   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
