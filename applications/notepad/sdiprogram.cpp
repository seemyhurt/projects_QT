#include "sdiprogram.h"

SDIProgram::SDIProgram(QWidget *parent)
    : QMainWindow{parent}
{
    QMenu* pmnuFile = new QMenu ("&File");
    QMenu* pmnuHelp = new QMenu ("&Help");

    Notepad* pdoc = new Notepad;

    pmnuFile->addAction( "&Open...",
                         pdoc,
                         SLOT(slotLoad()),
                         QKeySequence("CTRL+O"));

    pmnuFile->addAction("&Save",
                        pdoc,
                        SLOT(slotSave()),
                        QKeySequence ("CTRL+S"));
    pmnuFile->addAction ( "&Save As ...",
                          pdoc,
                          SLOT(slotSaveAs()));

    pmnuFile->addSeparator();
    pmnuFile->addAction("&Quit",
                        qApp,
                        SLOT(quit()),
                        QKeySequence ("CTRL+Q"));
    pmnuHelp->addAction("&About",
                        this,
                        SLOT(slotAЬout()),
                        Qt::Key_F1);
    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuHelp);
    setCentralWidget(pdoc);
    connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));
    statusBar()->showMessage ("Ready", 2000);
}
void SDIProgram::slotAbout (){
    QMessageBox::about(this, "Application", "SDI Example");
}
void SDIProgram::slotChangeWindowTitle(const QString& str){
    setWindowTitle(str);
}
