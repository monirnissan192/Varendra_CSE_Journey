#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <cmath>

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * abs(dy) - abs(dx);

    int x = x1;
    int y = y1;

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    for (int i = 0; i < abs(dx); i++)
    {
        x = x + (dx > 0 ? 1 : -1);   // move right or left
        if (p < 0)
            p = p + 2 * abs(dy);
        else
        {
            y = y + (dy > 0 ? 1 : -1); // move up or down
            p = p + 2 * (abs(dy) - abs(dx));
        }
        glVertex2i(x, y);
    }
    glEnd();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0f);



    bresenhamLine(175,150,225,200); // top-left
    bresenhamLine(225,200,275,150); // top-right
    bresenhamLine(275,150, 225,100); // bottom-right
    bresenhamLine(225,100,175,150); // bottom-left

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);  // white background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 300, 0, 300);        // 2D area
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple Rhombus using Bresenham");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
