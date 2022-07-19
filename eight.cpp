#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
int yflag = 1;
float ya = 50;
void animate()
{
	if (ya > -50 && yflag==1)
	{
		ya -= 0.2;
	}
	if (ya <= -50)
		yflag = 0;
	
	if (ya < 50 && yflag==0)
		ya += 0.2;
	if (ya >= 50)
		yflag = 1;
	glutPostRedisplay();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 800);
	glMatrixMode(GL_MODELVIEW);
}
void draw()
{
	GLdouble x[4], y1[4], y2[4],y3[4];
	GLdouble yt1[200], xt[200],yt2[200],yt3[200],t;
	int i = 0;
	x[0] = 100, x[1] = 200, x[2] = 300, x[3] = 400;
	y1[0] = 500, y1[1] = 550+ya, y1[2] = 500, y1[3] = 550-ya;
	y2[0] = 400, y2[1] = 450+ya, y2[2] = 400, y2[3] = 450-ya;
	y3[0] = 300, y3[1] = 350+ya, y3[2] = 300, y3[3] = 350-ya;
	for (i=0,t = 0; t < 1; i++,t+=0.007)
	{
		xt[i] = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
		yt1[i] = pow(1 - t, 3) * y1[0] + 3 * t * pow(1 - t, 2) * y1[1] + 3 * pow(t, 2) * (1 - t) * y1[2] + pow(t, 3) * y1[3];
		yt2[i] = pow(1 - t, 3) * y2[0] + 3 * t * pow(1 - t, 2) * y2[1] + 3 * pow(t, 2) * (1 - t) * y2[2] + pow(t, 3) * y2[3];
		yt3[i] = pow(1 - t, 3) * y3[0] + 3 * t * pow(1 - t, 2) * y3[1] + 3 * pow(t, 2) * (1 - t) * y3[2] + pow(t, 3) * y3[3];
	}
	//glPointSize(3);
	glColor3f(1, 0, 0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < 200; i++)
	{
		glVertex2d(xt[i], yt1[i]);
		glVertex2d(xt[i], yt2[i]);
		//glVertex2f(xt[i], yt3[i]);
	}
	glEnd();
	glColor3f(0, 1, 0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < 200; i++)
	{
	//glVertex2f(xt[i], yt1[i]);
	glVertex2d(xt[i], yt2[i]);
	glVertex2d(xt[i], yt3[i]);
	}
	glEnd();
	glColor3f(1, 1, 1);
	glRecti(100, 500, 50, 90);
	glFlush();
}
void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glFlush();

}
int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("BC");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutMainLoop();
	return 0;
}
