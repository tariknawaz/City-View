#include <iostream>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
# define PI 3.14159265358979323846
#include <stdlib.h>
#include <math.h>
#include <cstring>
using namespace std;

GLfloat position = 1.0f;
GLfloat pos1 = 1.0f;
GLfloat pos =-6.0f;
GLfloat p =-6.0f;
GLfloat bspeed = 0.02f;
GLfloat speed = 0.1f;
GLfloat speed1 = 0.1f;
GLfloat s = 0.02f;
int b = 0;
float raining = 2.6;
float ron = 0;
float raining2 = 2.6;
float _cameraAngle = 0.0;
float Sun_rise = 0;
float Sun_down = 2.3;
float Moon_rise = 4.3;
float Moon_down = 2.3;

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);   //jdciubk*/
}

void handleKeypress(int key, int x, int y) {

    switch (key) {

    case GLUT_KEY_F1:
        b = 7;
		break;

    case GLUT_KEY_F2:
        b = 8;
		break;

    case GLUT_KEY_F3:
        ron = 1;
		break;

    case GLUT_KEY_F4:
        ron = 0;
		break;

    case GLUT_KEY_F8:
        speed = 0;
		break;

    case GLUT_KEY_F9:
       speed = 0.1;
		break;

    case GLUT_KEY_F10:
        p = 0;
		break;

    case GLUT_KEY_F11:
        p = 0.1;
		break;

    default:
        break;

    glutPostRedisplay();
    }
}

