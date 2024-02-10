#ifndef MYSERVER_H
#define MYSERVER_H

#include <QtWidgets>
#include <QTcpSocket>
#include <QTcpServer>
class MyServer : public QWidget
{
    Q_OBJECT
private:
    QTextEdit* m_ptxt;
    quint16 m_nNextBlockSize;
    QTcpServer* m_ptcpServer;

    void sendToClient(QTcpSocket* pSocket, const QString& str);

public:
    explicit MyServer(int nPort, QWidget *parent = nullptr);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();

};

#endif // MYSERVER_H
