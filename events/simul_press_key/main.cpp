
#include <QApplication>
#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLineEdit txt("User input: ");
    txt.show();
    txt.resize(300, 20);
    int i;
    for (i = 0; i < Qt::Key_Z - Qt::Key_A + 1; ++i) {
        char c = (char)65 + i;
        QChar ch = c;
        int nKey = Qt::Key_A + i;
        QKeyEvent keyPress(QEvent::KeyPress, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, &keyPress);
        QKeyEvent keyRelease(QEvent::KeyRelease, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, &keyRelease);
    }
    return a.exec();
}
