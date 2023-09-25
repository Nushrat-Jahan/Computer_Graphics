// Project
#include<bits/stdc++.h>
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<string.h>
using namespace std;

//l1=level1, l2=level2, l3=level3, mj=biggest monster
bool m1=true ,m2=true, m3=true, m4=true, mj=false,l1=true,l2=false,l3=false,bfire=false;
bool mj1=false,mj2=false;
int counter,m1c=0,m2c=0,m3c=0,m4c=0,mjc=0,pt=0;
int screen_width, screen_height;
int startx, starty;
float theta;
GLfloat position = 0.0f;
GLfloat speed = 0.05f;
GLfloat positionroket=0.0f;
GLfloat speedroket = 0.1f;
GLfloat positionbullet=0.0f;
GLfloat speedbullet = 0.03f;
GLfloat PistolLR = 0.0f;
GLfloat PistolUD = 0.0f;
GLfloat PositionMonster=0.0f;


void update(int value) {

    if(position < -1.90)
    {
       position = 0.0f;
        PositionMonster-=0.2;
       if(PositionMonster < -.9)
        PositionMonster =0.0;
    }
    if(mj) speed = 0.08;
    position -= speed;
	glutPostRedisplay();
     if(l1)
     {
        if(positionbullet>=position+1.0f && positionbullet-.15f<=position+1.0f )
          {
             float x1=PistolUD+.3;
             if(x1>=0.6 && x1<=0.8)          { m1=false; positionbullet=0.0f; bfire=false; }
             else if(x1>=0.3  && x1<=0.5)    { m2=false; positionbullet=0.0f; bfire=false; }
             else if(x1>=-0.05 && x1<=0.15)  { m3=false; positionbullet=0.0f; bfire=false; }
             else if(x1>=-.45  &&  x1<=-.25) { m4=false; positionbullet=0.0f; bfire=false; }
             if(mj==true)
             {
              if(x1>=.35  &&  x1<=0.75) { mj=false; positionbullet=0.0f; bfire=false; mj1=true; }
             }
          }
         if(m1==false && m2==false && m3==false && m4==false) { mj=true; }
         if(mj1)    { l1=false; l2=true; m1=true; m2=true; m3=true; m4=true;}
    }

    else if(l2)
     {
         if(positionbullet>=position+1.0f && positionbullet-.15f<=position+1.0f )
           {
              float x1=PistolUD+.3;
              if     (x1>=0.6 && x1<=0.8)     { m1=false; positionbullet=0.0f; bfire=false; }
              else if(x1>=0.3  && x1<=0.5)    { m2=false; positionbullet=0.0f; bfire=false; }
              else if(x1>=-0.05 && x1<=0.15)  { m3=false; positionbullet=0.0f; bfire=false; }
              else if(x1>=-.45  &&  x1<=-.25) { m4=false; positionbullet=0.0f; bfire=false; }
              if(mj==true) {if(x1>=0.3  &&  x1<=0.7) { mj=false; positionbullet=0.0f; bfire=false; mj2=true; }}
           }
           if(m1==false && m2==false && m3==false && m4==false) { mj=true; }
           if(mj2)    { mj1=false; l2=false; l3=true; m1=true; m2=true; m3=true; m4=true;}
     }

     else if(l3)
      {
          if(positionbullet>=position+1.0f && positionbullet-.15f<=position+1.0f )
           {
              float x1=PistolUD+.3;
              if(x1>=0.4 && x1<=0.5)            { m1=false; positionbullet=0.0f; bfire=false; }
              else if(x1>=0.04  && x1<=0.26)    { m2=false; positionbullet=0.0f; bfire=false; }
              else if(x1>=-0.26 && x1<=-0.04)   { m3=false; positionbullet=0.0f; bfire=false; }
              else if(x1>=-.5  &&  x1<=-.4)     { m4=false; positionbullet=0.0f; bfire=false; }
              if(mj) if(x1>=.3  &&  x1<=0.65)   { mj=false; positionbullet=0.0f; bfire=false; }
          }
          if(m1==false && m2==false && m3==false && m4==false) { mj=true; }
      }

	glutTimerFunc(100, update, 0);
}

