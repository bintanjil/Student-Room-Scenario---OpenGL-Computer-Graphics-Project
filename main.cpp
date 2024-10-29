#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include<mmsystem.h>
using namespace std;

float ucar1 = 0.0f;
float ucar2 = 0.0f;
float ucloud = 0.0f;
float uboat=0.0f;
float clock_angle1 = 0.0f;
float clock_angle2 = 0.0f;
float fan_angle1 = 0.0f;
float mill_angle = 0.0f;

int fan=0;
void update_fan(int value)
{


     if(fan==1)
     {
        fan_angle1-=5.0f;
        if(fan_angle1 > 360.0)
        {
            fan_angle1-=360;
        }
     }


    glutPostRedisplay();
    glutTimerFunc(2, update_fan, 0);
}


GLfloat _rain=0.0;


void update_cloud(int value)
{
    ucloud += 0.01;
    if(ucloud > 0)
    {
    ucloud = -30;
    }


    glutPostRedisplay();
    glutTimerFunc(2, update_cloud, 0);
}

void Rain(int value){


         _rain += 0.05f;

    glBegin(GL_POINTS);
    for(int i=1;i<=500;i++)
    {
        int x= rand() % 111 + (-18);
        int y=rand() % 115 + (-22);;

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+2,y-5);
        glEnd();
    }
    glutPostRedisplay();


	glutTimerFunc(2, Rain, 0);

    glFlush();


}
void rainy()
{
       Rain(0.0);

}


GLfloat _snow=0.0;
void Snow(int value) {

         _snow += 0.01f;

    glBegin(GL_QUADS);
    for (int i = 1; i <= 100; i++) {

        int x = rand() % 111 + (-18);
        int y = rand() % 123 + (-31);


        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(x, y);

        for (int angle = 0; angle <= 360; angle += 2) {
            float radians = angle * (3.14159 / 180.0);
            glVertex2f(x + sin(radians) * 0.5, y + cos(radians) * 0.5);
        }
        glEnd();

    }


    glutPostRedisplay();
    glutTimerFunc(20, Snow, 0);

    glFlush();
}

int car=0;
void update_car(int value)
{
     if(car==1)
     {
       ucar1 += 0.1;
    if(ucar1 > 75)
    {
    ucar1 = -50;
    }



    ucar2 -= 0.5;
    if(ucar2 < -80)
    {
    ucar2 = 33;
    }
     }


    glutPostRedisplay();
    glutTimerFunc(2, update_car, 0);
}



int bt=0;
void update_boat(int value)
{
    if(bt==1)
    {
         uboat += 0.05;
    if(uboat > 90)
    {
    uboat = -40;
    }



    }
    glutPostRedisplay();
    glutTimerFunc(2, update_boat, 0);


}


void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}


void room()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // Floor
	glColor3f(0.86f, 0.84f, 0.67f);
	glVertex2f(-100,100);
	glVertex2f(100,100);
	glVertex2f(100,-100);
	glVertex2f(-100,-100);
	glEnd();


    glBegin(GL_POLYGON); // Wall-1
	glColor3f(0.61f, 0.90f, 0.75f);
	glVertex2f(-85,100);
	glVertex2f(100,100);
	glVertex2f(100,-40);
	glVertex2f(-85,-40);
	glEnd();


	glBegin(GL_POLYGON); // Wall-2
	glColor3f(0.69f, 1.0f, 0.85f);
	glVertex2f(-100,100);
	glVertex2f(-85,100);
	glVertex2f(-85,-40);
	glVertex2f(-100,-70);
	glEnd();

}

void room_overwrite()
{
    glMatrixMode(GL_MODELVIEW);


    glBegin(GL_POLYGON); // Outer frame
	glColor3f(0.78f, 0.78f, 0.78f);
	glVertex2f(-20,95);
	glVertex2f(-18,95);
	glVertex2f(-18,-35);
	glVertex2f(-20,-35);
	glEnd();

	glBegin(GL_POLYGON); // wall-1
	glColor3f(0.61f, 0.90f, 0.75f);
	glVertex2f(-80,95);
	glVertex2f(-20,95);
	glVertex2f(-20,-35);
	glVertex2f(-80,-35);
	glEnd();



}


void window()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // Outer frame
	glColor3f(0.78f, 0.78f, 0.78f);
	glVertex2f(-20,95);
	glVertex2f(95,95);
	glVertex2f(95,-35);
	glVertex2f(-20,-35);
	glEnd();

	glBegin(GL_POLYGON); // Inner frame
	glColor3f(0.52f, 0.81f, 0.94f);
	glVertex2f(-18,91.5);
	glVertex2f(93,91.5);
	glVertex2f(93,-31.5);
	glVertex2f(-18,-31.5);
	glEnd();


}


void summer_sky_day()
{
    glBegin(GL_POLYGON);
	glColor3ub(132, 206, 239);
	glVertex2f(-18,91.5);
	glVertex2f(93,91.5);
	glVertex2f(93,0);
	glVertex2f(-18,0);
	glEnd();

}

void rainy_sky_day()
{
    glBegin(GL_POLYGON);
	glColor3ub(210, 210, 210);
	glVertex2f(-18,91.5);
	glVertex2f(93,91.5);
	glVertex2f(93,0);
	glVertex2f(-18,0);
	glEnd();

}

void sky_n8()
{
    glBegin(GL_POLYGON);
	glColor3ub(10, 19, 79);
	glVertex2f(-18,91.5);
	glVertex2f(93,91.5);
	glVertex2f(93,0);
	glVertex2f(-18,0);
	glEnd();

}

void winter_sky_day()
{
    glBegin(GL_POLYGON);
	glColor3ub(185, 255, 255);
	glVertex2f(-18,91.5);
	glVertex2f(93,91.5);
	glVertex2f(93,0);
	glVertex2f(-18,0);
	glEnd();
}



void table()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // Upper part 1
	glColor3f(0.42, 0.23, 0.14);
	glVertex2f(-85,15);
	glVertex2f(-30,15);
	glVertex2f(-22,0);
	glVertex2f(-95,0);
	glEnd();

	glBegin(GL_POLYGON); // Upper part 2
	glColor3f(0.80, 0.83, 0.83);
	glVertex2f(-95,0);
	glVertex2f(-22,0);
	glVertex2f(-22,-2);
	glVertex2f(-95,-2);
	glEnd();


	glBegin(GL_POLYGON); // Left part 1
	glColor3f(0.42, 0.23, 0.14);
	glVertex2f(-92,-2);
	glVertex2f(-90.5,-2);
	glVertex2f(-90.5,-60);
	glVertex2f(-92,-60);
	glEnd();

	glBegin(GL_POLYGON); // Left part 2
	glColor3f(0.74, 0.76, 0.76);
	glVertex2f(-90.5,-2);
	glVertex2f(-82.5,-2);
	glVertex2f(-82.5,-43);
	glVertex2f(-90.5,-60);
	glEnd();


	glBegin(GL_POLYGON); // Right part 1
	glColor3f(0.42, 0.23, 0.14);
	glVertex2f(-40,-2);
	glVertex2f(-25,-2);
	glVertex2f(-25,-60);
	glVertex2f(-40,-60);
	glEnd();

	glBegin(GL_POLYGON); // Right part 2
	glColor3f(0.74, 0.76, 0.76);
	glVertex2f(-48,-2);
	glVertex2f(-40,-2);
	glVertex2f(-40,-60);
	glVertex2f(-48,-43);
	glEnd();


	glBegin(GL_POLYGON); // Back part
	glColor3f(0.32, 0.17, 0.06);
	glVertex2f(-82.5,-2);
	glVertex2f(-48,-2);
	glVertex2f(-48,-30);
	glVertex2f(-82.5,-30);
	glEnd();



    //shelf

	glLineWidth(2);

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-40, -17);
	glVertex2f(-25, -17);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-40, -32);
	glVertex2f(-25, -32);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-40, -47);
	glVertex2f(-25, -47);
	glEnd();



	// hook

	glLineWidth(5);

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-33.5, -13);
	glVertex2f(-30.5, -13);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-33.5, -28);
	glVertex2f(-30.5, -28);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-33.5, -43);
	glVertex2f(-30.5, -43);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-33.5, -56);
	glVertex2f(-30.5, -56);
	glEnd();

}

void table_fan()
{
    glBegin(GL_POLYGON); // base
	glColor3ub(81, 81, 81);
	glVertex2f(-87,9);
	glVertex2f(-81,9);
	glVertex2f(-80,6);
	glVertex2f(-88,6);
	glEnd();

	glBegin(GL_POLYGON); // base 2
	glColor3ub(43, 43, 43);
	glVertex2f(-88,6);
	glVertex2f(-80,6);
	glVertex2f(-80,3);
	glVertex2f(-88,3);
	glEnd();

	glBegin(GL_POLYGON); // stand
	glColor3ub(43, 43, 43);
	glVertex2f(-84.5,30);
	glVertex2f(-83.5,30);
	glVertex2f(-83,7.5);
	glVertex2f(-85,7.5);
	glEnd();



	circle(3, -84, 30, 0.32, 0.32, 0.32);

	glPushMatrix();
	glTranslatef(-84,30,0);
    glRotatef(fan_angle1, 0.0f, 0.0f, 1.0);


	glBegin(GL_POLYGON); // blade 1
	glColor3ub(31, 0, 0);
	glVertex2f(-1.5, 10);
	glVertex2f(1.5, 10);
	glVertex2f(0.3, 0);
	glVertex2f(-0.3, 0);
	glEnd();


	glBegin(GL_POLYGON); // blade 2
	glColor3ub(31, 0, 0);
	glVertex2f(0.0, 0.3);
	glVertex2f(10, 1.5);
	glVertex2f(10, -1.5);
	glVertex2f(0.0, -0.3);
	glEnd();

	glBegin(GL_POLYGON); // blade 3
	glColor3ub(31, 0, 0);
	glVertex2f(-1.5, -10);
	glVertex2f(1.5, -10);
	glVertex2f(0.3, 0);
	glVertex2f(-0.3, 0);
	glEnd();

	glBegin(GL_POLYGON); // blade 4
	glColor3ub(31, 0, 0);
	glVertex2f(0.0, 0.3);
	glVertex2f(-10, 1.5);
	glVertex2f(-10, -1.5);
	glVertex2f(0.0, -0.3);
	glEnd();



	glPopMatrix();

	circle(2, -84, 30, 0.14, 0, 0);



}


void monitor()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // Stand lower part 1
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-60, 14);
	glVertex2f(-56,14);
	glVertex2f(-53,11);
	glVertex2f(-63,11);
	glEnd();

	glBegin(GL_POLYGON); // Stand lower part 2
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-63,11);
	glVertex2f(-53,11);
	glVertex2f(-53,10);
	glVertex2f(-63,10);
	glEnd();

	glBegin(GL_POLYGON); // Stand upper part
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-58.6, 25);
	glVertex2f(-57.4,25);
	glVertex2f(-57.4,14);
	glVertex2f(-58.6,14);
	glEnd();

	glBegin(GL_POLYGON); // display outer part
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-72, 55);
	glVertex2f(-44,55);
	glVertex2f(-44,25);
	glVertex2f(-72,25);
	glEnd();

	glBegin(GL_POLYGON); // display inner part
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-71.5, 54);
	glVertex2f(-44.5,54);
	glVertex2f(-44.5,26);
	glVertex2f(-71.5,26);
	glEnd();

	// red light

	glLineWidth(2);

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-44.7, 25.7);
	glVertex2f(-44.4, 25.7);
	glEnd();
}

void pc()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // pc tempered glass
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-41, 50);
	glVertex2f(-36,42);
	glVertex2f(-36,5);
	glVertex2f(-41,13);
	glEnd();


	glBegin(GL_POLYGON); // pc front
	glColor3f(0.35, 0.35, 0.35);
	glVertex2f(-36,42);
	glVertex2f(-27,42);
	glVertex2f(-27,5);
	glVertex2f(-36,5);
	glEnd();


	glBegin(GL_POLYGON); // pc upper part
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(-41,50);
	glVertex2f(-34,50);
	glVertex2f(-27,42);
	glVertex2f(-36,42);
	glEnd();


	glBegin(GL_POLYGON); //PC front design
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-36, 37);
	glVertex2f(-27, 37);
	glVertex2f(-27, 32);
	glVertex2f(-36, 32);
	glEnd();

	// red light

	glLineWidth(3);

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-27.7, 33);
	glVertex2f(-27.4, 33);
	glEnd();

}

void speaker()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // hub front 1
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-79.5,25);
	glVertex2f(-74,25);
	glVertex2f(-74,10);
	glVertex2f(-79.5,10);
	glEnd();

	glBegin(GL_POLYGON); // hub front 2
	glColor3f(0.25, 0.25, 0.25);
	glVertex2f(-79,23);
	glVertex2f(-74.5,23);
	glVertex2f(-74.5,19);
	glVertex2f(-79,19);
	glEnd();

	// red light

	glLineWidth(3);

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-78, 20);
	glVertex2f(-77.7, 20);
	glEnd();

	glBegin(GL_POLYGON); // hub right
	glColor3f(0.35, 0.35, 0.35);
	glVertex2f(-74,25);
	glVertex2f(-73,27);
	glVertex2f(-73,12);
	glVertex2f(-74,10);
	glEnd();

	glBegin(GL_POLYGON); // hub up
	glColor3f(0.25, 0.25, 0.25);
	glVertex2f(-77.5,27);
	glVertex2f(-73,27);
	glVertex2f(-74,25);
	glVertex2f(-79.5,25);
	glEnd();

	circle(1,-75.5,21.5,0,0,0); // volume controller

	glBegin(GL_POLYGON); // lest speaker body
	glColor3f(0.25, 0.25, 0.25);
	glVertex2f(-70,20);
	glVertex2f(-66.5,20);
	glVertex2f(-66.5,10);
	glVertex2f(-70,10);
	glEnd();

	circle(1.7,-68.25,15,0,0,0); // lest speaker
	circle(1.4,-68.25,15,0.35,0.35,0.35); // lest speaker
	circle(0.5,-68.25,15,0,0,0); // lest speaker


	glBegin(GL_POLYGON); // right speaker body
	glColor3f(0.25, 0.25, 0.25);
	glVertex2f(-50,20);
	glVertex2f(-46.5,20);
	glVertex2f(-46.5,10);
	glVertex2f(-50,10);
	glEnd();

	circle(1.7,-48.25,15,0,0,0); // right speaker
	circle(1.4,-48.25,15,0.35,0.35,0.35); // right speaker
	circle(0.5,-48.25,15,0,0,0); // right speaker

}

void keybord()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // 1
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-67,8);
	glVertex2f(-53,8);
	glVertex2f(-50,4);
	glVertex2f(-70,4);
	glEnd();

	glBegin(GL_POLYGON); // 2
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-70,4);
	glVertex2f(-50,4);
	glVertex2f(-50,3);
	glVertex2f(-70,3);
	glEnd();

}

