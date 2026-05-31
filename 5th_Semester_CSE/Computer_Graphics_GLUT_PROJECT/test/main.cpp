#include <windows.h>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2f(1,0);
        glVertex2f(-1,0);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Nissan");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
