#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

//-------------------------------------------
Complex::Complex(double aRe, double aIm)
{
    //консруктор класса Complex

    Re = aRe;
    Im = aIm;
}

//-------------------------------------------
Complex::Complex(const Complex& aRval)
{
    //консруктор копирования класса Complex

    Re = aRval.Re;
    Im = aRval.Im;
}

//-------------------------------------------
Complex::~Complex()
{
    //деконсруктор объекта класса Complex

    Re = 0.0;
    Im = 0.0;
}

//-------------------------------------------
void Complex::Set(double aRe, double aIm)
{
    //сеттер, устанавливает комплексное число

    Re = aRe;
    Im = aIm;
}

//-------------------------------------------
Complex::operator double()
{
    //переопределенный оператор(),
    //возвращает модуль комплексного числа
    //возвращает double

    return abs();
}

//-------------------------------------------
double Complex::abs()
{
    //возвращает модуль комплексного числа
    //возвращает double

    return sqrt(Re * Re + Im * Im);
}

//-------------------------------------------
Complex Complex::operator+ (const Complex& aRval)
{
    //определение оператора сложения комплексных чисел
    //возвращает Complex

    Complex Result;

    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;

    return Result;
}

//-------------------------------------------
  Complex Complex::operator- (const Complex& aRval)
{
    //определение оператора вычитания комплексных чисел
    //возвращает Complex

    Complex Result;

    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;

    return Result;
}

//-------------------------------------------
Complex Complex::operator+ (const double& aval)
{
    //определение оператора сложения комплексных
    //чисел с вещественным числом
    //возвращает Complex

    Complex result;

    result.Re = Re +aval;
    result.Im = Im;

    return result;
}

//-------------------------------------------
Complex Complex::operator- (const  double& aRval)
{
    //определение оператора вычитания комплексных
    //чисел с вещественным числом
    //возвращает Complex

    Complex Result(*this);

    Result.Re = Re - aRval;

    return Result;
}

//-------------------------------------------
Complex Complex::operator* (const Complex& aRval)
{
    //определение оператора умножения комплексных чисел
    //возвращает Complex

    Complex Result;

    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;

    return Result;
}

//-------------------------------------------
Complex Complex::operator* (const double& aRval)
{
    //определение оператора умножения комплексных
    //чисел с вещественным числом
    //возвращает Complex

    Complex Result;

    Result.Re =Re*aRval;
    Result.Im =Im*aRval;

    return Result;
}

//-------------------------------------------
Complex Complex::operator/ (const double& aRval)
{
    //определение оператора деления комплексного числа
    //на вещественное число
    //возвращает Complex

    Complex Result;

    Result.Re = Re / aRval;
    Result.Im = Im / aRval;

    return Result;
}

//-------------------------------------------
Complex& Complex::operator+= (const Complex& arval)
{
    //определение оператора сложения с присвоением
    //для двух комплексных чисел
    //возвращает ссылку на Complex

    Re += arval.Re;
    Im += arval.Im;

    return *this;
}

//-------------------------------------------
Complex& Complex::operator-= (const Complex& aRval)
{
    //определение оператора вычитания с присвоением
    //для двух комплексных чисел
    //возвращает ссылку на Complex

    Re -= aRval.Re;
    Im -= aRval.Im;

    return *this;
}

//-------------------------------------------
Complex& Complex::operator*=(const Complex&aRval)
{
    //определение оператора умножения с присвоением
    //для двух комплексных чисел
    //возвращает ссылку на Complex

    double tmpRe = Re;

    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;

    return *this;
}

//-------------------------------------------
Complex& Complex::operator+= (const double& aRval)
{
    //определение оператора сложения с присвоением
    //для комплексного числа с вещественным
    //возвращает ссылку на Complex

    Re += aRval;

    return *this;
 }

//-------------------------------------------
Complex& Complex::operator-= (const double&aRval)
{
    //определение оператора вычитания с присвоением
    //для комплексного числа с вещественным
    //возвращает ссылку на Complex

    Re -= aRval;

    return *this;
}

//-------------------------------------------
Complex& Complex::operator*= (const double& aRval)
{
    //определение оператора умножения с присвоением
    //для комплексного числа с вещественным
    //возвращает ссылку на Complex

    Re *= aRval;
    Im *= aRval;

    return *this;
}

//-------------------------------------------
Complex& Complex::operator/= (const double& aRval)
{
    //определение оператора деления комплексного
    //числа на вещественное с присвоением
    //возвращает ссылку на Complex

    Re /= aRval;
    Im /= aRval;

    return *this;
}

//-------------------------------------------
Complex& Complex::operator= (const Complex& aRval)
{
    //определение оператора присвоения комплексного числа
    //возвращает ссылку на Complex
    Re=aRval.Re;
    Im=aRval.Im;

    return *this;
}

//-------------------------------------------
Complex& Complex::operator= (const double& aRval)
{
    //определение оператора присвоения вещественного числа
    //возвращает ссылку на Complex

    Re = aRval;
    Im = 0.0;

    return *this;
}

//-------------------------------------------
istream& operator>> (istream& stream, Complex& aRval)
{
    //определение потока ввода

    char tmp[256];

    stream >> aRval.Re >> aRval.Im >> tmp;

    return stream;
}

//-------------------------------------------
ostream& operator<< (ostream& stream, Complex& aRval)
{
    //определение потока вывода
    stream << aRval.Re;

    if(!(aRval.Im < 0))
        stream << '+';

    stream << aRval.Im << 'i';

    return stream;
}

//-------------------------------------------
Complex operator+ (const double& aLval, const Complex& aRval)
{
    //определяет сложение вещественного числа с комплексным
    //возвращает Complex

    Complex result;

    result.Re = aLval + aRval.Re;
    result.Im = aRval.Im;

    return result;
}

//-------------------------------------------
Complex operator-(const double &aLval, const Complex& aRval)
{
    //определяет вычитание из вещественного числа комплексного
    //возвращает Complex

    Complex result;
    result.Re = aLval - aRval.Re;
    result.Im = -aRval.Im;

    return result;
}

//-------------------------------------------
Complex operator* (const double& aLval, const Complex& aRval)
{
    //определяет умнодение вещественного числа на комплексное
    //возвращает Complex

    Complex result;

    result.Re =aLval * aRval.Re;
    result.Im =aLval * aRval.Im;

    return result;
}
