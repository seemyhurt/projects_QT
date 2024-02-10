#ifndef VERYLONG_H
#define VERYLONG_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <QDebug>

class verylong
{

private:
    std::string vlstr; //Число как строка

public:

    verylong(const std::string & other) :
        vlstr(other)
    {
    }

    //конструктор числом
    verylong(const unsigned long n)
    {
        vlstr = std::to_string(n);
    }

    void putvl();
    verylong operator + (const verylong);   //сложение
    verylong operator * (const verylong);   //умножение
    verylong multdigit(const int) const;    //умножение на число
    verylong mult10(const verylong) const;  // умножение на 10
};

#endif // VERYLONG_H