void updatebullet(int value) {
    if(bfire)
    {
       if(positionbullet > 1.8)
        positionbullet = 1.8f;
        positionbullet += speedbullet;
	    glutPostRedisplay();
    }
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
		    bfire=true;
		    updatebullet(positionbullet);
		}
		if (state == GLUT_UP)
		{
		    bfire = false;
		    positionbullet=0.0f;
		}
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 27)
        exit(0);
}
void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
    if(PistolUD > .66)
        {
          PistolUD = PistolUD;
	      glutPostRedisplay();
        }
    else PistolUD+=0.05;
break;
case GLUT_KEY_DOWN:
if(PistolUD < -1.1)
        {
          PistolUD = PistolUD;
	      glutPostRedisplay();
        }
    else PistolUD-=0.05;
break;
case GLUT_KEY_LEFT:
if(PistolLR < -.2)
        {
          PistolLR = PistolLR;
	      glutPostRedisplay();
        }
    else PistolLR-=0.05;
break;
case GLUT_KEY_RIGHT:
if(PistolLR > 1.4)
        {
          PistolLR = PistolLR;
	      glutPostRedisplay();
        }
    else PistolLR+=0.05;
break;
}

glutPostRedisplay();
}

void House()
{
glColor3f (0.21, 0.5, 0.21);
glRectf(-.99,-1,-.80,-.8);
glColor3f (0.76, 0.29, 0.05);
glRectf(-0.79,-1,-.57,-.7);
glColor3f (1, 0.66, 0.66);
glRectf(-.56,-1,-.35,-.6);
glColor3f (.51, 0.6, 0.69);
glRectf(-.34,-1,-.09,-.6);
glRectf(-.31,-.6,-.12,-.5);
glColor3f (.92, 0.4, 0.78);
glRectf(-.08,-1,.16,-.55);
glColor3f (.79, 0.19, 0.63);
glRectf(.17,-1,.36,-.7);
glColor3f (0.21, 0.75, 0.51);
glRectf(.37,-1,.51,-.6);
glColor3f (.64, 0.62, 0.63);
glRectf(.52,-1,.72,-.62);
glColor3f (.94, 0.2, 0.1);
glRectf(.73,-1,.98,-.7);
glRectf(.75,-.7,.96,-.6);

// Windows
glColor3f (1.0, 1.0, 1.0);
//House 1
glRectf(-.97,-1,-.92,-.84);
glRectf(-.9,-.98,-.87,-.92);
glRectf(-.9,-.90,-.87,-.84);
glRectf(-.86,-.98,-.83,-.92);
glRectf(-.86,-.9,-.83,-.84);

//House 2
glRectf(-.77,-1,-.72,-.84);
glRectf(-.7,-.98,-.67,-.92);
glRectf(-.7,-.90,-.67,-.84);
glRectf(-.66,-.98,-.63,-.92);
glRectf(-.66,-.9,-.63,-.84);

//House 3
glRectf(-.54,-1,-.49,-.84);
glRectf(-.47,-.98,-.44,-.92);
glRectf(-.47,-.90,-.44,-.84);
glRectf(-.43,-.98,-.40,-.92);
glRectf(-.43,-.9,-.40,-.84);

glRectf(-.54,-.81,-.49,-.66);
glRectf(-.47,-.80,-.44,-.74);
glRectf(-.47,-.72,-.44,-.66);
glRectf(-.43,-.80,-.40,-.74);
glRectf(-.43,-.72,-.40,-.66);

//House 4
glRectf(-.3,-1,-.25,-.84);
glRectf(-.23,-.98,-.18,-.92);
glRectf(-.23,-.90,-.18,-.84);
glRectf(-.17,-.98,-.12,-.92);
glRectf(-.17,-.9,-.12,-.84);

glRectf(-.3,-.81,-.25,-.66);
glRectf(-.23,-.80,-.18,-.74);
glRectf(-.23,-.72,-.18,-.66);
glRectf(-.17,-.80,-.12,-.74);
glRectf(-.17,-.72,-.12,-.66);

//House 5
glRectf(-.05,-1,0.0,-.84);
glRectf(.02,-.98,0.07,-.92);
glRectf(.02,-.90,0.07,-.84);
glRectf(0.08,-.98,.13,-.92);
glRectf(0.08,-.9,.13,-.84);

glRectf(-.05,-.81,0.0,-.66);
glRectf(0.02,-.80,0.07,-.74);
glRectf(0.02,-.72,0.07,-.66);
glRectf(0.08,-.80,.13,-.74);
glRectf(0.08,-.72,.13,-.66);

//House 6
glRectf(0.19,-1,0.24,-.84);
glRectf(.26,-.98,0.29,-.92);
glRectf(.26,-.90,0.29,-.84);
glRectf(0.3,-.98,.33,-.92);
glRectf(0.3,-.9,.33,-.84);

//House 7
glRectf(0.38,-1,0.42,-.84);
glRectf(0.43,-.98,0.46,-.92);
glRectf(0.43,-.90,0.46,-.84);
glRectf(0.47,-.98,.50,-.92);
glRectf(0.47,-.9,.50,-.84);

glRectf(0.38,-.81,0.42,-.66);
glRectf(0.43,-.80,0.46,-.74);
glRectf(0.43,-.72,0.46,-.66);
glRectf(0.47,-.80,.50,-.74);
glRectf(0.47,-.72,.50,-.66);

//House 8
glRectf(0.55,-1,0.59,-.84);
glRectf(0.60,-.98,0.64,-.92);
glRectf(0.60,-.90,0.64,-.84);
glRectf(0.65,-.98,.69,-.92);
glRectf(0.65,-.9,.69,-.84);

glRectf(0.55,-.81,0.59,-.66);
glRectf(0.60,-.80,0.64,-.74);
glRectf(0.60,-.72,0.64,-.66);
glRectf(0.65,-.80,0.69,-.74);
glRectf(0.65,-.72,0.69,-.66);

//House 9
glRectf(0.78,-1,0.82,-.84);
glRectf(0.83,-.98,0.87,-.92);
glRectf(0.83,-.90,0.87,-.84);
glRectf(0.88,-.98,.92,-.92);
glRectf(0.88,-.9,.92,-.84);

glRectf(0.78,-.81,0.82,-.66);
glRectf(0.83,-.80,0.87,-.74);
glRectf(0.83,-.72,0.87,-.66);
glRectf(0.88,-.80,0.92,-.74);
glRectf(0.88,-.72,0.92,-.66);
}

