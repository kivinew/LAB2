/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
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
void showTable();
void deleteAll(Complex** &, int);
Complex add(Complex**, int);

Complex *model = new Complex;
Complex** arrPointers;                                                      // объявление массива исходных объектов
Complex** arrResult;                                                        // объявление массива объектов-результатов
int arrSize = 5;                                                            // размер таблицы

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("LAB2: Complex numbers");

    cout<<"Введите эталонный объект Complex: "<<endl;
    cin>>*model;
    system("cls");
    arrPointers = new Complex*[arrSize]();                                  // определение массива
	arrResult = new Complex*[arrSize]();
    for (int i = 0; i<arrSize; i++)                                         // заполнить строки таблицы
    {
        gotoxy(40, 3);
        cout<<*model<<endl;
        gotoxy(0, 0);
        showTable();
        *(arrPointers+arrSize) = new Complex;
        cin>>*arrPointers[arrSize];
        cout<<*arrPointers[arrSize]<<endl;
        system("cls");
    }
	while (menu());
    delete model;
    return 0;
}

int menu()                                      // меню LAB2
{
    system("cls");
    showTable();
    cout<<endl<<"1 - сложение комплексных чисел"<<endl
        <<"2 - вычитание комплексных чисел"<<endl
        <<"3 - инкремент элемента таблицы"<<endl
        <<"4 - декремент элемента таблицы"<<endl
        <<"5 - умножение элемента таблицы"<<endl
        <<"6 - деление элемента таблицы"<<endl
        <<"ESC - выход"<<endl;
    while (!_kbhit());
    int choice = _getch();
	int number;																	// номер элемента таблицы
    
    switch (choice)
    {
    case '1':
		cout << "Выберите элемент для сложения с эталоном ";
		cin >> number;

        break;
    case '2':
		cout << "Выберите элемент для вычитания от эталона ";
		cin >> number;
        break;
    case '3':
		cout << "Выберите элемент для инкрементирования ";
		cin >> number;
        break;
	case '4':
		cout << "Выберите элемент для декрементирования ";
		cin >> number;
        break;
	case '5':
		cout << "Выберите элемент для умножения ";
		cin >> number;
        break;
	case '6':
		cout << "Выберите элемент для деления ";
		cin >> number;
        break;
    case ESC:
        deleteAll(arrPointers, arrSize);
        deleteAll(arrResult, arrSize);
        return FALSE;
    }
    return TRUE;
}

void showTable()                                    // вывод таблицы объектов
{
    cout<<"Объект :"<<endl;
    for (int i = 0; i<arrSize; i++)
    {
        cout<<i<<": ";
        if (arrPointers[i]!=NULL)                                               // если указатель не равен нулю
        {
            cout<<*arrPointers[i];                                              
    gotoxy(40,3);
    cout<<*model<<endl;// то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Complex** &arr, int size)							// удаление массива
{
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);										// удаление объектов массива
    }
    delete[] arr;                                       // удаление массива
    cout<<"Массив удалён"<<endl;
    _getch();
    return;
}

Complex add(Complex** arr, int number)
{
	Complex result = *model + *(arr[number]);
	return result;
}

Complex sub(Complex** arr, int number)
{
	Complex result = *model - *(arr[number]);
	return result;
}

//Complex multi(Complex** arr, int number)
//{
//	Complex result = *model * *(arr[number]);
//	return result;
//}

//Complex div(Complex** arr, int number)
//{
//	Complex result = *model * *(arr[number])
//		return result;
//}

void gotoxy(int x, int y)                                                // перевод курсора в положение X,Y
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdOut, coord);
    return;
}