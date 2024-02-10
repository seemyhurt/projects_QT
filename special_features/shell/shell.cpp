#include "shell.h"

Shell::Shell(QWidget *parent)
    : QWidget{parent}
{
    m_process = new QProcess(this);
    m_ptxtDisplay = new QTextEdit;

    QLabel* plbl = new QLabel("&Command:");
    #ifdef Q_OS_WIN
    QString strCommand = "dir";
    #else
    QString strCommand = "ls";
    #endif

    m_ptxtCommand = new QLineEdit(strCommand);
    plbl->setBuddy(m_ptxtCommand) ;

    QPushButton* pcmd = new QPushButton("&Enter");
    connect(m_process, &QProcess::readyReadStandardOutput, this, &Shell::slotDataOnStdout);
    connect(m_ptxtCommand, &QLineEdit::returnPressed, this, &Shell::slotReturnPressed);
    connect(pcmd, &QPushButton::clicked, this, &Shell::slotReturnPressed);

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(plbl);
    phbxLayout->addWidget(m_ptxtCommand);
    phbxLayout->addWidget(pcmd);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(m_ptxtDisplay);
    pvbxLayout->addLayout(phbxLayout);
    setLayout(pvbxLayout);
}

void Shell::slotDataOnStdout()
{
    m_ptxtDisplay->append(m_process->readAllStandardOutput());
}
void Shell::slotReturnPressed()
{
    QString strCommand = "";
    #ifdef Q_OS_WIN
    strCommand = "cmd /c ";
    #endif
    strCommand += m_ptxtCommand->text();
    m_process->start(strCommand);
}
