#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
class Downloader : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager* m_pnam;
public:
    explicit Downloader(QObject *parent = nullptr);
    void download(const QUrl&);
signals:
    void downloadProgress(qint64, qint64);
    void done (const QUrl&, const QByteArray&);
    void error();
private slots:
    void slotFinished(QNetworkReply*);
};
#endif // DOWNLOADER_H
