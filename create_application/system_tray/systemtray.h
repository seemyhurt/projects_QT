#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QtWidgets>
class QSystemTrayIcon;
class QMenu;
class SystemTray : public QLabel
{
    Q_OBJECT
private:
    QSystemTrayIcon* m_ptrayicon;
    QMenu*  m_ptrayIconМenu;
    bool m_blIconSwitcher;
protected:
    virtual void closeEvent(QCloseEvent*);
public:
    SystemTray(QWidget* pwgt = nullptr);
public slots:
    void slotShowHide();
    void slotShowMessage();
    void slotChangeIcon ();
};

#endif // SYSTEMTRAY_H
