/* Перегрузка операторов.
Программу, разработанную в лабораторной работе № 1, модифицировать таким образом, 
чтобы появилась возможность применять к объектам класса следующие операторы:
​ Инкремент, декремент (можно только одну из префиксной и постфиксной форм).
​ Сложение объектов класса.
​ Операторы сравнения.
​ Оператор присваивания.
​ Оператор приведения к типу int (или другому численному).
​ Операторы ввода и вывода в поток.
*/

#include "comPlex.h"
#include <locale>
#define ESC         27
#define SPACEBAR    32
#define ONE         49
#define TWO         50
#define THREE       51
#define FOUR        52
#define FIVE        53
#define SIX         54
#define ENTER       13
#define DEL         83

void gotoxy(int, int);
int menu();
void paste(Complex);
void showTable(int, int, Complex**&);
void deleteAll(Complex** &, int);
void add(Complex** &, int);
void sub(Complex**, int);
//Complex mul(Complex**, int);
//Complex div(Complex**, int);

const Complex model(1.5,2.5);          // константный объект класса
Complex** arrPointers;                                              // объявление массива исходных объектов
Complex** arrResult;                                                // объявление массива объектов-результатов
int arrSize = 5;                                                    // размер таблицы

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("LAB2: Complex numbers");
    system("cls");
    arrPointers = new Complex*[arrSize]();                                  // определение массива
	arrResult = new Complex*[arrSize]();
    for (int i = 0; i<arrSize; i++)                                         // заполнить строки таблицы
    {
        gotoxy(40, 0);
        cout<<model<<endl;
        showTable(0,0,arrPointers);
        *(arrPointers+i) = new Complex(0,0);              	// создаем объект с параметрами инициализации
        cout<<i<<"-й элемент таблицы:"<<endl;
        cin>>*arrPointers[i];
        cout<<*arrPointers[i]<<endl;
    }
    for (int i = 0; i<arrSize; i++)
    {
        *(arrResult+i) = new Complex();
    }
	while (menu());
    return 0;
}

int menu()                                                         		// меню LAB2
{
    system("cls");
    gotoxy(0, 0);
    cout<<"Исходные значения:"<<endl;
    showTable(0, 1, arrPointers);
    cout<<endl<<endl<<"Результаты:"<<endl;
    showTable(0, 7, arrResult);
    gotoxy(25,2);
    cout<<model;
    gotoxy(0, 18);
    cout<<"Выберите операцию для применения к значениям из таблицы:"
        <<"\t1 - сложение"<<endl
        <<"\t2 - вычитание"<<endl
        <<"\t3 - инкремент"<<endl
        <<"\t4 - декремент"<<endl
        <<"\t5 - умножение"<<endl
        <<"\t6 - деление"<<endl
        <<"ESC - выход"<<endl;
    while (!_kbhit());
    int choice = _getch();

    switch (choice)
    {
    case '1':
        for (int i = 0; i<arrSize; i++)
        {
            add(arrPointers, i);
        }
        break;
    case '2':
        for (int i = 0; i<arrSize; i++)
        {
            sub(arrPointers, i);
        }
        break;
    case '3':
		
        break;
	case '4':
		
        break;
	case '5':
		
        break;
	case '6':
		
        break;
    case ESC:
        deleteAll(arrPointers, arrSize);
        deleteAll(arrResult, arrSize);
        return FALSE;
    }


    return TRUE;
}

void showTable(int x, int y, Complex** &arr)                            // вывод таблицы объектов
{
    cout<<"Объект :"<<endl;
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

void add(Complex** &arr, int num)
{
	*arrResult[num] = *(arr[num]) + model;
}

void sub(Complex** arr, int num)
{
	*arrResult[num] = *(arr[num]) - model;
}

//Complex mul(Complex** arr, int num)
//{
//	Complex result = *model * *(arr[num]);
//	return result;
//}
//
//Complex div(Complex** arr, int num)
//{
//	Complex result = *model * *(arr[num])
//	return result;
//}

void deleteAll(Complex** &arr, int size)                          		// удаление массива
{    
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);                                    	    // удаление объектов массива
    }
    delete[] arr;                                                       // удаление массива
    cout<<"Массив удалён"<<endl;
    _getch();
    return;
}

void gotoxy(int x, int y)                                           // перевод курсора в положение X,Y
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdOut, coord);
    return;
}
