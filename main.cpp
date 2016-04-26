/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
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

const Complex model(1.5,2.5);          // ����������� ������ ������
Complex** arrPointers;                                              // ���������� ������� �������� ��������
Complex** arrResult;                                                // ���������� ������� ��������-�����������
int arrSize = 5;                                                    // ������ �������

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("LAB2: Complex numbers");
    system("cls");
    arrPointers = new Complex*[arrSize]();                                  // ����������� �������
	arrResult = new Complex*[arrSize]();
    for (int i = 0; i<arrSize; i++)                                         // ��������� ������ �������
    {
        gotoxy(40, 0);
        cout<<model<<endl;
        showTable(0,0,arrPointers);
        *(arrPointers+i) = new Complex(0,0);              	// ������� ������ � ����������� �������������
        cout<<i<<"-� ������� �������:"<<endl;
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

int menu()                                                         		// ���� LAB2
{
    system("cls");
    gotoxy(0, 0);
    cout<<"�������� ��������:"<<endl;
    showTable(0, 1, arrPointers);
    cout<<endl<<"����������:"<<endl;
    showTable(0, 7, arrResult);
    gotoxy(25,2);
    cout<<model;
    gotoxy(0, 18);
    cout<<"�������� �������� ��� ���������� � ��������� �� �������:"
        <<"\t1 - ��������"<<endl
        <<"\t2 - ���������"<<endl
        <<"\t3 - ���������"<<endl
        <<"\t4 - ���������"<<endl
        <<"\t5 - ���������"<<endl
        <<"\t6 - �������"<<endl
        <<"ESC - �����"<<endl;
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

void showTable(int x, int y, Complex** &arr)                            // ����� ������� ��������
{
    cout<<"������ :"<<endl;
    for (int i = 0; i<arrSize; i++)
    {
        gotoxy(x, y+i);
        cout<<i<<": ";
        if (arr[i]!=NULL)                                               // ���� ��������� �� ����� ����
        {
            cout<<*arr[i];                                              // �� ������� ������
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

void deleteAll(Complex** &arr, int size)                          		// �������� �������
{    
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);                                    	    // �������� �������� �������
    }
    delete[] arr;                                                       // �������� �������
    cout<<"������ �����"<<endl;
    _getch();
    return;
}

void gotoxy(int x, int y)                                           // ������� ������� � ��������� X,Y
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdOut, coord);
    return;
}
