#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QWidget>
class QLineEdit;
class QWebEngineView;
class QPushButton;

class WebBrowser : public QWidget
{
    Q_OBJECT

private:
    QLineEdit* m_ptxt;
    QWebEngineView* m_pwv;
    QPushButton* m_pcmdBack;
    QPushButton* m_pcmdForward;

public:
    WebBrowser(QWidget *parent = nullptr);

private slots:
    void slotGo();
    void slotFinished(bool);
};
#endif // WEBBROWSER_H
