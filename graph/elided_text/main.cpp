#include <QtWidgets>
#include <QApplication>
class ElidedText : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*){
        QString str = "This is а long text. Please , resize the window";
        QString strElided = fontMetrics().elidedText(str, Qt::ElideMiddle, width()) ;
        QPainter painter(this);
        painter.drawText(rect() , strElided);
    }
public:
    ElidedText(QWidget* pwgt = 0) : QWidget(pwgt)
    {}
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElidedText w;
    w. resize(170,30);
    w.show();
    return a.exec();
}
