#include <QRegularExpression>
#include <QApplication>
#include <QtWidgets>
class NameValidator : public QValidator {
public:
    NameValidator(QObject* parent = nullptr) : QValidator(parent)
    {

    }
    virtual State validate(QString& str, int& pos) const
    {
        QRegularExpression rxp = QRegularExpression("[0-9]");
        if (str.contains(rxp)) {
            return Invalid;
        }
        return Acceptable;
    }
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QSpinBox spb;
    spb.setRange(1, 100);
    spb.setSuffix(" МВ");
    spb.setButtonSymbols(QSpinBox::PlusMinus);
    spb.setWrapping(true);

    QDateTimeEdit* dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime());

    QLabel* plblText = new QLabel("&Name (The digits will not Ье accepted!) :");
    QLineEdit* ptxt = new QLineEdit;

    NameValidator* pnameValidator = new NameValidator(ptxt);
    ptxt->setValidator(pnameValidator);
    plblText->setBuddy(ptxt);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(&spb);
    //phbxLayout->addStretch(2);
    pvbxLayout->addWidget(dateTimeEdit);
    pvbxLayout->addWidget(plblText);
    pvbxLayout->addWidget(ptxt);

    w.setLayout(pvbxLayout);
    w.show() ;
    return a.exec();
}
