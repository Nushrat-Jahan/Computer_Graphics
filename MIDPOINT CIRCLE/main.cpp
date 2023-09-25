//Name : NUSHRAT JAHAN
//ID   : 18-36586-1
//MIDPOINT CIRCLE ALGORITHM

#include<GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
int inx, iny, r, pk, x, y;

void plot(int x, int y)
{
    x+=inx,y+=iny;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void Display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (15.0, 0.0, 0.0);
	glPointSize(4.0);

    //Plotting midpoint circle algorithm
	x = 0,y = r,pk = 1 - r;
	plot(x, y);
	while (x<=y)
	{
		if (pk < 0){ pk += 2*x+1;}
		else { y--; pk += 2*(x-y)+1;}
		x++;
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
		cout << x << " " << y << endl;
	}
	glFlush ();
}

void myInit (void)
{
	glClearColor(0.85, 0.85, 0.85, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
	cout << "Please enter the center x and y coordinates:" << endl;
	cout << "x value  : ";
	cin >> inx;
	cout << "y value : ";
	cin >> iny;
	cout << "Enter radius : ";
	cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("MIDPOINT CIRCLE ALGORITHM");
	glutDisplayFunc(Display);
	myInit ();
	glutMainLoop();

}
