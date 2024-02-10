#ifndef BLINKLABEL_H
#define BLINKLABEL_H

#include <QLabel>

class BlinkLabel : public QLabel
{
    Q_OBJECT
private:
    bool m_bBlink;
    QString m_strText;
protected:
    virtual void timerEvent(QTimerEvent*);
public:
    explicit BlinkLabel(const QString& strText,
                        int ninterval = 200,
                        QWidget * pwgt = 0);

};

#endif // BLINKLABEL_H
