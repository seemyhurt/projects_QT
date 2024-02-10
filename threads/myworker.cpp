#include "myworker.h"

//Конструктор виджета
MyWorker::MyWorker(unsigned long n, QObject *parent)
    : QObject{parent}, m_nValue(1), number(0), fact(n)
{
}

//Расчет очень большого факториала
//Для хранения используем класс verylong
void MyWorker::slotDoWork()
{
    number = 1;
    for (unsigned long j = 1; j < fact; j++){
        if (j % (fact / 100) == 0)
            setNextValue();
        number = number * j;
    }
    number.putvl();
    emit finished();

}
//Изменяем индикатор выполнения
void MyWorker::setNextValue()
{
    emit valueChanged(++m_nValue);
    if (m_nValue==100)
        emit finished();
}