void Pistol()
{
    if(l1)
    {
       glColor3f (0.0, 0.0, 1.0);
       glRectf(-.78,.3,-.5,.25);
       glRectf(-.78,.25,-.65,.15);
       glRectf(-.78,.15,-.7,.10);
       glColor3f (1.0, 1.0, 1.0);
       glRectf(-.74,.25,-.67,.18);
    }

    if(l2)
    {
       glColor3f (0.0, 0.0, 1.0);
    glRectf(-.6,.3,-.5,.25);

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.1416/180;
      glVertex2f(-.65+.08*cos(theta),.28+.08*sin(theta));
   }
   glEnd();
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.1416/180;
      glVertex2f(-.65+.06*cos(theta),.28+.06*sin(theta));
   }
   glEnd();
   glColor3f (0.0, 0.0, 1.0);
      glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.1416/180;
      glVertex2f(-.65+.04*cos(theta),.28+.04*sin(theta));
   }
   glEnd();
    }

    if(l3)
    {
        glBegin(GL_QUADS);
        glColor3ub(23, 100, 255);
        glVertex2f(-.7,.1);
        glVertex2f(-.7,.3);
        glVertex2f(-.8,.3);
        glVertex2f(-.8,.1);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(255, 100, 25);
        glVertex2f(-.6,.2);
        glVertex2f(-.6,.3);
        glVertex2f(-.7,.3);
        glVertex2f(-.7,.2);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(25, 200, 25);
        glVertex2f(-.6,.2);
        glVertex2f(-.5,.25);
        glVertex2f(-.6,.3);
        glEnd();
    }
}
void PistolBullet()
{
    if(l1 || l2)
    {
       glColor3f (1.0, 0.0, 1.0);
       glRectf(-.6,.3,-.55,.25);
    }
    if(l3)
    {
        glBegin(GL_QUADS);
        glColor3ub(255, 100, 25);
        glVertex2f(-.5,.24);
        glVertex2f(-.48,.24);
        glVertex2f(-.48,.26);
        glVertex2f(-.5,.26);
        glEnd();
    }
}

