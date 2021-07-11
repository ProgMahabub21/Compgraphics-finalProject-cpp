#include <windows.h>
#include <GL/glut.h>
#include <math.h>

int _angle1 = 0;
void Border()
{
    glBegin(GL_LINES);
    glColor3ub(0, 255, 0);
    glVertex2f(0, 300);
    glVertex2f(500, 300);
    glEnd();

}
void Mountain()
{
    glBegin(GL_POLYGON);
    glColor3ub(107, 107, 71);
    glVertex2f(85, 430);
    glColor3ub(14, 89, 7);
    glVertex2f(100, 455);
    glVertex2f(200, 300);
    glColor3ub(72, 36, 20);
    glVertex2f(170, 300);
    // glVertex2f(0, 300);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3ub(107, 107, 71);
    glVertex2f(0, 350);
    glVertex2f(80, 450);
    glColor3ub(12, 20, 30);
    glVertex2f(140, 380);
    glVertex2f(170, 300);
    glVertex2f(0, 300);
    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(79, 92, 89);
    glVertex2f(160, 360);
    glColor3ub(14, 89, 7);
   // glColor3ub(90, 113, 125);
    glVertex2f(260, 480);
    glColor3ub(107, 107, 71);
    glVertex2f(330, 360);
    glColor3ub(72, 36, 20);
    glVertex2f(380, 300);
    glColor3ub(12, 20, 30);
    glVertex2f(200, 300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(107, 107, 71);
    glVertex2f(330,360);
    glVertex2f(420, 450);
    glVertex2f(500, 370);
    glVertex2f(500, 300);
    glVertex2f(380, 300);
    glEnd();
}


void SmallMountain(int x,int y)
{
    glBegin(GL_POLYGON);
    glColor3ub(46, 43, 43);
    glVertex2f(0+x, 370+y);
    glVertex2f(15+x, 400+y);
    glVertex2f(30+x, 360+y);
    glVertex2f(0+x, 350+y);
    glEnd();
}

void outliner()
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0,350);
    glVertex2f(80, 450);
    glVertex2f(80, 450);
    glVertex2f(140, 380);
    glVertex2f(140, 380);
    glVertex2f(170, 300);
    glVertex2f(90, 435);
    glVertex2f(100, 455);
    glVertex2f(100, 455);
    glVertex2f(200, 300);
    glVertex2f(260, 480);
    glVertex2f(330, 360);
    glVertex2f(330, 360);
    glVertex2f(380, 300);
    glVertex2f(330, 360);
    glVertex2f(420, 450);
    glVertex2f(420, 450);
    glVertex2f(500, 370);

    glEnd();
}
void scaledMountain()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.1f, -2.0f, 0.0f);
    SmallMountain(320, 10);
    glPopMatrix();
}

void circle(int xx, int yy, float r)
{

    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    glColor3ub(252, 186, 3);     //midday sun color palatte
   // glColor3ub(128, 128, 128);
    for (int i = 0; i < 200; i++)
    {
        // glColor3ub(255, 215, 0);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
       // float r = 4.0f;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xx, y + yy);
    }
    glEnd();
}

void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(51, 190, 255);
    glVertex2f(0,300);
    glVertex2f(500, 300);
    glVertex2f(500, 500);
    glVertex2f(0, 500);

    glEnd();
}
void field()
{
    glBegin(GL_QUADS);          //greeny
    glColor3ub(0, 77, 0);
    glVertex2f(0, 300);
    glColor3ub(255.0, 255.0, 0.0);
    glVertex2f(500, 300);
    glColor3ub(0, 51, 0);
    glVertex2f(500, 200);
    glColor3ub(0, 153, 0);
    glVertex2f(0, 200);
    glEnd();

    
    glBegin(GL_QUADS);      //muddy
    glColor3ub(0, 77, 0);
    glVertex2f(0, 0);
    glColor3ub(103, 146, 125);
    glVertex2f(500, 0);
    glColor3ub(144, 120, 48);
    glVertex2f(500, 80);
    glColor3ub(179, 89, 0);
    glVertex2f(0, 80);

    glEnd();
    
}
void Grass()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glScalef(0.2f, 0.1f, 0.0f); 
    glBegin(GL_TRIANGLES);//low-leaf-left
    glVertex2f(75, 100);
    glVertex2f(50, 175);
    glVertex2f(100, 100);
    glEnd();
    glBegin(GL_TRIANGLES);//low-leaf-right
    glVertex2f(125, 100);
    glVertex2f(150, 175);
    glVertex2f(100, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(87.5, 100);//mid-leaf-left
    glVertex2f(75, 225);
    glVertex2f(100, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(112.5, 100);//mid-leaf-right
    glVertex2f(125, 225);
    glVertex2f(100, 100);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(92.5, 100);//top-leaf-mid
    glVertex2f(100, 275);
    glVertex2f(107.5, 100);
    glEnd();

    glPopMatrix();
}
void Road()
{
    int x = 0,y=0;
glColor3ub(15, 15, 10); // Clear the color buffer (background)
glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
glVertex2f(0,200);
glVertex2f(500,200);
glVertex2f(500,80);
glVertex2f(0,80);

glEnd();
glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(x, 140);
glVertex2f(y+45, 140);
glEnd();

glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(x+90, 140);
glVertex2f(y+135, 140);
glEnd();

glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(x+180, 140);
glVertex2f(y+225, 140);
glEnd();

glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(x+270, 140);
glVertex2f(y+315, 140);
glEnd();

glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(x+360, 140);
glVertex2f(y+405, 140);
glEnd();

glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2f(x + 450, 140);
glVertex2f(y + 495, 140);
glEnd();

glBegin(GL_LINES);          //road barrier
glColor3ub(96, 97, 101);
glLineWidth(5);
glVertex2f(500, 95);
glVertex2f(0, 95);
glVertex2f(500, 85);
glVertex2f(0, 85);
glVertex2f(500, 75);
glVertex2f(0, 75);
glEnd();

glBegin(GL_LINES);      //barrier fench        
glColor3ub(128, 64, 0);
glLineWidth(10);
int j = 0;
for (int i = 0; i < 20; i++)
{
    glVertex2f(10+j, 100);
    glVertex2f(10+j, 70);
    j += 25;
}

glEnd();
}
void Grassloop()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    for(int col=0;col<6;col++)
    {

    glTranslatef(-10.0f, 0.0f, 0.0f);   //for once
    Grass();
    for (int time = 0; time < 32; time++)
    {
        glTranslatef(15.0f, 0.0f, 0.0f);
        Grass();
    }
    glTranslatef(-470.0f, 10.0f, 0.0f);   //for once
    }
    glPopMatrix();
}
void circle()
{
    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    // glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(7.5);
    glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(128, 128, 128);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 30;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }

    //glVertex2f(0.3f,0.4f);
    //glVertex2f(0.1f,0.4f);

    glEnd();
}

