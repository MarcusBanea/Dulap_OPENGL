/*
 *  robot.c
 *  Compunerea transformarilor geometrice pentru desenarea obiectelor 
 *  animate ierarhice.
 *  Intercatiune:  sagetile 
 *  
 */
#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

void myinit(void);
void drawPlane(void);
void CALLBACK elbowAdd (void);
void CALLBACK elbowSubtract (void);
void CALLBACK shoulderAdd (void);
void CALLBACK shoulderSubtract (void);
void CALLBACK shoulderXAdd(void);
void CALLBACK shoulderXSubtract(void);
void CALLBACK elbowXSubtract(void);
void CALLBACK elbowXAdd(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);

static int shoulder = 0, elbow = 0, angle1 = 0, angle2 = 0;
static int dulapX = 0, dulapY = 0, dulapZ = 0;
static int sertar = 0;
static double x_sertar[] = { 1.8 };
static double y_sertar[] = { 0.5 };
static double z_sertar[] = { 0.80 };
static double poz[] = {0,0,0,0,0};
static double og[] = {2.2,1.1,0,-1.1,-2.2};


void CALLBACK elbowAdd (void)
{
    if(elbow < 90)
        elbow = (elbow + 5) % 360;
}

void CALLBACK elbowSubtract (void)
{
    if(elbow > 0)
    elbow = (elbow - 5) % 360;
}

void CALLBACK shoulderAdd (void)
{
    if(shoulder < 0)
        shoulder = (shoulder + 5) % 360;
}

void CALLBACK shoulderSubtract (void)
{
    if(shoulder > -90)
        shoulder = (shoulder - 5) % 360;
    //elbow = (elbow - 5) % 360;
}

void CALLBACK shoulderXAdd(void)
{
    angle1 = (angle1 + 5) % 360;
}

void CALLBACK shoulderXSubtract(void)
{
    angle1 = (angle1 - 5) % 360;
}

void CALLBACK elbowXAdd(void)
{
    angle2 = (angle2 + 5) % 360;
}

void CALLBACK elbowXSubtract(void)
{
    angle2 = (angle2 - 5) % 360;
}

void CALLBACK dulapDreapta(void)
{
    dulapX = (dulapX + 5) % 360;
}

void CALLBACK dulapStanga(void)
{
    dulapX = (dulapX - 5) % 360;
}

void CALLBACK dulapSus(void)
{
    dulapY = (dulapY + 5) % 360;
}

void CALLBACK dulapJos(void)
{
    dulapY = (dulapY - 5) % 360;
}

void CALLBACK dulapFata(void)
{
    dulapZ = (dulapZ + 5) % 360;
}

void CALLBACK dulapSpate(void)
{
    dulapZ = (dulapZ - 5) % 360;
}





void CALLBACK moveFataSertar1()
{
    if(poz[0] <= 1.5 && shoulder == -90 && elbow == 90)
        poz[0] += 0.1;
}

void CALLBACK moveSpateSertar1()
{
    if(poz[0] > 0)
        poz[0] -= 0.1;
}

void CALLBACK moveFataSertar2()
{
    if (poz[1] <= 1.5 && shoulder == -90 && elbow == 90)
        poz[1] += 0.1;
}

void CALLBACK moveSpateSertar2()
{
    if (poz[1] > 0)
        poz[1] -= 0.1;
}

void CALLBACK moveFataSertar3()
{
    if (poz[2] <= 1.5 && shoulder == -90 && elbow == 90)
        poz[2] += 0.1;
}

void CALLBACK moveSpateSertar3()
{
    if (poz[2] > 0)
        poz[2] -= 0.1;
}

void CALLBACK moveFataSertar4()
{
    if (poz[3] <= 1.5 && shoulder == -90 && elbow == 90)
        poz[3] += 0.1;
}

void CALLBACK moveSpateSertar4()
{
    if (poz[3] > 0)
        poz[3] -= 0.1;
}

void CALLBACK moveFataSertar5()
{
    if (poz[4] <= 1.5 && shoulder == -90 && elbow == 90)
        poz[4] += 0.1;
}

void CALLBACK moveSpateSertar5()
{
    if (poz[4] > 0)
        poz[4] -= 0.1;
}