void Monster()
{
    if(l1)
    {
       glColor3f (0.0, .9, 0.5);
    if(m1)
    {
       glRectf(.68,.6,.85,.75);
       glRectf(.68,.75,.73,.80);
       glRectf(.8,.75,.85,.80);

    }

    if(m2)
    {

       glRectf(.78,.3,.95,.45);
       glRectf(.78,.45,.83,.50);
       glRectf(.9,.45,.95,.50);
    }

    if(m3)
    {
       glRectf(.58,.1,.75,-.05);
       glRectf(.58,.1,.63,.15);
       glRectf(.7,.1,.75,.15);
    }

    if(m4)
    {
        glRectf(.78,-.3,.95,-.45);
        glRectf(.78,-.3,.83,-.25);
        glRectf(.9,-.3,.95,-.25);
    }
    }
    if(l2)
    {
        if(m1)
        {

            glColor3f (1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            for(int i=0; i<360; i++)
             {
               theta=i*3.1416/180;
               glVertex2f(.65+.12*cos(theta),.78+.06*sin(theta));
             }
            glEnd();
            glColor3f (0.0, 0.0, 0.0);
            glRectf(.55,.77,.62,.80);
            glRectf(.68,.77,.75,.80);
            glRectf(.64,.73,.66,.76);
        }
        if(m2)
        {
            glColor3f (1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            for(int i=0; i<360; i++)
             {
               theta=i*3.1416/180;
               glVertex2f(.68+.12*cos(theta),.48+.06*sin(theta));
             }
            glEnd();
            glColor3f (0.0, 0.0, 0.0);
            glRectf(.58,.47,.65,.50);
            glRectf(.71,.47,.78,.50);
            glRectf(.67,.43,.69,.46);
        }
        if(m3)
        {
            glColor3f (1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
            for(int i=0; i<360; i++)
             {
               theta=i*3.1416/180;
               glVertex2f(.70+.12*cos(theta),.10+.06*sin(theta));
             }
            glEnd();
            glColor3f (0.0, 0.0, 0.0);
            glRectf(.60,.09,.67,.12);
            glRectf(.73,.09,.80,.12);
            glRectf(.69,.05,.71,.08);
        }
        if(m4)
        {
            glColor3f (1.0, 0.0, 0.0);
             glBegin(GL_POLYGON);
            for(int i=0; i<360; i++)
             {
               theta=i*3.1416/180;
               glVertex2f(.70+.12*cos(theta),-.18+.06*sin(theta));
             }
            glEnd();
            glColor3f (0.0, 0.0, 0.0);
            glRectf(.60,-.19,.67,-.16);
            glRectf(.73,-.19,.80,-.16);
            glRectf(.69,-.20,.71,-.23);
        }
    }
    if(l3)
    {
        if(m1)
        {
            glBegin(GL_QUADS);
            glColor3ub(0, 266, 25);
            glVertex2f(.8,.4);
            glVertex2f(.8,.5);
            glVertex2f(.7,.5);
            glVertex2f(.7,.4);
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.8,.43);
            glVertex2f(.86,.43);
            glVertex2f(.86,.46);
            glVertex2f(.8,.46);
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.7,.43);
            glVertex2f(.7,.46);
            glVertex2f(.64,.46);
            glVertex2f(.64,.43);
            glEnd();
        }

        if(m2)
        {
           glBegin(GL_QUADS);
           glColor3ub(0, 266, 25);
           glVertex2f(.8,.1);
           glVertex2f(.8,.2);
           glVertex2f(.7,.2);
           glVertex2f(.7,.1);
           glEnd();
           glBegin(GL_QUADS);
           glColor3ub(255, 0, 0);
           glVertex2f(.73,.04);
           glVertex2f(.76,.04);
           glVertex2f(.76,.1);
           glVertex2f(.73,.1);
           glEnd();
           glBegin(GL_QUADS);
           glColor3ub(255, 0, 0);
           glVertex2f(.73,.2);
           glVertex2f(.76,.2);
           glVertex2f(.76,.26);
           glVertex2f(.73,.26);
           glEnd();
        }

     if(m3)
     {

            glBegin(GL_QUADS);
            glColor3ub(0, 266, 25);
            glVertex2f(.8,-.1);
            glVertex2f(.8,-.2);
            glVertex2f(.7,-.2);
            glVertex2f(.7,-.1);
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.73,-.04);
            glVertex2f(.76,-.04);
            glVertex2f(.76,-.1);
            glVertex2f(.73,-.1);
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.73,-.2);
            glVertex2f(.76,-.2);
            glVertex2f(.76,-.26);
            glVertex2f(.73,-.26);
            glEnd();
     }

     if(m4)
     {
        glBegin(GL_QUADS);
            glColor3ub(0, 266, 25);
            glVertex2f(.8,-.4);
            glVertex2f(.8,-.5);
            glVertex2f(.7,-.5);
            glVertex2f(.7,-.4);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.8,-.43);
            glVertex2f(.86,-.43);
            glVertex2f(.86,-.46);
            glVertex2f(.8,-.46);
            glEnd();
            glBegin(GL_QUADS);
            glColor3ub(255, 0, 0);
            glVertex2f(.7,-.43);
            glVertex2f(.7,-.46);
            glVertex2f(.64,-.46);
            glVertex2f(.64,-.43);
            glEnd();
     }

     }



}

 void Bigmonster()
 {
     if(l1)
     {
         if(mj)
         {
              glColor3f (0.0, .9, 0.5);
              glRectf(.68,.6,.85,.75);
              glRectf(.68,.7,.65,.65);
              glRectf(.78,.55,.83,.6);
              glRectf(.65,.35,.85,.55);
              glColor3f (0.0, 0.0, 0.0);
              glRectf(.7,.72,.75,.67);
        }
     }
     if(l2)
     {
         if(mj)
         {

             glColor3f (0.0,0.60, 0.60);
             glBegin(GL_TRIANGLES);
             glVertex2f(.95,.7);
             glVertex2f(.95,.3);
             glVertex2f(.7,.5);
             glEnd();

             glColor3f (0.60,0.0, 0.60);
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.65+.30*cos(theta),.5+.20*sin(theta));}
             glEnd();

             glColor3f (1.0,1.0, 1.0);
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.48+.05*cos(theta),.47+.05*sin(theta));}
             glEnd();
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.48+.05*cos(theta),.58+.05*sin(theta));}
             glEnd();
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.58+.05*cos(theta),.53+.05*sin(theta));}
             glEnd();

             glColor3f (0.0,0.0, 0.0);
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.48+.02*cos(theta),.47+.02*sin(theta));}
             glEnd();
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.48+.02*cos(theta),.58+.02*sin(theta));}
             glEnd();
             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.58+.02*cos(theta),.53+.02*sin(theta));}
             glEnd();

             glBegin(GL_POLYGON);
             for(int i=0; i<360; i++){ theta=i*3.1416/180; glVertex2f(.72+.03*cos(theta),.52+.07*sin(theta));}
             glEnd();

             glColor3f (1.0,0.0, 0.0);
             glBegin(GL_TRIANGLES);
             glVertex2f(.72,.57);
             glVertex2f(.72,.47);
             glVertex2f(.9,.5);
             glEnd();

             glColor3f (0.0, 0.40, 0.60);
             glRectf(.35,.47,.25,.54);
             //glColor3f (1.0, 1.0, 1.0);
             //glRectf(.60,.30,.65,.70);
         }
     }
     if(l3)
     {
         if(mj)
         {
             glBegin(GL_QUADS);
             glColor3ub(255, 0, 0);
             glVertex2f(.6,.3);
             glVertex2f(.9,.3);
             glVertex2f(.9,.65);
             glVertex2f(.6,.65);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(255, 255,255);
             glVertex2f(.65,.45);
             glVertex2f(.75,.45);
             glVertex2f(.75,.47);
             glVertex2f(.65,.47);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(255, 255,255);
             glVertex2f(.78,.38);
             glVertex2f(.83,.38);
             glVertex2f(.83,.40);
             glVertex2f(.78,.40);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(255, 255,255);
             glVertex2f(.78,.52);
             glVertex2f(.83,.52);
             glVertex2f(.83,.54);
             glVertex2f(.78,.54);
             glEnd();
             glBegin(GL_TRIANGLES);
             glColor3ub(0, 0, 0);
             glVertex2f(.9,.3);
             glVertex2f(1,.35);
             glVertex2f(.9,.4);
             glEnd();
             glBegin(GL_TRIANGLES);
             glColor3ub(0, 0, 0);
             glVertex2f(.9,.55);
             glVertex2f(1,.60);
             glVertex2f(.9,.65);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(0,0,0);
             glVertex2f(.6,.42);
             glVertex2f(.6,.52);
             glVertex2f(.4875,.52);
             glVertex2f(.4875,.42);
             glEnd();
             glBegin(GL_QUADS);
             glColor3ub(0,0,0);
             glVertex2f(.4875,.3);
             glVertex2f(.4875,.63);
             glVertex2f(.3,.63);
             glVertex2f(.3,.3);
             glEnd();
             glBegin(GL_TRIANGLES);
             glColor3ub(0, 0, 0);
             glVertex2f(.65,.65);
             glVertex2f(.4,.75);
             glVertex2f(.6,.6);
             glEnd();
             glBegin(GL_TRIANGLES);
             glColor3ub(0, 0, 0);
             glVertex2f(.6,.35);
             glVertex2f(.43,.22);
             glVertex2f(.65,.3);
             glEnd();
        }
    }
}

  void BigAttack()
 {
     if(mj)
     {
         glColor3f (1.0, 0.0, 0.0);
         if(l1) glRectf(.68,.7,.73,.65);
         if(l2) glRectf(.45,.48,.5,.53);
         if(l3) glRectf(.45,.45,.5,.50);
     }
 }