void mouse()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // mouse pad
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-51,8);
	glVertex2f(-41,8);
	glVertex2f(-36,2);
	glVertex2f(-47,2);
	glEnd();
}




void update_clock1(int value) {




    clock_angle1+=24.0f;
    if(clock_angle1 > 360.0)
    {
        clock_angle1-=360;
    }
    glutPostRedisplay();


    glutTimerFunc(20, update_clock1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_clock2(int value) {




    clock_angle2+=4.0f;
    if(clock_angle2 > 360.0)
    {
        clock_angle2-=360;
    }
    glutPostRedisplay();




    glutTimerFunc(20, update_clock2, 0); //Notify GLUT to call update again in 25 milliseconds
}

void clock()
{
    glMatrixMode(GL_MODELVIEW);

    circle(7,-57,90,0.35,0.35,0.35); // outer
    circle(6,-57,90,1,1,0.82); // inner
    circle(0.5,-57,90,0,0,0); // inner

    // lines

    glLineWidth(2);

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-62.7, 90);
	glVertex2f(-61.7, 90);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-52.3, 90);
	glVertex2f(-51.3, 90);
	glEnd();

	glLineWidth(2);

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-57, 95.5);
	glVertex2f(-57, 94);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-57, 86);
	glVertex2f(-57, 84.3);
	glEnd();

	glPushMatrix();
	glTranslatef(-57,90,0);
    glRotatef(-clock_angle1, 0.0f, 0.0f, 1.0);

	glLineWidth(3); // hour
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0, 0);
	glVertex2f(0, 5);
	glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-57,90,0);
    glRotatef(-clock_angle2, 0.0f, 0.0f,1.0f);

    glLineWidth(5); // hour
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0, 0);
	glVertex2f(0, 3);
	glEnd();

	glLineWidth(2); // minute



	glPopMatrix();

}


void small_Table()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // upper part 1
	glColor3f(0.42, 0.23, 0.14);
	glVertex2f(55,-25);
	glVertex2f(35,-25);
	glVertex2f(30,-30);
	glVertex2f(60,-30);
	glEnd();

	glBegin(GL_POLYGON); // upper part 2
	glColor3f(0.38, 0.17, 0.06);
	glVertex2f(30,-32);
	glVertex2f(60,-32);
	glVertex2f(60,-30);
	glVertex2f(30,-30);
	glEnd();


	glBegin(GL_POLYGON); // body
	glColor3f(0.32, 0.17, 0.06);
	glVertex2f(43,-32);
	glVertex2f(47,-32);
	glVertex2f(47,-45);
	glVertex2f(43,-45);
	glEnd();


	glBegin(GL_POLYGON); // stand 1
	glColor3f(0.32, 0.17, 0.06);
	glVertex2f(49,-43);
	glVertex2f(41,-43);
	glVertex2f(40,-47);
	glVertex2f(50,-47);
	glEnd();

	glBegin(GL_POLYGON); // stand 2
	glColor3f(0.32, 0.17, 0.06);
	glVertex2f(40,-47);
	glVertex2f(50,-47);
	glVertex2f(50,-49);
	glVertex2f(40,-49);
	glEnd();
}

void coffee()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // upper part 1
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(47.5,-18);
	glVertex2f(42.5,-18);
	glVertex2f(42.5,-26);
	glVertex2f(47.5,-26);
	glEnd();

	circle(2.5, 45, -26, 0.6, 0.6, 0.6);
	circle(2.5, 45, -18, 0.5, 0.5, 0.5);

}

void mojo()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // upper part 1
	glColor3f(0.14, 0.04, 0.0);
	glVertex2f(46,-15);
	glVertex2f(43,-15);
	glVertex2f(43,-26);
	glVertex2f(46,-26);
	glEnd();


	circle(1.5, 44.5, -26, 0.14, 0.04, 0.0);

	glBegin(GL_POLYGON); // upper part 1
	glColor3f(0.14, 0.04, 0.0);
	glVertex2f(45,-10);
	glVertex2f(44,-10);
	glVertex2f(43,-15);
	glVertex2f(46,-15);
	glEnd();

	glBegin(GL_POLYGON); // upper part 1
	glColor3f(0.53, 0.04, 0.0);
	glVertex2f(45,-8.5);
	glVertex2f(44,-8.5);
	glVertex2f(44,-10);
	glVertex2f(45,-10);
	glEnd();

	glBegin(GL_POLYGON); // upper part 1
	glColor3f(0.53, 0.04, 0.0);
	glVertex2f(46,-15);
	glVertex2f(43,-15);
	glVertex2f(43,-20);
	glVertex2f(46,-20);
	glEnd();

}

void chair()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // back rest main
	glColor3f(0.47, 0.06, 0.0);
	glVertex2f(-75,5);
	glVertex2f(-55,5);
	glVertex2f(-55,-35);
	glVertex2f(-75,-35);
	glEnd();

	glBegin(GL_POLYGON); // back rest upper
	glColor3f(0.65, 0.06, 0.0);
	glVertex2f(-74,6.5);
	glVertex2f(-56,6.5);
	glVertex2f(-55,5);
	glVertex2f(-75,5);
	glEnd();

	glBegin(GL_POLYGON); // sit
	glColor3f(0.43, 0.24, 0.16);
	glVertex2f(-77,-35);
	glVertex2f(-53,-35);
	glVertex2f(-53,-38);
	glVertex2f(-77,-38);
	glEnd();

	glBegin(GL_POLYGON); // sit left
	glColor3f(0.43, 0.24, 0.16);
	glVertex2f(-77,-35);
	glVertex2f(-75,-35);
	glVertex2f(-75,-32);
	glEnd();

	glBegin(GL_POLYGON); // sit right
	glColor3f(0.43, 0.24, 0.16);
	glVertex2f(-55,-35);
	glVertex2f(-53,-35);
	glVertex2f(-55,-32);
	glEnd();

	glBegin(GL_POLYGON); // front left leg
	glColor3f(0.43, 0.24, 0.16);
	glVertex2f(-72,-38);
	glVertex2f(-69.5,-38);
	glVertex2f(-69.5,-68);
	glVertex2f(-72,-68);
	glEnd();

	glBegin(GL_POLYGON); // front left leg 2
	glColor3f(0.37, 0.20, 0.16);
	glVertex2f(-69.5,-38);
	glVertex2f(-68.5,-38);
	glVertex2f(-68.5,-66);
	glVertex2f(-69.5,-68);
	glEnd();


	glBegin(GL_POLYGON); // front right leg
	glColor3f(0.43, 0.24, 0.16);
	glVertex2f(-58,-38);
	glVertex2f(-60.5,-38);
	glVertex2f(-60.5,-68);
	glVertex2f(-58,-68);
	glEnd();


	glBegin(GL_POLYGON); // front right leg 2
	glColor3f(0.37, 0.20, 0.16);
	glVertex2f(-60.5,-38);
	glVertex2f(-61.5,-38);
	glVertex2f(-61.5,-66);
	glVertex2f(-60.5,-68);
	glEnd();

	glBegin(GL_POLYGON); // back left leg
	glColor3f(0.43, 0.24, 0.16);
	glVertex2f(-75,-38);
	glVertex2f(-72.5,-38);
	glVertex2f(-72.5,-73);
	glVertex2f(-75,-73);
	glEnd();

	glBegin(GL_POLYGON); // back left leg 2
	glColor3f(0.37, 0.20, 0.16);
	glVertex2f(-72.5,-38);
	glVertex2f(-71.5,-38);
	glVertex2f(-71.5,-71);
	glVertex2f(-72.5,-73);
	glEnd();


	glBegin(GL_POLYGON); // back right leg
	glColor3f(0.43, 0.24, 0.16);
	glVertex2f(-55,-38);
	glVertex2f(-57.5,-38);
	glVertex2f(-57.5,-73);
	glVertex2f(-55,-73);
	glEnd();


	glBegin(GL_POLYGON); // back right leg 2
	glColor3f(0.37, 0.20, 0.16);
	glVertex2f(-58.5,-38);
	glVertex2f(-57.5,-38);
	glVertex2f(-57.5,-73);
	glVertex2f(-58.5,-71);
	glEnd();

	glBegin(GL_POLYGON); // extra wood
	glColor3f(0.49, 0.28, 0.16);
	glVertex2f(-72.5,-38);
	glVertex2f(-57.5,-38);
	glVertex2f(-57.5,-45);
	glVertex2f(-72.5,-45);
	glEnd();

}

void couch()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // couch sit
	glColor3f(0.58, 0.30, 0.0);
	glVertex2f(97,-27);
	glVertex2f(55,-27);
	glVertex2f(55,-67);
	glVertex2f(97,-67);
	glEnd();

	glBegin(GL_POLYGON); // couch back rest
	glColor3f(0.58, 0.30, 0.0);
	glVertex2f(92,-7);
	glVertex2f(60,-7);
	glVertex2f(60,-27);
	glVertex2f(92,-27);
	glEnd();

	glBegin(GL_POLYGON); // couch back rest 2
	glColor3f(0.64, 0.36, 0.0);
	glVertex2f(90.5,-4.5);
	glVertex2f(61.5,-4.5);
	glVertex2f(60,-7);
	glVertex2f(92,-7);
	glEnd();

	glBegin(GL_POLYGON); // couch left hand rest
	glColor3f(0.64, 0.36, 0.0);
	glVertex2f(94,-23);
	glVertex2f(92,-23);
	glVertex2f(92,-27);
	glVertex2f(97,-27);
	glEnd();

	glBegin(GL_POLYGON); // couch right hand rest
	glColor3f(0.64, 0.36, 0.0);
	glVertex2f(58,-23);
	glVertex2f(60,-23);
	glVertex2f(60,-27);
	glVertex2f(55,-27);
	glEnd();

	glBegin(GL_POLYGON); // couch left leg
	glColor3f(0.38, 0.17, 0.06);
	glVertex2f(60,-67);
	glVertex2f(63,-67);
	glVertex2f(63,-73);
	glVertex2f(60,-73);
	glEnd();

	glBegin(GL_POLYGON); // couch right leg
	glColor3f(0.38, 0.17, 0.06);
	glVertex2f(89,-67);
	glVertex2f(92,-67);
	glVertex2f(92,-73);
	glVertex2f(89,-73);
	glEnd();

}

void road()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // road side
	glColor3f(0.20, 0.20, 0.20);
	glVertex2f(-18,-0.5);
	glVertex2f(-18,2);
	glVertex2f(91,2);
	glVertex2f(91,-0.5);
	glEnd();

	glBegin(GL_POLYGON); // road side
	glColor3f(0.35, 0.35, 0.35);
	glVertex2f(-18,2);
	glVertex2f(-18,3);
	glVertex2f(91,3);
	glVertex2f(91,2);
	glEnd();

	glBegin(GL_POLYGON); // road yellow stripe
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-15,-0.5);
	glVertex2f(-15,2);
	glVertex2f(-14,2);
	glVertex2f(-14,-0.5);
	glEnd();

	glBegin(GL_POLYGON); // road yellow stripe 2
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-15,2);
	glVertex2f(-15.5,3);
	glVertex2f(-14.5,3);
	glVertex2f(-14,2);
	glEnd();


	glBegin(GL_POLYGON); // road yellow stripe
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-5, -0.5);
    glVertex2f(-5, 2);
    glVertex2f(-4, 2);
    glVertex2f(-4, -0.5);
    glEnd();

    glBegin(GL_POLYGON); // road yellow stripe 2
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-5, 2);
    glVertex2f(-5.5, 3);
    glVertex2f(-4.5, 3);
    glVertex2f(-4, 2);
    glEnd();

    glBegin(GL_POLYGON); // road yellow stripe
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(5, -0.5);
    glVertex2f(5, 2);
    glVertex2f(6, 2);
    glVertex2f(6, -0.5);
    glEnd();

    glBegin(GL_POLYGON); // road yellow stripe 2
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(5, 2);
    glVertex2f(4.5, 3);
    glVertex2f(5.5, 3);
    glVertex2f(6, 2);
    glEnd();

    glBegin(GL_POLYGON); // road yellow stripe
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(15, -0.5);
    glVertex2f(15, 2);
    glVertex2f(16, 2);
    glVertex2f(16, -0.5);
    glEnd();

    glBegin(GL_POLYGON); // road yellow stripe 2
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(15, 2);
    glVertex2f(14.5, 3);
    glVertex2f(15.5, 3);
    glVertex2f(16, 2);
    glEnd();


    glBegin(GL_POLYGON); // road yellow stripe
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(25, -0.5);
    glVertex2f(25, 2);
    glVertex2f(26, 2);
    glVertex2f(26, -0.5);
    glEnd();

    glBegin(GL_POLYGON); // road yellow stripe 2
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(25, 2);
    glVertex2f(24.5, 3);
    glVertex2f(25.5, 3);
    glVertex2f(26, 2);
    glEnd();

    glBegin(GL_POLYGON); // road yellow stripe
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(35, -0.5);
    glVertex2f(35, 2);
    glVertex2f(36, 2);
    glVertex2f(36, -0.5);
glEnd();

glBegin(GL_POLYGON); // road yellow stripe 2
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(35, 2);
    glVertex2f(34.5, 3);
    glVertex2f(35.5, 3);
    glVertex2f(36, 2);
glEnd();

glBegin(GL_POLYGON); // road yellow stripe
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(45, -0.5);
    glVertex2f(45, 2);
    glVertex2f(46, 2);
    glVertex2f(46, -0.5);
glEnd();

glBegin(GL_POLYGON); // road yellow stripe 2
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(45, 2);
    glVertex2f(44.5, 3);
    glVertex2f(45.5, 3);
    glVertex2f(46, 2);
glEnd();


glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(55, -0.5);
    glVertex2f(55, 2);
    glVertex2f(56, 2);
    glVertex2f(56, -0.5);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(55, 2);
    glVertex2f(54.5, 3);
    glVertex2f(55.5, 3);
    glVertex2f(56, 2);
glEnd();


glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(65, -0.5);
    glVertex2f(65, 2);
    glVertex2f(66, 2);
    glVertex2f(66, -0.5);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(65, 2);
    glVertex2f(64.5, 3);
    glVertex2f(65.5, 3);
    glVertex2f(66, 2);
glEnd();


glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(75, -0.5);
    glVertex2f(75, 2);
    glVertex2f(76, 2);
    glVertex2f(76, -0.5);
glEnd();

glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(75, 2);
    glVertex2f(74.5, 3);
    glVertex2f(75.5, 3);
    glVertex2f(76, 2);
