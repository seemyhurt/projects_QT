#include "startdialog.h"

StartDialog::StartDialog(QWidget* pwgt): QPushButton("Press Ме", pwgt)
{
    connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
}
void StartDialog::slotButtonClicked (){
    InputDialog* pinputDialog = new InputDialog;
    if (pinputDialog->exec() == QDialog::Accepted){
        QMessageBox::information(0, "Information",
                                 "First Name: "
                                 + pinputDialog->firstName()
                                 + "\nLast Name: "
                                 + pinputDialog->lastName());
    }
    delete pinputDialog;
}
