#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position = 0.0f;
GLfloat speed = 0.1f;

void update(int value) {

    if(position > 1.0)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'a':
    speed = 0.0f;
    break;
case 'w':
    speed += 0.1f;
    break;


glutPostRedisplay();


	}
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();



glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.2f, -0.2f);
      glVertex2f( 0.2f, -0.2f);
      glVertex2f( 0.2f,  0.2f);
      glVertex2f(-0.2f,  0.2f);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(0.2f,-0.2f);
   glVertex2f(0.5f, 0.0f);
   glVertex2f(0.2f, 0.2f);
   glEnd();


glPopMatrix();

//Buildings structure
//232,192,131
//195,74,14
//255,206,168
//130,154,175
//149,153,156


//Windows
glColor3f (0.71, 0.91, 0.96);
glRectf(-.98,-1,-.95,-.9);
for(int i=10; i<55; i+=18) glRecti(i+58,0,i+72,30);
for(int i=65; i<110; i+=30)
{
   glRectf(i,95,i+25,105);
   glRectf(i,80,i+25,90);
   glRectf(i,55,i+25,65);
   glRectf(i,40,i+25,50);
}
for(int i=130; i<190; i+=14)
{
   glRectf(i,65,i+10,75);
   glRectf(i,50,i+10,60);
   glRectf(i,35,i+10,45);
   glRectf(i,20,i+10,30);
   glRectf(i,5,i+10,15);
}

for(int i=212; i<280; i+=14)
{
   glRectf(i,95,i+10,115);
   glRectf(i,70,i+10,90);
   glRectf(i,35,i+10,60);
   glRectf(i,5,i+10,30);
}

for(int i=300; i<340; i+=14)
{
   glRectf(i,75,i+10,100);
   glRectf(i,40,i+10,65);
   glRectf(i,5,i+10,30);
}
for(int i=360; i<400; i+=14)
{
   glRectf(i,25,i+10,30);
   glRectf(i,15,i+10,20);
   glRectf(i,5,i+10,10);
}
glRecti(405,0,415,20);
for(int i=360; i<415; i+=14)
{
   glRectf(i,55,i+10,60);
   glRectf(i,45,i+10,50);
   glRectf(i,35,i+10,40);
}

for(int i=431; i<460; i+=14)
{
   glRectf(i,35,i+10,45);
   glRectf(i,20,i+10,30);
   glRectf(i,5,i+10,15);
}

for(int i=490; i<540; i+=8)
{
   glRectf(i,95,i+5,105);
   glRectf(i,80,i+5,90);
   glRectf(i,65,i+5,75);
   glRectf(i,50,i+5,60);
   glRectf(i,35,i+5,45);
   glRectf(i,20,i+5,30);
   glRectf(i,5,i+5,15);
}

for(int i=560; i<630; i+=14)
{
   glRectf(i,65,i+10,75);
   glRectf(i,50,i+10,60);
   glRectf(i,35,i+10,45);
   glRectf(i,20,i+10,30);
   glRectf(i,5,i+10,15);
}

for(int i=565; i < 620; i+=12)
{
    glRectf(i,80, i+10,95);
}
for(int i=570; i < 610; i+=12)
{
    glRectf(i,100, i+10,115);
}

   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(640, 420);
   glutInitWindowPosition(400, 150);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