glEnd();

    glBegin(GL_POLYGON); // main
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex2f(-18,-0.5);
	glVertex2f(-18,-28.5);
	glVertex2f(91,-28.5);
	glVertex2f(91,-0.5);
	glEnd();



	glBegin(GL_POLYGON); // stripe
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-18,-13);
	glVertex2f(-18,-14.5);
	glVertex2f(91,-14.5);
	glVertex2f(91,-13);
	glEnd();

}

void greenField_day_summer()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); //grass down
    glColor3ub(0.0, 130, 0.0);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,-0.5);
    glVertex2f(-18,-0.5);
    glEnd();

    glBegin(GL_POLYGON); //grass down
    glColor3ub(0.0, 130, 0.0);
    glVertex2f(43,15.5);
    glVertex2f(50,18.5);
    glVertex2f(91,18.5);
    glVertex2f(70,15.5);
    glEnd();


    glBegin(GL_POLYGON); //grass up
    glColor3ub(0.0, 130, 0.0);
    glVertex2f(-18,60.5);
    glVertex2f(91,60.5);
    glVertex2f(91,43.5);
    glVertex2f(15,43.5);
    glVertex2f(10,42.5);
    glVertex2f(-18,42.5);
    glEnd();
}

void greenField_winter()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); //grass down
    glColor3ub(230, 255, 255);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,-0.5);
    glVertex2f(-18,-0.5);
    glEnd();

    glBegin(GL_POLYGON); //grass down
    glColor3ub(230, 255, 255);
    glVertex2f(43,15.5);
    glVertex2f(50,18.5);
    glVertex2f(91,18.5);
    glVertex2f(70,15.5);
    glEnd();


    glBegin(GL_POLYGON); //grass up
    glColor3ub(230, 255, 255);
    glVertex2f(-18,60.5);
    glVertex2f(91,60.5);
    glVertex2f(91,43.5);
    glVertex2f(15,43.5);
    glVertex2f(10,42.5);
    glVertex2f(-18,42.5);
    glEnd();
}



void greenField_night_summer()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); //grass down
    glColor3ub(0.0, 95, 0.0);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,-0.5);
    glVertex2f(-18,-0.5);
    glEnd();

    glBegin(GL_POLYGON); //grass down
    glColor3ub(0.0, 95, 0.0);
    glVertex2f(43,15.5);
    glVertex2f(50,18.5);
    glVertex2f(91,18.5);
    glVertex2f(70,15.5);
    glEnd();


    glBegin(GL_POLYGON); //grass up
    glColor3ub(0.0, 95, 0.0);
    glVertex2f(-18,60.5);
    glVertex2f(91,60.5);
    glVertex2f(91,43.5);
    glVertex2f(15,43.5);
    glVertex2f(10,42.5);
    glVertex2f(-18,42.5);
    glEnd();
}

void summer_day_river()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON);
    glColor3ub(51, 153, 255);
    glVertex2f(-18,43.5);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,43.5);
    glEnd();

}


void summer_night_river()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON);
    glColor3ub(31, 51, 156);
    glVertex2f(-18,43.5);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,43.5);
    glEnd();

}

void rainy_day_river()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON);
    glColor3ub(120, 155, 150);
    glVertex2f(-18,43.5);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,43.5);
    glEnd();

}

void rainy_night_river()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON);
    glColor3ub(49, 75, 98);
    glVertex2f(-18,43.5);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,43.5);
    glEnd();

}

void winter_day_river()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON);
    glColor3ub(121, 191, 206);
    glVertex2f(-18,43.5);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,43.5);
    glEnd();

}

void winter_night_river()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON);
    glColor3ub(121, 161, 191);
    glVertex2f(-18,43.5);
    glVertex2f(-18,17.5);
    glVertex2f(91,17.5);
    glVertex2f(91,43.5);
    glEnd();

}



void Star()

{

    circle(0.2,-16,90,1,1,1);
    circle(0.21,-13,90.75,1,1,1);
    circle(0.18,-10,90.5,1,1,1);
    circle(0.17,-9,89.6,1,1,1);

    circle(0.2,-16,85,1,1,1);
    circle(0.21,-13,84.75,1,1,1);
    circle(0.18,-10,82.5,1,1,1);
    circle(0.17,-9,87.6,1,1,1);

    circle(0.15,-3,90.,1,1,1);
    circle(0.16,0,90,1,1,1);
    circle(0.2,5,89,1,1,1);
    circle(0.21,7,90,1,1,1);

    circle(0.15,-3,86.,1,1,1);
    circle(0.16,0,87,1,1,1);
    circle(0.2,5,89,1,1,1);
    circle(0.21,7,85,1,1,1);

    circle(0.14,26,90.33,1,1,1);
    circle(0.17,29,88,1,1,1);
    circle(0.2,-10,90,1,1,1);
    circle(0.14,33,86,1,1,1);
    circle(0.2,37,86,1,1,1);
    circle(0.1,40,87,1,1,1);

    circle(0.15,33,90,1,1,1);
    circle(0.17,36,90,1,1,1);
    circle(0.16,27,90,1,1,1);
    circle(0.2,47,86,1,1,1);
    circle(0.1,50,86,1,1,1);
    circle(0.11,53,90,1,1,1);
    circle(0.14,56,88,1,1,1);
    circle(0.16,60,88.17,1,1,1);

    circle(0.11,60,82,1,1,1);
    circle(0.1,63,90,1,1,1);
    circle(0.2,21,87,1,1,1);
    circle(0.13,67,90,1,1,1);

    circle(0.20,67,90,1,1,1);

    circle(0.16,70,90,1,1,1);

    circle(0.10,26,90,1,1,1);

    circle(0.11,40,90,1,1,1);

    circle(0.12,45,90,1,1,1);


    circle(0.17,16,90,1,1,1);

    circle(0.12,15,90,1,1,1);

    circle(0.16,-3,90,1,1,1);

}

