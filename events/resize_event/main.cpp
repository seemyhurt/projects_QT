
#include <QtWidgets>
#include <QApplication>

//======================================================================
class ResizeObserver : public QLabel {
public:
    ResizeObserver(QWidget* pwgt = 0) : QLabel(pwgt)
    {
        setAlignment(Qt::AlignCenter);
    }
protected:
    virtual void resizeEvent(QResizeEvent* pe){
        setText (QString ( "Resized")
                 + "\n width () =" + QString::number (pe->size().width())
                 + "\n height () =" + QString::number (pe->size().height()));
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ResizeObserver w;
    w.resize(250, 130);
    w.show();
    return a.exec();
}
