#include<iostream>
#include<windows.h>
#include<GL/glut.h>
int xc=0,yc=0,r=50;
void Display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    int x=0;
    int y=r;
    int Pk=1-r;
    while(x<=y){
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc - x, yc + y);
    x++;
    if(Pk<0){
        Pk=Pk+2*x+1;
    }
    else{
        Pk=Pk+2*(x-y)+1;
        y--;
    }
    }
    glEnd();
    glutSwapBuffers();
}
void init(){
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-100.0,100.0,-100.0,100.0);
}
int main(int argc,char**argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("232311192");
init();
glutDisplayFunc(Display);
glutMainLoop();
return 0;
}
