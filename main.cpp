#include<windows.h>
#include<glut.h>
#include<math.h>
#include<iostream>
void init(){
    glClearColor(0,0,0,0);
    glOrtho(-50, 60, -30, 45, -10, 10);
}
int a=0; float b=0,c=0,d=0,e=0,f=0,g=0,h=0,s=0;
void animate(int v)
{

     a+=1;
     if(a%2==0)
        a=2;
     else
        a=1;
    // std::cout<<a<<std::endl;
     b-=.099;

     c-=.0070;

     d-=.015;

     e-=.06;

    /* if(e<=-75)
     {
        e=53;
     } */
    glutPostRedisplay();
    glutTimerFunc(100,animate,0);
}

void drawCircle(float x, float y, float radius){
    glPointSize(3);
    glBegin(GL_POLYGON);

    for(float i=0;i<=7;i+=.01)
        glVertex2f(x+radius*cos(i),y+radius*sin(i));
    glEnd();
}
void cloud(float x, float y){
    glColor3f(0.945, 0.956, 0.956);//light ash color
    drawCircle(x-10.5,y+1,1);
    drawCircle(x-8.5,y+2,1.5);
    drawCircle(x-6,y+4,2.5);
    drawCircle(x-4,y+2.5,2.5);
    drawCircle(x-2,y+2,1.5);
    drawCircle(x+2,y+2,2);
    drawCircle(x+4,y+1.5,1.5);
    drawCircle(x+6,y+1.5,1.2);
    drawCircle(x+8,y+1.3,1.3);
    drawCircle(x+10,y+1.2,.8);

    //for straight line below
    glColor3f(0.945, 0.956, 0.956);//light ash color
    glBegin(GL_QUADS);
    glVertex2f(x-9,y+2);
    glVertex2f(x+8,y+2);
    glColor3f(0.713, 0.8, 0.803);//dark ash color
    glVertex2f(x+13,y);
    glVertex2f(x-13,y);
    glEnd();
}
void sky(){
    //SKy
     glBegin(GL_QUADS);
        glVertex2f(60, -3);
        glColor3f(.6,.96,8);
        glVertex2f(60, 60);
        glColor3f(.10,.5,.70);
        glVertex2f(-60, 60);
        //glColor3f(.85,.83,.88);
        glVertex2f(-60, 3);
    glEnd();
    glFlush();
}
void drawLine(float x1, float y1, float x2,float y2, float width){
    float a=x1, b=y1,c=x2,d=y2, w=width;
glLineWidth(w);
glColor3f(.0, .0, 0.0);
glBegin(GL_LINES);
glVertex2f(a, b);
glVertex2f(c, d);
glEnd();
glFlush();
}
void whiteLine(float x1, float y1, float x2,float y2, float width){
    float a=x1, b=y1,c=x2,d=y2, w=width;
glLineWidth(w);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f(a, b);
glVertex2f(c, d);
glEnd();
glFlush();
}
void windowLine(float x1, float y1, float x2,float y2){
    float a=x1, b=y1,c=x2,d=y2;
glLineWidth(3);
glColor3f(.58f, .58f, .58f);
glBegin(GL_LINES);
glVertex2f(a, b);
glVertex2f(c, d);
glEnd();
glFlush();
}

void drawQuad(float x1,float y1,float x2,float y2,float x3, float y3, float x4, float y4){
    float a=x1,b=y1,c=x2,d=y2,e=x3,f=y3,g=x4,h=y4;
    glColor3f(.85f, .85f, .85f);
    glBegin(GL_QUADS);
        glVertex2f(a, b);   //full quad
        glVertex2f(c, d);
        glVertex2f(e, f);
        glVertex2f(g, h);
    glEnd();
    glFlush();
}

void drawColorQuad(float x1,float y1,float x2,float y2,float x3, float y3, float x4, float y4, float Red, float Green, float Blue){
    float a=x1,b=y1,c=x2,d=y2,e=x3,f=y3,g=x4,h=y4,rd=Red,gr=Green,bl=Blue;
    glColor3f(rd, gr, bl);
    glBegin(GL_QUADS);
        glVertex2f(a, b);   //full quad with color
        glVertex2f(c, d);
        glVertex2f(e, f);
        glVertex2f(g, h);
    glEnd();
    glFlush();
}
/////draw triangle//////////
void drawTriangle(float x1,float y1,float x2,float y2,float x3,float y3, float Red, float Green, float Blue){
    float a=x1,b=y1,c=x2,d=y2,e=x3,f=y3,re=Red,gr=Green,bl=Blue;
    glColor3f(re,gr,bl);
    glBegin(GL_TRIANGLES);
        glVertex2f(a,b);
        glVertex2f(c,d);
        glVertex2f(e,f);
    glEnd();
    glFlush();
}
void drawWindow(float x1,float y1,float x2,float y2,float x3, float y3, float x4, float y4){
        float a=x1,b=y1,c=x2,d=y2,e=x3,f=y3,g=x4,h=y4;
    glColor3f(0.65f, .72f, .86f);
    glBegin(GL_QUADS);
        glVertex2f(a, b);   //full quad
        glVertex2f(c, d);
        glVertex2f(e, f);
        glVertex2f(g, h);
    glEnd();
    glFlush();
}

