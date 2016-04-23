#pragma once
<<<<<<< HEAD
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class Complex
{
    static double const pi ;
    static int counter;
    static int num;
    int objNum;
    double real, image;
public:
    Complex();
    Complex(int, int);
    Complex(Complex &);
    ~Complex();

    
    Complex &operator++();
    Complex operator++(int);
    Complex &operator--();
    Complex operator--(int);
    Complex operator+(Complex &);  
    Complex operator-(Complex &);
    Complex &operator=(Complex &);
    bool operator==(Complex);
    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator >> (istream &in, Complex &obj);

    static int getCounter();
    void edit();
    static void del(Complex* &);
    void showObject();
    double mod();
    double arg();
};
=======
#include <math.h>
#include <cstdio>
#include <iostream>
#include <conio.h>

using namespace std;

static int counter ;
class comPlex
{
    double real , image;
    long long int big [ 50000 ];
public:
    const double pi = 3.141592654;
    comPlex ( );
    ~comPlex ( );
    bool entering ( );
    double mod ( );
    double arg ( );
};
>>>>>>> 88b49302bccfe1ab86b747c9ffc12aff4fab0500
