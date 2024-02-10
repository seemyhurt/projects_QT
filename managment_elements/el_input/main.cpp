#include "widget.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QLabel* plblDisplay = new QLabel;
    plblDisplay->setFrameStyle(QFrame::Box | QFrame::Raised);
    plblDisplay->setLineWidth(2);
    plblDisplay->setFixedHeight(50);

    QLabel* plblText = new QLabel("&Text:");
    QLineEdit* ptxt= new QLineEdit;
    plblText->setBuddy(ptxt);
    QObject::connect(ptxt, SIGNAL(textChanged(const QString&) ),plblDisplay, SLOT(setText(const QString&)));

    QLabel* plblPassword = new QLabel("&Password:");
    QLineEdit* ptxtPassword = new QLineEdit;
    plblPassword->setBuddy(ptxtPassword);
    ptxtPassword->setEchoMode(QLineEdit::Password);
    QObject::connect(ptxtPassword, SIGNAL(textChanged(const QString&) ),plblDisplay, SLOT(setText(const QString&)));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(plblDisplay);
    pvbxLayout->addWidget(plblText);
    pvbxLayout->addWidget(ptxt);
    pvbxLayout->addWidget(plblPassword);
    pvbxLayout->addWidget(ptxtPassword);
    w.setLayout(pvbxLayout);
    w.show();
    return a.exec();
}