void update(int value) {

    if(position > 6.0)
        position = -6.2f;

    position += bspeed;

    if(pos1 > 6.0)
        pos1 = -6.2f;

    pos1 += speed1;

    if(pos < -8.0)
        pos = 6.2f;

    pos -= speed;

    if(p < -8.0)
        p = 6.0f;

    p -=s;


    raining -= 0.5f;
	if(raining < (-0.3) && ron == 1){
        raining = 2.6;
	}

	raining2 -= 0.5f;
	if(raining2 < 1 && ron == 1){
        raining2 = 2.6;
	}

        if(b == 7 && Sun_down > 0.5){
        Sun_down -= 0.01f;
        Moon_rise -= 0.01f;
        Moon_down = Moon_rise;
        Sun_rise = Sun_down;

       }

        if(b == 8 && Sun_rise < 2.3 ){
        Sun_rise += 0.01f;
         Moon_down += 0.01f;
         Moon_rise = Moon_down;
        Sun_down = Sun_rise;
       }


	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

void init()
{
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void drawSun(){

       glPushMatrix();

    if( b == 0){
        glTranslatef(3.7,2.3,0);
    }
    if ( b == 7 ){
        glTranslatef(3.7,Sun_down,0);
    }

    if ( b == 8 ){
        glTranslatef(3.7,Sun_rise,0);
    }



	glBegin(GL_POLYGON);
	glColor3ub(209, 95, 38);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

glPopMatrix();

///sun end

}

void drawMoon(){

  glPushMatrix();

    if( b == 0){
        glTranslatef(3.7,3.3,0);
    }
    if ( b == 7 ){
        glTranslatef(3.7,Moon_rise,0);
    }

    if ( b == 8 ){
        glTranslatef(3.7,Moon_down,0);
    }


	glBegin(GL_POLYGON);
	glColor3ub(250, 250, 250);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
	glEnd();

    glPopMatrix();

}

void redBuildingOne()
{
    glPushMatrix();
    glTranslatef(-0.3,-0.1,0);
    glScalef(5.3,2.0,0);

    glBegin(GL_QUADS);
    glColor3f(0.863f, 0.078f, 0.235f);
    glVertex2f(-0.7f,-0.1f);
    glVertex2f(-0.7f, 0.3);         //building
    glVertex2f(-1.0f,0.3f);
    glVertex2f(-1.0f,-0.1f);

    glColor3f(0.545f, 0.271f, 0.075f);
    glVertex2f(-0.7f,0.3f);
    glVertex2f(-0.7f,0.5f);            //roof
    glVertex2f(-0.8f,0.5f);
    glVertex2f(-1.0f,0.3f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.91f,0.13f);
    glVertex2f(-0.91f, 0.25f);         //window
    glVertex2f(-0.96f,0.25f);
    glVertex2f(-0.96f,0.13f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.82f,0.13f);
    glVertex2f(-0.82f, 0.25f);         //window
    glVertex2f(-0.87f,0.25f);
    glVertex2f(-0.87f,0.13f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.73f,0.13f);
    glVertex2f(-0.73f, 0.25f);         //window
    glVertex2f(-0.78f,0.25f);
    glVertex2f(-0.78f,0.13f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.81f,-0.1f);
    glVertex2f(-0.81f, 0.06f);         //gate
    glVertex2f(-0.88f,0.06f);
    glVertex2f(-0.88f,-0.1f);

    glEnd();


    glPopMatrix();
    glPopMatrix();

}

void blueBuildingOne()
{
    glPushMatrix();
    glTranslatef(0.1,-0.1,0);
    glScalef(5.9,2.0,0);

    glBegin(GL_QUADS);
    glColor3f(0.000f, 0.000f, 0.804f);
    glVertex2f(-0.5f,-0.1f);
    glVertex2f(-0.5f,0.6f);     //building
    glVertex2f(-0.7f,0.6f);
    glVertex2f(-0.7f,-0.1f);

    glColor3f(0.36f,0.25f,0.20f);
    glVertex2f(-0.5f,0.6f);
    glVertex2f(-.4f,.8f);           //roof
    glVertex2f(-.65f,.8f);
    glVertex2f(-.75f,.6f);

    glColor3f(0.000f, 0.000f, 0.502f);
    glVertex2f(-.35f,.7f);
    glVertex2f(-.4f,.8f);           //side
    glVertex2f(-.5f,.6f);
    glVertex2f(-.5f,.55f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.62f,0.37f);
    glVertex2f(-0.62f, 0.54f);         //window
    glVertex2f(-0.68f,0.54f);
    glVertex2f(-0.68f,0.37f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.52f,0.37f);
    glVertex2f(-0.52f, 0.54f);         //window
    glVertex2f(-0.58f,0.54f);
    glVertex2f(-0.58f,0.37f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.62f,0.33f);
    glVertex2f(-0.62f, 0.16f);         //window
    glVertex2f(-0.68f,0.16f);
    glVertex2f(-0.68f,0.33f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.52f,0.33f);
    glVertex2f(-0.52f, 0.16f);         //window
    glVertex2f(-0.58f,0.16f);
    glVertex2f(-0.58f,0.33f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.56f,-0.1f);
    glVertex2f(-0.56f, 0.1f);         //gate
    glVertex2f(-0.64f,0.1f);
    glVertex2f(-0.64f,-0.1f);

    glEnd();

    glPopMatrix();
    glPopMatrix();

}

void yellowBuildingOne()
{
    glPushMatrix();
    glTranslatef(0.1,-0.1,0);
    glScalef(5.9,2.0,0);


    glBegin(GL_QUADS);

    glColor3f(0.855f, 0.647f, 0.125f);
    glVertex2f(-.3f,-.1f);
    glVertex2f(-.3f,.55f);           //building
    glVertex2f(-.5f,.55f);
    glVertex2f(-.5f,-.1f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.545f, 0.271f, 0.075f);
    glVertex2f(-.3f,.55f);
    glVertex2f(-.2f,.7f);       //roof
    glVertex2f(-.4f,.7f);
    glVertex2f(-.5f,.55f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.722f, 0.525f, 0.043f);
    glVertex2f(-.2f,.5f);
    glVertex2f(-.2f,.7f);
    glVertex2f(-.3f,.55f);          //side
    glVertex2f(-.3f,.3f);

    glEnd();
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.48f,0.3f);
    glVertex2f(-0.48f, 0.5f);         //window
    glVertex2f(-0.42f,0.5f);
    glVertex2f(-0.42f,0.3f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.38f,0.3f);
    glVertex2f(-0.38f, 0.5f);         //window
    glVertex2f(-0.32f,0.5f);
    glVertex2f(-0.32f,0.3f);

    glColor3f(0.0f, 0.0f, 0.f);
    glVertex2f(-0.36f,-0.1f);
    glVertex2f(-0.36f, 0.1f);         //gate
    glVertex2f(-0.44f,0.1f);
    glVertex2f(-0.44f,-0.1f);

    glEnd();

    glPopMatrix();
    glPopMatrix();

}

void blueBuildingTwo()
{
    glPushMatrix();
    glTranslatef(0.1,-0.1,0);
    glScalef(5.9,2.0,0);

    glBegin(GL_QUADS);

    glColor3f(0.000f, 0.000f, 0.804f);
    glVertex2f(0.0f,-.1f);
    glVertex2f(0.0f,.3f);           //building
    glVertex2f(-.3f,.3f);
    glVertex2f(-.3f,-.1f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.36f,0.25f,0.20f);
    glVertex2f(0.0f,.3f);
    glVertex2f(-.1f,.5f);       //roof
    glVertex2f(-.2f,.5f);
    glVertex2f(-.3f,.3f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.000f, 0.000f, 0.804f);
    glVertex2f(-.1,.3f);
    glVertex2f(-.1f,.4f);
    glVertex2f(-.2f,.4f);         //top
    glVertex2f(-.2f,.3f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.000f, 0.000f, 0.804f);
    glVertex2f(-.1f,.4f);
    glVertex2f(-.15f,.6f);
    glVertex2f(-.2f,.4f);     //triangleTop

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.824f, 0.412f, 0.118f);
    glVertex2f(-.26f,.26f);
    glVertex2f(-.26f,.2f);           //window
    glVertex2f(-.18f,.2f);
    glVertex2f(-.18f,.26f);

    glColor3f(0.824f, 0.412f, 0.118f);
    glVertex2f(-.04f,.26f);
    glVertex2f(-.04f,.2f);           //window
    glVertex2f(-.12f,.2f);
    glVertex2f(-.12f,.26f);

    glColor3f(0.824f, 0.412f, 0.118f);
    glVertex2f(-.09f,-.1f);
    glVertex2f(-.09f,.1f);           //gate
    glVertex2f(-.20f,.1f);
    glVertex2f(-.20f,-.1f);

    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void redBuildingTwo()
{
    glPushMatrix();
    glTranslatef(0.1,-0.1,0);
    glScalef(5.9,2.0,0);

    glBegin(GL_QUADS);
    glColor3f(1.000f, 0.894f, 0.710f); // bottom

    glVertex2f(.3f,-.1f);
    glVertex2f(.3f,.2f);
    glVertex2f(0.0f,.2f);
    glVertex2f(0.0f,-.1f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.545f, 0.000f, 0.000f); // top

    glVertex2f(.3f,.2f);
    glVertex2f(.3f,.6f);
    glVertex2f(0.0f,.6f);
    glVertex2f(0.0f,.2f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.824f, 0.412f, 0.118f); //roof

    glVertex2f(.3f,.6f);
    glVertex2f(.25f,.8f);
    glVertex2f(-.05f,.8f);
    glVertex2f(0.0f,.6f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);

    glVertex2f(0.0f,.6f);
    glVertex2f(-.05f,.8f);
    glVertex2f(-.1f,.5f);       //side
    glVertex2f(0.0f,.3f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.855f, 0.647f, 0.125f);
    glVertex2f(.21f,-.1f);
    glVertex2f(.21f,.12f);       //bottom gate
    glVertex2f(.1f,.12f);
    glVertex2f(.1f,-.1f);

    glColor3f(0.329f, 0.329f, 0.329f); // top window
    glVertex2f(.28f,.57f);
    glVertex2f(.28f,.43f);
    glVertex2f(0.22f,.43f);
    glVertex2f(0.22f,.57f);

    glColor3f(0.329f, 0.329f, 0.329f); // top window
    glVertex2f(.18f,.57f);
    glVertex2f(.18f,.43f);
    glVertex2f(0.12f,.43f);
    glVertex2f(0.12f,.57f);

    glColor3f(0.329f, 0.329f, 0.329f); // top window
    glVertex2f(.08f,.57f);
    glVertex2f(.08f,.43f);
    glVertex2f(0.02f,.43f);
    glVertex2f(0.02f,.57f);

    glColor3f(0.329f, 0.329f, 0.329f); // top window
    glVertex2f(.28f,.38f);
    glVertex2f(.28f,.24f);
    glVertex2f(0.22f,.24f);
    glVertex2f(0.22f,.38f);

    glColor3f(0.329f, 0.329f, 0.329f); // top window
    glVertex2f(.18f,.38f);
    glVertex2f(.18f,.24f);
    glVertex2f(0.12f,.24f);
    glVertex2f(0.12f,.38f);

    glColor3f(0.329f, 0.329f, 0.329f); // top window
    glVertex2f(.08f,.38f);
    glVertex2f(.08f,.24f);
    glVertex2f(0.02f,.24f);
    glVertex2f(0.02f,.38f);

    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void whiteBuildingOne()
{
    glPushMatrix();
    glTranslatef(0.05,-0.1,0);
    glScalef(5.9,2.0,0);

    glBegin(GL_QUADS);
    glColor3f(0.941f, 1.000f, 1.000f);

    glVertex2f(.5f,-.1f);
    glVertex2f(.5f,.55f);       //body
    glVertex2f(.3f,.55f);
    glVertex2f(.3f,-.1f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.545f, 0.271f, 0.075f);

    glVertex2f(.55f,.55f);
    glVertex2f(.4f,.8f);
    glVertex2f(.25f,.8f);
    glVertex2f(.3f,.55f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.44f,-.1f);
    glVertex2f(.44f,.12f);       //gate
    glVertex2f(.36f,.12f);
    glVertex2f(.36f,-.1f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.32f,.52f);
    glVertex2f(.32f,.4f);       //window
    glVertex2f(.38f,.4f);
    glVertex2f(.38f,.52f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.42f,.52f);
    glVertex2f(.42f,.4f);       //window
    glVertex2f(.48f,.4f);
    glVertex2f(.48f,.52f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.32f,.34f);
    glVertex2f(.32f,.22f);       //window
    glVertex2f(.38f,.22f);
    glVertex2f(.38f,.34f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.42f,.34f);
    glVertex2f(.42f,.22f);       //window
    glVertex2f(.48f,.22f);
    glVertex2f(.48f,.34f);

    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void greenBuildingOne()
{
    glPushMatrix();
    glTranslatef(0.5,-0.1,0);
    glScalef(5,2.1,0);

    glBegin(GL_QUADS);
    glColor3f(0.133f, 0.545f, 0.133f);

    glVertex2f(.8f,-.1f);
    glVertex2f(.8f,.3f);
    glVertex2f(.5f,.3f);    //body
    glVertex2f(.5f,-.1f);

    glColor3f(0.36f,0.25f,0.20f);
    glVertex2f(.85f,.3f);
    glVertex2f(.7f,.5f);
    glVertex2f(.5f,.5f);   //roof
    glVertex2f(.5f,.3f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.6f,-.1f);
    glVertex2f(.6f,.11f);       //gate
    glVertex2f(.7f,.11f);
    glVertex2f(.7f,-.1f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.52f,.26f);
    glVertex2f(.52f,.18f);       //window
    glVertex2f(.58f,.18f);
    glVertex2f(.58f,.26f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.62f,.26f);
    glVertex2f(.62f,.18f);       //window
    glVertex2f(.68f,.18f);
    glVertex2f(.68f,.26f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.72f,.26f);
    glVertex2f(.72f,.18f);       //window
    glVertex2f(.78f,.18f);
    glVertex2f(.78f,.26f);

    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void yellowBuildingTwo()
{
    glPushMatrix();
    glTranslatef(-0.08,-0.1,0);
    glScalef(5.65,2.1,0);

    glBegin(GL_QUADS);
    glColor3f(0.855f, 0.647f, 0.125f);

    glVertex2f(1.0f,-.1f);
    glVertex2f(1.0f,.5f);
    glVertex2f(.85f,.5f);             //body
    glVertex2f(.85f,-.1f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.545f, 0.271f, 0.075f);

    glVertex2f(1.0f,.5f);
    glVertex2f(1.0f,.7f);                   //roof
    glVertex2f(.75f,.7f);
    glVertex2f(.85f,.5f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.722f, 0.525f, 0.043f);

    glVertex2f(.85f,-.1f);
    glVertex2f(.85f,.3f);
    glVertex2f(.8f,.3f);
    glVertex2f(.8f,-.1f);       //side
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.722f, 0.525f, 0.043f);

    glVertex2f(.85f,.3f);
    glVertex2f(.85f,.5f);
    glVertex2f(.75f,.7f);
    glVertex2f(.75f,.3f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.89f,-.1f);
    glVertex2f(.89f,.11f);       //gate
    glVertex2f(.96f,.11f);
    glVertex2f(.96f,-.1f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.87f,.29f);
    glVertex2f(.87f,.17f);       //window
    glVertex2f(.92f,.17f);
    glVertex2f(.92f,.29f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.94f,.29f);
    glVertex2f(.94f,.17f);       //window
    glVertex2f(.99f,.17f);
    glVertex2f(.99f,.29f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.87f,.33f);
    glVertex2f(.87f,.45f);       //window
    glVertex2f(.92f,.45f);
    glVertex2f(.92f,.33f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(.94f,.33f);
    glVertex2f(.94f,.45f);       //window
    glVertex2f(.99f,.45f);
    glVertex2f(.99f,.33f);

    glEnd();

    glPopMatrix();
    glPopMatrix();

}

void sky()
{
    //glLoadIdentity();
    glPushMatrix();
    glTranslatef(-8,0,0);
    glScalef(20,4,1);
    glColor3ub(160, 193, 247);
    glBegin(GL_POLYGON);
    if(b == 8){glColor3ub(160, 193, 247);}
    if(b == 7){glColor3ub(0,0,0);}
	glVertex2f(-1.0f, 1.0f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(-1.0f, -1.0f);
	glEnd();
	glPopMatrix();
}

void road()
{
    glPushMatrix();
    glTranslatef(0,-0.1,0);
    glScalef(8.5,2.0,0);

    glBegin(GL_QUADS);
	glColor3f(0.7,0.7,0.7);
	glVertex2f(-1.0f, -0.1f);
	glVertex2f(1.0f, -0.1f);
	glVertex2f(1.0f, -0.6f);
	glVertex2f(-1.0f, -0.6f);
	glEnd();

    glPopMatrix();
    glPopMatrix();
}

void carOne()
{
    glPushMatrix();
    glTranslatef(0,-0.1,0);
    glScalef(4.5,1.5,0);

    glBegin(GL_QUADS);
    glColor3f(0.000f, 0.392f, 0.000f);

    glVertex2f(0.15,-0.2);
    glVertex2f(0.3,-0.2);
    glVertex2f(0.35,-0.3);
    glVertex2f(0.10,-0.3);       //top

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529f, 0.808f, 0.980f);  //window1

    glVertex2f(0.16,-0.21);
    glVertex2f(0.2,-0.21);
    glVertex2f(0.2,-0.3);
    glVertex2f(0.12,-0.3);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529f, 0.808f, 0.980f);  //window2

    glVertex2f(0.21,-0.21);
    glVertex2f(0.28,-0.21);
    glVertex2f(0.32,-0.3);
    glVertex2f(0.21,-0.3);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.000f, 0.392f, 0.000f);  //body

    glVertex2f(0.1,-0.3);
    glVertex2f(0.4,-0.3);
    glVertex2f(0.4,-0.4);
    glVertex2f(0.1,-0.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.000f, 0.388f, 0.278f);

    glVertex2f(0.37,-0.31);
    glVertex2f(0.39,-0.31);
    glVertex2f(0.39,-0.34);           //headlight
    glVertex2f(0.37,-0.34);

    glEnd();

    int i;

	GLfloat x=0.16f; GLfloat y=-0.4f; GLfloat radius =.05f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f,0.0f,0.0f);                          //tire1
    glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    int j;

	GLfloat x1=0.34f; GLfloat y1=-0.4f; GLfloat radius1 =.05f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f,0.0f,0.0f);                          //tire2
    glVertex2f(x1, y1); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            x1 + (radius1 * cos(j *  twicePi / triangleAmount1)),
			    y1 + (radius1 * sin(j * twicePi / triangleAmount1))
			);
		}
	glEnd();


    glPopMatrix();
}

