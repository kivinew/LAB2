﻿/* Перегрузка операторов.*/
#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include <Windows.h>
using namespace std;

class Complex
{
    static double const pi;
    static int counter;
    double real, image;
public:
    Complex();
    Complex(double, double);
    Complex(const Complex &);
    ~Complex();
    double mod();
    double arg();
    void showObject();
    static int getCounter();
    static void del(Complex* &);
    void edit();

    Complex & operator ++ ();
    Complex operator ++ (int);
    Complex & operator -- ();
    Complex operator -- (int);
    Complex operator + (Complex&);
    Complex operator - (Complex&);
    Complex operator + (const Complex&);
    Complex operator - (const Complex&);
    Complex operator - ();
    Complex & operator = (Complex);
    bool operator == (Complex);
    bool operator != (Complex);
    bool operator < (Complex &);
    bool operator < (const Complex &);
    bool operator > (Complex &);
    operator int();
    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator >> (istream &in, Complex &obj);
    friend ostream & operator << (ostream &out, const Complex &obj);
};
