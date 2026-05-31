#include<Windows.h>
#include<GL/glut.h>
 void Display(){
 glClear(GL_COLOR_BUFFER_BIT);
 glPointSize(4.0f);
 glBegin(GL_LINES);

 glColor3f(1.0f,0.0f,0.0f);
 glVertex2f(-40.0f,1.0f);
 glVertex2f(-0.0f,70.0f);

 glColor3f(1.0f,1.0f,0.0f);
 glVertex2f(-0.0f,70.0f);
 glVertex2f(50.0f,0.0f);

 glColor3f(1.0f,0.0f,1.0f);
 glVertex2f(50.0f,0.0f);
 glVertex2f(-30.0f,60.0f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(-30.0f,60.0f);
glVertex2f(40.0f,60.0f);

glColor3f(1.0f,1.0f,1.0f);
glVertex2f(40.0f,60.0f);
glVertex2f(-40.0f,1.0f);




 glEnd();
 glFlush();
 }
 void init(){
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-100.0,100.0,-100.0,100.0);
 }
 int main(int argc,char ** argv){
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);
 glutCreateWindow("Point are Drwaing");
 init();
 glutDisplayFunc(Display);
 glutMainLoop();
 }