void carTwo()
{
    glPushMatrix();
    glTranslatef(0,-0.2,0);
    glScalef(4.5,1.5,0);

    glBegin(GL_QUADS);
    glColor3f(0.294f, 0.000f, 0.510f);

    glVertex2f(0.55,-0.2);
    glVertex2f(0.7,-0.2);
    glVertex2f(0.75,-0.3);
    glVertex2f(0.5,-0.3);       //top

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529f, 0.808f, 0.980f);  //window1

    glVertex2f(0.56,-0.21);
    glVertex2f(0.61,-0.21);
    glVertex2f(0.61,-0.3);
    glVertex2f(0.51,-0.3);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529f, 0.808f, 0.980f);  //window2

    glVertex2f(0.62,-0.21);
    glVertex2f(0.69,-0.21);
    glVertex2f(0.74,-0.3);
    glVertex2f(0.62,-0.3);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.294f, 0.000f, 0.510f);  //body

    glVertex2f(0.45,-0.3);
    glVertex2f(0.8,-0.3);
    glVertex2f(0.8,-0.4);
    glVertex2f(0.45,-0.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.000f, 0.388f, 0.278f);

    glVertex2f(0.46,-0.31);
    glVertex2f(0.48,-0.31);
    glVertex2f(0.48,-0.34);           //headlight
    glVertex2f(0.46,-0.34);

    glEnd();

    int i;

	GLfloat x=0.55f; GLfloat y=-0.4f; GLfloat radius =.05f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f,0.0f,0.0f);                          //tire1
    glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    int j;

	GLfloat x1=0.72f; GLfloat y1=-0.4f; GLfloat radius1 =.05f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f,0.0f,0.0f);                          //tire2
    glVertex2f(x1, y1); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            x1 + (radius1 * cos(j *  twicePi / triangleAmount1)),
			    y1 + (radius1 * sin(j * twicePi / triangleAmount1))
			);
		}
	glEnd();


    glPopMatrix();
}

