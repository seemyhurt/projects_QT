#include "ogldraw.h"
#include "qopenglcontext.h"
#include "qopenglfunctions.h"
OGLDraw::OGLDraw(QWidget *pwgt) : QOpenGLWidget(pwgt)
{
}
void OGLDraw::initializeGL(){
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
void OGLDraw::resizeGL(int nWidth, int nHeight){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    glOrtho(0, 400, 200, 0, -1, 1);
}
void OGLDraw::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw(0, 0, GL_POINTS);
    draw(100, 0, GL_LINES);
    draw(200, 0, GL_LINE_STRIP);
    draw(300, 0, GL_LINE_LOOP);
    draw(0, 100, GL_TRIANGLE_STRIP);
    draw(100, 100, GL_POLYGON);
    draw(200, 100, GL_QUADS);
    draw(300, 100, GL_TRIANGLES);
}
void OGLDraw::draw(int xOffset, int yOffset, GLenum type){
    int n = 8;
    glPointSize(2);
    glBegin (type);
    glColor3f(0, 0, 0);
    for (int i = 0; i < n; ++i){
        float fAngle = 2 * 3.14 * i / n;
        int х = (int) (50 + cos(fAngle) * 40 + xOffset);
        int у = (int) (50 + sin(fAngle) * 40 + yOffset);
        glVertex2f (х, у) ;
    }
    glEnd();
}
