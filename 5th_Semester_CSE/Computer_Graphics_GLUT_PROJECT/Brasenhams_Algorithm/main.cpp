#include <iostream>
#include <GL/glut.h>
using namespace std;

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.302, 0.004);  // লাইন রঙ
    glPointSize(3.0f);

    int x0 = 50, y0 = 50;
    int x1 = 200, y1 = 150;

    int dx = x1 - x0;
    int dy = y1 - y0;

    int Pk = 2 * dy - dx;

    int xk = x0;
    int yk = y0;

    glBegin(GL_POINTS);
    glVertex2i(xk, yk);  // starting point

    for (int k = 0; k < dx; k++)
    {
        if (Pk < 0)
        {
            xk=xk+1;
            yk=yk;
            Pk = Pk + 2 * dy;
        }
        else
        {
            xk = xk + 1;
            yk = yk + 1;
            Pk = Pk + 2 * dy - 2 * dx;
        }
        glVertex2i(xk, yk);
    }

    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);  // window size অনুযায়ী
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("232311192 - Bresenham Line");

    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
