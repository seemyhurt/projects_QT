#ifndef PRINTER_H
#define PRINTER_H

#include <QWidget>
#include <QPrinter>
#include <QPrintDialog>
#include <QPaintDevice>
class QPrinter;
class QPaintDevice;
class Printer : public QWidget
{
    Q_OBJECT
private:
    QPrinter* m_pprinter;
public:
    explicit Printer(QWidget *parent = nullptr);
    virtual ~Printer();
protected:
    virtual void paintEvent(QPaintEvent* ре );
    void draw (QPaintDevice* ppd);

 public slots:
    void slotPrint();

};

#endif // PRINTER_H
