#include<windows.h>
#include<GL/glut.h>

void init(){
    glClearColor(0,0,0,0);
    glOrtho(-70, 70, -60, 60, -1, 1);
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

void drawQuad(float x1,float y1,float x2,float y2,float x3, float y3, float x4, float y4){
    float a=x1,b=y1,c=x2,d=y2,e=x3,f=y3,g=x4,h=y4;
    glColor3f(1.0f, 1.0f, 1.0f);
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
     glColor3f(1.0f, 1.0f, 1.0f);

     drawQuad(-40,25,-40,-6,-20,-7,-20,28);
     drawQuad(-20,28,3,18.5,3,-6,-20,-7);
     drawQuad(3,18.5,3,-6,14,-6,14,21);
     drawQuad(14,-6,14,21,32,15,32,-5);

     drawLine(-20,28,-20,-7);
     drawLine(3,18.5,3,-6);
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

