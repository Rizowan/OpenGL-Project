#include<windows.h>
#include<GL/glut.h>

void init(){
    glClearColor(0,0,0,0);
    glOrtho(-60, 60, -50, 50, -1, 1);
}

void drawLine(float x1, float y1, float x2,float y2){
    float a=x1, b=y1,c=x2,d=y2;
glLineWidth(1);
glColor3f(.0, .0, 0.0);
glBegin(GL_LINES);
glVertex2f(a, b);
glVertex2f(c, d);
glEnd();
glFlush();
}
void windowLine(float x1, float y1, float x2,float y2){
    float a=x1, b=y1,c=x2,d=y2;
glLineWidth(3);
glColor3f(.85f, .85f, .85f);
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

void windowBottom(float x1,float y1,float x2,float y2,float x3, float y3, float x4, float y4){
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

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    //walls
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

    /*drawLine(-23,26.4,-23,-6.2);
    drawLine(-25,26.2,-25,-6.2);
    drawLine(-30, 25.5,-30,-6.2);
    drawLine(-35, 24.5,-35,-6 );
    drawLine(-37, 24.2,-37,-6 );*/

    //window bottom brick
     windowBottom(-21,23.5, -39,20.8, -39,19.3, -21,22);

     for(int i=1;i<=4;i++){
        windowBottom(-21,23.5-(5.7*i), -39,20.8-(5.7*i), -39,19.3-(5.7*i), -21,22-(5.7*i));
     }

     //under bottom white wall
     drawQuad(-21,22, -39,19.3, -39,18.3, -21,21);
     for(int i=1;i<=4;i++){
        drawQuad(-21,22-(5.7*i), -39,19.3-(5.7*i), -39,18.3-(5.7*i), -21,21-(5.7*i));
     }
     //window separator
     drawQuad(-27,26,-28, 25.8,-28,-6,-27,-6.2);
     drawQuad(-32, 25.2,-33, 25,-33,-6,-32,-6.2);

     //black lines
     drawLine(-20,28,-20,-7);
     drawLine(3,19,3,-6);
     drawLine(14,21,14,-6);


}


int main(){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("IUBAT");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