void window_Grill()
{
    glMatrixMode(GL_MODELVIEW);

    // grill horizontal

	glLineWidth(3);

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(-18, 70);
	glVertex2f(92, 70);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(-18, 45);
	glVertex2f(92, 45);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(-18, 20);
	glVertex2f(92, 20);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(-18, -5);
	glVertex2f(92, -5);
	glEnd();



	 // grill vertical

	glLineWidth(3);

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(75, 91.5);
	glVertex2f(75, -30.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(55, 91.5);
	glVertex2f(55, -30.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(35, 91.5);
	glVertex2f(35, -30.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(15, 91.5);
	glVertex2f(15, -30.5);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(102, 102, 102);
	glVertex2f(-5, 91.5);
	glVertex2f(-5, -30.5);
	glEnd();


	glBegin(GL_POLYGON); // extension 1
	glColor3f(0.86f, 0.84f, 0.67f);
	glVertex2f(-18,-28.5);
	glVertex2f(93,-28.5);
	glVertex2f(93,-31.5);
	glVertex2f(-18,-31.5);
	glEnd();

	glBegin(GL_POLYGON); // extension 1
	glColor3f(0.90f, 0.84f, 0.67f);
	glVertex2f(91,91.5);
	glVertex2f(93,91.5);
	glVertex2f(93,-30.5);
	glVertex2f(91,-31.5);
	glEnd();

}


void porda()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // rod
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex2f(-22,98.5);
	glVertex2f(97,98.5);
	glVertex2f(97,96.5);
	glVertex2f(-22,96.5);
	glEnd();

	glBegin(GL_POLYGON); // porda 1
	glColor3f(0.30, 0.46, 0.53);
	glVertex2f(92,96.5);
	glVertex2f(96,96.5);
	glVertex2f(96,-45);
	glVertex2f(92,-40);
	glEnd();

	glBegin(GL_POLYGON); // porda 2
	glColor3f(0.40, 0.61, 0.70);
	glVertex2f(89,96.5);
	glVertex2f(93,96.5);
	glVertex2f(93,-45);
	glVertex2f(89,-40);
	glEnd();

	glBegin(GL_POLYGON); // porda 3
	glColor3f(0.20, 0.31, 0.35);
	glVertex2f(86,96.5);
	glVertex2f(90,96.5);
	glVertex2f(90,-45);
	glVertex2f(86,-40);
	glEnd();

	glBegin(GL_POLYGON); // porda 4
	glColor3f(0.30, 0.46, 0.53);
	glVertex2f(83,96.5);
	glVertex2f(87,96.5);
	glVertex2f(87,-45);
	glVertex2f(83,-40);
	glEnd();

	glBegin(GL_POLYGON); // porda 5
	glColor3f(0.40, 0.61, 0.70);
	glVertex2f(80,96.5);
	glVertex2f(84,96.5);
	glVertex2f(84,-45);
	glVertex2f(80,-40);
	glEnd();

	glBegin(GL_POLYGON); // porda 6
	glColor3f(0.20, 0.31, 0.35);
	glVertex2f(77,96.5);
	glVertex2f(81,96.5);
	glVertex2f(81,-45);
	glVertex2f(77,-40);
	glEnd();


}

void winter_hill()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // hill 1
    glColor3ub(106, 109, 0);
    glVertex2f(-18,60.5);
    glVertex2f(-18,80);
    glVertex2f(-16,85);
    glVertex2f(-5,60.5);
    glEnd();


    glBegin(GL_TRIANGLES); // hill 2
    glColor3ub(106, 109, 0);
    glVertex2f(-13,60.5);
    glVertex2f(-5,80);
    glVertex2f(5,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 3
    glColor3ub(106, 94, 0);
    glVertex2f(-10,60.5);
    glVertex2f(-2,85);
    glVertex2f(8,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 4
    glColor3ub(106, 109, 0);
    glVertex2f(0,60.5);
    glVertex2f(9,80);
    glVertex2f(18,60.5);
    glEnd();


    glBegin(GL_TRIANGLES); // hill 5
    glColor3ub(106, 94, 0);
    glVertex2f(2,60.5);
    glVertex2f(11,83);
    glVertex2f(20,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 6
    glColor3ub(106, 94, 0);
    glVertex2f(4,60.5);
    glVertex2f(13,81);
    glVertex2f(22,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 7
    glColor3ub(106, 94, 0);
    glVertex2f(8,60.5);
    glVertex2f(17,75);
    glVertex2f(25,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 8
    glColor3ub(106, 109, 0);
    glVertex2f(19,60.5);
    glVertex2f(27,75);
    glVertex2f(36,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 9
    glColor3ub(106, 94, 0);
    glVertex2f(22,60.5);
    glVertex2f(33,85);
    glVertex2f(44,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 10
    glColor3ub(106, 109, 0);
    glVertex2f(26,60.5);
    glVertex2f(36,82);
    glVertex2f(47,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 11
    glColor3ub(106, 94, 0);
    glVertex2f(36,60.5);
    glVertex2f(46,87);
    glVertex2f(57,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 12
    glColor3ub(106, 94, 0);
    glVertex2f(31,60.5);
    glVertex2f(41,83);
    glVertex2f(52,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 13
    glColor3ub(106, 109, 0);
    glVertex2f(46,60.5);
    glVertex2f(56,80);
    glVertex2f(67,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 14
    glColor3ub(106, 94, 0);
    glVertex2f(54,60.5);
    glVertex2f(65,87);
    glVertex2f(77,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 15
    glColor3ub(106, 109, 0);
    glVertex2f(63,60.5);
    glVertex2f(73,85);
    glVertex2f(84,60.5);
    glEnd();

    glBegin(GL_POLYGON); // hill 16
    glColor3ub(106, 94, 0);
    glVertex2f(66,60.5);
    glVertex2f(76,89);
    glVertex2f(87,60.5);
    glEnd();

}

void summer_hill()
{
    glMatrixMode(GL_MODELVIEW);



    glBegin(GL_POLYGON); // hill 1
    glColor3ub(11, 89, 0);
    glVertex2f(-18,60.5);
    glVertex2f(-18,80);
    glVertex2f(-16,85);
    glVertex2f(-5,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 3
    glColor3ub(11, 89, 0);
    glVertex2f(-10,60.5);
    glVertex2f(-2,85);
    glVertex2f(8,60.5);
    glEnd();


    glBegin(GL_TRIANGLES); // hill 2
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(-13,60.5);
    glVertex2f(-5,80);
    glVertex2f(5,60.5);
    glEnd();



    glBegin(GL_TRIANGLES); // hill 4
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(0,60.5);
    glVertex2f(9,80);
    glVertex2f(18,60.5);
    glEnd();


    glBegin(GL_TRIANGLES); // hill 5
    glColor3ub(11, 89, 0);
    glVertex2f(2,60.5);
    glVertex2f(11,83);
    glVertex2f(20,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 6
    glColor3ub(11, 89, 0);
    glVertex2f(4,60.5);
    glVertex2f(13,81);
    glVertex2f(22,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 7
    glColor3ub(11, 89, 0);
    glVertex2f(8,60.5);
    glVertex2f(17,75);
    glVertex2f(25,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 8
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(19,60.5);
    glVertex2f(27,75);
    glVertex2f(36,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 9
    glColor3ub(11, 89, 0);
    glVertex2f(22,60.5);
    glVertex2f(33,85);
    glVertex2f(44,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 10
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(26,60.5);
    glVertex2f(36,82);
    glVertex2f(47,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 11
    glColor3ub(11, 89, 0);
    glVertex2f(36,60.5);
    glVertex2f(46,87);
    glVertex2f(57,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 12
    glColor3ub(11, 89, 0);
    glVertex2f(31,60.5);
    glVertex2f(41,83);
    glVertex2f(52,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 13
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(46,60.5);
    glVertex2f(56,80);
    glVertex2f(67,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 14
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(54,60.5);
    glVertex2f(65,87);
    glVertex2f(77,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 15
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(63,60.5);
    glVertex2f(73,85);
    glVertex2f(84,60.5);
    glEnd();

    glBegin(GL_POLYGON); // hill 16
    glColor3ub(11, 89, 0);
    glVertex2f(66,60.5);
    glVertex2f(76,89);
    glVertex2f(87,60.5);
    glEnd();

}

void rainy_hill()
{
    glMatrixMode(GL_MODELVIEW);



    glBegin(GL_POLYGON); // hill 1
    glColor3ub(11, 89, 0);
    glVertex2f(-18,60.5);
    glVertex2f(-18,80);
    glVertex2f(-16,85);
    glVertex2f(-5,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 3
    glColor3ub(11, 89, 0);
    glVertex2f(-10,60.5);
    glVertex2f(-2,85);
    glVertex2f(8,60.5);
    glEnd();


    glBegin(GL_TRIANGLES); // hill 2
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(-13,60.5);
    glVertex2f(-5,80);
    glVertex2f(5,60.5);
    glEnd();



    glBegin(GL_TRIANGLES); // hill 4
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(0,60.5);
    glVertex2f(9,80);
    glVertex2f(18,60.5);
    glEnd();


    glBegin(GL_TRIANGLES); // hill 5
    glColor3ub(11, 89, 0);
    glVertex2f(2,60.5);
    glVertex2f(11,83);
    glVertex2f(20,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 6
    glColor3ub(11, 89, 0);
    glVertex2f(4,60.5);
    glVertex2f(13,81);
    glVertex2f(22,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 7
    glColor3ub(11, 89, 0);
    glVertex2f(8,60.5);
    glVertex2f(17,75);
    glVertex2f(25,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 8
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(19,60.5);
    glVertex2f(27,75);
    glVertex2f(36,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 9
    glColor3ub(11, 89, 0);
    glVertex2f(22,60.5);
    glVertex2f(33,85);
    glVertex2f(44,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 10
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(26,60.5);
    glVertex2f(36,82);
    glVertex2f(47,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 11
    glColor3ub(11, 89, 0);
    glVertex2f(36,60.5);
    glVertex2f(46,87);
    glVertex2f(57,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 12
    glColor3ub(11, 89, 0);
    glVertex2f(31,60.5);
    glVertex2f(41,83);
    glVertex2f(52,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 13
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(46,60.5);
    glVertex2f(56,80);
    glVertex2f(67,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 14
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(54,60.5);
    glVertex2f(65,87);
    glVertex2f(77,60.5);
    glEnd();

    glBegin(GL_TRIANGLES); // hill 15
    glColor3f(0.04, 0.43, 0.0);
    glVertex2f(63,60.5);
    glVertex2f(73,85);
    glVertex2f(84,60.5);
    glEnd();

    glBegin(GL_POLYGON); // hill 16
    glColor3ub(11, 89, 0);
    glVertex2f(66,60.5);
    glVertex2f(76,89);
    glVertex2f(87,60.5);
    glEnd();

}



void day_lamp()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // base
	glColor3ub(100, 100, 100);
	glVertex2f(37,16);
	glVertex2f(37,12);
	glVertex2f(40,12);
	glVertex2f(40,16);
	glEnd();

    glBegin(GL_POLYGON); // stand
	glColor3ub(130, 130, 130);
	glVertex2f(38.2,41);
	glVertex2f(38.2,16);
	glVertex2f(38.8,16);
	glVertex2f(38.8,41);
	glEnd();

	glBegin(GL_POLYGON); // upper part
	glColor3ub(100, 100, 100);
	glVertex2f(35,41.5);
	glVertex2f(35,41);
	glVertex2f(39.5,41);
	glVertex2f(39.5,41.5);
	glEnd();

	glBegin(GL_POLYGON); // light
	glColor3ub(255, 255, 255);
	glVertex2f(35.5,41);
	glVertex2f(35.7,40);
	glVertex2f(37.3,40);
	glVertex2f(37.5,41);
	glEnd();

}

void night_lamp()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // base
	glColor3ub(100, 100, 100);
	glVertex2f(37,16);
	glVertex2f(37,12);
	glVertex2f(40,12);
	glVertex2f(40,16);
	glEnd();

    glBegin(GL_POLYGON); // stand
	glColor3ub(130, 130, 130);
	glVertex2f(38.2,41);
	glVertex2f(38.2,16);
	glVertex2f(38.8,16);
	glVertex2f(38.8,41);
	glEnd();

	glBegin(GL_POLYGON); // upper part
	glColor3ub(100, 100, 100);
	glVertex2f(35,41.5);
	glVertex2f(35,41);
	glVertex2f(39.5,41);
	glVertex2f(39.5,41.5);
	glEnd();

	glBegin(GL_POLYGON); // light
	glColor3ub(255, 255, 0);
	glVertex2f(35.5,41);
	glVertex2f(35.7,40);
	glVertex2f(37.3,40);
	glVertex2f(37.5,41);
	glEnd();

}


void bench()
{
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_POLYGON); // sit
	glColor3ub(61, 68, 35);
	glVertex2f(20,16);
	glVertex2f(18,14);
	glVertex2f(34,14);
	glVertex2f(32,16);
	glEnd();

	glBegin(GL_POLYGON); // sit lower part
	glColor3ub(86, 68, 35);
	glVertex2f(18,14);
	glVertex2f(34,14);
	glVertex2f(34,13);
	glVertex2f(18,13);
	glEnd();

	glBegin(GL_POLYGON); // back rest
	glColor3ub(86, 68, 35);
	glVertex2f(18,22.5);
	glVertex2f(34,22.5);
	glVertex2f(34,17.5);
	glVertex2f(18,17.5);
	glEnd();

	glBegin(GL_POLYGON); // back rest stand 1
	glColor3ub(86, 68, 35);
	glVertex2f(20,17.5);
	glVertex2f(21,17.5);
	glVertex2f(21,14);
	glVertex2f(20,14);
	glEnd();

	glBegin(GL_POLYGON); // back rest stand 2
	glColor3ub(86, 68, 35);
	glVertex2f(31,17.5);
	glVertex2f(32,17.5);
	glVertex2f(32,14);
	glVertex2f(31,14);
	glEnd();

	glBegin(GL_POLYGON); // back left leg
	glColor3ub(86, 68, 35);
	glVertex2f(20,13);
	glVertex2f(21,13);
	glVertex2f(21,8);
	glVertex2f(20,8);
	glEnd();

	glBegin(GL_POLYGON); // front left leg
	glColor3ub(61, 68, 35);
	glVertex2f(21.5,13);
	glVertex2f(22.5,13);
	glVertex2f(22.5,9);
	glVertex2f(21.5,9);
	glEnd();

	glBegin(GL_POLYGON); // back right leg
	glColor3ub(86, 68, 35);
	glVertex2f(31,13);
	glVertex2f(32,13);
	glVertex2f(32,8);
	glVertex2f(31,8);
	glEnd();

	glBegin(GL_POLYGON); // front right leg
	glColor3ub(61, 68, 35);
	glVertex2f(29.5,13);
	glVertex2f(30.5,13);
	glVertex2f(30.5,9);
	glVertex2f(29.5,9);
	glEnd();


}


void summer_sun()
{
    glMatrixMode(GL_MODELVIEW);

    circle(7,22,72,90.96,0.76,0.27);


}

void winter_sun()
{
    glMatrixMode(GL_MODELVIEW);

    circle(7,22,72,0.96,0.76,0.27);




}

void moon()
{
    glMatrixMode(GL_MODELVIEW);

    circle(2.5,5,85,1,1,1);

}

void summer_cloud()
{
    glPushMatrix(); //Box1
    glTranslatef(ucloud, 0.0f, 0.0f);

    circle(2, -48, 85, 1.0, 1.0, 1.0); // cloud 1
	circle(2, -46, 86, 1.0, 1.0, 1.0);
	circle(2, -45, 83.5, 1.0, 1.0, 1.0);

    circle(2, -28, 83, 1.0, 1.0, 1.0); // cloud 7
	circle(2, -25, 84, 1.0, 1.0, 1.0);
	circle(2, -26, 81.5, 1.0, 1.0, 1.0);
	circle(2, -23, 82, 1.0, 1.0, 1.0);

	circle(2, -8, 85, 1.0, 1.0, 1.0); // cloud 1
	circle(2, -6, 86, 1.0, 1.0, 1.0);
	circle(2, -5, 83.5, 1.0, 1.0, 1.0);

	circle(2, 12, 83, 1.0, 1.0, 1.0); // cloud 2
	circle(2, 15, 84, 1.0, 1.0, 1.0);
	circle(2, 14, 81.5, 1.0, 1.0, 1.0);
	circle(2, 17, 82, 1.0, 1.0, 1.0);

	circle(2, 32, 87, 1.0, 1.0, 1.0); // cloud 3
	circle(2, 34, 88, 1.0, 1.0, 1.0);
	circle(2, 35, 85.5, 1.0, 1.0, 1.0);

	circle(2, 54, 82, 1.0, 1.0, 1.0); // cloud 4
	circle(2, 57, 83, 1.0, 1.0, 1.0);
	circle(2, 56, 80.5, 1.0, 1.0, 1.0);
	circle(2, 59, 81, 1.0, 1.0, 1.0);

	circle(2, 54, 82, 1.0, 1.0, 1.0); // cloud 5
	circle(2, 57, 83, 1.0, 1.0, 1.0);
	circle(2, 56, 80.5, 1.0, 1.0, 1.0);
	circle(2, 59, 81, 1.0, 1.0, 1.0);

	circle(2, 67, 85, 1.0, 1.0, 1.0); // cloud 6
	circle(2, 70, 86, 1.0, 1.0, 1.0);
	circle(2, 69, 83.5, 1.0, 1.0, 1.0);
	circle(2, 72, 84, 1.0, 1.0, 1.0);

	glPopMatrix();
}

void rainy_cloud()
{
    glPushMatrix(); //Box1
    glTranslatef(ucloud, 0.0f, 0.0f);

    circle(2, -48, 85, 0.64, 0.64, 0.64); // cloud 1
	circle(2, -46, 86, 0.64, 0.64, 0.64);
	circle(2, -45, 83.5, 0.64, 0.64, 0.64);

    circle(2, -28, 83, 0.64, 0.64, 0.64); // cloud 7
	circle(2, -25, 84, 0.64, 0.64, 0.64);
	circle(2, -26, 81.5, 0.64, 0.64, 0.64);
	circle(2, -23, 82, 0.64, 0.64, 0.64);

	circle(2, -8, 85, 0.64, 0.64, 0.64); // cloud 1
	circle(2, -6, 86, 0.64, 0.64, 0.64);
	circle(2, -5, 83.5, 0.64, 0.64, 0.64);

	circle(2, 12, 83, 0.64, 0.64, 0.64); // cloud 2
	circle(2, 15, 84, 0.64, 0.64, 0.64);
	circle(2, 14, 81.5, 0.64, 0.64, 0.64);
	circle(2, 17, 82, 0.64, 0.64, 0.64);

	circle(2, 32, 87, 0.64, 0.64, 0.64); // cloud 3
	circle(2, 34, 88, 0.64, 0.64, 0.64);
	circle(2, 35, 85.5, 0.64, 0.64, 0.64);

	circle(2, 54, 82, 0.64, 0.64, 0.64); // cloud 4
	circle(2, 57, 83, 0.64, 0.64, 0.64);
	circle(2, 56, 80.5, 0.64, 0.64, 0.64);
	circle(2, 59, 81, 0.64, 0.64, 0.64);

	circle(2, 54, 82, 0.64, 0.64, 0.64); // cloud 5
	circle(2, 57, 83, 0.64, 0.64, 0.64);
	circle(2, 56, 80.5, 0.64, 0.64, 0.64);
	circle(2, 59, 81, 0.64, 0.64, 0.64);

	circle(2, 67, 85, 0.64, 0.64, 0.64); // cloud 6
	circle(2, 70, 86, 0.64, 0.64, 0.64);
	circle(2, 69, 83.5, 0.64, 0.64, 0.64);
	circle(2, 72, 84, 0.64, 0.64, 0.64);

	glPopMatrix();
}

void boat()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Box1
    glTranslatef(uboat, 0.0f, 0.0f);




    glBegin(GL_POLYGON); // lower part
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-15,38);
	glVertex2f(5,38);
	glVertex2f(-1,35);
	glVertex2f(-9,35);
	glEnd();

    glBegin(GL_POLYGON); // upper part
    glColor3ub(60, 0, 0.0);
    glVertex2f(-9,43);
    glVertex2f(-1,43);
    glVertex2f(-1,38);
	glVertex2f(-9,38);
	glEnd();

	glPopMatrix();

}

void car1()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Box1
    glTranslatef(ucar1, 0.0f, 0.0f);



    glBegin(GL_POLYGON); // upper part
    glColor3ub(0, 0, 0);
    glVertex2f(7,2);
	glVertex2f(1,2);
    glVertex2f(-2,-3);
    glVertex2f(10,-3);
	glEnd();

	glBegin(GL_POLYGON); // lower part
    glColor3ub(140, 140, 140);
    glVertex2f(-7,-3);
	glVertex2f(17,-3);
	glVertex2f(20,-5);
    glVertex2f(20,-10);
    glVertex2f(-7,-10);
	glEnd();

	circle(2.5, 0, -10, 0, 0, 0); // back tire
	circle(2.5, 13, -10, 0, 0, 0);// right tire

	glLineWidth(1);

	glBegin(GL_LINES);// gate left
	glColor3ub(0, 0, 0);
	glVertex2f(5, -9);
	glVertex2f(5, -4);
	glEnd();

	glBegin(GL_LINES); // gate right
	glColor3ub(0, 0, 0);
	glVertex2f(-2 ,-6.5);
	glVertex2f(-2, -4);
	glEnd();

	glLineWidth(2);

	glBegin(GL_LINES); // gate handle left
	glColor3ub(0, 0, 0);
	glVertex2f(-1 , -4);
	glVertex2f(0 , -4);
	glEnd();

	glBegin(GL_LINES); // gate handle right
	glColor3ub(0, 0, 0);
	glVertex2f(6.5 , -4);
	glVertex2f(7.5 , -4);
	glEnd();


	glBegin(GL_POLYGON); // back light
    glColor3ub(255, 0, 0);
    glVertex2f(-7,-3.5);
	glVertex2f(-6,-3.5);
    glVertex2f(-6,-5);
    glVertex2f(-7,-5);
	glEnd();


	glBegin(GL_POLYGON); // head light
    glColor3ub(255, 255, 0);
    glVertex2f(19,-5.5);
	glVertex2f(20,-5.5);
    glVertex2f(20,-7);
    glVertex2f(19,-7);
	glEnd();


	glPopMatrix();

}

void car2()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix(); //Box1
    glTranslatef(ucar2, 0.0f, 0.0f);


    glBegin(GL_POLYGON); // upper part
    glColor3ub(0, 0, 0);
    glVertex2f(52,-8);
	glVertex2f(46,-8);
    glVertex2f(43,-13);
    glVertex2f(55,-13);
	glEnd();

	glBegin(GL_POLYGON); // lower part
    glColor3ub(115, 9, 0);
    glVertex2f(33,-15);
    glVertex2f(36,-13);
	glVertex2f(60,-13);
    glVertex2f(60,-20);
    glVertex2f(33,-20);
	glEnd();

	circle(2.5, 40, -20, 0, 0, 0); // front tire
	circle(2.5, 53, -20, 0, 0, 0);// back tire

	glLineWidth(1);

	glBegin(GL_LINES);// gate left
	glColor3ub(0, 0, 0);
	glVertex2f(47.5, -19);
	glVertex2f(47.5, -14);
	glEnd();

	glBegin(GL_LINES); // gate right
	glColor3ub(0, 0, 0);
	glVertex2f(54 ,-16.5);
	glVertex2f(54, -14);
	glEnd();

	glLineWidth(2);

	glBegin(GL_LINES); // gate handle left
	glColor3ub(0, 0, 0);
	glVertex2f(45 , -14);
	glVertex2f(46 , -14);
	glEnd();

	glBegin(GL_LINES); // gate handle right
	glColor3ub(0, 0, 0);
	glVertex2f(52 , -14);
	glVertex2f(53 , -14);
	glEnd();


	glBegin(GL_POLYGON); // head light
    glColor3ub(255, 255, 0);
    glVertex2f(33,-15.5);
	glVertex2f(34,-15.5);
    glVertex2f(34,-17);
    glVertex2f(33,-17);
	glEnd();


	glBegin(GL_POLYGON); // back light
    glColor3ub(255, 0, 0);
    glVertex2f(59,-13.5);
	glVertex2f(60,-13.5);
    glVertex2f(60,-15);
    glVertex2f(59,-15);
	glEnd();

	glPopMatrix();

}

void day_houses()
{
    glMatrixMode(GL_MODELVIEW);

    //house 2

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(7,65);
	glVertex2f(17,65);
    glVertex2f(19,62);
    glVertex2f(9,62);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(255, 255, 255);
    glVertex2f(9,62);
    glVertex2f(19,62);
    glVertex2f(19,58);
    glVertex2f(9,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(24, 147, 153);
    glVertex2f(5,62);
    glVertex2f(7,65);
    glVertex2f(9,62);
    glVertex2f(9,58);
    glVertex2f(5,58);
	glEnd();

	glBegin(GL_POLYGON); // window 1
    glColor3ub(0, 0, 0);
    glVertex2f(5.8, 61);
    glVertex2f(6.2, 61);
    glVertex2f(6.2, 59);
    glVertex2f(5.8, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(0, 0, 0);
    glVertex2f(7.5, 61);
    glVertex2f(8, 61);
    glVertex2f(8, 59);
    glVertex2f(7.5, 59);
    glEnd();

        glBegin(GL_POLYGON); // window 3
    glColor3ub(0, 0, 0);
    glVertex2f(9.5, 61);
    glVertex2f(10, 61);
    glVertex2f(10, 59);
    glVertex2f(9.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 4
    glColor3ub(0, 0, 0);
    glVertex2f(11, 61);
    glVertex2f(11.5, 61);
    glVertex2f(11.5, 59);
    glVertex2f(11, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 5
    glColor3ub(0, 0, 0);
    glVertex2f(12.5, 61);
    glVertex2f(13, 61);
    glVertex2f(13, 59);
    glVertex2f(12.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 6
    glColor3ub(0, 0, 0);
    glVertex2f(14, 61);
    glVertex2f(14.5, 61);
    glVertex2f(14.5, 59);
    glVertex2f(14, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 7
    glColor3ub(0, 0, 0);
    glVertex2f(15.5, 61);
    glVertex2f(16, 61);
    glVertex2f(16, 59);
    glVertex2f(15.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 8
    glColor3ub(0, 0, 0);
    glVertex2f(17, 61);
    glVertex2f(17.5, 61);
    glVertex2f(17.5, 59);
    glVertex2f(17, 59);
    glEnd();


    //house 1

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(0,65);
	glVertex2f(5,65);
    glVertex2f(7,62);
    glVertex2f(2,62);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(255, 255, 255);
    glVertex2f(2,62);
    glVertex2f(7,62);
    glVertex2f(7,58);
    glVertex2f(2,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(24, 147, 153);
    glVertex2f(-2,62);
    glVertex2f(0,65);
    glVertex2f(2,62);
    glVertex2f(2,58);
    glVertex2f(-2,58);
	glEnd();

	glBegin(GL_POLYGON); // window 1
	glColor3ub(0, 0, 0);
    glVertex2f(-1.2,61);
    glVertex2f(-0.8,61);
    glVertex2f(-0.8,59);
    glVertex2f(-1.2,59);
	glEnd();

	glBegin(GL_POLYGON); // window 2
	glColor3ub(0, 0, 0);
    glVertex2f(0.5,61);
    glVertex2f(1,61);
    glVertex2f(1,59);
    glVertex2f(0.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 3
	glColor3ub(0, 0, 0);
    glVertex2f(2.5,61);
    glVertex2f(3,61);
    glVertex2f(3,59);
    glVertex2f(2.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 4
	glColor3ub(0, 0, 0);
    glVertex2f(4,61);
    glVertex2f(4.5,61);
    glVertex2f(4.5,59);
    glVertex2f(4,59);
	glEnd();

	glBegin(GL_POLYGON); // window 5
	glColor3ub(0, 0, 0);
    glVertex2f(5.5,61);
    glVertex2f(6,61);
    glVertex2f(6,59);
    glVertex2f(5.5,59);
	glEnd();


	//house 3

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(32,65);
	glVertex2f(42,65);
    glVertex2f(44,62);
    glVertex2f(34,62);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(255, 255, 255);
    glVertex2f(34,62);
    glVertex2f(44,62);
    glVertex2f(44,58);
    glVertex2f(34,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(24, 147, 153);
    glVertex2f(30,62);
    glVertex2f(32,65);
    glVertex2f(34,62);
    glVertex2f(34,58);
    glVertex2f(30,58);
	glEnd();


    glBegin(GL_POLYGON); // window 1
	glColor3ub(0, 0, 0);
    glVertex2f(30.8,61);
    glVertex2f(31.2,61);
    glVertex2f(31.2,59);
    glVertex2f(30.8,59);
	glEnd();

	glBegin(GL_POLYGON); // window 2
	glColor3ub(0, 0, 0);
    glVertex2f(32.5,61);
    glVertex2f(33,61);
    glVertex2f(33,59);
    glVertex2f(32.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 3
	glColor3ub(0, 0, 0);
    glVertex2f(34.5,61);
    glVertex2f(35,61);
    glVertex2f(35,59);
    glVertex2f(34.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 4
	glColor3ub(0, 0, 0);
    glVertex2f(36,61);
    glVertex2f(36.5,61);
    glVertex2f(36.5,59);
    glVertex2f(36,59);
	glEnd();

	glBegin(GL_POLYGON); // window 5
	glColor3ub(0, 0, 0);
    glVertex2f(37.5,61);
    glVertex2f(38,61);
    glVertex2f(38,59);
    glVertex2f(37.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 6
	glColor3ub(0, 0, 0);
    glVertex2f(39,61);
    glVertex2f(39.5,61);
    glVertex2f(39.5,59);
    glVertex2f(39,59);
	glEnd();

	glBegin(GL_POLYGON); // window 7
	glColor3ub(0, 0, 0);
    glVertex2f(40.5,61);
    glVertex2f(41,61);
    glVertex2f(41,59);
    glVertex2f(40.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 8
	glColor3ub(0, 0, 0);
    glVertex2f(42,61);
    glVertex2f(42.5,61);
    glVertex2f(42.5,59);
    glVertex2f(42,59);
	glEnd();

	//house 4

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(47,70);
	glVertex2f(54,70);
    glVertex2f(56,67);
    glVertex2f(49,67);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(255, 255, 255);
    glVertex2f(49,67);
    glVertex2f(56,67);
    glVertex2f(56,58);
    glVertex2f(49,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(24, 147, 153);
    glVertex2f(45,67);
    glVertex2f(47,70);
    glVertex2f(49,67);
    glVertex2f(49,58);
    glVertex2f(45,58);
	glEnd();

	glBegin(GL_POLYGON); // window 1
    glColor3ub(0, 0, 0);
    glVertex2f(45.8, 61);
    glVertex2f(46.2, 61);
    glVertex2f(46.2, 59);
    glVertex2f(45.8, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(0, 0, 0);
    glVertex2f(47.5, 61);
    glVertex2f(48, 61);
    glVertex2f(48, 59);
    glVertex2f(47.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 3
    glColor3ub(0, 0, 0);
    glVertex2f(45.8, 66);
    glVertex2f(46.2, 66);
    glVertex2f(46.2, 64);
    glVertex2f(45.8, 64);
    glEnd();

    glBegin(GL_POLYGON); // window 4
    glColor3ub(0, 0, 0);
    glVertex2f(47.5, 66);
    glVertex2f(48, 66);
    glVertex2f(48, 64);
    glVertex2f(47.5, 64);
    glEnd();

    glBegin(GL_POLYGON); // window 5
    glColor3ub(0, 0, 0);
    glVertex2f(50, 61);
    glVertex2f(51.2, 61);
    glVertex2f(51.2, 59);
    glVertex2f(50, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 6
    glColor3ub(0, 0, 0);
    glVertex2f(50, 66);
    glVertex2f(51.2, 66);
    glVertex2f(51.2, 64);
    glVertex2f(50, 64);
    glEnd();

    glBegin(GL_POLYGON); // window 7
    glColor3ub(0, 0, 0);
    glVertex2f(54, 61);
    glVertex2f(55.2, 61);
    glVertex2f(55.2, 59);
    glVertex2f(54, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 8
    glColor3ub(0, 0, 0);
    glVertex2f(54, 66);
    glVertex2f(55.2, 66);
    glVertex2f(55.2, 64);
    glVertex2f(54, 64);
    glEnd();

    glBegin(GL_POLYGON); // door
    glColor3ub(0, 0, 0);
    glVertex2f(52, 61);
    glVertex2f(53.2, 61);
    glVertex2f(53.2, 58);
    glVertex2f(52, 58);
    glEnd();



	//house 5

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(62,65);
	glVertex2f(69,65);
    glVertex2f(67,62);
    glVertex2f(60,62);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(255, 255, 255);
    glVertex2f(60,62);
    glVertex2f(67,62);
    glVertex2f(67,58);
    glVertex2f(60,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(24, 147, 153);
    glVertex2f(67,62);
    glVertex2f(69,65);
    glVertex2f(71,62);
    glVertex2f(71,58);
    glVertex2f(67,58);
	glEnd();

	glBegin(GL_POLYGON); // window 1
    glColor3ub(0, 0, 0);
    glVertex2f(60.8, 61);
    glVertex2f(61.2, 61);
    glVertex2f(61.2, 59);
    glVertex2f(60.8, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(0, 0, 0);
    glVertex2f(62.5, 61);
    glVertex2f(63, 61);
    glVertex2f(63, 59);
    glVertex2f(62.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 3
    glColor3ub(0, 0, 0);
    glVertex2f(64.5, 61);
    glVertex2f(65, 61);
    glVertex2f(65, 59);
    glVertex2f(64.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 4
    glColor3ub(0, 0, 0);
    glVertex2f(66, 61);
    glVertex2f(66.5, 61);
    glVertex2f(66.5, 59);
    glVertex2f(66, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 5
    glColor3ub(0, 0, 0);
    glVertex2f(68, 61);
    glVertex2f(68.5, 61);
    glVertex2f(68.5, 59);
    glVertex2f(68, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 6
    glColor3ub(0, 0, 0);
    glVertex2f(69.5, 61);
    glVertex2f(70, 61);
    glVertex2f(70, 59);
    glVertex2f(69.5, 59);
    glEnd();


}

void night_houses()
{
    glMatrixMode(GL_MODELVIEW);

    //house 2

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(7,65);
	glVertex2f(17,65);
    glVertex2f(19,62);
    glVertex2f(9,62);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(195, 242, 255);
    glVertex2f(9,62);
    glVertex2f(19,62);
    glVertex2f(19,58);
    glVertex2f(9,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(11, 113, 155);
    glVertex2f(5,62);
    glVertex2f(7,65);
    glVertex2f(9,62);
    glVertex2f(9,58);
    glVertex2f(5,58);
	glEnd();

	glBegin(GL_POLYGON); // window 1
    glColor3ub(255, 255, 0);
    glVertex2f(5.8, 61);
    glVertex2f(6.2, 61);
    glVertex2f(6.2, 59);
    glVertex2f(5.8, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(255, 255, 0);
    glVertex2f(7.5, 61);
    glVertex2f(8, 61);
    glVertex2f(8, 59);
    glVertex2f(7.5, 59);
    glEnd();

        glBegin(GL_POLYGON); // window 3
    glColor3ub(255, 255, 0);
    glVertex2f(9.5, 61);
    glVertex2f(10, 61);
    glVertex2f(10, 59);
    glVertex2f(9.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 4
    glColor3ub(255, 255, 0);
    glVertex2f(11, 61);
    glVertex2f(11.5, 61);
    glVertex2f(11.5, 59);
    glVertex2f(11, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 5
    glColor3ub(255, 255, 0);
    glVertex2f(12.5, 61);
    glVertex2f(13, 61);
    glVertex2f(13, 59);
    glVertex2f(12.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 6
    glColor3ub(255, 255, 0);
    glVertex2f(14, 61);
    glVertex2f(14.5, 61);
    glVertex2f(14.5, 59);
    glVertex2f(14, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 7
    glColor3ub(255, 255, 0);
    glVertex2f(15.5, 61);
    glVertex2f(16, 61);
    glVertex2f(16, 59);
    glVertex2f(15.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 8
    glColor3ub(255, 255, 0);
    glVertex2f(17, 61);
    glVertex2f(17.5, 61);
    glVertex2f(17.5, 59);
    glVertex2f(17, 59);
    glEnd();


    //house 1

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(0,65);
	glVertex2f(5,65);
    glVertex2f(7,62);
    glVertex2f(2,62);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(195, 242, 255);
    glVertex2f(2,62);
    glVertex2f(7,62);
    glVertex2f(7,58);
    glVertex2f(2,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(11, 113, 155);
    glVertex2f(-2,62);
    glVertex2f(0,65);
    glVertex2f(2,62);
    glVertex2f(2,58);
    glVertex2f(-2,58);
	glEnd();

	glBegin(GL_POLYGON); // window 1
	glColor3ub(255, 255, 0);
    glVertex2f(-1.2,61);
    glVertex2f(-0.8,61);
    glVertex2f(-0.8,59);
    glVertex2f(-1.2,59);
	glEnd();

	glBegin(GL_POLYGON); // window 2
	glColor3ub(255, 255, 0);
    glVertex2f(0.5,61);
    glVertex2f(1,61);
    glVertex2f(1,59);
    glVertex2f(0.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 3
	glColor3ub(255, 255, 0);
    glVertex2f(2.5,61);
    glVertex2f(3,61);
    glVertex2f(3,59);
    glVertex2f(2.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 4
	glColor3ub(255, 255, 0);
    glVertex2f(4,61);
    glVertex2f(4.5,61);
    glVertex2f(4.5,59);
    glVertex2f(4,59);
	glEnd();

	glBegin(GL_POLYGON); // window 5
	glColor3ub(255, 255, 0);
    glVertex2f(5.5,61);
    glVertex2f(6,61);
    glVertex2f(6,59);
    glVertex2f(5.5,59);
	glEnd();


	//house 3

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(32,65);
	glVertex2f(42,65);
    glVertex2f(44,62);
    glVertex2f(34,62);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(195, 242, 255);
    glVertex2f(34,62);
    glVertex2f(44,62);
    glVertex2f(44,58);
    glVertex2f(34,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(11, 113, 155);
    glVertex2f(30,62);
    glVertex2f(32,65);
    glVertex2f(34,62);
    glVertex2f(34,58);
    glVertex2f(30,58);
	glEnd();


    glBegin(GL_POLYGON); // window 1
	glColor3ub(255, 255, 0);
    glVertex2f(30.8,61);
    glVertex2f(31.2,61);
    glVertex2f(31.2,59);
    glVertex2f(30.8,59);
	glEnd();

	glBegin(GL_POLYGON); // window 2
	glColor3ub(255, 255, 0);
    glVertex2f(32.5,61);
    glVertex2f(33,61);
    glVertex2f(33,59);
    glVertex2f(32.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 3
	glColor3ub(255, 255, 0);
    glVertex2f(34.5,61);
    glVertex2f(35,61);
    glVertex2f(35,59);
    glVertex2f(34.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 4
	glColor3ub(255, 255, 0);
    glVertex2f(36,61);
    glVertex2f(36.5,61);
    glVertex2f(36.5,59);
    glVertex2f(36,59);
	glEnd();

	glBegin(GL_POLYGON); // window 5
	glColor3ub(255, 255, 0);
    glVertex2f(37.5,61);
    glVertex2f(38,61);
    glVertex2f(38,59);
    glVertex2f(37.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 6
	glColor3ub(255, 255, 0);
    glVertex2f(39,61);
    glVertex2f(39.5,61);
    glVertex2f(39.5,59);
    glVertex2f(39,59);
	glEnd();

	glBegin(GL_POLYGON); // window 7
	glColor3ub(255, 255, 0);
    glVertex2f(40.5,61);
    glVertex2f(41,61);
    glVertex2f(41,59);
    glVertex2f(40.5,59);
	glEnd();

	glBegin(GL_POLYGON); // window 8
	glColor3ub(255, 255, 0);
    glVertex2f(42,61);
    glVertex2f(42.5,61);
    glVertex2f(42.5,59);
    glVertex2f(42,59);
	glEnd();

	//house 4

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(47,70);
	glVertex2f(54,70);
    glVertex2f(56,67);
    glVertex2f(49,67);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(195, 242, 255);
    glVertex2f(49,67);
    glVertex2f(56,67);
    glVertex2f(56,58);
    glVertex2f(49,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(11, 113, 155);
    glVertex2f(45,67);
    glVertex2f(47,70);
    glVertex2f(49,67);
    glVertex2f(49,58);
    glVertex2f(45,58);
	glEnd();

	glBegin(GL_POLYGON); // window 1
    glColor3ub(255, 255, 0);
    glVertex2f(45.8, 61);
    glVertex2f(46.2, 61);
    glVertex2f(46.2, 59);
    glVertex2f(45.8, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(255, 255, 0);
    glVertex2f(47.5, 61);
    glVertex2f(48, 61);
    glVertex2f(48, 59);
    glVertex2f(47.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 3
    glColor3ub(255, 255, 0);
    glVertex2f(45.8, 66);
    glVertex2f(46.2, 66);
    glVertex2f(46.2, 64);
    glVertex2f(45.8, 64);
    glEnd();

    glBegin(GL_POLYGON); // window 4
    glColor3ub(255, 255, 0);
    glVertex2f(47.5, 66);
    glVertex2f(48, 66);
    glVertex2f(48, 64);
    glVertex2f(47.5, 64);
    glEnd();

    glBegin(GL_POLYGON); // window 5
    glColor3ub(255, 255, 0);
    glVertex2f(50, 61);
    glVertex2f(51.2, 61);
    glVertex2f(51.2, 59);
    glVertex2f(50, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 6
    glColor3ub(255, 255, 0);
    glVertex2f(50, 66);
    glVertex2f(51.2, 66);
    glVertex2f(51.2, 64);
    glVertex2f(50, 64);
    glEnd();

    glBegin(GL_POLYGON); // window 7
    glColor3ub(255, 255, 0);
    glVertex2f(54, 61);
    glVertex2f(55.2, 61);
    glVertex2f(55.2, 59);
    glVertex2f(54, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 8
    glColor3ub(255, 255, 0);
    glVertex2f(54, 66);
    glVertex2f(55.2, 66);
    glVertex2f(55.2, 64);
    glVertex2f(54, 64);
    glEnd();

    glBegin(GL_POLYGON); // door
    glColor3ub(255, 255, 0);
    glVertex2f(52, 61);
    glVertex2f(53.2, 61);
    glVertex2f(53.2, 58);
    glVertex2f(52, 58);
    glEnd();



	//house 5

    glBegin(GL_POLYGON); // roof
    glColor3ub(162, 92, 0);
    glVertex2f(62,65);
	glVertex2f(69,65);
    glVertex2f(67,62);
    glVertex2f(60,62);
	glEnd();


	glBegin(GL_POLYGON); // main body
	glColor3ub(195, 242, 255);
    glVertex2f(60,62);
    glVertex2f(67,62);
    glVertex2f(67,58);
    glVertex2f(60,58);
	glEnd();

	glBegin(GL_POLYGON); // side body
	glColor3ub(11, 113, 155);
    glVertex2f(67,62);
    glVertex2f(69,65);
    glVertex2f(71,62);
    glVertex2f(71,58);
    glVertex2f(67,58);
	glEnd();

	glBegin(GL_POLYGON); // window 1
    glColor3ub(255, 255, 0);
    glVertex2f(60.8, 61);
    glVertex2f(61.2, 61);
    glVertex2f(61.2, 59);
    glVertex2f(60.8, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 2
    glColor3ub(255, 255, 0);
    glVertex2f(62.5, 61);
    glVertex2f(63, 61);
    glVertex2f(63, 59);
    glVertex2f(62.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 3
    glColor3ub(255, 255, 0);
    glVertex2f(64.5, 61);
    glVertex2f(65, 61);
    glVertex2f(65, 59);
    glVertex2f(64.5, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 4
    glColor3ub(255, 255, 0);
    glVertex2f(66, 61);
    glVertex2f(66.5, 61);
    glVertex2f(66.5, 59);
    glVertex2f(66, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 5
    glColor3ub(255, 255, 0);
    glVertex2f(68, 61);
    glVertex2f(68.5, 61);
    glVertex2f(68.5, 59);
    glVertex2f(68, 59);
    glEnd();

    glBegin(GL_POLYGON); // window 6
    glColor3ub(255, 255, 0);
    glVertex2f(69.5, 61);
    glVertex2f(70, 61);
    glVertex2f(70, 59);
    glVertex2f(69.5, 59);
    glEnd();


}

void summer_day_trees()
{

    //tree 2

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f(0, 33);
    glVertex2f(3, 48);
    glVertex2f(6, 33);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f(-2, 23);
    glVertex2f(3, 41);
    glVertex2f(8, 23);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f(-3, 15);
    glVertex2f(3, 35);
    glVertex2f(9, 15);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f(2, 8);
    glVertex2f(3, 43);
    glVertex2f(4, 8);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f(3, 13);
    glVertex2f(6, 23);
    glVertex2f(3, 16);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f(3, 15);
    glVertex2f(0, 25);
    glVertex2f(3, 18);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f(3, 23);
    glVertex2f(5, 33);
    glVertex2f(3, 26);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f(3, 25);
    glVertex2f(1, 35);
    glVertex2f(3, 28);
glEnd();



    //tree 1

    glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f(-10, 30);
    glVertex2f(-7, 45);
    glVertex2f(-4, 30);
    glEnd();

    glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f(-12, 20);
    glVertex2f(-7, 38);
    glVertex2f(-2, 20);
    glEnd();

    glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f(-13, 12);
    glVertex2f(-7, 32);
    glVertex2f(-1, 12);
    glEnd();

    glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f(-8, 5);
    glVertex2f(-7, 40);
    glVertex2f(-6, 5);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f(-7, 10);
    glVertex2f(-4, 20);
    glVertex2f(-7, 13);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f(-7, 12);
    glVertex2f(-10, 22);
    glVertex2f(-7, 15);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f(-7, 20);
    glVertex2f(-5, 30);
    glVertex2f(-7, 23);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f(-7, 22);
    glVertex2f(-9, 32);
    glVertex2f(-7, 25);
    glEnd();


    //tree 3

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f(40, 30);
    glVertex2f(43, 45);
    glVertex2f(46, 30);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f(38, 20);
    glVertex2f(43, 38);
    glVertex2f(48, 20);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f(37, 12);
    glVertex2f(43, 32);
    glVertex2f(49, 12);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f(42, 5);
    glVertex2f(43, 40);
    glVertex2f(44, 5);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f(43, 10);
    glVertex2f(46, 20);
    glVertex2f(43, 13);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f(43, 12);
    glVertex2f(40, 22);
    glVertex2f(43, 15);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f(43, 20);
    glVertex2f(45, 30);
    glVertex2f(43, 23);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f(43, 22);
    glVertex2f(41, 32);
    glVertex2f(43, 25);
glEnd();


//tree 4

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f(55, 34);
    glVertex2f(58, 49);
    glVertex2f(61, 34);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f(53, 24);
    glVertex2f(58, 42);
    glVertex2f(63, 24);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f(52, 16);
    glVertex2f(58, 36);
    glVertex2f(64, 16);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f(57, 9);
    glVertex2f(58, 44);
    glVertex2f(59, 9);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f(58, 14);
    glVertex2f(61, 24);
    glVertex2f(58, 17);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f(58, 16);
    glVertex2f(55, 26);
    glVertex2f(58, 19);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f(58, 24);
    glVertex2f(60, 34);
    glVertex2f(58, 27);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f(58, 26);
    glVertex2f(56, 36);
    glVertex2f(58, 29);
glEnd();




//tree 3

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f(65, 30);
    glVertex2f(68, 45);
    glVertex2f(71, 30);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f(63, 20);
    glVertex2f(68, 38);
    glVertex2f(73, 20);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f(62, 12);
    glVertex2f(68, 32);
    glVertex2f(74, 12);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f(67, 5);
    glVertex2f(68, 40);
    glVertex2f(69, 5);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f(68, 10);
    glVertex2f(71, 20);
    glVertex2f(68, 13);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f(68, 12);
    glVertex2f(65, 22);
    glVertex2f(68, 15);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f(68, 20);
    glVertex2f(70, 30);
    glVertex2f(68, 23);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f(68, 22);
    glVertex2f(66, 32);
    glVertex2f(68, 25);
glEnd();


//tree 6

GLfloat scale_factor = 0.3;
GLfloat y_shift = 190;
GLfloat x_shift = 10;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f((65 + x_shift) * scale_factor, (30 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (45 + y_shift) * scale_factor);
    glVertex2f((71 + x_shift) * scale_factor, (30 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f((63 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (38 + y_shift) * scale_factor);
    glVertex2f((73 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f((62 + x_shift) * scale_factor, (12 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (32 + y_shift) * scale_factor);
    glVertex2f((74 + x_shift) * scale_factor, (12 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f((67 + x_shift) * scale_factor, (5 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (40 + y_shift) * scale_factor);
    glVertex2f((69 + x_shift) * scale_factor, (5 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift) * scale_factor, (10 + y_shift) * scale_factor);
    glVertex2f((71 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (13 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift) * scale_factor, (12 + y_shift) * scale_factor);
    glVertex2f((65 + x_shift) * scale_factor, (22 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (15 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
    glVertex2f((70 + x_shift) * scale_factor, (30 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (23 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift) * scale_factor, (22 + y_shift) * scale_factor);
    glVertex2f((66 + x_shift) * scale_factor, (32 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (25 + y_shift) * scale_factor);
glEnd();




//tree 6

GLfloat tree_scale_factor = 0.3;
GLfloat tree_y_shift = 190;
GLfloat tree_x_shift = 25;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f((65 + tree_x_shift) * tree_scale_factor, (30 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (45 + tree_y_shift) * tree_scale_factor);
    glVertex2f((71 + tree_x_shift) * tree_scale_factor, (30 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f((63 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (38 + tree_y_shift) * tree_scale_factor);
    glVertex2f((73 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f((62 + tree_x_shift) * tree_scale_factor, (12 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (32 + tree_y_shift) * tree_scale_factor);
    glVertex2f((74 + tree_x_shift) * tree_scale_factor, (12 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f((67 + tree_x_shift) * tree_scale_factor, (5 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (40 + tree_y_shift) * tree_scale_factor);
    glVertex2f((69 + tree_x_shift) * tree_scale_factor, (5 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (10 + tree_y_shift) * tree_scale_factor);
    glVertex2f((71 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (13 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (12 + tree_y_shift) * tree_scale_factor);
    glVertex2f((65 + tree_x_shift) * tree_scale_factor, (22 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (15 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
    glVertex2f((70 + tree_x_shift) * tree_scale_factor, (30 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (23 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (22 + tree_y_shift) * tree_scale_factor);
    glVertex2f((66 + tree_x_shift) * tree_scale_factor, (32 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (25 + tree_y_shift) * tree_scale_factor);
glEnd();



    //tree 6

GLfloat scale_factor1 = 0.3;
GLfloat y_shift1 = 190;
GLfloat x_shift1 = 175;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f((65 + x_shift1) * scale_factor1, (30 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (45 + y_shift1) * scale_factor1);
    glVertex2f((71 + x_shift1) * scale_factor1, (30 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f((63 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (38 + y_shift1) * scale_factor1);
    glVertex2f((73 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f((62 + x_shift1) * scale_factor1, (12 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (32 + y_shift1) * scale_factor1);
    glVertex2f((74 + x_shift1) * scale_factor1, (12 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f((67 + x_shift1) * scale_factor1, (5 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (40 + y_shift1) * scale_factor1);
    glVertex2f((69 + x_shift1) * scale_factor1, (5 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (10 + y_shift1) * scale_factor1);
    glVertex2f((71 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (13 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (12 + y_shift1) * scale_factor1);
    glVertex2f((65 + x_shift1) * scale_factor1, (22 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (15 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
    glVertex2f((70 + x_shift1) * scale_factor1, (30 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (23 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (22 + y_shift1) * scale_factor1);
    glVertex2f((66 + x_shift1) * scale_factor1, (32 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (25 + y_shift1) * scale_factor1);
glEnd();



//tree 6

GLfloat scale_factor2 = 0.3;
GLfloat y_shift2 = 190;
GLfloat x_shift2 = -80;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f((65 + x_shift2) * scale_factor2, (30 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (45 + y_shift2) * scale_factor2);
    glVertex2f((71 + x_shift2) * scale_factor2, (30 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f((63 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (38 + y_shift2) * scale_factor2);
    glVertex2f((73 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f((62 + x_shift2) * scale_factor2, (12 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (32 + y_shift2) * scale_factor2);
    glVertex2f((74 + x_shift2) * scale_factor2, (12 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f((67 + x_shift2) * scale_factor2, (5 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (40 + y_shift2) * scale_factor2);
    glVertex2f((69 + x_shift2) * scale_factor2, (5 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (10 + y_shift2) * scale_factor2);
    glVertex2f((71 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (13 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (12 + y_shift2) * scale_factor2);
    glVertex2f((65 + x_shift2) * scale_factor2, (22 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (15 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
    glVertex2f((70 + x_shift2) * scale_factor2, (30 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (23 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (22 + y_shift2) * scale_factor2);
    glVertex2f((66 + x_shift2) * scale_factor2, (32 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (25 + y_shift2) * scale_factor2);
glEnd();


//tree 6

GLfloat scale_factor3 = 0.3;
GLfloat y_shift3 = 185;
GLfloat x_shift3 = 17.5;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 89, 0);
    glVertex2f((65 + x_shift3) * scale_factor3, (30 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (45 + y_shift3) * scale_factor3);
    glVertex2f((71 + x_shift3) * scale_factor3, (30 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 89, 0);
    glVertex2f((63 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (38 + y_shift3) * scale_factor3);
    glVertex2f((73 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 89, 0);
    glVertex2f((62 + x_shift3) * scale_factor3, (12 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (32 + y_shift3) * scale_factor3);
    glVertex2f((74 + x_shift3) * scale_factor3, (12 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(86, 68, 35);
    glVertex2f((67 + x_shift3) * scale_factor3, (5 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (40 + y_shift3) * scale_factor3);
    glVertex2f((69 + x_shift3) * scale_factor3, (5 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (10 + y_shift3) * scale_factor3);
    glVertex2f((71 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (13 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (12 + y_shift3) * scale_factor3);
    glVertex2f((65 + x_shift3) * scale_factor3, (22 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (15 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
    glVertex2f((70 + x_shift3) * scale_factor3, (30 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (23 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(86, 68, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (22 + y_shift3) * scale_factor3);
    glVertex2f((66 + x_shift3) * scale_factor3, (32 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (25 + y_shift3) * scale_factor3);
glEnd();



}

void summer_night_trees()
{

    //tree 2

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f(0, 33);
    glVertex2f(3, 48);
    glVertex2f(6, 33);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f(-2, 23);
    glVertex2f(3, 41);
    glVertex2f(8, 23);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f(-3, 15);
    glVertex2f(3, 35);
    glVertex2f(9, 15);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(2, 8);
    glVertex2f(3, 43);
    glVertex2f(4, 8);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(3, 13);
    glVertex2f(6, 23);
    glVertex2f(3, 16);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(3, 15);
    glVertex2f(0, 25);
    glVertex2f(3, 18);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(3, 23);
    glVertex2f(5, 33);
    glVertex2f(3, 26);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(3, 25);
    glVertex2f(1, 35);
    glVertex2f(3, 28);
glEnd();



    //tree 1

    glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f(-10, 30);
    glVertex2f(-7, 45);
    glVertex2f(-4, 30);
    glEnd();

    glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f(-12, 20);
    glVertex2f(-7, 38);
    glVertex2f(-2, 20);
    glEnd();

    glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f(-13, 12);
    glVertex2f(-7, 32);
    glVertex2f(-1, 12);
    glEnd();

    glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(-8, 5);
    glVertex2f(-7, 40);
    glVertex2f(-6, 5);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(-7, 10);
    glVertex2f(-4, 20);
    glVertex2f(-7, 13);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(-7, 12);
    glVertex2f(-10, 22);
    glVertex2f(-7, 15);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(-7, 20);
    glVertex2f(-5, 30);
    glVertex2f(-7, 23);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(-7, 22);
    glVertex2f(-9, 32);
    glVertex2f(-7, 25);
    glEnd();


    //tree 3

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f(40, 30);
    glVertex2f(43, 45);
    glVertex2f(46, 30);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f(38, 20);
    glVertex2f(43, 38);
    glVertex2f(48, 20);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f(37, 12);
    glVertex2f(43, 32);
    glVertex2f(49, 12);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(42, 5);
    glVertex2f(43, 40);
    glVertex2f(44, 5);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(43, 10);
    glVertex2f(46, 20);
    glVertex2f(43, 13);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(43, 12);
    glVertex2f(40, 22);
    glVertex2f(43, 15);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(43, 20);
    glVertex2f(45, 30);
    glVertex2f(43, 23);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(43, 22);
    glVertex2f(41, 32);
    glVertex2f(43, 25);
glEnd();


//tree 4

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f(55, 34);
    glVertex2f(58, 49);
    glVertex2f(61, 34);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f(53, 24);
    glVertex2f(58, 42);
    glVertex2f(63, 24);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f(52, 16);
    glVertex2f(58, 36);
    glVertex2f(64, 16);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(57, 9);
    glVertex2f(58, 44);
    glVertex2f(59, 9);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(58, 14);
    glVertex2f(61, 24);
    glVertex2f(58, 17);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(58, 16);
    glVertex2f(55, 26);
    glVertex2f(58, 19);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(58, 24);
    glVertex2f(60, 34);
    glVertex2f(58, 27);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(58, 26);
    glVertex2f(56, 36);
    glVertex2f(58, 29);
glEnd();


//tree 3

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f(65, 30);
    glVertex2f(68, 45);
    glVertex2f(71, 30);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f(63, 20);
    glVertex2f(68, 38);
    glVertex2f(73, 20);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f(62, 12);
    glVertex2f(68, 32);
    glVertex2f(74, 12);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(67, 5);
    glVertex2f(68, 40);
    glVertex2f(69, 5);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(68, 10);
    glVertex2f(71, 20);
    glVertex2f(68, 13);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(68, 12);
    glVertex2f(65, 22);
    glVertex2f(68, 15);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(68, 20);
    glVertex2f(70, 30);
    glVertex2f(68, 23);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(68, 22);
    glVertex2f(66, 32);
    glVertex2f(68, 25);
glEnd();


//tree 6

GLfloat scale_factor = 0.3;
GLfloat y_shift = 190;
GLfloat x_shift = 10;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f((65 + x_shift) * scale_factor, (30 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (45 + y_shift) * scale_factor);
    glVertex2f((71 + x_shift) * scale_factor, (30 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f((63 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (38 + y_shift) * scale_factor);
    glVertex2f((73 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f((62 + x_shift) * scale_factor, (12 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (32 + y_shift) * scale_factor);
    glVertex2f((74 + x_shift) * scale_factor, (12 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + x_shift) * scale_factor, (5 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (40 + y_shift) * scale_factor);
    glVertex2f((69 + x_shift) * scale_factor, (5 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift) * scale_factor, (10 + y_shift) * scale_factor);
    glVertex2f((71 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (13 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift) * scale_factor, (12 + y_shift) * scale_factor);
    glVertex2f((65 + x_shift) * scale_factor, (22 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (15 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
    glVertex2f((70 + x_shift) * scale_factor, (30 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (23 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift) * scale_factor, (22 + y_shift) * scale_factor);
    glVertex2f((66 + x_shift) * scale_factor, (32 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (25 + y_shift) * scale_factor);
glEnd();




//tree 6

GLfloat tree_scale_factor = 0.3;
GLfloat tree_y_shift = 190;
GLfloat tree_x_shift = 25;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f((65 + tree_x_shift) * tree_scale_factor, (30 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (45 + tree_y_shift) * tree_scale_factor);
    glVertex2f((71 + tree_x_shift) * tree_scale_factor, (30 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f((63 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (38 + tree_y_shift) * tree_scale_factor);
    glVertex2f((73 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f((62 + tree_x_shift) * tree_scale_factor, (12 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (32 + tree_y_shift) * tree_scale_factor);
    glVertex2f((74 + tree_x_shift) * tree_scale_factor, (12 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + tree_x_shift) * tree_scale_factor, (5 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (40 + tree_y_shift) * tree_scale_factor);
    glVertex2f((69 + tree_x_shift) * tree_scale_factor, (5 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (10 + tree_y_shift) * tree_scale_factor);
    glVertex2f((71 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (13 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (12 + tree_y_shift) * tree_scale_factor);
    glVertex2f((65 + tree_x_shift) * tree_scale_factor, (22 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (15 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
    glVertex2f((70 + tree_x_shift) * tree_scale_factor, (30 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (23 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (22 + tree_y_shift) * tree_scale_factor);
    glVertex2f((66 + tree_x_shift) * tree_scale_factor, (32 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (25 + tree_y_shift) * tree_scale_factor);
glEnd();



    //tree 6

GLfloat scale_factor1 = 0.3;
GLfloat y_shift1 = 190;
GLfloat x_shift1 = 175;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f((65 + x_shift1) * scale_factor1, (30 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (45 + y_shift1) * scale_factor1);
    glVertex2f((71 + x_shift1) * scale_factor1, (30 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f((63 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (38 + y_shift1) * scale_factor1);
    glVertex2f((73 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f((62 + x_shift1) * scale_factor1, (12 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (32 + y_shift1) * scale_factor1);
    glVertex2f((74 + x_shift1) * scale_factor1, (12 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + x_shift1) * scale_factor1, (5 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (40 + y_shift1) * scale_factor1);
    glVertex2f((69 + x_shift1) * scale_factor1, (5 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (10 + y_shift1) * scale_factor1);
    glVertex2f((71 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (13 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (12 + y_shift1) * scale_factor1);
    glVertex2f((65 + x_shift1) * scale_factor1, (22 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (15 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
    glVertex2f((70 + x_shift1) * scale_factor1, (30 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (23 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (22 + y_shift1) * scale_factor1);
    glVertex2f((66 + x_shift1) * scale_factor1, (32 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (25 + y_shift1) * scale_factor1);
glEnd();



//tree 6

GLfloat scale_factor2 = 0.3;
GLfloat y_shift2 = 190;
GLfloat x_shift2 = -80;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f((65 + x_shift2) * scale_factor2, (30 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (45 + y_shift2) * scale_factor2);
    glVertex2f((71 + x_shift2) * scale_factor2, (30 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f((63 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (38 + y_shift2) * scale_factor2);
    glVertex2f((73 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f((62 + x_shift2) * scale_factor2, (12 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (32 + y_shift2) * scale_factor2);
    glVertex2f((74 + x_shift2) * scale_factor2, (12 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + x_shift2) * scale_factor2, (5 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (40 + y_shift2) * scale_factor2);
    glVertex2f((69 + x_shift2) * scale_factor2, (5 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (10 + y_shift2) * scale_factor2);
    glVertex2f((71 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (13 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (12 + y_shift2) * scale_factor2);
    glVertex2f((65 + x_shift2) * scale_factor2, (22 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (15 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
    glVertex2f((70 + x_shift2) * scale_factor2, (30 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (23 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (22 + y_shift2) * scale_factor2);
    glVertex2f((66 + x_shift2) * scale_factor2, (32 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (25 + y_shift2) * scale_factor2);
glEnd();


//tree 6

GLfloat scale_factor3 = 0.3;
GLfloat y_shift3 = 185;
GLfloat x_shift3 = 17.5;

glBegin(GL_POLYGON); // tree 1 leave 1
    glColor3ub(0, 64, 0);
    glVertex2f((65 + x_shift3) * scale_factor3, (30 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (45 + y_shift3) * scale_factor3);
    glVertex2f((71 + x_shift3) * scale_factor3, (30 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 2
    glColor3ub(0, 64, 0);
    glVertex2f((63 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (38 + y_shift3) * scale_factor3);
    glVertex2f((73 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree 1 leave 3
    glColor3ub(0, 64, 0);
    glVertex2f((62 + x_shift3) * scale_factor3, (12 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (32 + y_shift3) * scale_factor3);
    glVertex2f((74 + x_shift3) * scale_factor3, (12 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + x_shift3) * scale_factor3, (5 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (40 + y_shift3) * scale_factor3);
    glVertex2f((69 + x_shift3) * scale_factor3, (5 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (10 + y_shift3) * scale_factor3);
    glVertex2f((71 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (13 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (12 + y_shift3) * scale_factor3);
    glVertex2f((65 + x_shift3) * scale_factor3, (22 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (15 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
    glVertex2f((70 + x_shift3) * scale_factor3, (30 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (23 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (22 + y_shift3) * scale_factor3);
    glVertex2f((66 + x_shift3) * scale_factor3, (32 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (25 + y_shift3) * scale_factor3);
glEnd();



}

void winter_trees()
{

    //tree 2



glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(2, 8);
    glVertex2f(3, 43);
    glVertex2f(4, 8);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(3, 13);
    glVertex2f(6, 23);
    glVertex2f(3, 16);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(3, 15);
    glVertex2f(0, 25);
    glVertex2f(3, 18);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(3, 23);
    glVertex2f(5, 33);
    glVertex2f(3, 26);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(3, 25);
    glVertex2f(1, 35);
    glVertex2f(3, 28);
glEnd();



    //tree 1


    glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(-8, 5);
    glVertex2f(-7, 40);
    glVertex2f(-6, 5);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(-7, 10);
    glVertex2f(-4, 20);
    glVertex2f(-7, 13);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(-7, 12);
    glVertex2f(-10, 22);
    glVertex2f(-7, 15);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(-7, 20);
    glVertex2f(-5, 30);
    glVertex2f(-7, 23);
    glEnd();

    glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(-7, 22);
    glVertex2f(-9, 32);
    glVertex2f(-7, 25);
    glEnd();


    //tree 3



glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(42, 5);
    glVertex2f(43, 40);
    glVertex2f(44, 5);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(43, 10);
    glVertex2f(46, 20);
    glVertex2f(43, 13);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(43, 12);
    glVertex2f(40, 22);
    glVertex2f(43, 15);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(43, 20);
    glVertex2f(45, 30);
    glVertex2f(43, 23);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(43, 22);
    glVertex2f(41, 32);
    glVertex2f(43, 25);
glEnd();


//tree 4

glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(57, 9);
    glVertex2f(58, 44);
    glVertex2f(59, 9);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(58, 14);
    glVertex2f(61, 24);
    glVertex2f(58, 17);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(58, 16);
    glVertex2f(55, 26);
    glVertex2f(58, 19);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(58, 24);
    glVertex2f(60, 34);
    glVertex2f(58, 27);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(58, 26);
    glVertex2f(56, 36);
    glVertex2f(58, 29);
glEnd();


//tree 3



glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f(67, 5);
    glVertex2f(68, 40);
    glVertex2f(69, 5);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f(68, 10);
    glVertex2f(71, 20);
    glVertex2f(68, 13);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f(68, 12);
    glVertex2f(65, 22);
    glVertex2f(68, 15);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f(68, 20);
    glVertex2f(70, 30);
    glVertex2f(68, 23);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f(68, 22);
    glVertex2f(66, 32);
    glVertex2f(68, 25);
glEnd();


//tree 6

GLfloat scale_factor = 0.3;
GLfloat y_shift = 190;
GLfloat x_shift = 10;



glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + x_shift) * scale_factor, (5 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (40 + y_shift) * scale_factor);
    glVertex2f((69 + x_shift) * scale_factor, (5 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift) * scale_factor, (10 + y_shift) * scale_factor);
    glVertex2f((71 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (13 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift) * scale_factor, (12 + y_shift) * scale_factor);
    glVertex2f((65 + x_shift) * scale_factor, (22 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (15 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift) * scale_factor, (20 + y_shift) * scale_factor);
    glVertex2f((70 + x_shift) * scale_factor, (30 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (23 + y_shift) * scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift) * scale_factor, (22 + y_shift) * scale_factor);
    glVertex2f((66 + x_shift) * scale_factor, (32 + y_shift) * scale_factor);
    glVertex2f((68 + x_shift) * scale_factor, (25 + y_shift) * scale_factor);
glEnd();




//tree 6

GLfloat tree_scale_factor = 0.3;
GLfloat tree_y_shift = 190;
GLfloat tree_x_shift = 25;



glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + tree_x_shift) * tree_scale_factor, (5 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (40 + tree_y_shift) * tree_scale_factor);
    glVertex2f((69 + tree_x_shift) * tree_scale_factor, (5 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (10 + tree_y_shift) * tree_scale_factor);
    glVertex2f((71 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (13 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (12 + tree_y_shift) * tree_scale_factor);
    glVertex2f((65 + tree_x_shift) * tree_scale_factor, (22 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (15 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (20 + tree_y_shift) * tree_scale_factor);
    glVertex2f((70 + tree_x_shift) * tree_scale_factor, (30 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (23 + tree_y_shift) * tree_scale_factor);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (22 + tree_y_shift) * tree_scale_factor);
    glVertex2f((66 + tree_x_shift) * tree_scale_factor, (32 + tree_y_shift) * tree_scale_factor);
    glVertex2f((68 + tree_x_shift) * tree_scale_factor, (25 + tree_y_shift) * tree_scale_factor);
glEnd();



    //tree 6

GLfloat scale_factor1 = 0.3;
GLfloat y_shift1 = 190;
GLfloat x_shift1 = 175;


glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + x_shift1) * scale_factor1, (5 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (40 + y_shift1) * scale_factor1);
    glVertex2f((69 + x_shift1) * scale_factor1, (5 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (10 + y_shift1) * scale_factor1);
    glVertex2f((71 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (13 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (12 + y_shift1) * scale_factor1);
    glVertex2f((65 + x_shift1) * scale_factor1, (22 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (15 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (20 + y_shift1) * scale_factor1);
    glVertex2f((70 + x_shift1) * scale_factor1, (30 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (23 + y_shift1) * scale_factor1);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift1) * scale_factor1, (22 + y_shift1) * scale_factor1);
    glVertex2f((66 + x_shift1) * scale_factor1, (32 + y_shift1) * scale_factor1);
    glVertex2f((68 + x_shift1) * scale_factor1, (25 + y_shift1) * scale_factor1);
glEnd();



//tree 6

GLfloat scale_factor2 = 0.3;
GLfloat y_shift2 = 190;
GLfloat x_shift2 = -80;



glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + x_shift2) * scale_factor2, (5 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (40 + y_shift2) * scale_factor2);
    glVertex2f((69 + x_shift2) * scale_factor2, (5 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (10 + y_shift2) * scale_factor2);
    glVertex2f((71 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (13 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (12 + y_shift2) * scale_factor2);
    glVertex2f((65 + x_shift2) * scale_factor2, (22 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (15 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (20 + y_shift2) * scale_factor2);
    glVertex2f((70 + x_shift2) * scale_factor2, (30 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (23 + y_shift2) * scale_factor2);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift2) * scale_factor2, (22 + y_shift2) * scale_factor2);
    glVertex2f((66 + x_shift2) * scale_factor2, (32 + y_shift2) * scale_factor2);
    glVertex2f((68 + x_shift2) * scale_factor2, (25 + y_shift2) * scale_factor2);
glEnd();


//tree 6

GLfloat scale_factor3 = 0.3;
GLfloat y_shift3 = 185;
GLfloat x_shift3 = 17.5;



glBegin(GL_POLYGON); // tree 1 main branch
    glColor3ub(71, 53, 35);
    glVertex2f((67 + x_shift3) * scale_factor3, (5 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (40 + y_shift3) * scale_factor3);
    glVertex2f((69 + x_shift3) * scale_factor3, (5 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 1
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (10 + y_shift3) * scale_factor3);
    glVertex2f((71 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (13 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 2
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (12 + y_shift3) * scale_factor3);
    glVertex2f((65 + x_shift3) * scale_factor3, (22 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (15 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 3
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (20 + y_shift3) * scale_factor3);
    glVertex2f((70 + x_shift3) * scale_factor3, (30 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (23 + y_shift3) * scale_factor3);
glEnd();

glBegin(GL_POLYGON); // tree branch 4
    glColor3ub(71, 53, 35);
    glVertex2f((68 + x_shift3) * scale_factor3, (22 + y_shift3) * scale_factor3);
    glVertex2f((66 + x_shift3) * scale_factor3, (32 + y_shift3) * scale_factor3);
    glVertex2f((68 + x_shift3) * scale_factor3, (25 + y_shift3) * scale_factor3);
glEnd();



}

void update_mill(int value)
{

    mill_angle+=5.0f;
    if(mill_angle > 360.0)
    {
        mill_angle-=360;
    }
    glutPostRedisplay();


    glutTimerFunc(20, update_mill, 0); //Notify GLUT to call update again in 25 milliseconds
}

void windmill()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-11, 55);
    glVertex2f(-10.2, 66);
    glVertex2f(-9.8, 66);
    glVertex2f(-9, 55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.42, 0.23, 0.14);
    glVertex2f(-11.5, 55);
    glVertex2f(-8.5, 55);
    glVertex2f(-8.5, 54);
    glVertex2f(-11.5, 54);
    glEnd();


    glPushMatrix();
	glTranslatef(-10,66,0);
    glRotatef(mill_angle, 0.0f, 0.0f, 1.0);


    glBegin(GL_POLYGON);
    glColor3f(0.42, 0.23, 0.14);
    glVertex2f(-5, 0.5);
    glVertex2f(5, 0.5);
    glVertex2f(5, -0.5);
    glVertex2f(-5, -0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.42, 0.23, 0.14);

    glVertex2f(-0.5, 5);
    glVertex2f(0.5, 5);
    glVertex2f(0.5, -5);
    glVertex2f(-0.5, -5);
    glEnd();

    glPopMatrix();

    circle(1, -10, 66, 0.25, 0.25, 0.25);

}
char summer_day_text[] = "Summer Day";
char summer_night_text[] = "Summer Night";
char rainy_day_text[] = "Rainy Day";
char rainy_night_text[] = "Rainy Night";
char winter_day_text[] = "Winter Day";
char winter_night_text[] = "Winter Night";
char coffeetxt[] = "Coffee";
char mojotxt[] = "Mojo";

void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);

    }
}

void summer_day_text1()
{

    glPushMatrix();
    glTranslatef(-61.5, 39, 0);
    Sprint(0.0,0,summer_day_text);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(43.2, -18.2, 0);
    Sprint(0.0,0,mojotxt);
    glPopMatrix();
}

void rainy_day_text1()
{

    glPushMatrix();
    glTranslatef(-61.5, 39, 0);
    Sprint(0.0,0,rainy_day_text);
    glPopMatrix();


}

void summer_night_text1()
{

    glPushMatrix();
    glTranslatef(-61.5, 39, 0);
    Sprint(0.0,0,summer_night_text);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43.2, -18.2, 0);
    Sprint(0.0,0,mojotxt);
    glPopMatrix();
}

void rainy_night_text1()
{

    glPushMatrix();
    glTranslatef(-61.5, 39, 0);
    Sprint(0.0,0,rainy_night_text);
    glPopMatrix();
}

void winter_day_text1()
{

    glPushMatrix();
    glTranslatef(-61.5, 39, 0);
    Sprint(0.0,0,winter_day_text);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(43.2, -25, 0);
    Sprint(0.0,0,coffeetxt);
    glPopMatrix();

}

void winter_night_text1()
{

    glPushMatrix();
    glTranslatef(-61.5, 39, 0);
    Sprint(0.0,0,winter_night_text);
    glPopMatrix();
}



void dis();
void display1();



void init()
{
    glClearColor(0.5f, 0.5f, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}
void disback(int val)
{
    glutDisplayFunc(display1);
}

void display11() //winter night
{
    glClear(GL_COLOR_BUFFER_BIT);

	room();
	window();
	sky_n8();
	Star();



    winter_night_river();
    greenField_winter();
    road();
    bench();

    road();
    bench();
    car1();
    car2();
    moon();

    winter_hill();
    room_overwrite();
    night_lamp();
    night_houses();
    windmill();
    winter_trees();
    Snow(0.0);

    window_Grill();
    porda();
    small_Table();
    coffee();
    couch();

    table();
	monitor();
	pc();
	speaker();
    keybord();
    mouse();
    clock();

    chair();
    table_fan();
    winter_night_text1();

    glutTimerFunc(5000,disback,0);
	glutSwapBuffers();

	glFlush();
}


void display10(int val)
{
    glutDisplayFunc(display11);
}


void display9() //winter day
{
    glClear(GL_COLOR_BUFFER_BIT);

	room();
	window();
	winter_sky_day();



    winter_day_river();
    greenField_winter();
    road();
    bench();

    road();
    bench();
    car1();
    car2();
    winter_sun();

    winter_hill();
    room_overwrite();
    day_lamp();
    day_houses();
    windmill();
    winter_trees();
    Snow(0.0);

    window_Grill();
    porda();
    small_Table();
    coffee();
    couch();

    table();
	monitor();
	pc();
	speaker();
    keybord();
    mouse();
    clock();

    chair();
    table_fan();
    winter_day_text1();


    glutTimerFunc(5000,display10,0);
	glutSwapBuffers();

	glFlush();
}


void display8(int val)
{
    glutDisplayFunc(display9);
}



void display7() //rainy night
{
    glClear(GL_COLOR_BUFFER_BIT);

	room();
	window();
	sky_n8();



    rainy_night_river();
    greenField_night_summer();
    road();
    bench();

    road();
    bench();
    car1();
    car2();
    boat();
    rainy_hill();
    room_overwrite();

    night_lamp();
    night_houses();
    windmill();
    summer_night_trees();

    window_Grill();
    porda();
    small_Table();

    couch();

    table();
	monitor();
	pc();
	speaker();
    keybord();
    mouse();
    clock();

    chair();
    table_fan();
    rainy_night_text1();


    glutTimerFunc(5000,display8,0);
	glutSwapBuffers();

	glFlush();
}


void display6(int val)
{
    glutDisplayFunc(display7);
}


void display5() //rainy day
{
    glClear(GL_COLOR_BUFFER_BIT);

	room();
	window();
	rainy_sky_day();



    rainy_day_river();
    greenField_day_summer();
    road();
    bench();

    road();
    bench();
    car1();
    car2();
    boat();
    rainy_cloud();
    rainy_hill();
    room_overwrite();

    day_lamp();

    day_houses();
    windmill();
    summer_day_trees();

    rainy();

    window_Grill();
    porda();
    small_Table();
    couch();

    table();
	monitor();
	pc();
	speaker();
    keybord();
    mouse();
    clock();

    chair();
    table_fan();
    rainy_day_text1();

    glutTimerFunc(5000,display6,0);
	glutSwapBuffers();

	glFlush();
}


void display4(int val)
{
    glutDisplayFunc(display5);
}


void display3() //summer night
{
    glClear(GL_COLOR_BUFFER_BIT);

	room();
	window();
	sky_n8();
	Star();



    summer_night_river();
    greenField_night_summer();
    road();
    bench();

    road();
    bench();
    car1();
    car2();
    boat();
    moon();

    summer_hill();
    room_overwrite();
    night_lamp();
    night_houses();
    windmill();
    summer_night_trees();

    window_Grill();
    porda();
    small_Table();
    mojo();
    couch();

    table();
	monitor();
	pc();
	speaker();
    keybord();
    mouse();
    clock();

    chair();
    table_fan();
    summer_night_text1();


    glutTimerFunc(5000,display4,0);
	glutSwapBuffers();

	glFlush();
}

void display2(int val)
{

    glutDisplayFunc(display3);

}

void display1() //summer day
{

    glClear(GL_COLOR_BUFFER_BIT);

	room();
	window();
	summer_sky_day();


    summer_day_river();
    greenField_day_summer();
    road();
    bench();

    road();
    bench();
    car1();
    car2();
    boat();
    summer_sun();
    summer_cloud();

    summer_hill();
    room_overwrite();
    day_lamp();
    day_houses();
    windmill();
    summer_day_trees();

    window_Grill();
    porda();
    small_Table();
    mojo();
    couch();

    table();

	monitor();
	pc();
	speaker();
    keybord();
    mouse();
    clock();

    chair();
    table_fan();
    summer_day_text1();



    glutTimerFunc(5000,display2,0);
	glutSwapBuffers();

	glFlush();

}

void dis()
{
    glutDisplayFunc(display1);
}

void mykeyboard(unsigned char key, int x, int y){



    if( key=='s' || key=='S' )
    {
        car=1;
    }
    else if( key=='b' || key=='B' )
    {
        car=0;
    }


    else if (key=='j' || key=='J')
    {
        bt=1;

    }

    else if (key=='k' || key=='K')
    {
        bt=0;

    }

    else if (key=='F' || key=='f')
    {
        fan=1;

    }

    else if (key=='G' || key=='g')
    {
        fan=0;

    }



}



int main(int argc, char** argv)
{

    cout<<"!!!!!!!!!!!!!!!!!!!!- Please Follow The Instructions -!!!!!!!!!!!!!!!!!!!!"<<endl<<endl;
    cout<<"Press : S or s To start the car"<<endl;
    cout<<"Press : B or b To stop the car"<<endl;
    cout<<"Press : J or j To start the boat"<<endl;
    cout<<"Press : K or k To stop the car"<<endl;
    cout<<"Press : F or f To start the boat"<<endl;
    cout<<"Press : G or g To stop the car"<<endl<<endl;

    cout<<"---------------------------- Enjoy The Scenario ---------------------------"<<endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("cg.project.io");

	glutDisplayFunc(dis);
    glutKeyboardFunc(mykeyboard);
	init();


    glutTimerFunc(2, update_car, 0);
    glutTimerFunc(2, update_cloud, 0);
    glutTimerFunc(2, update_boat, 0);
    glutTimerFunc(2, update_clock1, 0);
    glutTimerFunc(2, update_clock2, 0);
    glutTimerFunc(2, update_fan, 0);
    glutTimerFunc(2, update_mill, 0);
	glutMainLoop();
	return 0;
}
