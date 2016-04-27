#include "comPlex.h"

int Complex::counter;
int Complex::num;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(-1.), image(-1.)                             	// ����������� �� ���������
{
    objNum = ++num;
    counter++;
}

Complex::Complex(double re, double im): real(re), image(im)             // ����������� � �����������
{
    objNum = ++num;                      
    counter++;
}

//Complex::Complex(const Complex &obj): real(obj.real), image(obj.image)        // ����������� �����������
//{
//    objNum = ++num;
//    counter++;
//}

Complex::~Complex()                                                     // ����������
{
    --counter;
    cout<<"������ "<<objNum<<" �����."<<endl;
    Sleep(250);
}

int Complex::getCounter()                                               // ������� ���������� ��������
{
    return counter;
}

int Complex::getNum()                                                   // ������� ����� �������
{
    return objNum;
}

void Complex::edit()                                                    // �������� �������
{
    cout<<endl<<"�������������� �����: real= "<<endl;
    cin>>real;
    cout<<"������ �����: image= "<<endl;
    cin>>image;
    return;
}

void Complex::del(Complex* &obj)                                        // �������� �������
{
    if (obj!=NULL)
    {
        delete obj;
        obj = NULL;
    }
    return;
}

void Complex::showObject()                                              // ����� �������
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0)
        cout<<"arg Z="<<arg()*180/pi<<"\t"<<endl;
    else
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                                   // ������ |Z|
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                                   // �������� arg Z
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

Complex Complex::operator+(Complex Right)                                // Complex + Complex
{
    Complex temp;
    temp.real = real+Right.real;
    temp.image = image+Right.image;
    return temp;
}

Complex Complex::operator-(Complex Right)                                // Complex - Complex
{
    Complex temp;
    temp.real = real-Right.real;
    temp.image = image-Right.image;
    return temp;
}

Complex Complex ::operator - ()                                 // ������� �����
{
    Complex temp;
    temp.real = -real;
    temp.image = -image;

    return temp;
}

Complex &Complex::operator=(const Complex Right)                     	// Complex = Complex
{
    if (&Right==this)
        return *this;
    this->real = Right.real;
    this->image = Right.image;
    return *this;
}

bool Complex::operator==(Complex Right)                           // Complex == Complex
{
    return ((this->real==Right.real)&&(this->image==Right.image));
}

bool Complex::operator!=(Complex Right)                           // Complex == Complex
{
    return !(*this==Right);
}

bool Complex::operator < (Complex &Right)
{
    return ((real < Right.real)&&(image < Right.image));
}

bool Complex::operator > (Complex &Right)
{
    return ((real > Right.real)&&(image > Right.image));
}

Complex:: operator int()
{
    return real*image;
}

Complex & Complex::operator() (int re, int im)
{
    real += re;
    image += im;
    return *this;
}

ostream & operator << (ostream &out, Complex &obj)                    	// cout<<
{
    out<<"Z = "<<obj.real<<" + "<<obj.image<<" * i";
	return out;
}

istream & operator>>(istream &in, Complex &obj)                    	// cin>>
{
    cout<<"������� real = ";
    in>>obj.real;
    cout<<"������� image =";
    in>>obj.image;
    return in;
}

ostream & operator << (ostream &out, const Complex &obj)
{
    out<<"Z = "<<obj.real<<" + "<<obj.image<<" * i";
    return out;
}