void brick(float x1,float y1,float x2,float y2,float x3, float y3, float x4, float y4){
        float a=x1,b=y1,c=x2,d=y2,e=x3,f=y3,g=x4,h=y4;
    glColor3f(.49f, .35f, .36f);
    glBegin(GL_QUADS);
        glVertex2f(a, b);   //full quad
        glVertex2f(c, d);
        glVertex2f(e, f);
        glVertex2f(g, h);
    glEnd();
    glFlush();
}
void wallOne(){
    //walls white beneath
     drawQuad(-40,25, -40,-6, -20,-7, -20,28);
     drawQuad(-20,28, 3,19, 3,-6, -20,-7);
     drawQuad(3,19,3,-6,14,-6,14,21);
     drawQuad(14,-6,14,21,32,15,32,-5);

     //window
     drawWindow(-21,26.7, -27,26, -27,-6.2,-21,-6);
     drawWindow(-28, 25.8, -32, 25.2, -32,-6.2, -28,-6 );
     drawWindow(-33, 25, -39, 24, -39,-5.8, -33,-6 );

    //lines between windows
    windowLine(-23,26.4,-23,-6.2);
    windowLine(-25,26.2,-25,-6.2);
    windowLine(-30, 25.5,-30,-6.2);
    windowLine(-35, 24.5,-35,-6 );
    windowLine(-37, 24.2,-37,-6 );

    //window bottom brick
     brick(-21,23.5, -39,20.8, -39,19.3, -21,22);

     for(int i=1;i<=4;i++){
        brick(-21,23.5-(5.7*i), -39,20.8-(5.3*i), -39,19.3-(5.3*i), -21,22-(5.7*i));
     }

     //under bottom white wall
     drawQuad(-21,22, -39,19.3, -39,18.3, -21,21);
     for(int i=1;i<=4;i++){
        drawQuad(-21,22-(5.7*i), -39,19.3-(5.3*i), -39,18.3-(5.3*i), -21,21-(5.7*i));
     }
     //window separator white
     drawQuad(-27,26,-28, 25.8,-28,-6,-27,-6.2);
     drawQuad(-32, 25.2,-33, 25,-33,-6,-32,-6.2);
}

void wallTwo(){
    //window glass
    drawWindow(-19,26.7, -11,23.6, -11,-6.2,-19,-6.2);
    drawWindow(-10,23.2, -4,20.9, -4,-6.2, -10,-6.2);
    drawWindow(-3,20.5, 2.5,18.4, 2.5,-6,-3,-6);
    //lines between windows
    windowLine(-14,24.7,-14,-6.2);
    windowLine(-16,25.5,-16,-6.2);
    windowLine(-8,22.4,-8,-6.2);
    windowLine(-6,21.6, -6,-6.2);
    windowLine(-1,19.7, -1,-6);
    windowLine(1,19, 1,-6);
    //window bottom brick
    brick(-19,23.5, 2.5,15.5, 2.5,14.3, -19,22);
    for(int i=1; i<=4; i++){
        brick(-19,23.5-(5.7*i), 2.5,15.5-(4.2*i), 2.5,14.3-(4.2*i), -19,22-(5.7*i));
    }
    //window bottom white separator
    drawQuad(-19,22, 2.5,14.4, 2.5,13.5, -19,21);
    for(int i=1; i<=4; i++){
        drawQuad(-19,22-(5.7*i), 2.5,14.4-(4.2*i), 2.5,13.5-(4.2*i), -19,21-(5.7*i));
    }
    //window separator white
    drawQuad(-11,23.6, -10,23.2, -10,-6.2,-11,-6.2);
    drawQuad(-4,20.9,-3,20.5,-3,-6,-4,-6.2);
}
void wallThree(){
    drawWindow(3.5,18.4, 7,19.1, 7,-6, 3.5,-6); //window glass
    brick(10,19.5, 13.5,20.2, 13.5,-6, 10,-6);

    //window bottom brick
    brick(3.5,15.4, 7,16, 7,15, 3.5,14.4);
    brick(3.5,15.4-(4.2), 7,16-(4.2), 7,15-(4.2), 3.5,14.4-(4.2));
    brick(3.5,15.4-(4.5*2), 7,16-(4.5*2), 7,15-(4.6*2), 3.5,14.4-(4.5*2));
    brick(3.5,15.4-(4.5*3), 7,16-(4.5*3), 7,15-(4.6*3), 3.5,14.4-(4.5*3));
    brick(3.5,15.4-(4.5*4), 7,16-(4.6*4), 7,15-(4.6*4), 3.5,14.4-(4.5*4));
    //windows bottom white
    drawQuad(3.5,14.4, 13.5,16.2, 13.5,15.2, 3.5,13.4);
    for(int i=1; i<=4; i++){
        drawQuad(3.5,14.4-(4.5*i), 13.5,16.2-(4.7*i), 13.5,15.2-(4.7*i), 3.5,13.4-(4.4*i));
    }

    //washroom windows
    drawWindow(11,19, 12,19.2, 12,17.2, 11,17);
    drawWindow(11,14, 12,14.2, 12,12.2, 11,12);
    drawWindow(11,9, 12,9.2, 12,7.2, 11,7);
    drawWindow(11,4.4, 12,4.6, 12,2.6, 11,2.4);
    drawWindow(11,0.0, 12,0.2, 12,-1.6, 11,-1.8);

}

