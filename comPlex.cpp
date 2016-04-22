#include "comPlex.h"

int Complex::counter;
int Complex::num;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(0), image(0)                                   // конструктор по умолчанию
{
    objNum = ++num;
    counter++;
}

Complex::Complex(int re, int im): real(re), image(im)                   // конструктор с параметрами
{
    objNum = ++num;
    counter++;
}

Complex::Complex(Complex &obj): real(obj.real), image(obj.image)        // конструктор копирования
{
    objNum = ++num;
    counter++;
}

Complex::~Complex()                                                     // деструктор
{
    --counter;
    cout<<"ДЕСТРУКТОР: id"<<objNum<<" удален."<<endl;
    for (int i = 0; i<150000000; ++i);
}

Complex& Complex::operator++()                                                          // префиксный ++инкремент
{
    real++;
    image++;
    return *this;
}

Complex Complex::operator++(int)                                                        // постфиксный инкремент++
{
    Complex temp = *this;
    ++*this;
    return temp;
}

Complex& Complex::operator--()                                                          // префиксный --декремент
{
    real--;
    image--;
    return *this;
}

Complex Complex::operator--(int)                                                        // постфиксный декремент--
{
    Complex temp = *this;
    --*this;
    return temp;
}

Complex Complex::operator+(Complex &obj)                                                // бинарный + плюс
{
    return Complex(real+obj.real, image+obj.image);
}

Complex Complex::operator-(Complex &obj)                                                // бинарный - минус
{
    return Complex(real-obj.real, image-obj.image);
}

bool Complex::operator==(Complex objectRight)                                           // проверка на == равенство
{
    return ((this->real==objectRight.real)&&(this->image==objectRight.image));
}

Complex &Complex::operator=(Complex &objectRight)                                       // присваивание =
{
    if (&objectRight==this) 
        return *this;
    this->real = objectRight.real;
    this->image = objectRight.image;
    return *this;
}

ostream & operator << (ostream &out, Complex &obj)                                      // cout<<
{
    out<<"Z = "<<obj.real<<" + "<<obj.image<<" * i";
	return out;
}

istream & operator >> (istream &in, Complex &obj)                                       // cin>>
{
    cout<<"real = ";
    in>>obj.real;
    cout<<"image =";
    in>>obj.image;
	return in;
}

int Complex::getCounter()                                               // возврат счётчика
{
    return counter;
}

void Complex::edit()                                                    // редактирование объекта
{
    cout<<endl<<"Введите действительную часть Z: real= "<<endl;
    cin>>real;
    cout<<"Введите мнимую часть Z: image= "<<endl;
    cin>>image;
    return;
}

void Complex::del(Complex* &obj)                            // удаление объекта
{
    if (obj!=NULL)
    {
        delete obj;
        obj = NULL;
    }
    return;
}

void Complex::showObject()                                  // вывод объектов
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0) 
        cout<<"arg Z="<<arg()*180/pi<<"\t"<<endl;
    else 
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                       // модуль
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                       // аргумент
{
    if (real>0) return atan(image/real);
    if (real<0)
    {
        if (image>0) return pi+atan(image/real);
        if (image<0) return -pi+atan(image/real);
        if (image==0) return pi;
    }
    if (real==0)
    {
        if (image>0) return pi/2;
        if (image<0) return -pi/2;
    }
    return 0;
}