void displayCar()
{
    glPushMatrix();
    glTranslatef(pos1,0.2f, 0.0f);
    carOne();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(pos,0.0f, 0.0f);
    carTwo();
    glPopMatrix();

    glFlush();

}
void stairs()
{
    glPushMatrix();
    glTranslatef(0,-0.2,0);
    glScalef(8.5,1.2,0);

    //glLoadIdentity();
	glBegin(GL_QUADS);
	glColor3f(1,0.9,0.9);
	glVertex2f(-1.0f, -0.7f);
	glVertex2f(1.0f, -0.7f);
	glVertex2f(1.0f, -1.1f);
	glVertex2f(-1.0f, -1.1f);
	glEnd();

	glPopMatrix();
    glPopMatrix();
}

void waterBody()
{
    glPushMatrix();
    glTranslatef(-1.1,-0.7,0);
    glScalef(8.5,2.0,0);
    //glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3f(0.118f, 0.565f, 1.000f);
    glVertex2f(-1.0f,-0.4f);
    glVertex2f(1.0f,-0.4f);
    glVertex2f(1.0f,-1.1f);
    glVertex2f(-1.0f,-1.1f);

    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void boat1()
{
    glPushMatrix();
    glTranslatef(0,-0.9,0);
    glScalef(4,2.0,0);

    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.22f, -0.8f);
	glVertex2f(0.25f, -0.93f);
	glVertex2f(0.53f, -0.93f);
    glVertex2f(0.6f, -0.8f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.22f, -0.8f);
	glVertex2f(0.22f, -0.74f);
	glVertex2f(0.32f, -0.74f);
    glVertex2f(0.32f, -0.8f);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void boat()
{
    glPushMatrix();
    glTranslatef(0,-0.75,0);
    glScalef(4,2.0,0);

    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.2f, -0.6f);
	glVertex2f(-0.17f, -0.73f);
	glVertex2f(0.1f, -0.73f);
    glVertex2f(0.17f, -0.6f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.2f, -0.6f);
	glVertex2f(-0.2f, -0.54f);
	glVertex2f(-0.1f, -0.54f);
    glVertex2f(-0.1f, -0.6f);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void umbrellaone()
{
    glPushMatrix();
    glTranslatef(-2,-0.3,0);
    glScalef(3.5,3.0,0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.000f, 0.388f, 0.278f);

    glVertex2f(-1.0f,-0.2f);
    glVertex2f(-0.7f,-0.2f);
    glVertex2f(-0.85f,-0.1f);
    glEnd();


    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.545f, 0.271f, 0.075f);
	glVertex2f(-0.85f, -0.2f);
	glVertex2f(-0.85f, -0.4f);
	glEnd();
	glPopMatrix();
    glPopMatrix();

}


