#ifndef MDIPROGRAM_H
#define MDIPROGRAM_H

#include <QMainWindow>
#include <QtWidgets>
class MDIProgram : public QMainWindow
{
    Q_OBJECT
private:
    QMdiArea * m_pma;
    QMenu* m_pmnuWindows;
    QSignalMapper* m_psigMapper;
    QTextEdit* createNewDoc();
public:
    explicit MDIProgram(QWidget *parent = nullptr);
signals:
    void changeWindowTitle(const QString&);
private slots:
    void slotChangeWindowTitle(const QString&);
    void slotNewDoc();
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotAbout();
    void slotWindows();
    void slotSetActiveSubWindow(QObject *);
};

#endif // MDIPROGRAM_H
