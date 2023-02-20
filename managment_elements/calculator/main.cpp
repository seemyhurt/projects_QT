#include <QtWidgets/QtWidgets>
#include <QApplication>
#include "calculator.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Calculator calculator;
    calculator.setWindowTitle("Calculator");
    calculator.resize(230, 200);

    calculator.show();
    return a.exec();
}