void wallFour(){
    brick(14.5,20, 22,17.6, 22,-5.4,  14.5,-5.8);
    drawWindow(23,17.3, 31,14.6, 31,-4.8, 23,-5.3);

    //windows between washrooms
    drawWindow(17.5,19, 19.5,18.4, 19.5,-5.4, 17.5,-5.3);
    //blue window separator
    windowLine(26,16.3, 26,-5);
    windowLine(29,15.2, 29,-5);
    //window bottom brick
    brick(14.5,17.2, 14.5,16.2, 31,11.5, 31,12.5);
    brick(14.5,17.2-4.7, 14.5,16.2-4.7, 31,11.5-3.9, 31,12.5-3.9);
    brick(14.5,17.2-4.7*2, 14.5,16.2-4.7*2, 31,11.5-3.9*2, 31,12.5-3.9*2);
    brick(14.5,17.2-4.7*3, 14.5,16.2-4.7*3, 31,11.5-3.8*3, 31,12.5-3.8*3);
    brick(14.5,17.2-4.7*4, 14.5,16.2-4.7*4, 31,11.5-3.8*4, 31,12.5-3.8*4);
    //window bottom white separator
    drawQuad(14.5,16.2, 14.5,15.2, 31,10.5, 31,11.5 );
    drawQuad(14.5,16.2-4.7, 14.5,15.2-4.7, 31,10.5-4, 31,11.5-4);
    drawQuad(14.5,16.2-4.7*2, 14.5,15.2-4.7*2, 31,10.5-3.9*2, 31,11.5-3.9*2);
    drawQuad(14.5,16.2-4.7*3, 14.5,15.2-4.7*3, 31,10.5-3.8*3, 31,11.5-3.8*3);
    drawQuad(14.5,16.2-4.7*4, 14.5,15.2-4.7*4, 31,10.5-3.7*4, 31,11.5-3.7*4);
}
void lemonLime(){
    //aud
    drawColorQuad(33,1, 33.8,1, 33.8,-2, 33,-2,         .73,.1,.03);
    drawColorQuad(40,1, 40.8,1, 40.8,-2, 40,-2,         .73,.1,.03); //pillars
    drawColorQuad(31,1, 42,3.8, 52,3.5, 63,0,           .5,.2,.2);drawLine(31,1, 42,3.8, 1); drawLine(31,1, 63,0, 1); drawLine(52,3.5, 63,0, 1);
    drawColorQuad(52,3.5, 57,3.2, 66,0, 63,0,            .5,.2,.2);
    drawTriangle(39,3.5,  55,3.0, 47,6.8,               .5,.2,.2);drawLine(55,3.0, 47,6.8, 1);
    drawColorQuad(47,6.8, 52,6.3, 58,3.2, 55,3.0,       .5,.2,.2);drawLine(58,3.2, 55,3.0, 1);
    drawLine(40,3.5, 54,3.0, 1);
    //canteen
    drawTriangle(13,-2.4, 26,1, 35,-2.4, /*color*/ .16,.2,.21 );
    drawColorQuad(26,1, 31,0.1, 40,-2.4, 35,-2.4,   .16,.2,.21 );
    drawLine(26,1, 35,-2.4, 1);drawLine(13,-2.4, 26,1, 1);drawLine(13,-2.4, 35,-2.4, 1);
    brick(16,-2.4, 32,-2.4, 32,-6.8, 16,-6);
    brick(32,-2.4, 38.5,-2.4, 38.5,-5.8, 32,-6.8); drawLine(32,-2.4, 32,-6.8, 1); drawLine(16,-2.4,16,-6,1);
    drawWindow(22,-3.1, 26,-3.1, 26,-5.8, 22,-5.7);
    //sitting place
    drawTriangle(35,-2.4, 48,.8, 61,-3, .16,.2,.21); drawLine(35,-2.4, 48,.8, 1); drawLine(48,.8, 61,-3, 1); drawLine(35,-2.4, 61,-3, 1);
    //fence bottom
    drawColorQuad(38,-2.4, 38.5,-2.4, 38.5,-6.8, 38,-6.8, .19,.16,.15);
    drawColorQuad(50,-2.6, 50.5,-2.6, 50.5,-6.8, 50,-6.8, .19,.16,.15);
    drawColorQuad(58,-2.7, 58.5,-2.7, 58.5,-6.8, 58,-6.8, .19,.16,.15);
    brick(16,-6, 63,-7, 63,-8, 16,-7); drawLine(16,-6, 63,-7, 1); //drawLine(63,-8, 16,-7, 1);


}
void grass(){
    drawColorQuad(-20,-7, 3,-6, 16,-6, 3,-8, .21,.40,.15);
    drawTriangle(16,-6, 3,-8, 16,-7, .21,.40,.15);
    drawColorQuad(3,-8, 16,-7, 63,-8, 63,-10, .21,.40,.15);
    drawColorQuad(-20,-7, -40,-6, -300,-60, -150,-50, .2,.55,.2);
    glBegin(GL_QUADS);
        glVertex2f(-20,-7);
        glColor3f(.21,.31,.15);
        glVertex2f(65,-10);
        glColor3f(.18,.66,.24);
        glVertex2f(60,-40);
        glColor3f(.18,.66,.24);
        glVertex2f(-150,-50);
    glEnd();
    glFlush();

}

