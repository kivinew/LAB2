/* Лабораторная работа №2. Перегрузка операторов.
Программу, разработанную в лабораторной работе № 1, модифицировать таким образом,
чтобы появилась возможность применять к объектам класса следующие операторы:
​ Инкремент, декремент (можно только одну из префиксной и постфиксной форм).
​ Сложение объектов класса.
​ Операторы сравнения.
​ Оператор присваивания.
​ Оператор приведения к типу int (или другому численному).
​ Операторы ввода и вывода в поток.
*/

#include "Complex.h"
#include <locale>
#define ESC         27
#define ONE         49
#define TWO         50
#define THREE       51
#define FOUR        52
#define FIVE        53
void gotoxy(int, int);
int menu();
void showTable(int, int, Complex**&);
void deleteArr(Complex** &, int);
void add(Complex**, int);
void sub(Complex**, int);
void inc(Complex**, int);
void dec(Complex**, int);

const Complex model(1.5, 2.5);                              // константный объект класса
Complex** arrPointers;                                      // объявление массива исходных объектов
Complex** arrResult;                                        // объявление массива объектов-результатов
int arrSize = 5;                                            // размер таблицы

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleTitleA("LAB2: Complex numbers");
    arrPointers = new Complex*[arrSize]();                  // определение массива
    arrResult = new Complex*[arrSize]();
    for (int i = 0; i<arrSize; i++)                         // заполнить строки таблицы
    {
        gotoxy(18, 4);
        cout<<model<<endl;
        showTable(0, 2, arrPointers);
        *(arrPointers+i) = new Complex(0, 0);               // создаем объект с параметрами инициализации
        cout<<endl<<i<<"-й элемент таблицы:"<<endl;
        arrPointers[i]->edit();
        cout<<*arrPointers[i]<<endl;
    }
    for (int i = 0; i<arrSize; i++)
    {
        *(arrResult+i) = new Complex();
    }
    while (menu());
    return 0;
}

int menu()                                                  // меню LAB2
{
    system("cls");
    gotoxy(0, 0);
    cout<<"Исходные значения:";
    showTable(0, 2, arrPointers);
    gotoxy(40, 0);
    cout<<"Результаты:";
    showTable(40, 2, arrResult);
    gotoxy(20, 4);
    cout<<model;
    for (int i = 0; i<arrSize; i++)
    {
        gotoxy(37, 2+i);
        if (*arrResult[i]==model)
            cout<<"=";
        else
        {
            Complex temp = model;
            cout<<((int)*arrResult[i]<(int)temp ? ">" : "<");
        }
        gotoxy(65, 2+i);
        cout<<"(int)Complex = "<<(int)*arrResult[i];
    }
    gotoxy(0, 18);
    cout<<"Выберите операцию для применения к значениям из таблицы:"
        <<"\n\t1 - вычитание"<<endl
        <<"\t2 - сложение"<<endl
        <<"\t3 - декремент"<<endl
        <<"\t4 - инкремент"<<endl
        <<"\t5 - изменить исходные значения"<<endl
        <<"\tESC - выход"<<endl;
    while (!_kbhit());
    int choice = _getch();

    switch (choice)
    {
    case '1':                           // вычитание
        for (int i = 0; i<arrSize; i++)
        {
            sub(arrPointers, i);
        }
        break;
    case '2':                           // сложение
        for (int i = 0; i<arrSize; i++)
        {
            add(arrPointers, i);
        }
        break;
    case '3':                           // декремент
        for (int i = 0; i<arrSize; i++)
        {
            dec(arrResult, i);
        }
        break;
    case '4':                           // инкремент
        for (int i = 0; i<arrSize; i++)
        {
            inc(arrResult, i);
        }
        break;
	case '5':
        int num;
        gotoxy(0,8);
        cout<<"Введите номер элемента таблицы: ";
        cin>>num;
        gotoxy(0, 9);
        arrPointers[num]->edit();
        break;
    case ESC:
        deleteArr(arrPointers, arrSize);
        deleteArr(arrResult, arrSize);
        return FALSE;
    }
    return TRUE;
}

void showTable(int x, int y, Complex** &arr)                            // вывод таблицы объектов
{
    for (int i = 0; i<arrSize; i++)
    {
        gotoxy(x, y+i);
        cout<<i<<": ";
        if (arr[i]!=NULL)                                               // если указатель не равен нулю
        {
            cout<<*arr[i];                                              // то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
}

void add(Complex** arr, int num)
{
    *arrResult[num] = *(arr[num])+model;
}

void sub(Complex** arr, int num)
{
    *arrResult[num] = *(arr[num])-model;
}

void inc(Complex** arr, int num)
{
    ++*(arr[num]);
}

void dec(Complex** arr, int num)
{
    --*(arr[num]);
}

void deleteArr(Complex** &arr, int size)                          		// удаление массива
{
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);                                    	    // удаление объектов массива
    }
    delete[] arr;                                                       // удаление массива
    return;
}

void gotoxy(int x, int y)                                           	// перевод курсора в положение X,Y
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdOut, coord);
    return;
}
