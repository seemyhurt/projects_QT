#include "verylong.h"

void verylong::putvl() // вывод на экран verylong
{
    qDebug() << vlstr.c_str();
}

verylong verylong::operator + (const verylong v)
{
    std::string temp;
    int j;

    auto maxlen = std::max(vlstr.size(), temp.size());
    int carry = 0;

    for (j = 0; j < maxlen; j++)
    {
        int d1 = (j > vlstr.size() - 1) ? 0 : vlstr[j] - '0';
        //разряд
        int d2 = (j > temp.size() - 1) ? 0 : v.vlstr[j] - '0';
        int digitsum = d1 + d2 + carry;
        if (digitsum >= 10)
        {
            digitsum -= 10; carry = 1;
        }
        else
            carry = 0;
        temp[j] = digitsum + '0';
    }
    if (carry == 1)
        temp[j++] = '1';
    return verylong(temp);
}
//---------------------------------------------------------
verylong verylong::operator * (const verylong v)//умножение
{
    verylong pprod(0);            //произведение одного разряда
    verylong tempsum(0);          //текущая сумма
    for (int j = 0; j < v.vlstr.size(); j++)//для каждого разряда аргумента
    {
        int digit = v.vlstr[j] - '0'; //получить разряд
        pprod = multdigit(digit);   //умножить текущий на него
        for (int k = 0; k < j; k++)      //умножить результат на
            pprod = mult10(pprod);    //  степень 10-ти
        tempsum = tempsum + pprod;  //прибавить произведение к
                                    //текущей сумме
    }
    return tempsum;               //вернуть полученную текущую сумму
}
//---------------------------------------------------------
verylong verylong::mult10(const verylong v) const //умножение аргумента
//на 10
{
    std::string temp;
    for (auto j = v.vlstr.size() - 1; j >= 0; j--)//сдвинуться на один разряд
        temp[j + 1] = v.vlstr[j];     //выше
    temp[0] = '0';                //обнулить самый младший разряд
    return verylong(temp);        //вернуть результат
}
//---------------------------------------------------------
verylong verylong::multdigit(const int d2) const
{                          //умножение числа на
    std::string temp;             //аргумент (цифру)
    int j, carry = 0;
    for (j = 0; j < vlstr.size(); j++)    //для каждого разряда
    {                                //  в этом сверхбольшом
        int d1 = vlstr[j] - '0';   //получить значение разряда
        int digitprod = d1 * d2; //умножить на цифру
        digitprod += carry;      //добавить старый перенос
        if (digitprod >= 10)    //если возник новый перенос,
        {
            carry = digitprod / 10;  //переносу присвоить //значение старшего разряда
            digitprod -= carry * 10; //результату - младшего
        }
        else
            carry = 0;             //иначе перенос = 0
        temp[j] = digitprod + '0'; //вставить символ в строку
    }
    if (carry != 0)             //если на конце перенос,
        temp[j++] = carry + '0';   //это последний разряд
    return verylong(temp);     //вернуть сверхбольшое число
};
