#include "mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setMouseTracking(true);
    m_plblX = new QLabel(this);
    m_plblY = new QLabel(this);
    statusBar()->addWidget(m_plblY);
    statusBar()->addWidget(m_plblX );
}
void MyMainWindow::mouseMoveEvent(QMouseEvent* pe)
{
    m_plblX->setText("X=" + QString().setNum(pe->x()));
    m_plblY->setText ("У=" + QString().setNum (pe->y()));
}
