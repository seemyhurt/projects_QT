#ifndef DROP_H
#define DROP_H

#include <QLabel>

class Drop : public QLabel
{
    Q_OBJECT
protected:
    virtual void dragEnterEvent(QDragEnterEvent* pe);
    virtual void dropEvent(QDropEvent* pe);
public:
    Drop(QWidget* pwgt = 0);
};

#endif // DROP_H
