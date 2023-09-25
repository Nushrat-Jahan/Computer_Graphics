#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.14159265358979323846

GLfloat hour, minute, second;

void Idle()
{
    glutPostRedisplay();
}

void drawCircle (GLfloat x, GLfloat y, GLfloat rad, GLfloat a, GLfloat b, GLfloat c) {
	int triangleAmount = 100;
	GLfloat twicePi = 2.0f * pi;
	glBegin(GL_TRIANGLE_FAN);
    glColor3f(a, b, c);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount; i++) {
       glVertex2f( x + (rad * cos(i *  twicePi / triangleAmount)),
       y + (rad * sin(i * twicePi / triangleAmount)));
    }
	glEnd();
}

void drawTrianle (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat a, GLfloat b, GLfloat c) {
    glBegin(GL_TRIANGLES);
    glColor3f(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawLine (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat a, GLfloat b, GLfloat c , int w) {
    glLineWidth(w);
    glBegin(GL_LINES);
    glColor3f(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawQuad (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, GLfloat a, GLfloat b, GLfloat c) {
    glBegin(GL_QUADS);
    glColor3f(a, b, c);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void drawTree (GLfloat x1, GLfloat y1) {
    drawQuad(x1, y1, x1 + 0.1, y1, x1 + 0.1, y1 + 0.8, x1, y1 + 0.8, 0.7, 0.4, 0);
    drawTrianle(x1 - 0.3, y1 + 0.8, x1 + 0.4, y1 + 0.8, x1 + 0.05, y1 + 1.2, 0.6, 0.8, 0.0);
}

void display() {

	glClearColor(1.0f, 0.7f, 0.2f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	drawCircle (0.0, 0.0, 0.8, 1, 1, 0.4);
    drawCircle (0.0, 0.0, 0.04, 0, 0, 0);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(hour, 0, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.055f, 0.4f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(-0.055f, 0.4f);
    glEnd();
    glPopMatrix();
	glLoadIdentity();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(minute, 0, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.04f, 0.5f);
    glVertex2f(0.0f, 0.7f);
    glVertex2f(-0.04f, 0.5f);
    glEnd();
    glPopMatrix();
	glLoadIdentity();

	glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(second, 0, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.02f, 0.6f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(-0.02f, 0.6f);
    glEnd();
    glPopMatrix();
	glLoadIdentity();

    hour += -0.00001f;
    minute += -0.0001f;
    second += -0.001f;
	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Setup");
	glutInitWindowSize(320, 320);
	glutDisplayFunc(display);
	glutIdleFunc(Idle);
	glutMainLoop();

	return 0;
}
