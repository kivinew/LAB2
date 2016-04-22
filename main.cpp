/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
*/

#include "comPlex.h"
#include <locale>
#include <Windows.h>
#define ESC         27
#define SPACEBAR    32
#define ONE         49
#define TWO         50
#define ENTER       13
#define DEL         83 

int main();

int menu2(Complex** &, int &);
void insert(Complex** &, int);
void showTable(Complex** &, int);
void deleteAll(Complex** &, int);
Complex *model = new Complex;

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("LAB2: Complex numbers");
    cout<<"Введите эталонный объект Complex: "<<endl;
    cin>>*model;
    system("cls");
    Complex** arrPointers;                                                      // объявление массива указателей
    int arrSize;                                                                // размер массива
    arrSize = 10;                                 
    arrPointers = new Complex*[arrSize]();                                      // определение массива
    for (int i = 0; i<arrSize; i++)
        insert(arrPointers, i);                                                 // заполнить строки таблицы
    while (menu2(arrPointers, arrSize)==TRUE);
    delete model;
    return 0;
}


int menu2(Complex** &objectArray, int&size)                                     // меню LAB2
{
    system("cls");
    showTable(objectArray, size);
    cout<<endl<<"1 - сложение комплексных чисел"<<endl
        <<"2 - вычитание комплексных чисел"<<endl
        <<"3 - инкремент элемента таблицы"<<endl
        <<"4 - декремент элемента таблицы"<<endl
        <<"5 - "<<endl
        <<"6 - "<<endl;
    while (!_kbhit());
    int choice = _getch();
    
    switch (choice)
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;
    case '6':
        break;

    }
    return TRUE;
}

void insert(Complex** &arr, int number)                                         // заполнить строки таблицы
{                                                                               // cin>>Complex
    cout<<"Введите "<<number<<"-й элемент таблицы"<<endl;
    cin>>*arr[number];
}

void showTable(Complex** &arr, int size)                                    // вывод таблицы объектов
{
    cout<<"Объект :"<<endl;
    for (int i = 0; i<size; i++)
    {
        cout<<i<<": ";
        if (arr[i]!=NULL)                                                   // если указатель не равен нулю
        {
            cout<<(*arr[i]);                                         // то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Complex** &arr, int size)                // удаление массива
{
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);                           // удаление объектов массива
    }
    delete[] arr;                                       // удаление массива
    cout<<"Массив удалён"<<endl;
    _getch();
    return;
}
