#include<windows.h>
#include <GL/glut.h>
#include <cmath>
void BresenhamsLine(int x0,int y0,int x1,int y1)
{
    int dx=x1-x0;
    int dy=y1-y0;

    int Pk=2*dy-dy;

    int xk=x0;
    int yk=y0;

    glBegin(GL_POINTS);
    glVertex2i(xk,yk);

    for(int i=0; i<=abs(dx); i++)
    {
        xk=xk+(dx>0?1:-1);//move left or right
        if(Pk<0)
        {
            Pk=Pk+2*abs(dy);
        }
        else
        {
            yk=yk+(dy>0?1:-1);
            Pk=Pk+2*(abs(dy)-abs(dx));
        }
        glVertex2i(xk,yk);
    }
    glEnd();
}
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.1,0.0);
    glPointSize(2.0f);

    BresenhamsLine(175,150,225,200);
    BresenhamsLine(225,200,275,100);
    BresenhamsLine(275,150,225,100);
    BresenhamsLine(225,100,175,150);
    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1); // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 300, 0, 300); // Coordinate system
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Easy DDA Rhombus");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
