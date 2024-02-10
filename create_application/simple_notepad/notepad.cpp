#include "notepad.h"

Notepad::Notepad(QWidget *pwgt): QTextEdit(pwgt)
{

}
void Notepad:: slotLoad(){
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()) {
        return;
    }
    QFile file (str);
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
        m_strfileName = str;
        emit changeWindowTitle(m_strfileName);
    }
}
void Notepad::slotSaveAs(){
    QString str = QFileDialog::getSaveFileName(0, m_strfileName);
    if (!str.isEmpty()) {
        m_strfileName = str;
        slotSave();
    }
}

void Notepad::slotSave(){
    if(m_strfileName.isEmpty()){
        slotSaveAs();
        return;
    }
    QFile file(m_strfileName);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream(&file) << toPlainText();
        file.close();
        emit changeWindowTitle(m_strfileName);
    }
}