void sun()
{
    glColor3f (1.0, .90, 0.2);
    float theta;
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.1416/180;
      glVertex2f(.15*cos(theta),.7+.15*sin(theta));
   }
   glEnd();
}
void cloud()
{
    if(l1 || l3) glColor3f (0.6, 0.89, 1);
    else if(l2) glColor3f (1.0, 1.0, 1);

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.4+.10*cos(theta),.6+.10*sin(theta));
   }
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.25+.15*cos(theta),.6+.15*sin(theta));
   }
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.1+.10*cos(theta),.6+.10*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.9+.10*cos(theta),.8+.10*sin(theta));
   }
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.75+.15*cos(theta),.8+.15*sin(theta));
   }
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.6+.10*cos(theta),.8+.10*sin(theta));
   }
   glEnd();

}
void Trees()
{
    glColor3f (0.60, 0.0, 0.0);
  glRectf(0.73,-.86,0.77,-.66);
  glRectf(0.63,-.86,0.67,-.66);
  glRectf (0.25, -0.87, 0.29,-.66);
  glRectf (-0.43, -0.87, -0.40,-.66);
}
void Greenland()
{


   glColor3f (0.0, 0.80, 0.0);
    float theta;
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.99+0.6*cos(theta),-.99+0.3*sin(theta));
   }
   glEnd();
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.1+.4*cos(theta),-.99+.2*sin(theta));
   }
   glEnd();
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(.5+.40*cos(theta),-.99+.15*sin(theta));
   }
   glEnd();
   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(0.9+.20*cos(theta),-.99+.20*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(.7+.17*cos(theta),-.7+.1*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(0.7+.1*cos(theta),-.6+.15*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-.4+.17*cos(theta),-.7+.1*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(-0.4+.08*cos(theta),-.65+.10*sin(theta));
   }
   glEnd();

     glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(.28+.17*cos(theta),-.7+.1*sin(theta));
   }
   glEnd();

   glBegin(GL_POLYGON);
   for(int i=0; i<360; i++)
   {
      theta=i*3.142/180;
      glVertex2f(0.28+.08*cos(theta),-.65+.10*sin(theta));
   }
   glEnd();


}
void sky(){


 glBegin(GL_QUADS);
   glColor3ub(135, 206, 235);
   glVertex2f(1,.2);
   glVertex2f(1,1);
   glVertex2f(-1,1);
   glVertex2f(-1,.2);
   glEnd();
}
void background(){
    if(l1)
    {
        glColor3f (0.0, 0.0, 0.0);
        glRectf(-1.0,0.0,1.0,1.0);
    }
    if(l2)
    {
        glColor3f (0.60f, 0.89f, 0.89f);
        glRectf(-1.0,0.0,1.0,1.0);
    }
    if(l3) glColor3ub(225, 226, 227);
   glBegin(GL_QUADS);
   glVertex2f(1,-1);
   glVertex2f(1,.2);
   glVertex2f(-1,.2);
   glVertex2f(-1,-1);
   glEnd();
}
void hill(){

   glBegin(GL_TRIANGLES);
   glColor3ub(219, 197, 176);
   glVertex2f(-1,-1);
   glVertex2f(-.7,-.6);
   glVertex2f(-.4,-1);

   glVertex2f(-.4,-1);
   glVertex2f(-0.1,-.6);
   glVertex2f(0.2,-1);

   glVertex2f(.2,-1);
   glVertex2f(.5,-.6);
   glVertex2f(0.8,-1);

   glVertex2f(.8,-1);
   glVertex2f(1,-.7);
   glVertex2f(1,-1);
   glEnd();
}

void welcomeScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    string welcome_text = "Welcome to Deadly Monsters.\nInstructions:\n";
    welcome_text += "1. Use <-(left arrow), ->(right arrow), up arrow, down arrow to control your self.\n<-= left\n-> = right\nup arrrow = up\ndown arrow = down\n";
    welcome_text += "2. Use left mouse to shoot.\n";
    welcome_text += "3. To avoid collision with enemy , you can either destroy enemy  by shooting it.\n";
    welcome_text += "4. Shooting the small enemy  will give you 10 points, whereas shooting Big monster will give 50 points.\n";
    welcome_text += "5. Press Esc to quit the game.\n";

    //memset(enemytankx, -1, sizeof(enemytankx));
    //memset(enemytanky, -1, sizeof(enemytanky));
    //fire.clear();
    int score = 0;
    //tankx = 30;
    //tanky = screen_height / 2 - tankh / 2;


    int x = 50, y = screen_height - 50;
    int len = welcome_text.size();
    glColor3ub(0, 0, 0);
    glRasterPos2i(x, y);
    for(int i = 0; i < len; i++)
    {
        if(welcome_text[i] == '\n')
        {
            y -= 30;
            glRasterPos2i(x, y);
        }

        else
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, welcome_text[i]);
    }


    int w = 200, h = 100;
    startx = screen_width / 2 - w / 2;
    starty = screen_height / 4;

    glBegin(GL_QUADS);
    glVertex2i(startx, starty);
    glVertex2i(startx + w, starty);
    glVertex2i(startx + w, starty + h);
    glVertex2i(startx, starty + h);
    glEnd();

    string start = "Start Game";
    len = start.size();
    glColor3ub(255, 255, 255);
    glRasterPos2i(startx + 40, starty + 40);
    for(int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, start[i]);
    }
    glFlush();

}


