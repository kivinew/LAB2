#include "comPlex.h"

comPlex::comPlex ( )                                                    // конструктор по умолчанию
{
    real = 0;
    image = 0;
    cout << counter++;
}

comPlex::~comPlex ( )
{
    system ( "cls" );
    cout << "DESTRUCTOR: " << counter-- << " Good bye!!" << endl;
}

bool comPlex::entering ( )                                              // ввод членов комплексного числа
{
    double tmpReal , tmpImage;                                          // временные переменные для проверки на ноль
    cout << "Enter real part of complex number Z: real= " ;             // действительная часть
    cin >> tmpReal;
    cout << "Enter image part of complex number Z: image= " ;           // мнимая часть
    cin >> tmpImage;
    cout << endl;

    if ( tmpReal == 0 && tmpImage == 0 )
{
        cout << "Module |Z| is 0 " << endl;
        cout << "ARGUMENT IS NOT DEFINED!!!" << endl;
        _getch ( );
        return false;
    }
    real = tmpReal;
    image = tmpImage;
    return true;
}

double comPlex::mod ( )                                             // модуль
{
    return sqrt ( real*real + image*image );
}

double comPlex::arg ( )                                             // аргумент
{
    if ( real > 0 ) return atan ( image / real );
    if ( real < 0 ) 
    {
        if ( image > 0 ) return pi + atan ( image / real );
        if ( image < 0 ) return -pi + atan ( image / real );
        if ( image == 0 ) return pi;
    }
    if ( real == 0 )
    {
        if ( image > 0 ) return pi / 2;
        if ( image < 0 ) return -pi / 2;
    }
    return 0;
}
