#include "webbrowser.h"
#include <QPushButton>
#include <QWebEngineView>
#include <QWebEngineHistory>
#include <QProgressBar>
#include <QLineEdit>
#include <QHBoxLayout>

WebBrowser::WebBrowser(QWidget *parent)
    : QWidget(parent)
{
    m_ptxt = new QLineEdit("http://www.bhv.ru");
    m_pwv = new QWebEngineView;
    m_pcmdBack = new QPushButton("<");
    m_pcmdForward = new QPushButton(">");

    m_pcmdBack->setEnabled(false);
    m_pcmdForward->setEnabled(false);

    auto pprb = new QProgressBar;
    auto pcmdGo = new QPushButton("&Go");
    auto pcmdStop=  new QPushButton("&Stop");
    auto pcmdRefresh =  new QPushButton("&Refresh");

    connect(pcmdGo, &QPushButton::clicked, this, &WebBrowser::slotGo);
    connect(m_ptxt, &QLineEdit::returnPressed, this, &WebBrowser::slotGo) ;
    connect(m_pcmdBack, &QPushButton::clicked, m_pwv, &QWebEngineView::back);
    connect (m_pcmdForward, &QPushButton::clicked, m_pwv, &QWebEngineView::forward);
    connect(pcmdRefresh, &QPushButton::clicked, m_pwv, &QWebEngineView::reload);
    connect(pcmdStop, &QPushButton::clicked, m_pwv, &QWebEngineView::stop);
    connect(m_pwv, &QWebEngineView::loadProgress, pprb, &QProgressBar::setValue);
    connect(m_pwv, &QWebEngineView::loadFinished, this,  &WebBrowser::slotFinished);

    //Layout setup
    auto phbx = new QHBoxLayout;
    phbx->addWidget(m_pcmdBack);
    phbx->addWidget(m_pcmdForward);
    phbx->addWidget(pcmdStop);
    phbx->addWidget(pcmdRefresh);
    phbx->addWidget(m_ptxt);
    phbx->addWidget(pcmdGo);

    auto playout = new QVBoxLayout;
    playout->addLayout(phbx);
    playout->addWidget(m_pwv);
    playout->addWidget(pprb);
    setLayout(playout);

    slotGo();
}

void WebBrowser::slotGo()
{
    if (!m_ptxt->text().startsWith("ftp://")
    &&  !m_ptxt->text().startsWith("http://")
    &&  !m_ptxt->text().startsWith("gopher://"))
    {
        m_ptxt->setText("http://" + m_ptxt->text());
    }
    m_pwv->load(QUrl(m_ptxt->text()));
}

void WebBrowser::slotFinished(bool bOk)
{
    if (!bOk)
        m_pwv->setHtml("<CENTER>An error has occured while loading the web page</CENTER>");

    m_ptxt->setText(m_pwv->url().toString());
    m_pcmdBack->setEnabled(m_pwv->page()->history()->canGoBack());
    m_pcmdForward->setEnabled(m_pwv->page()->history()->canGoForward());
}