void chairOne()
{
    glPushMatrix();
    glTranslatef(-5.5,-1.0,0);
    glScalef(1.3,0.5,0);

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.0f,-0.95f); //leg_1
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.05f,-1.0f);
    glVertex2f(0.05f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.5f,-0.95f); //leg_2
    glVertex2f(0.5f,-1.0f);
    glVertex2f(0.55f,-1.0f);
    glVertex2f(0.55f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(-0.2f,-0.85f); //center plank
    glVertex2f(-0.2f,-0.95f);
    glVertex2f(0.65f,-0.95f);
    glVertex2f(0.65f,-0.85f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.7f,-0.6);
    glVertex2f(0.5f,-0.85f); //back rest
    glVertex2f(0.6f,-0.85f);
    glVertex2f(0.8f,-0.6f);
    glEnd();

	glPopMatrix();
    glPopMatrix();

}

void chairTwo()
{
    glPushMatrix();
    glTranslatef(-4,-1.0,0);
    glScalef(1.3,0.5,0);

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.0f,-0.95f); //leg_1
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.05f,-1.0f);
    glVertex2f(0.05f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.5f,-0.95f); //leg_2
    glVertex2f(0.5f,-1.0f);
    glVertex2f(0.55f,-1.0f);
    glVertex2f(0.55f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(-0.2f,-0.85f); //center plank
    glVertex2f(-0.2f,-0.95f);
    glVertex2f(0.65f,-0.95f);
    glVertex2f(0.65f,-0.85f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.7f,-0.6);
    glVertex2f(0.5f,-0.85f); //back rest
    glVertex2f(0.6f,-0.85f);
    glVertex2f(0.8f,-0.6f);
    glEnd();

	glPopMatrix();
    glPopMatrix();

}

