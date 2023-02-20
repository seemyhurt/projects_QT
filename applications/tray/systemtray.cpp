#include "systemtray.h"

SystemTray::SystemTray(QWidget* pwgt) : QLabel("<H1>Application Window</H1>", pwgt), m_blIconSwitcher(false)
{
    setWindowTitle("System Tray");
    QAction* pactShowHide = new QAction("&Show/Hide Application Window", this);
    connect(pactShowHide, SIGNAL(triggered()), this, SLOT(slotShowHide()));

    QAction* pactShowМessage = new QAction("S&how Message", this);
    connect(pactShowМessage, SIGNAL(triggered()), this, SLOT(slotShowMessage()));

    QAction* pactChangeicon = new QAction("&Change Icon", this);
    connect(pactChangeicon, SIGNAL(triggered() ), this,SLOT(slotChangeIcon()));

    QAction* pactQuit = new QAction("&Quit", this);
    connect(pactQuit, SIGNAL(triggered() ), qApp, SLOT(quit()));

    m_ptrayIconМenu = new QMenu(this);
    m_ptrayIconМenu->addAction(pactShowHide);
    m_ptrayIconМenu->addAction(pactShowМessage);
    m_ptrayIconМenu->addAction(pactChangeicon);
    m_ptrayIconМenu->addAction(pactQuit);

    m_ptrayicon = new QSystemTrayIcon(this);
    m_ptrayicon->setContextMenu(m_ptrayIconМenu);
    m_ptrayicon->setToolTip("System Tray");
    slotChangeIcon();
    m_ptrayicon->show();
}
void SystemTray::closeEvent(QCloseEvent* pe){
    if(m_ptrayicon->isVisible()) {
        hide();
    }
}

void SystemTray::slotShowHide()
{
    setVisible(!isVisible());
}

void SystemTray::slotShowMessage()
{
    m_ptrayicon->showMessage("For your information",
                             "You have selected the "
                             "\"Show Message!\" option",
                             QSystemTrayIcon::Information,
                             3000);
}

void SystemTray::slotChangeIcon()
{
    m_blIconSwitcher = !m_blIconSwitcher;
    QString strPixmapName = m_blIconSwitcher ? "/home/seemyhurt/Изображения/Android.png"
                                             : "/home/seemyhurt/Изображения/Linux.png";
    m_ptrayicon->setIcon(QPixmap(strPixmapName));
}
