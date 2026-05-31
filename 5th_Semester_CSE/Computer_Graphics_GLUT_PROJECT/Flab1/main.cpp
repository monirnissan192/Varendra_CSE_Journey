#include<windows.h>
#include<Gl/glut.h>
#include<math.h>
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    int x1=1,y1=9,x2=4,y2=4,x3=-2.5,y3=4;
    glBegin(GL_LINES);

    glColor3f(0.0,0.0,0.0);

    glVertex2f(x1,y1);
    glVertex2f(x2,y2);

    glVertex2f(x2,y2);
    glVertex2f(x3,y3);

    glVertex2f(x3,y3);
    glVertex2f(x1,y1);


    glEnd();
// Translation
    int tx=2,ty=3;
    glBegin(GL_LINES);

    glVertex2f(x1+tx,y1+ty);
    glVertex2f(x2+tx,y2+ty);

    glVertex2f(x2+tx,y2+ty);
    glVertex2f(x3+tx,y3+ty);

    glVertex2f(x3+tx,y3+ty);
    glVertex2f(x1+tx,y1+ty);


    glEnd();
// Scaling
    int sx=2,sy=3;
    glBegin(GL_LINES);

    glVertex2f(x1*sx,y1*sy);
    glVertex2f(x2*sx,y2*sy);

    glVertex2f(x2*sx,y2*sy);
    glVertex2f(x3*sx,y3*sy);

    glVertex2f(x3*sx,y3*sy);
    glVertex2f(x1*sx,y1*sy);


    glEnd();

    // X Sharing
    int shr=1;
    glBegin(GL_LINES);

    glVertex2f(x1+shr*y1,y1);
    glVertex2f(x2+shr*y2,y2);

    glVertex2f(x2+shr*y2,y2);
    glVertex2f(x3+shr*y3,y3);

    glVertex2f(x3+shr*y3,y3);
    glVertex2f(x1+shr*y1,y1);

    glEnd();

    //Y Sharing
      shr=1;
    glBegin(GL_LINES);

    glVertex2f(x1,y1+shr*x1);
    glVertex2f(x2,y2+shr*x2);

    glVertex2f(x2,y2+shr*x2);
    glVertex2f(x3,y3+shr*x3);

    glVertex2f(x3,y3+shr*x3);
    glVertex2f(x1,y1+shr*x1);

    glEnd();
// X Reflection
    glBegin(GL_LINES);

    glVertex2f(x1,-y1);
    glVertex2f(x2,-y2);

    glVertex2f(x2,-y2);
    glVertex2f(x3,-y3);

    glVertex2f(x3,-y3);
    glVertex2f(x1,-y1);

    glEnd();

    // y Reflection
    glBegin(GL_LINES);

    glVertex2f(-x1,y1);
    glVertex2f(-x2,y2);

    glVertex2f(-x2,y2);
    glVertex2f(-x3,y3);

    glVertex2f(-x3,y3);
    glVertex2f(-x1,y1);
    glEnd();

//Rotation
    float ang=90.0;
    float rad=ang*M_PI/180;
    glBegin(GL_LINES);

    glVertex2f(x1*cos(rad)-y1*sin(rad),x1*sin(rad)+y1*cos(rad));
    glVertex2f(x2*cos(rad)-y2*sin(rad),x2*sin(rad)+y2*cos(rad));

    glVertex2f(x2*cos(rad)-y2*sin(rad),x2*sin(rad)+y2*cos(rad));
    glVertex2f(x3*cos(rad)-y3*sin(rad),x3*sin(rad)+y3*cos(rad));

    glVertex2f(x3*cos(rad)-y3*sin(rad),x3*sin(rad)+y3*cos(rad));
    glVertex2f(x1*cos(rad)-y1*sin(rad),x1*sin(rad)+y1*cos(rad));

     glEnd();

    glFlush();
}
void init()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-30.0,30.0,-30.0,30.0);
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("232311192");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
}