void umbrellatwo()
{
    glPushMatrix();
    glTranslatef(-2,-0.3,0);
    glScalef(3.5,3.0,0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.863f, 0.078f, 0.235f);

    glVertex2f(-0.6f,-0.2f);
    glVertex2f(-0.3f,-0.2f);
    glVertex2f(-0.45f,-0.1f);
    glEnd();


    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.545f, 0.271f, 0.075f);
	glVertex2f(-0.45f, -0.2f);
	glVertex2f(-0.45f, -0.4f);
	glEnd();
	glPopMatrix();
    glPopMatrix();

}

void chairThree()
{
    glPushMatrix();
    glTranslatef(-2.5,-1.0,0);
    glScalef(1.3,0.5,0);

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.0f,-0.95f); //leg_1
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.05f,-1.0f);
    glVertex2f(0.05f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.5f,-0.95f); //leg_2
    glVertex2f(0.5f,-1.0f);
    glVertex2f(0.55f,-1.0f);
    glVertex2f(0.55f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(-0.2f,-0.85f); //center plank
    glVertex2f(-0.2f,-0.95f);
    glVertex2f(0.65f,-0.95f);
    glVertex2f(0.65f,-0.85f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.7f,-0.6);
    glVertex2f(0.5f,-0.85f); //back rest
    glVertex2f(0.6f,-0.85f);
    glVertex2f(0.8f,-0.6f);
    glEnd();

	glPopMatrix();
    glPopMatrix();

}

