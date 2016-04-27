#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include <Windows.h>
using namespace std;

class Complex
{
    const double static pi ;
    int static counter;
    int static num;
    int objNum;
    double real, image;
public:
    Complex();
    Complex(double, double);
    //inline Complex(const Complex &);
	~Complex();
	double mod();
	double arg();
    void showObject();
	int static getCounter();
    int getNum();
    /*-----------------------------------------------------*/
	void static del(Complex* &);
    void edit();
	/*-----------------------------------------------------*/
    Complex &operator++();
    Complex operator++(int);
    Complex &operator--();
    Complex operator--(int);
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator - ();
    Complex &operator=(Complex);
    bool operator==(Complex);
    bool Complex::operator!=(Complex);
    bool Complex::operator < (Complex &);
    bool Complex::operator > (Complex &);
    operator int();
    Complex & operator() (int, int);
    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator >> (istream &in, Complex &obj);
    friend ostream & operator << (ostream &out, const Complex &obj);
};
