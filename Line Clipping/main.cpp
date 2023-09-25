//Nushrat Jahan
//18-36586-1
//Line Clipping

#include <bits/stdc++.h>
#include<GL/gl.h>
#include <GL/glut.h>

using namespace std;

int winx, winy, winX, winY, x1, y1, x2, y2,cor1,cor2,d1[4] = { 0, 0, 0, 0 },d2[4] = { 0, 0, 0, 0 };
bool flag = false;

int get1coordinate(int x, int y) {
	if (y > winY) d1[0] = 1;
	if (y < winy) d1[1] = 1;
	if (x > winX) d1[2] = 1;
	if (x < winx) d1[3] = 1;

	cor1 = d1[0] * 1000 + d1[1] * 100 + d1[2] * 10 + d1[3];
	return cor1;
}

int get2coordinate(int x, int y) {
	if (y > winY) d2[0] = 1;
	if (y < winy) d2[1] = 1;
	if (x > winX) d2[2] = 1;
	if (x < winx) d2[3] = 1;

	cor2 = d2[0] * 1000 + d2[1] * 100 + d2[2] * 10 + d2[3];
	return cor2;
}

void getPoints()
{
	get1coordinate(x1, y1);
	get2coordinate(x2, y2);
}

void Linedraw(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void Lineclip()
{

	if (get1coordinate(x1, y1) == 0 && get2coordinate(x2, y2) == 0 && flag == false) Linedraw(x1, y1, x2, y2);
	else
	{
		for (int i = 0; i < 4; i++)
		{

			if (d1[i] == d2[i] && d1[i] == 1)
			{
				flag = true;
				break;
			}


		}

		if (flag) cout << "Both point rejected" << endl;
		else
		{

			for (int i = 0; i < 4; i++)
			{
				if (d1[i] == 1)
				{
					switch (i)
					{

					case 0:
						y1 = winY;
						break;

					case 1:
						y1 = winy;
						break;

					case 2:
						x1 = winX;
						break;

					case 3:
						x1 = winx;
						break;
					}
				}

				if (d2[i] == 1)
				{
					switch (i)
					{

					case 0:
						y2 = winY;
						break;

					case 1:
						y2 = winy;
						break;

					case 2:
						x2 = winX;
						break;

					case 3:
						x2 = winx;
						break;
					}
				}
			}

			Linedraw(x1, y1, x2, y2);
		}
	}
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);
	glRecti(winx, winy, winX, winY);

	glColor3f(0.0, 0.0, 0.0);
	Lineclip();

	glFlush();
}

int main(int argc, char** argv)
{
	cout << "Enter Minimum window co-ordinates: ";
	cin >> winx >> winy;
	cout << "Enter Maximum window co-ordinates: ";
	cin >> winX >> winY;

	cout << "Enter co-ordinates of first point of line: ";
	cin >> x1 >> y1;
	cout << "Enter co-ordinates of second point of line: ";
	cin >> x2 >> y2;

	getPoints();

	cout << "First  point code: " << d1[0] << d1[1] << d1[2]<< d1[3] << endl;
	cout << "Second point code: " << d2[0] << d2[1] << d2[2] << d2[3] << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Clipping with Cohen-Sutherland algorithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
/*
Example input
100 100
200 200
70 80
300 500
*/
