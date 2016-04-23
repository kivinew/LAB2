#pragma once
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
