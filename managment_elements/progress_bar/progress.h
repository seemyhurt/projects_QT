#ifndef PROGRESS_H
#define PROGRESS_H
#include <QtWidgets/QtWidgets>
class QProgressBar;
class Progress : public QWidget
{
Q_OBJECT
private:
    QProgressBar* m_pprb;
    int m_nStep;
public:
    explicit Progress(QWidget *parent = nullptr);

public slots:
    void slotStep ();
    void slotReset();

};

#endif // PROGRESS_H
