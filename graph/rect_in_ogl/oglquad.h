#ifndef OGLQUAD_H
#define OGLQUAD_H
#include <QOpenGLWidget>
class OGLQuad : public QOpenGLWidget
{
protected:
    virtual void initializeGL();
    virtual void resizeGL (int nWidth, int nHeight);
    virtual void paintGL();
public:
    OGLQuad(QWidget* pwgt = 0);
};
#endif // OGLQUAD_H