void Sertar(double x,double y, double z, double poz, double og)
{
    //sertar test
    glPushMatrix();
    glColor3f(0.7411, 0.4823, 0);
    glTranslatef(0, og, -1+poz);
    glBegin(GL_QUADS);
    //fata sertar
    glVertex3f(0-x,0-y,z);
    glVertex3f(x,0-y,z);

    glVertex3f(x,0-y,z);
    glVertex3f(x,0+y,z);

    glVertex3f(x, 0 + y, z);
    glVertex3f(0-x,0+y,z);

    glVertex3f(0-x,0+y,z);
    glVertex3f(0-x,0-y,z);

    //spate sertar
    glVertex3f(-x, -y, -z);
    glVertex3f(x, - y, -z);

    glVertex3f(x, -y, -z);
    glVertex3f(x,y, -z);

    glVertex3f(x, y, -z);
    glVertex3f(-x,y, -z);

    glVertex3f(-x, y, -z);
    glVertex3f(-x, -y, -z);

    //lateral stanga
    glVertex3f(-x,-y,z);
    glVertex3f(-x,-y,-z);

    glVertex3f(-x,-y,-z);
    glVertex3f(-x,y,-z);

    glVertex3f(-x,y,-z);
    glVertex3f(-x,y,z);

    glVertex3f(-x,y,z);
    glVertex3f(-x,-y,z);

    //lateral dreapta
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, -z);

    glVertex3f(x, -y, -z);
    glVertex3f(x, y, -z);

    glVertex3f(x, y, -z);
    glVertex3f(x, y, z);

    glVertex3f(x, y, z);
    glVertex3f(x, -y, z);

    //jos
    glVertex3f(-x, -y, z);
    glVertex3f(x, -y, z);
    glVertex3f(x,-y,-z);
    glVertex3f(-x, -y, -z);

    
    glEnd();
    glColor3f(1, 1, 1);
    glTranslatef(0,0,0.85);
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluSphere(quadric, 0.1, 10, 5);
    glPopMatrix();
}



void CALLBACK display(void)
{

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3f (1.0, 1.0, 1.0);



    glPushMatrix();
        //rotirea dulapului pe axa y
        glRotatef((GLfloat)dulapX, 0.0, 1.0, 0.0);
        glRotatef((GLfloat)dulapY, 1.0, 0.0, 0.0);
        glRotatef((GLfloat)dulapZ, 0.0, 0.0, 1.0);

        //spatele dulapului
        /*
        glPushMatrix();
        glColor3f(0, 1, 0); //verde
        glTranslatef(0, 0, -1.1);
        auxSolidBox(4, 4, 0.1);
        glPopMatrix();
        */
        
        //lateralele dulapului
        /*
        glPushMatrix();
            glColor3f(1, 0, 0); //
            glTranslatef(0, 0, -0.5);
            auxSolidBox(4, 4, 1);
        glPopMatrix();
        */
        
        

        
        glBegin(GL_LINES);

        //SPATE
        glColor3f(1, 1, 0);
        //rama spate jos
        glVertex3f(-2, -3, -2.01);
        glVertex3f(2, -3, -2.01);
        //rama spate dreapta
        glVertex3f(2, -3, -2.01);
        glVertex3f(2, 3, -2.01);
        //rama spate sus
        glVertex3f(2, 3, -2.01);
        glVertex3f(-2, 3, -2.01);
        //rama spate stanga
        glVertex3f(-2, 3, -2.01);
        glVertex3f(-2, -3, -2.01);


        //lateral stanga
        glColor3f(0, 1, 0);
        glVertex3f(-2.01, -3, 0);
        glVertex3f(-2.01,-3,-2);

        glVertex3f(-2.01, -3, -2);
        glVertex3f(-2.01, 3, -2);
        //se va suprapune cu rama spate stanga

        glVertex3f(-2.01,3,-2);
        glVertex3f(-2.01,3,0);

        glVertex3f(-2.01,3,0);
        glVertex3f(-2.01,-3,0);
        //se va suprapune cu rama fata stanga

        //lateral dreapta
        glColor3f(0, 1, 0);
        glVertex3f(2.01,-3,0);
        glVertex3f(2.01,-3,-2);

        glVertex3f(2.01,-3,-2);
        glVertex3f(2.01,3,-2);
        //se va suprapune cu rama spate dreapta

        glVertex3f(2.01,3,-2);
        glVertex3f(2.01,3,0);

        glVertex3f(2.01, 3, 0);
        glVertex3f(2.01,-3,0);
        //se va suprapune cu rama fata dreapta

        //jos
        glVertex3f(-2.01, -3, 0);
        glVertex3f(2.01, -3, 0);
        glVertex3f(2.01, -3, -2);
        glVertex3f(-2.01, -3, -2);

        //sus
        glVertex3f(-2.01, 3, 0);
        glVertex3f(2.01, 3, 0);
        glVertex3f(2.01, 3, -2);
        glVertex3f(-2.01, 3, -2);

        
        glEnd();
        //sertarele dulapului
        for(int i = 0; i < 5; i++)
            Sertar(x_sertar[0], y_sertar[0], z_sertar[0], poz[i], og[i]);

        //usa din stanga 
        glColor3f(0.58, 0.43, 0.098);
        glPushMatrix();
            glTranslatef (-2.0, 0.0, 0.0);
            glRotatef ((GLfloat) shoulder, 0.0, 1.0, 0.0);
            glTranslatef (1.0, 0.0, 0.0);
            auxSolidBox(2, 6, 0.07);
        glPopMatrix();
    
        //usa din dreapta
        glPushMatrix();
            glTranslatef (2.05, 0.0, 0.0);
            glRotatef ((GLfloat) elbow, 0.0, 1.0, 0.0);
            glTranslatef (-1, 0.0, 0.0);
            auxSolidBox(2, 6, 0.07);
       glPopMatrix();

       


    glPopMatrix();
    //glRotatef((GLfloat)angle1, 1.0, 0.0, 0.0);
    //glRotatef((GLfloat)angle2, 1.0, 0.0, 0.0);
    //rotatie fata - spate pe axa y
    //glRotatef((GLfloat)angle1, 0.0, 1.0, 0.0);
    //rotatie fata - spate pe axa y
    //glRotatef((GLfloat)angle2, 0.0, 1.0, 0.0);

    glFlush();
}

