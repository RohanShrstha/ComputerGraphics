#include<GL/glut.h>
void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,300.0,0.0,200.0);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2i(120,130);
glVertex2i(150,100);
glEnd();
glColor3f(0.0,0.0,0.0);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'L');
glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(400,300);
	glutCreateWindow("An ex open GL program to display simple line");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
