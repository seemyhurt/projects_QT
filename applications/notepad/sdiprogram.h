#ifndef SDIPROGRAM_H
#define SDIPROGRAM_H
#include <QtWidgets>
#include <QMainWindow>
#include "notepad.h"
class SDIProgram : public QMainWindow
{
    Q_OBJECT
public:
    explicit SDIProgram(QWidget *parent = nullptr);

public slots:
    void slotAbout ();
    void slotChangeWindowTitle(const QString& str);
};

#endif // SDIPROGRAM_H
