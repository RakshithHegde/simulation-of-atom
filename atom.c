#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define pi 3.142
static GLfloat angle = 0;
static int submenu;
static int mainmenu;
static int value = -1;

void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000);
}
void circle(float rad) //orbit
{
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void drawString(float x, float y, float z, char *string) //for displaying texts in output
{
    glColor3f(0, 0, 0);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}
void drawhead(float x, float y, float z, char *string) //for the heading
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void nuc(float rad) //nucleus
{
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.7,0.02);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void eleright(float rad) //spawning electron on right
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 20 * cos(i), 20 * sin(i));
    }
    glEnd();
}
void eleleft(float rad) //spawning electron on left
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 20 * cos(i)), 20 * sin(i));  //size of the electron
    }
    glEnd();
}
void eletop(float rad) //spawning electron on top
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + 20 * sin(i));
    }
    glEnd();
}
void eledown(float rad) //spawning electron on bottom
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + 20 * sin(i)));
    }
    glEnd();
}
void eletr(float rad) //spawning electron on topright
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eletl(float rad) //spawning electron on topleft
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eledl(float rad) //spawning electron on down left
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eledr(float rad) //spawning electron on down right
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void display()
{
   glClearColor(0.9,0.6,0.2, 0);
    if (value != 0) //To display only nucleus until user gives input
    {   
        nuc(250);
        char n[] = "NUCLEUS";
        drawString(-90, 20, 0, n);
        char d[] = "(N & P+)";
        drawString(-100,-20, 0, d);
     }
    if (value == 1) //display hydrogen atom's structure
    {
        char n[] = "HYDROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400); //declaring spawn postion of an electron
        char e[] = " e-";
        drawString(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 2) //display helium atom's structure
    {
        char n[] = "HELIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(400, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        char e[] = " e-";
        drawString(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3) //display lithium atom's structure
    {
        char n[] = "LITHIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        char e[] = " e-";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4) //display beryllium atom's structure
    {
        char n[] = "BERYLLIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400); 
        eleleft(400);
        eletop(600);
        eledown(600);
        char e[] = " e-";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        char n[] = "BORON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        char e[] = " e-";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 6)
    {
        char n[] = "CARBON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        char e[] = " e-";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 7)
    {
        char n[] = "NITROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        char e[] = " e-";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 8)
    {
        char n[] = "OXYGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        char e[] = " e-";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 9)
    {
        char n[] = "FLUORINE";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        char e[] = " e-";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 10)
    {
        char n[] = "NEON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        char e[] = " e-";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    glutSwapBuffers();
}
void rotate()
{
    angle = angle + 10.0;  //speed of rotation of electrons
    if (angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}
void mouseControl(int button, int state, int x, int y) //for getting input from mouse
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(rotate);
        break;
    default:
        break;
    }
}
void menu(int option) 
{
    if (option == 13)
    {
        exit(0);
    }
    else if (option == 11)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
    }
    else
    {
        value = option;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}
void createMenu(void) //displaying menu
{
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddMenuEntry("START SIMULATION", 11);
    glutAddMenuEntry("STOP SIMULATION", 12);
    glutAddMenuEntry("EXIT", 13);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv) //main function
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("SIMULATION OF ATOM");
    init();
    glutDisplayFunc(display);
    createMenu();
    glutMainLoop();
    return 0;
}
