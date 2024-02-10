#ifndef BUTTONS_H
#define BUTTONS_H

#include "qgroupbox.h"
#include <QWidget>
class QCheckBox;
class QRadioButton;

class Buttons : public QGroupBox
{
    Q_OBJECT
private:
    QCheckBox* m_pchk;
    QRadioButton* m_pradRed;
    QRadioButton* m_pradGreen;
    QRadioButton* m_pradBlue;
public:
    explicit Buttons(QGroupBox *parent = nullptr);

public slots:
    void slotButtonClicked();
};

#endif // BUTTONS_H
