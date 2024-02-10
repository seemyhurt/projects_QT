#include "downloader.h"


Downloader::Downloader(QObject *parent)
    : QObject{parent}
{
    m_pnam = new QNetworkAccessManager(this);
    connect(m_pnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotFinished(QNetworkReply*)));
}

void Downloader::download(const QUrl& url){
    QNetworkRequest request(url);
    QNetworkReply* pnr = m_pnam->get(request);
    //Дождаться загрузки адреса
    /*QEventLoop loop;
    connect(&request, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();*/
    connect(pnr, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(downloadProgress(qint64, qint64)));
}
void Downloader::slotFinished(QNetworkReply* pnr){
    if (pnr->error( ) != QNetworkReply::NoError) {
        emit error ();
    }
    else {
        emit done(pnr->url(), pnr->readAll());
    }
    pnr->deleteLater();
}