void display()
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 0.0);
glPointSize(15.0);

if(l1)
{
glPushMatrix();
background();
House();
sun();
cloud();
glPopMatrix();

glPushMatrix();
glTranslatef(PistolLR,0.0,0.0f);
glPushMatrix();
glTranslatef(positionbullet,PistolUD,0.0f);
PistolBullet();
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,PistolUD,0.0f);
//glTranslatef(0.0f,PistolUD,0.0f);
Pistol();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(position,0.0f,0.0f);
Monster();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,PositionMonster,0.0f);
glPushMatrix();
glTranslatef(position,0.0f,0.0f);
BigAttack();
glPopMatrix();
glPushMatrix();
Bigmonster();
glPopMatrix();
glPopMatrix();
}

if(l2)
{
background();
glPushMatrix();
Trees();
Greenland();
sun();
cloud();
glPopMatrix();

glPushMatrix();
glTranslatef(PistolLR,0.0,0.0f);
glPushMatrix();
glTranslatef(positionbullet,PistolUD,0.0f);
PistolBullet();
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,PistolUD,0.0f);
Pistol();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(position,0.0f,0.0f);
Monster();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,PositionMonster,0.0f);
glPushMatrix();
glTranslatef(position,0.0f,0.0f);
BigAttack();
glPopMatrix();
glPushMatrix();
Bigmonster();
glPopMatrix();
glPopMatrix();
}

if(l3)
{
    glPushMatrix();
sky();
background();
hill();
sun();
cloud();
glPopMatrix();

glPushMatrix();
glTranslatef(PistolLR,0.0,0.0f);
glPushMatrix();
glTranslatef(positionbullet,PistolUD,0.0f);
PistolBullet();
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,PistolUD,0.0f);
Pistol();
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(position,0.0f,0.0f);
Monster();
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,PositionMonster,0.0f);
glPushMatrix();
glTranslatef(position,0.0f,0.0f);
BigAttack();
glPopMatrix();
glPushMatrix();
Bigmonster();
glPopMatrix();
glPopMatrix();
}

glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("DEADLY MONSTERS");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(keyboard);
   glutMouseFunc(handleMouse);
   glutSpecialFunc(SpecialInput);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
