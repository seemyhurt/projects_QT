﻿#include <QtWidgets>
#include <QApplication>
QImage brightness(const QImage& imgOrig, int n){
    QImage imgTemp = imgOrig;
    qint32 nHeight = imgTemp.height();
    qint32 nWidth = imgTemp.width();
    for (qint32 y = 0; y < nHeight; ++y){
        QRgb* tempLine = reinterpret_cast<QRgb*>(imgTemp.scanLine(y));
        for (qint32 х = 0; х < nWidth; ++х)
        {
            int r = qRed (*tempLine) + n;
            int g = qGreen(*tempLine) + n;
            int b = qBlue(*tempLine) + n;
            int a = qAlpha(*tempLine);
            *tempLine++ = qRgba(r > 255 ? 255 : r < 0 ? 0 : r,
                                g > 255 ? 255 : g < 0 ? 0 : g,
                                b > 255 ? 255 : b < 0 ? 0 : b,
                                a);
        }
    }
    return imgTemp;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QImage img(":/proto/picture.jpg") ;
    QHBoxLayout* phbx = new QHBoxLayout;
    phbx->setSpacing(0);
    for (int i = -150; i < 150; i += 50){
        QLabel* plbl = new QLabel;
        plbl->setFixedSize(img.size());
        plbl->setPixmap(QPixmap::fromImage(brightness(img,i)));
        phbx->addWidget(plbl);
    }
    w.setLayout(phbx);
    w.show();
    return a.exec();
}