void tree(GLdouble x, GLdouble y)
{
    //Tree leaves
    glColor3f(0.082, 0.478, 0.172);
    drawCircle(x,y,2);
    glColor3f(0.584, 0.752, 0.129);
    drawCircle(x-1,y-2,3);
    drawCircle(x-3,y-0.3,3);
    glColor3f(0.725, 0.858, 0.078);
    drawCircle(x-4,y+1.5,3);
    glColor3f(0.584, 0.752, 0.129);
    drawCircle(x-3.1,y+3.5,3);
    drawCircle(x-1.8,y+6.5,3.4);
    glColor3f(0.725, 0.858, 0.078);
    drawCircle(x+1.1,y+9.1,3);
    glColor3f(0.584, 0.752, 0.129);
    drawCircle(x+4,y+8,3);
    drawCircle(x+3,y+3,4);
    glColor3f(0.584, 0.752, 0.129);
    drawCircle(x+6.2,y+3.5,3);
    drawCircle(x+7.1,y+1.1,3);
    drawCircle(x+6.5,y-1,3);
    drawCircle(x+5,y-1.5,3);
    glColor3f(0.725, 0.858, 0.078);
    drawCircle(x+3.2,y-3.8,2.4);
    drawCircle(x+2.2,y-3.8,2.4);
    glColor3f(0.439, 0.631, 0.211);
    drawCircle(x+4,y+4.5,3.8);
    glColor3f(0.725, 0.858, 0.078);
    drawCircle(x+2.8,y+5.5,3.8);
    drawCircle(x+1.5,y+5.0,2);
    glColor3f(0.647, 0.776, 0.223);
    drawCircle(x+1.0,y+5.3,2.8);
    drawCircle(x+0.9,y+4.9,1.8);

    glColor3f(0.662, 0.298, 0.078);//tree branch
    glBegin(GL_QUADS);
    glVertex2f(x+1.5,y+2);
    glVertex2f(x+2.5,y+2);
    glVertex2f(x+3.0,y-12);
    glVertex2f(x+1.0,y-12);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);//2nd branch
    glBegin(GL_QUADS);
    glVertex2f(x+2.5,y-2);
    glVertex2f(x+2.5,y-3);
    glVertex2f(x+5.8,y+1);
    glVertex2f(x+5.8,y+1);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);//1st branch
    glBegin(GL_QUADS);
    glVertex2f(x+2.5,y+0);
    glVertex2f(x+2.5,y-0.8);
    glVertex2f(x+3.5,y+1);
    glVertex2f(x+4,y+1);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);//left 1st branch
    glBegin(GL_QUADS);
    glVertex2f(x+1.4,y+0);
    glVertex2f(x+1.5,y-1);
    glVertex2f(x+0.5,y+0.5);
    glVertex2f(x+0.2,y-0.01);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);//left 2nd branch
    glBegin(GL_QUADS);
    glVertex2f(x+2.5,y-2);
    glVertex2f(x+2.5,y-3);
    glVertex2f(x-0.2,y-0.2);
    glVertex2f(x-0.3,y-0.8);
    glEnd();

}

