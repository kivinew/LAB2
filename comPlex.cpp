#include "comPlex.h"

int Complex::counter;
int Complex::num;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(-1), image(-1)                             	// ����������� �� ���������
{
    objNum = ++num;
    counter++;
}

Complex::Complex(int re, int im): real(re), image(im)                   // ����������� � �����������
{
    objNum = ++num;                      
    counter++;
}

Complex::Complex(Complex &obj): real(obj.real), image(obj.image)        // ����������� �����������
{
    objNum = ++num;
    counter++;
}

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
    cout<<"������ "<<obj.getNum()<<"-� ������:"<<endl
        <<"������� real = ";
    in>>obj.real;
    cout<<"������� image =";
    in>>obj.image;
	return in;
}