void umbrellathree()
{
    glPushMatrix();
    glTranslatef(-2,-0.3,0);
    glScalef(3.5,3.0,0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.000f, 0.388f, 0.278f);

    glVertex2f(-0.2f,-0.2f);
    glVertex2f(0.1f,-0.2f);
    glVertex2f(-0.05f,-0.1f);
    glEnd();


    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.545f, 0.271f, 0.075f);
	glVertex2f(-0.05f, -0.2f);
	glVertex2f(-0.05f, -0.4f);
	glEnd();
	glPopMatrix();
    glPopMatrix();

}

void chairFour()
{
    glPushMatrix();
    glTranslatef(-1.0,-1.0,0);
    glScalef(1.3,0.5,0);

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.0f,-0.95f); //leg_1
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.05f,-1.0f);
    glVertex2f(0.05f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.5f,-0.95f); //leg_2
    glVertex2f(0.5f,-1.0f);
    glVertex2f(0.55f,-1.0f);
    glVertex2f(0.55f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(-0.2f,-0.85f); //center plank
    glVertex2f(-0.2f,-0.95f);
    glVertex2f(0.65f,-0.95f);
    glVertex2f(0.65f,-0.85f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.7f,-0.6);
    glVertex2f(0.5f,-0.85f); //back rest
    glVertex2f(0.6f,-0.85f);
    glVertex2f(0.8f,-0.6f);
    glEnd();

	glPopMatrix();
    glPopMatrix();

}

void umbrellafour()
{
    glPushMatrix();
    glTranslatef(-2,-0.3,0);
    glScalef(3.5,3.0,0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.863f, 0.078f, 0.235f);

    glVertex2f(0.2f,-0.2f);
    glVertex2f(0.5f,-0.2f);
    glVertex2f(0.35f,-0.1f);
    glEnd();


    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.545f, 0.271f, 0.075f);
	glVertex2f(0.35f, -0.2f);
	glVertex2f(0.35f, -0.4f);
	glEnd();
	glPopMatrix();
    glPopMatrix();

}

void chairFive()
{
    glPushMatrix();
    glTranslatef(0.3,-1.0,0);
    glScalef(1.3,0.5,0);

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.0f,-0.95f); //leg_1
    glVertex2f(0.0f,-1.0f);
    glVertex2f(0.05f,-1.0f);
    glVertex2f(0.05f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.5f,-0.95f); //leg_2
    glVertex2f(0.5f,-1.0f);
    glVertex2f(0.55f,-1.0f);
    glVertex2f(0.55f,-0.95f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(-0.2f,-0.85f); //center plank
    glVertex2f(-0.2f,-0.95f);
    glVertex2f(0.65f,-0.95f);
    glVertex2f(0.65f,-0.85f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2f(0.7f,-0.6);
    glVertex2f(0.5f,-0.85f); //back rest
    glVertex2f(0.6f,-0.85f);
    glVertex2f(0.8f,-0.6f);
    glEnd();

	glPopMatrix();
    glPopMatrix();

}

void umbrellafive()
{
    glPushMatrix();
    glTranslatef(-2,-0.3,0);
    glScalef(3.5,3.0,0);

    glBegin(GL_TRIANGLES);
    glColor3f(1.000f, 0.388f, 0.278f);

    glVertex2f(0.6f,-0.2f);
    glVertex2f(0.9f,-0.2f);
    glVertex2f(0.75f,-0.1f);
    glEnd();


    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.545f, 0.271f, 0.075f);
	glVertex2f(0.75f, -0.2f);
	glVertex2f(0.75f, -0.4f);
	glEnd();
	glPopMatrix();
    glPopMatrix();

}

