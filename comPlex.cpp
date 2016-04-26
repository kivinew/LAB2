#include "comPlex.h"

int Complex::counter;
int Complex::num;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(-1), image(-1)                             	// конструктор по умолчанию
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
    cout<<"Объект "<<objNum<<" удалён."<<endl;
    Sleep(250);
}

int Complex::getCounter()                                               // вернуть количество объектов
{
    return counter;
}

int Complex::getNum()                                                   // вернуть номер объекта
{
    return objNum;
}

void Complex::edit()                                                    // редактор объекта
{
    cout<<endl<<"действительная часть: real= "<<endl;
    cin>>real;
    cout<<"мнимая часть: image= "<<endl;
    cin>>image;
    return;
}

void Complex::del(Complex* &obj)                                        // удаление объекта
{
    if (obj!=NULL)
    {
        delete obj;
        obj = NULL;
    }
    return;
}

void Complex::showObject()                                              // вывод объекта
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0)
        cout<<"arg Z="<<arg()*180/pi<<"\t"<<endl;
    else
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                                   // модуль |Z|
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                                   // аргумент arg Z
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

Complex& Complex::operator++()                                          // ++Complex
{
    real++;
    image++;
    return *this;
}

Complex Complex::operator++(int)                                        // Complex++
{
Complex temp = *this;
++*this;
return temp;
}

Complex& Complex::operator--()                                          // --Complex
{
    real--;
    image--;
    return *this;
}

Complex Complex::operator--(int)                                        // Complex--
{
    Complex temp = *this;
    --*this;
    return temp;
}

Complex Complex::operator+(Complex &obj)                                // Complex + Complex
{
    Complex* res = new Complex(real+obj.real, image+obj.image);
    return *res;
}

Complex Complex::operator-(Complex &obj)                                // Complex - Complex
{
    Complex* res = new Complex(real-obj.real, image-obj.image);
    return *res;
}

bool Complex::operator==(Complex objectRight)                           // Complex == Complex
{
    return ((this->real==objectRight.real)&&(this->image==objectRight.image));
}

Complex &Complex::operator=(Complex objectRight)                     	// Complex = Complex
{
    if (&objectRight==this)
        return *this;
    this->real = objectRight.real;
    this->image = objectRight.image;
    return *this;
}

ostream & operator << (ostream &out, Complex &obj)                    	// cout<<
{
    out<<"Z = "<<obj.real<<" + "<<obj.image<<" * i";
	return out;
}

istream & operator >> (istream &in, Complex &obj)                    	// cin>>
{
    cout<<"Создаём "<<obj.getNum()<<"-й объект:"<<endl
        <<"введите real = ";
    in>>obj.real;
    cout<<"введите image =";
    in>>obj.image;
	return in;
}
