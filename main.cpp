/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
*/

#include "comPlex.h"
#include <Windows.h>
#include <list>


void main ( )
{
    SetCursorPos ( 600 , 0 ) ;
    SetConsoleTitleA ( "LAB1: complex numbers" ) ;
    comPlex *Z = new comPlex[2000];
    do
    {
        system ( "cls" );
        if ( Z -> entering ( ) )
        {
            cout << "Module |Z| is ..." << Z -> mod ( ) << endl;
            cout << "Argument arg Z is ..." << Z -> arg ( ) * 180 / Z -> pi << endl;
        }
        else
        {
            //delete Z;
            return;
        }
        _getch ( );
    } while ( 1 );
    return ;
}