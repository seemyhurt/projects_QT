#ifndef MOUSEFILTER_H
#define MOUSEFILTER_H

#include <QObject>

class MouseFilter : public QObject
{
Q_OBJECT
public:
    explicit MouseFilter(QObject *parent = nullptr);
protected:
    virtual bool eventFilter(QObject*, QEvent*);
};

#endif // MOUSEFILTER_H
