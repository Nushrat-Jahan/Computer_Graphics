//Nushrat Jahan
//ID 18-36586-1
// Batman home assignment

#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
glPointSize(5.0);


//border line of batman
//1st horizontal line
glBegin(GL_QUADS);
glColor3f (0.0, 0.0, 0.0);
glVertex2i(162, 440);
glVertex2i(162,460);
glVertex2i(468,460);
glVertex2i(468,440);
glEnd();

//2nd horizontal line
glBegin(GL_QUADS);
glVertex2i(162,40);
glVertex2i(162,60);
glVertex2i(468,60);
glVertex2i(468,40);
glEnd();

//1st vertical line
glBegin(GL_QUADS);
glVertex2i(36,180);
glVertex2i(36,320);
glVertex2i(54,320);
glVertex2i(54,180);
glEnd();

//2nd vertical line
glBegin(GL_QUADS);
glVertex2i(576,180);
glVertex2i(576,320);
glVertex2i(594,320);
glVertex2i(594,180);
glEnd();

//YELLOW
//1st horizontal line
glBegin(GL_QUADS);
glColor3f (1.0, 1.0, 0.0);
glVertex2i(162, 440);
glVertex2i(162,420);
glVertex2i(468,420);
glVertex2i(468,440);
glEnd();

//2nd horizontal line
glBegin(GL_QUADS);
glVertex2i(162,60);
glVertex2i(162,80);
glVertex2i(468,80);
glVertex2i(468,60);
glEnd();

//1st vertical line
glBegin(GL_QUADS);
glVertex2i(54,180);
glVertex2i(54,320);
glVertex2i(72,320);
glVertex2i(72,180);
glEnd();

//2nd vertical line
glBegin(GL_QUADS);
glVertex2i(576,180);
glVertex2i(576,320);
glVertex2i(558,320);
glVertex2i(558,180);
glEnd();

//using points
glPointSize(18.0);
glBegin(GL_POINTS);
glColor3f (0.0, 0.0, 0.0);

//Black border
for(int i=152,j=430; i>=62; i-=18,j-=20) glVertex2i(i,j);
for(int i=477,j=430; i<=567; i+=18,j-=20) glVertex2i(i,j);
for(int i=63,j=170; i<171; i+=18,j-=20) glVertex2i(i,j);
for(int i=568,j=170; i>468; i-=18,j-=20) glVertex2i(i,j);

//Yellow border
glColor3f (1.0, 1.0, 0.0);
for(int i=170,j=430; i>=62; i-=18,j-=20) {glVertex2i(i,j); glVertex2i(i+18,j);}
for(int i=459,j=430; i<=567; i+=18,j-=20) {glVertex2i(i,j); glVertex2i(i-18,j);}
for(int i=63,j=190; i<=171; i+=18,j-=20) {glVertex2i(i,j); glVertex2i(i+18,j);}
for(int i=568,j=190; i>=468; i-=18,j-=20) {glVertex2i(i,j); glVertex2i(i-18,j);}

//Batman line by line
//LIne 1
for(int i=188; i<=459; i+=18)
{
    if(i==278 || i==350)
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,410);
    }
    else
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,410);
    }
}

//Line 2
for(int i=170; i<=459; i+=18)
{
    if((i>=278 && i<=350) || (i>=170 && i<=206) || (i>=422 && i<=458))
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,390);
    }
    else
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,390);
    }
}

//Line 3
for(int i=152; i<=476; i+=18)
{
    if((i>=278 && i<=350) || (i>=152 && i<206) || (i>=440 && i<=476))
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,370);
    }
    else
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,370);
    }
}

//Line 4
for(int i=134; i<=494; i+=18)
{
    if((i>=278 && i<=350) || (i>=134 && i<206) || (i>=440 && i<=494))
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,350);
    }
    else
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,350);
    }
}

//Line 5
for(int i=116; i<=512; i+=18)
{
    if((i>=278 && i<=350) || (i>=116 && i<206) || (i>=440 && i<=512))
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,330);
    }
    else
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,330);
    }
}

//Line 6
for(int i=98; i<=530; i+=18)
{
    if((i>=260 && i<=368) || (i>=98 && i<=206) || (i>=422 && i<=530))
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,310);
    }
    else
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,310);
    }
}

//Line 7-11
glColor3f (0.0, 0.0, 0.0);
for(int i=80; i<=548; i+=18)
{
    for(int j=290; j>=210; j-=20)
        glVertex2i(i,j);
}

//Line 12
for(int i=98; i<=530; i+=18)
{
    if(i==98 || i==530) glVertex2i(i,190);
    else
    {
        glVertex2i(i,190);
        glVertex2i(i,170);
    }
}

//Line 13
for(int i=134; i<=512; i+=18)
{
    if(i==260 || i==368)
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,150);
    }
    else
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,150);
    }
}

//Line 14
for(int i=152; i<494; i+=18)
{
    if((i>=242 && i<296) || (i>=350 && i<=386))
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,130);
    }
    else
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,130);
    }
}

//Line 15
for(int i=170; i<476; i+=18)
{
    if((i>=224 && i<296) || (i>=350 && i<=404))
    {
        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,110);
    }
    else
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,110);
    }
}

//Line 16
for(int i=188; i<458; i+=18)
{
    if(i==314 || i==206 || i==422)
    {
        glColor3f (0.0, 0.0, 0.0);
        glVertex2i(i,90);
    }
    else
    {

        glColor3f (1.0, 1.0, 0.0);
        glVertex2i(i,90);
    }
}
glEnd();

//Grid Lines
glColor3f (15.0, .50, 5.0);
glBegin(GL_LINES);
for(int i=0; i<=640; i+=18)
{
    glVertex2i(i,0);
    glVertex2i(i,470);
}
for(int i=0; i<=480; i+=20)
{
    glVertex2i(0,i);
    glVertex2i(640,i);
}
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
