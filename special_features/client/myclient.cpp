#include "myclient.h"

MyClient::MyClient(const QString &strHost, int nPort, QWidget *parent)
    : QWidget(parent), m_nNextBlockSize(0)
{
    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost(strHost, nPort);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead() ), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAЬstractSocket::SocketError)), this, SLOT (slotError (QAbstractSocket::SocketError)));

    m_ptxtinfo = new QTextEdit;
    m_ptxtinput = new QLineEdit;
    m_ptxtinfo->setReadOnly(true);

    QPushButton* pcmd = new QPushButton("&Send");
    connect(pcmd, SIGNAL(clicked()), SLOT(slotSendToServer()));
    connect(m_ptxtinput, SIGNAL(returnPressed()), this, SLOT (slotSendToServer () ));

    //Layout setup
    QVBoxLayout * pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(new QLabel("<H1>Client</H1>"));
    pvbxLayout->addWidget(m_ptxtinfo);
    pvbxLayout->addWidget(m_ptxtinput);
    pvbxLayout->addWidget(pcmd);
    setLayout(pvbxLayout);
}
void MyClient::slotReadyRead (){
    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_5_12);
    for (;;) {
        if (!m_nNextBlockSize){
            if(m_pTcpSocket->bytesAvailable()< sizeof(quint16)){
                break;
            }
            in >> m_nNextBlockSize;
        }
        if(m_pTcpSocket->bytesAvailable() < m_nNextBlockSize){
            break;
        }
        QTime time;
        QString str;
        in >> time >> str;
        m_ptxtinfo->append(time.toString() +" "+ str);
        m_nNextBlockSize =0;
    }
}
void MyClient::slotError(QAbstractSocket::SocketError err){
    QString strError = "Error: "+ (err == QAbstractSocket::HostNotFoundError
                                   ? "The host was not found." :
                                     err == QAbstractSocket::RemoteHostClosedError
                                     ? "The remote host is closed." :
                                       err == QAbstractSocket::ConnectionRefusedError?
                                       "The connection was refused." :
                                       QString(m_pTcpSocket->errorString()));
    m_ptxtinfo->append(strError);
}

void MyClient::slotSendToServer(){
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << quint16(0) << QTime::currentTime() << m_ptxtinput->text();
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    m_pTcpSocket->write(arrBlock);
    m_ptxtinput->setText("");
}

void MyClient::slotConnected(){
    m_ptxtinfo->append("Received the connected() signal");
}