void cloud1()
{
    glPushMatrix();
    glTranslatef(-5,1,0);
    glScalef(9,2,0);
   // glLoadIdentity();
    int i;

	GLfloat x=.5f; GLfloat y=.8f; GLfloat radius =.05f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	   glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.55f; GLfloat b=.78f;

	glBegin(GL_TRIANGLE_FAN);
	   glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=.45f; GLfloat d=.78f;

	glBegin(GL_TRIANGLE_FAN);
	   glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.52f; GLfloat f=.75f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.6f; GLfloat h=.77f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glPopMatrix();
    glPopMatrix();

}

void rain(){

    glPushMatrix();
    glTranslatef(0,raining,0);

    glPushMatrix();/////////------ Rain Push 1
    glRotatef(30,-30,0,0);
    glTranslatef(0,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop
    glPushMatrix();/////////------ Rain Push-2
    glRotatef(30,-30,0,0);
    glTranslatef(-0,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-3
    glRotatef(30,-30,0,0);
    glTranslatef(1,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-4
    glRotatef(30,-30,0,0);
    glTranslatef(2,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-5
    glRotatef(30,-30,0,0);
    glTranslatef(3,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop



	glPushMatrix();/////////------ Rain Push-6
    glRotatef(30,-30,0,0);
    glTranslatef(4,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
        glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
        glEnd();
        glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-6
    glRotatef(30,-30,0,0);
    glTranslatef(5,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-7
    glRotatef(30,-30,0,0);
    glTranslatef(6,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


    glPushMatrix();/////////------ Rain Push-8
    glRotatef(30,-30,0,0);
    glTranslatef(7,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop

    glPopMatrix();////////////////////////////////////----------------------------- RAINING POP-------------------------------------------


    glPushMatrix();////////////////-----------------------------------RAINING _------------------------------------------------------------ step 2
    glTranslatef(0,raining2,0);

    glPushMatrix();/////////------ Rain Push-1
    glRotatef(30,-30,0,0);
    glTranslatef(0,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	 glPushMatrix();/////////------ Rain Push-2
    glRotatef(30,-30,0,0);
    glTranslatef(-0,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-3
    glRotatef(30,-30,0,0);
    glTranslatef(1,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-4
    glRotatef(30,-30,0,0);
    glTranslatef(2,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-5
    glRotatef(30,-30,0,0);
    glTranslatef(3,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop



	glPushMatrix();/////////------ Rain Push-6
    glRotatef(30,-30,0,0);
    glTranslatef(4,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
        glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
        glEnd();
        glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-6
    glRotatef(30,-30,0,0);
    glTranslatef(5,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


	glPushMatrix();/////////------ Rain Push-7
    glRotatef(30,-30,0,0);
    glTranslatef(6,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop


    glPushMatrix();/////////------ Rain Push-8
    glRotatef(30,-30,0,0);
    glTranslatef(7,-1.6,0);

    glPushMatrix();
    glTranslatef(-4.20,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.30,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-4.40,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.50,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.60,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.70,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

    glPushMatrix();
      glTranslatef(-4.80,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();


      glPushMatrix();
      glTranslatef(-4.90,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();

      glPushMatrix();
      glTranslatef(-5.00,-1.6,1);
        glBegin(GL_POLYGON);
       glColor3ub(160, 193, 247);
        glVertex3f(1.415,.4,0);
        glVertex3f(1.415,.7,0);
        glVertex3f(1.4,.7,0);
        glVertex3f(1.4,.4,0);
      glEnd();
      glPopMatrix();



	glPopMatrix();//////////////------- Rain Pop

    glPopMatrix();////////////////////////////////////----------------------------- RAINING POP-------------------------------------------


}
void displayboat() {

    //glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    boat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    boat1();
    glPopMatrix();
    glFlush();

}

void displayCloud() {

    //glLoadIdentity();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(p,0.0f, 0.0f);
    cloud1();
    glPopMatrix();


}

void displayCity()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units*/

    sky();
    drawSun();
    drawMoon();
    redBuildingOne();
    blueBuildingOne();
    yellowBuildingOne();
    blueBuildingTwo();
    redBuildingTwo();
    whiteBuildingOne();
    yellowBuildingTwo();
    greenBuildingOne();
    road();
    displayCar();
    carTwo();
    stairs();
    waterBody();
    displayboat();
    umbrellaone();
    chairOne();
    umbrellatwo();
    chairTwo();
    umbrellathree();
    chairThree();
    umbrellafour();
    chairFour();
    umbrellafive();
    chairFive();
    displayCloud();
    rain();

	glutSwapBuffers();

	//glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 1500);   // Set the window's initial width & height
    glutCreateWindow("Copenhagen"); // Create a window with the given title

	glutDisplayFunc(displayCity); // Register display callback handler for window re-paint
	glutReshapeFunc(handleResize);
	glutSpecialFunc(handleKeypress);
    glutTimerFunc(25, update, 0);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
