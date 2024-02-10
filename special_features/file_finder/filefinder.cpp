#include "filefinder.h"

FileFinder::FileFinder(QWidget *parent)
    : QWidget{parent}
{
    m_ptxtDir = new QLineEdit(QCoreApplication::applicationDirPath());
    m_ptxtMask = new QLineEdit("*");
    m_ptxtResult = new QTextEdit;

    QLabel* plblDir = new QLabel("&Directory");
    QLabel* plblMask = new QLabel("&Mask");
    QPushButton* pcmdDir = new QPushButton("&Open");
    QPushButton* pcmdFind = new QPushButton("&Find");

    connect(pcmdDir, SIGNAL(clicked()), this, SLOT(slotBrowse() ));
    connect(pcmdFind, SIGNAL(clicked()), this,  SLOT(slotFind()));

    plblDir->setBuddy(m_ptxtDir);
    plblMask->setBuddy(m_ptxtMask);

    //Layout setup
    QGridLayout* pgrdLayout = new QGridLayout;
    pgrdLayout->setContentsMargins(5, 5, 5, 5);
    pgrdLayout->setSpacing(15);
    pgrdLayout->addWidget(plblDir, 0, 0);
    pgrdLayout->addWidget(plblMask, 1, 0);
    pgrdLayout->addWidget(m_ptxtDir, 0, 1);
    pgrdLayout->addWidget(m_ptxtMask, 1, 1);
    pgrdLayout->addWidget(pcmdDir, 0, 2);
    pgrdLayout->addWidget(pcmdFind, 1, 2);
    pgrdLayout->addWidget(m_ptxtResult, 2, 0, 1, 3);
    setLayout(pgrdLayout);
}

void FileFinder::slotBrowse(){
    QString str = QFileDialog::getExistingDirectory(0,
                                                    "Select а Directory",
                                                    m_ptxtDir->text());
    if ( !str.isEmpty()) {
        m_ptxtDir->setText(str);
    }
}
void FileFinder::slotFind (){
    start(QDir(m_ptxtDir->text()));
}
void FileFinder::start(const QDir& dir){
    QApplication::processEvents();
    m_ptxtResult->clear();
    QStringList listFiles = dir.entryList(m_ptxtMask->text().split(u' '), QDir::Files);
    foreach (QString file, listFiles) {
        m_ptxtResult->append(dir.absoluteFilePath(file));
    }
    QStringList listDir = dir.entryList(QDir::Dirs);
    foreach (QString subdir, listDir) {
        if (subdir == "." || subdir == "..") {
            continue;
        }
        start(QDir(dir.absoluteFilePath(subdir)));
    }
}
