#include <GL/glut.h>
#include <GL/gl.h>
#include "ObjectHandler.h"
#include <stdio.h>

Point *p = new Point(2,2,2);
Object o(p);

void init (void) {
/*  select clearing (background) color       */
    glClearColor(1.0, 1.0, 1.0, 1.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 10, 0.0, 10, 0.0, 10.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Point* points = o.getPoints();
    glColor3f(1,0,1);
    glBegin(GL_QUADS);
        for (int i =0; i<o.getPointsSize(); i++) {
            printf("%f %f %f\n",points[i].x,points[i].y,points[i].z);
            glVertex3f(points[i].x,points[i].y,points[i].z);
        }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
/*    ObjectHandler::scale(o,2,2,2);
    ObjectHandler::translate(o,2,2,2);*/
    //o = ObjectHandler::rotate(o,45,0);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Map Editor");
    glEnable(GL_DEPTH_TEST);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
