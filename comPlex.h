#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include <Windows.h>
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
	double mod();
	double arg();
    void showObject();
	static int getCounter();
    int getNum();
    /*-----------------------------------------------------*/
	static void del(Complex* &);
    void edit();
	/*-----------------------------------------------------*/
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
};
