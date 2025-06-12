#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWidget widget;
    widget.setWindowTitle("Аффинные преобразования пятиугольника");
    widget.resize(600, 500);
    widget.show();

    return app.exec();
}
