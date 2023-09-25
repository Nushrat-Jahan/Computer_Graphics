//Nushrat Jahan
//ID 18-36586-1
// Home Lab task

#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
glPointSize(15.0);

//baseline
glBegin(GL_POLYGON);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(35, 50);
glVertex2i(610, 50);
glVertex2i(610, 55);
glVertex2i(35, 55);
glEnd();

//starting of house
glBegin(GL_POLYGON);
glColor3f (0.66, 0.66, 0.66);
glVertex2i(65, 55);
glVertex2i(580, 55);
glVertex2i(580, 255);
glVertex2i(65, 255);
glEnd();

//Label of house
glBegin(GL_POLYGON);
glColor3f (0.25, 0.2, 0.20);
glVertex2i(45, 255);
glVertex2i(600, 255);
glVertex2i(600, 262);
glVertex2i(45, 262);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(35, 262);
glVertex2i(610, 262);
glVertex2i(610, 270);
glVertex2i(35, 270);
glEnd();

glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(45, 256);
glVertex2i(600, 256);
glVertex2i(45, 255);
glVertex2i(600, 255);
glVertex2i(600, 261);
glVertex2i(45, 261);
glEnd();

glBegin(GL_LINES);
glVertex2i(35, 262);
glVertex2i(610, 262);
glVertex2i(610, 268);
glVertex2i(35, 268);
glVertex2i(610, 267);
glVertex2i(35, 267);
glEnd();

//Right Pipes
glBegin(GL_POLYGON);
glColor3f (0.3, 0.3, 0.3);
glVertex2i(58, 248);
glVertex2i(65, 248);
glVertex2i(65, 70);
glVertex2i(58, 70);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(35, 262);
glVertex2i(45, 262);
glVertex2i(45, 255);
glVertex2i(35, 255);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(35, 255);
glVertex2i(65, 238);
glVertex2i(65, 250);
glVertex2i(45, 257);
glEnd();

//Little piece of pipe
glBegin(GL_POLYGON);
glVertex2i(50, 55);
glVertex2i(65, 70);
glVertex2i(65, 75);
glVertex2i(50, 70);
glEnd();

//box in right side
glBegin(GL_POLYGON);
glVertex2i(45, 55);
glVertex2i(65, 55);
glVertex2i(65, 62);
glVertex2i(45, 62);
glEnd();

//Left Pipes
glBegin(GL_POLYGON);
glVertex2i(580, 250);
glVertex2i(588, 250);
glVertex2i(588, 70);
glVertex2i(580, 70);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(610, 262);
glVertex2i(600, 262);
glVertex2i(600, 255);
glVertex2i(610, 255);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(610, 255);
glVertex2i(580, 240);
glVertex2i(580, 250);
glVertex2i(600, 257);
glEnd();

//Little piece of pipe
glBegin(GL_POLYGON);
glVertex2i(595, 62);
glVertex2i(580, 68);
glVertex2i(580, 75);
glVertex2i(595, 70);
glEnd();

//Shade
glBegin(GL_TRIANGLES);
glColor3f (0.85, 0.85, 0.85);
glVertex2i(45, 270);
glVertex2i(600, 270);
glVertex2i(320, 450);
glEnd();


glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
for(int i=45,j=270; i<=320; i+=5, j+=3)
{
   glVertex2i(i, 270);
   glVertex2i(i, j);
}
glVertex2i(350, 270);
glVertex2i(182, 360);
glEnd();

//Secondary head shed
glBegin(GL_TRIANGLES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(72, 290);
glVertex2i(310, 290);
glVertex2i(182, 360);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f (0.6, 0.6, 0.6);
glVertex2i(90, 290);
glVertex2i(290, 290);
glVertex2i(182, 340);
glEnd();

glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
for(int i=1,j=290; j<360; i+=20, j+=10)
{
   glVertex2i(72+i, j);
   glVertex2i(310-i, j);
}
glEnd();


glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
for(int i=600,j=270; i>=320; i-=5, j+=3)
{
   glVertex2i(i, 270);
   glVertex2i(i, j);
}
glEnd();

//Head shed
glBegin(GL_POLYGON);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(320, 450);
glVertex2i(182, 360);
glVertex2i(203,360);
glVertex2i(320,430);
glVertex2i(440,360);
glVertex2i(460, 360);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f (0.6, 0.6, 0.6);
glVertex2i(216, 370);
glVertex2i(425, 370);
glVertex2i(320, 430);
glEnd();

glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
for(int i=1,j=370; j<430; i+=15, j+=10)
{
   glVertex2i(205+i, j);
   glVertex2i(440-i, j);
}
glEnd();

//Partition house
glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(300, 255);
glVertex2i(300, 55);
glEnd();

//Left
glBegin(GL_POLYGON);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(320, 60);
glVertex2i(550, 60);
glVertex2i(550, 225);
glVertex2i(320, 225);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.8, 0.8, 0.8);
glVertex2i(322, 62);
glVertex2i(548, 62);
glVertex2i(548, 223);
glVertex2i(322, 223);
glEnd();

glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
for(int i=62; i<=223; i+=23)
{
  glVertex2i(320, i);
  glVertex2i(550, i);
}
glEnd();


//Right door
glBegin(GL_POLYGON);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(285, 60);
glVertex2i(285, 240);
glVertex2i(220, 240);
glVertex2i(220, 60);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.66, 0.66, 0.66);
glVertex2i(283, 62);
glVertex2i(283, 238);
glVertex2i(222, 238);
glVertex2i(222, 62);
glEnd();

//Door
glBegin(GL_POLYGON);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(285, 80);
glVertex2i(285, 220);
glVertex2i(225, 220);
glVertex2i(225, 80);
glEnd();

glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(285, 60);
glVertex2i(300, 60);
glVertex2i(222, 60);
glVertex2i(222, 50);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.25, 0.2, 0.2);
glVertex2i(281, 84);
glVertex2i(281, 216);
glVertex2i(229, 216);
glVertex2i(229, 84);
glEnd();


//Bits in door
glBegin(GL_QUADS);
glColor3f (0.8, 0.8, 0.8);
for(int i=103; i<=193; i+=30)
{
glVertex2i(237, i);
glVertex2i(275, i);
glVertex2i(275, i+7);
glVertex2i(237, i+7);
}
glEnd();

//Handle
glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(232, 145);
glVertex2i(232, 160);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(100, 100);
glVertex2i(190, 100);
glVertex2i(190, 225);
glVertex2i(100, 225);
glEnd();

//Window
glBegin(GL_POLYGON);
glColor3f (0.3, 0.3, 0.3);
glVertex2i(103, 150);
glVertex2i(145, 150);
glVertex2i(145, 222);
glVertex2i(103, 222);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.3, 0.3, 0.3);
glVertex2i(147, 150);
glVertex2i(188, 150);
glVertex2i(188, 222);
glVertex2i(147, 222);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.71, 0.91, 0.96);
glVertex2i(149, 153);
glVertex2i(186, 153);
glVertex2i(186, 220);
glVertex2i(149, 220);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.71, 0.91, 0.96);
glVertex2i(105, 153);
glVertex2i(143, 153);
glVertex2i(143, 220);
glVertex2i(105, 220);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.71, 0.91, 0.96);
glVertex2i(147, 153);
glVertex2i(186, 153);
glVertex2i(186, 220);
glVertex2i(147, 220);
glEnd();

//upper Arrow
glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(110, 185);
glVertex2i(135, 185);
glVertex2i(135, 185);
glVertex2i(130, 192);
glVertex2i(135, 185);
glVertex2i(130, 178);
glEnd();

//Lower window
glBegin(GL_POLYGON);
glColor3f (0.3, 0.3, 0.3);
glVertex2i(103, 148);
glVertex2i(145, 148);
glVertex2i(145, 102);
glVertex2i(103, 102);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(147, 148);
glVertex2i(188, 148);
glVertex2i(188, 102);
glVertex2i(147, 102);
glEnd();

glBegin(GL_POLYGON);
glColor3f (0.71, 0.91, 0.96);
glVertex2i(105, 145);
glVertex2i(143, 145);
glVertex2i(143, 105);
glVertex2i(105, 105);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(149, 145);
glVertex2i(186, 145);
glVertex2i(186, 105);
glVertex2i(149, 105);
glEnd();

//Lower Arrow
glBegin(GL_LINES);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(110, 125);
glVertex2i(135, 125);
glVertex2i(135, 125);
glVertex2i(130, 132);
glVertex2i(135, 125);
glVertex2i(130, 118);
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
glutCreateWindow ("My Little Home");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
