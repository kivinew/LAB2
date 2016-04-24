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
void showTable(Complex** &, int);
void deleteAll(Complex** &, int);
Complex add(Complex**, int);
Complex sub(Complex**, int);
Complex mul(Complex**, int);
Complex div(Complex**, int);

Complex *model = new Complex;
Complex** arrPointers;                                              // ���������� ������� �������� ��������
Complex** arrResult;                                                // ���������� ������� ��������-�����������
int arrSize = 5;                                                    // ������ �������

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("LAB2: Complex numbers");

    cout<<"������� ��������� ������ Complex: "<<endl;
    cin>>*model;
    system("cls");
    arrPointers = new Complex*[arrSize]();                                  // ����������� �������
	arrResult = new Complex*[arrSize]();
    for (int i = 0; i<arrSize; i++)                                         // ��������� ������ �������
    {
        gotoxy(40, 3);
        cout<<*model<<endl;
        gotoxy(0, 0);
        showTable();
        *(arrPointers+arrSize) = new Complex(0,0);              // ����� ������������ � ����������� �������������
        cin>>*arrPointers[arrSize];
        cout<<*arrPointers[arrSize]<<endl;
        system("cls");
    }
	while (menu());
    delete model;
    return 0;
}

int menu()                                                                  // ���� LAB2
{
    system("cls");
    showTable();
    gotoxy(20,15);
    cout<<*model<<endl<<endl
        <<"1 - �������� ����������� �����"<<endl
        <<"2 - ��������� ����������� �����"<<endl
        <<"3 - ��������� �������� �������"<<endl
        <<"4 - ��������� �������� �������"<<endl
        <<"5 - ��������� �������� �������"<<endl
        <<"6 - ������� �������� �������"<<endl
        <<"ESC - �����"<<endl;
    while (!_kbhit());
    int choice = _getch();
	int number;                                                            // ����� �������� �������

    switch (choice)
    {
    case '1':
		cout << "�������� ������� ��� �������� � �������� ";
		cin >> number;
        add();
        break;
    case '2':
		cout << "�������� ������� ��� ��������� �� ������� ";
		cin >> number;
        break;
    case '3':
		cout << "�������� ������� ��� ����������������� ";
		cin >> number;
        break;
	case '4':
		cout << "�������� ������� ��� ����������������� ";
		cin >> number;
        break;
	case '5':
		cout << "�������� ������� ��� ��������� ";
		cin >> number;
        break;
	case '6':
		cout << "�������� ������� ��� ������� ";
		cin >> number;
        break;
    case ESC:
        deleteAll(arrPointers, arrSize);
        deleteAll(arrResult, arrSize);
        return FALSE;
    }


    return TRUE;
}

void showTable(Complex** arr, int size)                                 // ����� ������� ��������
{
    cout<<"������ :"<<endl;
    for (int i = 0; i<size; i++)
    {
        cout<<i<<": ";
        if (arr[i]!=NULL)                                               // ���� ��������� �� ����� ����
        {
            cout<<*arr[i];                                              // �� ������� ������
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Complex** &arr, int size)                                // �������� �������
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

void paste(Complex)
{
    arrResult[];
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

Complex mul(Complex** arr, int number)
{
	Complex result = *model * *(arr[number]);
	return result;
}

Complex div(Complex** arr, int number)
{
	Complex result = *model * *(arr[number])
	return result;
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
