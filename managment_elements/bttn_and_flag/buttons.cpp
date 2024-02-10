#include "buttons.h"
#include "qapplication.h"
#include "qboxlayout.h"
#include "qcheckbox.h"
#include "qgroupbox.h"
#include "qpushbutton.h"
#include "qradiobutton.h"

Buttons::Buttons(QGroupBox *parent)
    : QGroupBox("QGroupBox", parent)
{
    resize(100, 150);
    setCheckable(true);
    setChecked(true);

    m_pradRed = new QRadioButton("&Red");
    m_pradGreen = new QRadioButton("&Green");
    m_pradBlue = new QRadioButton("&Blue");

    m_pradGreen->setChecked(true);

    connect(m_pradRed, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_pradGreen, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_pradBlue, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    m_pchk = new QCheckBox("&Light");
    m_pchk->setChecked(true);
    connect(m_pchk, SIGNAL(clicked()), SLOT(slotButtonClicked()) );

    QPushButton* pcmd = new QPushButton("&Exit");
    connect(pcmd, SIGNAL(clicked()), qApp, SLOT(quit()));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(m_pradRed);
    pvbxLayout->addWidget(m_pradGreen);
    pvbxLayout->addWidget(m_pradBlue);
    pvbxLayout->addWidget(m_pchk);
    pvbxLayout->addWidget(pcmd);

    setLayout(pvbxLayout);
    slotButtonClicked();
}
void Buttons::slotButtonClicked()

{
    QPalette pal = palette();
    int nLight = m_pchk->isChecked() ? 150 : 80;
    if(m_pradRed->isChecked()) {
        pal.setColor(backgroundRole(), QColor(Qt::red).lighter(nLight));
    }
    else if(m_pradGreen->isChecked()) {
        pal.setColor(backgroundRole(), QColor(Qt::green).lighter(nLight));
    }
    else {
        pal.setColor(backgroundRole(), QColor(Qt::blue).lighter(nLight));
    }
    setPalette(pal);
}

