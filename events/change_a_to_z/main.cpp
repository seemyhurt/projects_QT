#include <QtWidgets>
#include <QApplication>

class KeyFilter : public QObject {
protected:
    bool eventFilter(QObject* pobj, QEvent* pe){
        if (pe->type() == QEvent::KeyPress){
            if (((QKeyEvent*)pe)->key() == Qt::Key_Z) {
                QKeyEvent keyEvent (QEvent::KeyPress,
                                    Qt::Key_A,
                                    Qt::NoModifier,
                                    "А");
                QApplication::sendEvent(pobj, &keyEvent);
                return true;
            }
        }
        return false;
    }
public:
    KeyFilter(QObject* pobj = nullptr) : QObject(pobj)
    {}
};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLineEdit txt;
    txt.show();
    KeyFilter* pFilter = new KeyFilter(&txt);
    txt.installEventFilter(pFilter);
    return app.exec();
}
