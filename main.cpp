#include<windows.h>
#include<GL/glut.h>

void init(){
    glClearColor(0,0,0,0);
    glOrtho(-60, 60, -40, 40, -1, 1);
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
    brick(16,-6, 63,-7, 63,-8, 16,-7); drawLine(16,-6, 63,-7, 1); drawLine(63,-8, 16,-7, 1);


}
void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

     sky();
     wallOne();
     wallTwo();
     wallThree();
     wallFour();
     //black lines
     drawLine(-20,28,-20,-7, 1);
     drawLine(3,19,3,-6, 1);
     drawLine(14,21,14,-6, 1);

     lemonLime();
}

int main(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glEnable(GLUT_MULTISAMPLE);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("IUBAT");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
