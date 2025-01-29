#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
GLdouble X1=100, Y1=100, X2=450, Y2=350; // define line end points
void LineDDA(void)
{
GLdouble dx=X2-X1 , dy=Y2-Y1,steps; // calculate diff betn line end points
float xInc,yInc,x=X1,y=Y1;
steps=(abs(dx)>abs(dy))?abs(dx):abs(dy); //max diff is length
xInc=dx/(float)steps;
yInc=dy/(float)steps;
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
glVertex2d(x,y); //plot initial point
for(int k=0;k<steps;k++)
{
x+=xInc; //decide next incremented x co-ord
y+=yInc; //decide next incremented y co-ord
glVertex2d(x,y); //plot each incremented point till length
}
glEnd();
glFlush();
}
void Init()
{
glClearColor(1.0,1.0,0.0,0.0); //set window color and alpha value
glColor3f(0.0,0.0,0.0); //set line color
glViewport(0 , 0 , 640 , 480); //set viewport
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0 , 640 , 0 , 480); //set viewing rectangle
}
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set color model
glutInitWindowSize(640,480); //set window size
glutInitWindowPosition(0,0); //set initial window position
glutCreateWindow("LineDDA"); //set window title
Init();
glutDisplayFunc(LineDDA);
glutMainLoop();
}

