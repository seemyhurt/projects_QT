#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QtWidgets>
#include <QTcpSocket>

class MyClient : public QWidget
{
    Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket;
    QTextEdit* m_ptxtinfo;
    QLineEdit* m_ptxtinput;
    quint16 m_nNextBlockSize;
public:
    MyClient(const QString& strHost, int nPort, QWidget *parent = nullptr);
private slots:
    void slotReadyRead();
    void slotError (QAbstractSocket::SocketError) ;
    void slotSendToServer();
    void slotConnected();
};
#endif // MYCLIENT_H
