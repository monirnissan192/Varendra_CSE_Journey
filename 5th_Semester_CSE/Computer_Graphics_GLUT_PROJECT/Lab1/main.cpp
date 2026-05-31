#include<windows.h>
#include<GL/glut.h>

void Display(){
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(20.0f);
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2f(0.5f,0.5f);
glColor3f(0.0f,1.0f,0.0f);
glVertex2f(-0.5f,0.5f);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(0.5f,-0.5f);
glColor3f(1.0f,.0f,1.0f);
glVertex2f(-0.5f,-0.5f);
glColor3f(0.0f,1.0f,1.0f);
glVertex2f(0.0f,0.0f);

glEnd();
glFlush();
}

void init(){
glClearColor(0.0f,0.0f,0.0f,1.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1.0,1.0,-1.0,1.0);
}
int main(int argc,char ** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow(" Pixel Drawing in GLUT ");
init();
glutDisplayFunc(Display);
glutMainLoop();
return 0;
}
