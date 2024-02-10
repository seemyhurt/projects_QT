#ifndef SHELL_H
#define SHELL_H

#include <QtWidgets>

class Shell : public QWidget
{
    Q_OBJECT
private:
    QProcess* m_process ;
    QLineEdit* m_ptxtCommand;
    QTextEdit* m_ptxtDisplay;
public:
    explicit Shell(QWidget *parent = nullptr);

public slots:
    void slotDataOnStdout();
    void slotReturnPressed();

};

#endif // SHELL_H
