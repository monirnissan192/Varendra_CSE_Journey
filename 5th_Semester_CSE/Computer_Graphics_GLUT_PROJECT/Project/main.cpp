#include <GL/glut.h>
#include <math.h>
#include <iostream>

float globalAngle = 0.0f;
float scaleFactor = 1.0f;
float transX = 0.0f;
float transY = 0.0f;
float orbitSpeed = 0.5f;

const float PI = 3.14159265358979323846;

void drawCircle(float radius, int segments, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * PI * float(i) / float(segments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawStars() {
    glPointSize(2.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
        glVertex2f(0.8, 0.8); glVertex2f(-0.7, -0.6);
        glVertex2f(0.4, -0.8); glVertex2f(-0.8, 0.5);
        glVertex2f(0.2, 0.9); glVertex2f(-0.2, -0.2);
        glVertex2f(0.9, -0.4); glVertex2f(-0.5, 0.9);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(transX, transY, 0.0f);
    glScalef(scaleFactor, scaleFactor, 1.0f);

    drawStars();

    glPushMatrix();
        glRotatef(globalAngle / 2, 0.0f, 0.0f, 1.0f);
        drawCircle(0.2f, 50, 1.0f, 0.8f, 0.0f);

        glColor3f(1.0f, 0.6f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.25, 0); glVertex2f(0.25, 0);
            glVertex2f(0, -0.25); glVertex2f(0, 0.25);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(globalAngle, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.6f, 0.0f, 0.0f);

        drawCircle(0.1f, 30, 0.0f, 0.5f, 1.0f);

        glPushMatrix();
            glRotatef(globalAngle * 3, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.18f, 0.0f, 0.0f);
            drawCircle(0.04f, 20, 0.8f, 0.8f, 0.8f);
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();
        float cometPos = fmod(globalAngle * 0.5f, 4.0f) - 2.0f;
        glTranslatef(cometPos, cometPos + 0.5f, 0.0f);
        float pulse = 1.0f + 0.3f * sin(globalAngle * 0.1f);
        glScalef(pulse, pulse, 1.0f);

        drawCircle(0.05f, 10, 1.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(0.0f, 0.0f); glVertex2f(-0.2f, -0.2f);
        glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void timer(int value) {
    globalAngle += orbitSpeed;
    if (globalAngle > 360) globalAngle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            scaleFactor += 0.1f;
            break;
        case '-':
            if (scaleFactor > 0.2f) scaleFactor -= 0.1f;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:    transY -= 0.1f; break;
        case GLUT_KEY_DOWN:  transY += 0.1f; break;
        case GLUT_KEY_LEFT:  transX += 0.1f; break;
        case GLUT_KEY_RIGHT: transX -= 0.1f; break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D Transformation Project");

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, timer, 0);

    std::cout << "Controls:" << std::endl;
    std::cout << "[+] : Zoom In" << std::endl;
    std::cout << "[-] : Zoom Out" << std::endl;
    std::cout << "[Arrows] : Pan view" << std::endl;

    glutMainLoop();
    return 0;
}
