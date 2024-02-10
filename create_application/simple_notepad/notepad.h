#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QtWidgets>
class Notepad : public QTextEdit
{
    Q_OBJECT
private:
    QString m_strfileName;
public:
    Notepad(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad ();
    void slotSave ();
    void slotSaveAs();
};

#endif // NOTEPAD_H