void myinit (void) 
{
    glShadeModel (GL_FLAT);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, (GLfloat) w/(GLfloat) h, 1, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);  
}


int main(int argc, char** argv)
{
    auxInitDisplayMode (AUX_SINGLE | AUX_RGB | AUX_DEPTH);
    auxInitPosition (0, 0, 800, 800);
    auxInitWindow ("Composite Modeling Transformations");

    myinit ();

    auxKeyFunc (AUX_LEFT, shoulderSubtract);
    auxKeyFunc (AUX_RIGHT, shoulderAdd);
    auxKeyFunc (AUX_UP, elbowAdd);
    auxKeyFunc (AUX_DOWN, elbowSubtract);
    auxKeyFunc (AUX_a, shoulderXAdd);
    auxKeyFunc (AUX_d, shoulderXSubtract);
    auxKeyFunc (AUX_w, elbowXAdd);
    auxKeyFunc (AUX_s, elbowXSubtract);
    auxKeyFunc (AUX_1, dulapStanga);
    auxKeyFunc (AUX_2, dulapDreapta);
    auxKeyFunc (AUX_3, dulapSus);
    auxKeyFunc (AUX_4, dulapJos);
    auxKeyFunc (AUX_5, dulapFata);
    auxKeyFunc (AUX_6, dulapSpate);
    auxKeyFunc (AUX_Q, moveFataSertar1);
    auxKeyFunc (AUX_W, moveSpateSertar1);
    auxKeyFunc (AUX_E, moveFataSertar2);
    auxKeyFunc (AUX_R, moveSpateSertar2);
    auxKeyFunc(AUX_T, moveFataSertar3);
    auxKeyFunc(AUX_Y, moveSpateSertar3);
    auxKeyFunc(AUX_U, moveFataSertar4);
    auxKeyFunc(AUX_I, moveSpateSertar4);
    auxKeyFunc(AUX_O, moveFataSertar5);
    auxKeyFunc(AUX_P, moveSpateSertar5);
    auxReshapeFunc (myReshape);
    auxMainLoop(display);
    return(0);
}
