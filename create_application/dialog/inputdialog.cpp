#include "inputdialog.h"

InputDialog::InputDialog(QWidget* pwgt): QDialog(pwgt, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
    m_ptxtFirstName =  new QLineEdit;
    m_ptxtLastName =  new QLineEdit;

    QLabel* plblFirstNarne = new QLabel("&First Name");
    QLabel* plblLastNarne = new QLabel("&Last Name");

    plblFirstNarne->setBuddy(m_ptxtFirstName);
    plblLastNarne->setBuddy(m_ptxtLastName);

    QPushButton* pcmdOk = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");

    connect(pcmdOk, SIGNAL(clicked() ), SLOT(accept() ));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

    //Layout setup
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblFirstNarne, 0, 0);
    ptopLayout->addWidget(plblLastNarne, 1, 0);
    ptopLayout->addWidget(m_ptxtFirstName, 0, 1);
    ptopLayout->addWidget(m_ptxtLastName, 1, 1);
    ptopLayout->addWidget(pcmdOk, 2,0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);
}
QString InputDialog::firstName() const
{
    return m_ptxtFirstName->text();
}
QString InputDialog::lastName( ) const
{
    return m_ptxtLastName->text();
}