void cloud()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(20, 95.5, 0);
    circle();

    glTranslatef(15, 2.5, 0);
    circle();

    glTranslatef(20, 5, 0);
    circle();

    glTranslatef(30, 2.5, 0);
    circle();

    glTranslatef(0, -2.5, 0);
    circle();

    glTranslatef(0, -5, 0);
    circle();

    glTranslatef(0, -7.5, 0);
    circle();

    glPopMatrix();

    // glutSwapBuffers();
}

void movingCloude()
{

    glPushMatrix();
    glTranslatef(60, 400, 0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.5, 0.5, 1);
    glTranslatef(_angle1 % 1000, 0, 0);
    glPushMatrix();
    glTranslatef(-100, 0, 0);
    cloud();
    glTranslatef(200, 35, 0);
    cloud();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    // glutSwapBuffers();
}
void update(int value)
{

    _angle1 += 1.0f;
    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(20, update, 0); //Notify GLUT to call update again in 25 milliseconds
}
void treeRoot()
{
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
   // glVertex2f(25,80);
    glVertex2f(30, 200);
    glVertex2f(25, 200);
    glVertex2f(25, 350);
    glVertex2f(30, 350);
    glEnd();

}
void treeBody()
{
    
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glVertex2f(10,220);
    glVertex2f(27.5,215);
    glVertex2f(45, 220);
    glVertex2f(27.5, 250);
    glEnd();
}
void treeborder()
{
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(0, 153, 0);
    glVertex2f(10, 220);
    glVertex2f(27.5, 215);
    glVertex2f(27.5, 215);
    glVertex2f(45, 220);
    glVertex2f(45, 220);
    glVertex2f(27.5, 250);
    glVertex2f(27.5, 250);
    glVertex2f(10, 220);
    glEnd();



}
void tree()
{
    treeRoot();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    treeBody();
    treeborder();
    
    for (int i = 1; i < 7; i++)
    {
        glScalef(0.9, 1, 0);
        glTranslatef(3, 19, 0);   // for 0.8 is 6.8 
        treeBody();
        treeborder();
       // glTranslatef(-4.8, -5, 0);
        
    }
    glPopMatrix();
    
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(27, 363);
    glVertex2f(27, 215);
    glEnd();
    
}
void treeloop()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(20, 0, 0);
    tree();
    glTranslatef(-20, 0, 0);
    
    for (int i = 1; i < 9; i++)
    {
     //   glScalef(0.8, 1, 0);
        glTranslatef(80, 0, 0);   // for 0.9 is 3.0 
        tree();
        glTranslatef(-20, 0, 0);

    }
  
    glPopMatrix();
}
void output(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5);
    sky();
    Border();
    SmallMountain(0,0);
    SmallMountain(140, 0);
    SmallMountain(155, -2);
    SmallMountain(310, 03);
    SmallMountain(335, 07);
    //scaledMountain();
    circle(175, 440, 20);
    movingCloude();
    Mountain();
    outliner();
    field();
    Road();
 
    Grassloop();
 //   tree();
    treeloop();
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    //
    glutInitWindowSize(1024, 648);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Highway");
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(output);
    glutTimerFunc(20, update, 0); //Add a timer
    glutMainLoop();
    return 0;
}
