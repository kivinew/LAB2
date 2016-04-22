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

    static int getCounter();
    void edit();
    static void del(Complex* &);
    void showObject();
    double mod();
    double arg();
};
