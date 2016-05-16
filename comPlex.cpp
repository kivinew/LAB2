/* Перегрузка операторов.*/
#include "comPlex.h"

int Complex::counter;
int Complex::num;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(0.), image(0.)                                         // конструктор по умолчанию
{
    objNum = ++num;
    counter++;
}

Complex::Complex(double re, double im): real(re), image(im)                     // конструктор с параметрами
{
    objNum = ++num;
    counter++;
}

Complex::Complex(const Complex &obj): real(obj.real), image(obj.image)          // конструктор копирования
{
    objNum = ++num;
    counter++;
}

Complex::~Complex()                                                             // деструктор
{
    counter--;
}

int Complex::getCounter()                                                       // возврат счётчика
{
    return counter;
}

int Complex::getNum()                                                   // âåðíóòü íîìåð îáúåêòà
{
    return objNum;
}

void Complex::edit()                                                    // ðåäàêòîð îáúåêòà
{
    cin>>*this;
    return;
}

void Complex::del(Complex* &obj)                                        // óäàëåíèå îáúåêòà
{
    if (obj!=NULL)
    {
        delete obj;
        obj = NULL;
    }
    return;
}

void Complex::showObject()                                              // âûâîä îáúåêòà
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0)
        cout<<"arg Z="<<arg()*180/pi<<"\t"<<endl;
    else
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                                   // ìîäóëü |Z|
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                                   // àðãóìåíò arg Z
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

Complex Complex::operator+(Complex& Right)                                // Complex + Complex
{
    Complex temp;
    temp.real = real+Right.real;
    temp.image = image+Right.image;
    return temp;
}

Complex Complex::operator-(Complex& Right)                                // Complex - Complex
{
    Complex temp;
    temp.real = real-Right.real;
    temp.image = image-Right.image;
    return temp;
}

Complex Complex::operator+(const Complex& Right)                                // Complex + Complex
{
    Complex temp;
    temp.real = real+Right.real;
    temp.image = image+Right.image;
    return temp;
}

Complex Complex::operator-(const Complex& Right)                                // Complex - Complex
{
    Complex temp;
    temp.real = real-Right.real;
    temp.image = image-Right.image;
    return temp;
}

Complex Complex ::operator - ()                                 // унарный минус
{
    Complex temp;
    temp.real = -real;
    temp.image = -image;
    return temp;
}

Complex &Complex::operator = (const Complex Right)              // Complex = Complex
{
    if (&Right==this)
        return *this;
    this->real = Right.real;
    this->image = Right.image;
    return *this;
}

bool Complex::operator == (Complex Right)                       // Complex == Complex
{
    double tLeft = sqrt(real*real+image*image);
    double tRight = sqrt(Right.real*Right.real+Right.image*Right.image);
    return (tLeft==tRight);
}

bool Complex::operator != (Complex Right)                       // Complex == Complex
{
    return !(*this==Right);
}

bool Complex::operator < (Complex &Right)
{
    double tLeft = sqrt(real*real+image*image);
    double tRight = sqrt(Right.real*Right.real+Right.image*Right.image);
    return (tLeft<tRight);
}

bool Complex::operator < (const Complex &Right)
{
    double tLeft = sqrt(real*real+image*image);
    double tRight = sqrt(Right.real*Right.real+Right.image*Right.image);
    return (tLeft<tRight);
}

bool Complex::operator > (Complex &Right)
{
    return Right<*this;
}

Complex:: operator int()
{
    return (int)sqrt(real*real+image*image);
}

Complex & Complex::operator() (int re, int im)
{
    real += re;
    image += im;
    return *this;
}

ostream & operator << (ostream &out, Complex &obj)                              // cout<<
{
    out<<"Z = "<<obj.real<<" + "<<obj.image<<"i      ";
    return out;
}

ostream & operator << (ostream &out, const Complex &obj)
{
    out<<"Z = "<<obj.real<<" + "<<obj.image<<"i      ";
    return out;
}

istream & operator>>(istream &in, Complex &obj)                                 // cin>>
{
    cout<<"ââåäèòå real =     \b\b\b\b";
    in>>obj.real;
    cout<<"ââåäèòå image =     \b\b\b\b";
    in>>obj.image;
    return in;
}