void tallTree(GLdouble x,GLdouble y)
{
    glColor3f(0.262, 0.741, 0.156);
    drawCircle(x+0,y+5,2);
    drawCircle(x-2,y+3,2);
    drawCircle(x-4,y+1,2);
    drawCircle(x-6,y-1,2);

    drawCircle(x+0,y+1,2);
    drawCircle(x-1.9,y+0,2);
    drawCircle(x+1.9,y+0,2);


    drawCircle(x+2,y+3,2);
    drawCircle(x+4,y+1,2);
    drawCircle(x+6,y-1,2);

    glColor3f(0.262, 0.741, 0.156);
    glBegin(GL_QUADS);
    glVertex2f(x-4,y-1);
    glVertex2f(x-6,y-3);
    glVertex2f(x+6,y-3);
    glVertex2f(x+4,y-1);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);
    glBegin(GL_QUADS);
    glVertex2f(x-1,y-3);
    glVertex2f(x-1.5,y-6);
    glVertex2f(x+1.5,y-6);
    glVertex2f(x+1,y-3);
    glEnd();
}

void drawTree(){
    glPushMatrix();
    glScalef(.5,1.3,0);
    tallTree(25,1);
    glPopMatrix();
    //trees under windows
    glPushMatrix();
    glScalef(.15,.20,0);
    tallTree(-285,-32);
    glPopMatrix();

    glPushMatrix();
    glScalef(.15,.20,0);
    tallTree(-330,-37);
    glPopMatrix();

    glPushMatrix();
    glScalef(.15,.20,0);
    tallTree(0,-28);
    glPopMatrix();

    glPushMatrix();
    glScalef(.15,.20,0);
    tallTree(-30,-30);
    glPopMatrix();

    glPushMatrix();
    glScalef(.15,.20,0);
    tallTree(-200,-29);
    glPopMatrix();

    glPushMatrix();
    glScalef(.15,.20,0);
    tallTree(-180,-30);
    glPopMatrix();
    //big trees
    glPushMatrix();
    glScalef(.7,.5,0);
    tree(45,-.8);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.1, .8, 0);
    tree(50,2);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.1, .8, 0);
    tree(-45,-2.5);
    glPopMatrix();
}
void fence(){
    drawColorQuad(-41,-6, -19,-6.5, -19,-7.5, -41,-7, .45,.43,.35);
    drawColorQuad(-19,-6.5, 3.5,-5.8, 3.5,-6.8, -19,-7.5, .45,.43,.35);
    drawColorQuad(3.5,-5.8, 11,-6, 11,-7, 3.5,-6.8, .45,.43,.35);
    drawColorQuad(11,-6, 15.5,-6, 15.5,-7, 11,-7, .45,.43,.35);
}
void animCloud(){
    glPushMatrix();
    glTranslatef(0-e,0,0);
    cloud(3,19);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0+e,0,0);
    cloud(30,35);
    glPopMatrix();
}
void draw(){
     glClear(GL_COLOR_BUFFER_BIT);

     sky();
     animCloud();
     wallOne();
     wallTwo();
     wallThree();
     wallFour();
     //black lines
     drawLine(-20,28,-20,-7, 1);
     drawLine(3,19,3,-6, 1);
     drawLine(14,21,14,-6, 1);

     lemonLime();
     glPushMatrix();
     grass();
     glPopMatrix();
     drawTree();
     fence();


     glutSwapBuffers();
}

int main(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("IUBAT");
    init();
    glutDisplayFunc(draw);
    glutTimerFunc(100,animate,0);
    glutMainLoop();
    return 0;
}
