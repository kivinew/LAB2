/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
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
    cout<<"������� ��������� ������ Complex: "<<endl;
    cin>>*model;
    system("cls");
    Complex** arrPointers;                                                      // ���������� ������� ����������
    int arrSize;                                                                // ������ �������
    arrSize = 10;                                 
    arrPointers = new Complex*[arrSize]();                                      // ����������� �������
    for (int i = 0; i<arrSize; i++)
        insert(arrPointers, i);                                                 // ��������� ������ �������
    while (menu2(arrPointers, arrSize)==TRUE);
    delete model;
    return 0;
}


int menu2(Complex** &objectArray, int&size)                                     // ���� LAB2
{
    system("cls");
    showTable(objectArray, size);
    cout<<endl<<"1 - �������� ����������� �����"<<endl
        <<"2 - ��������� ����������� �����"<<endl
        <<"3 - ��������� �������� �������"<<endl
        <<"4 - ��������� �������� �������"<<endl
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

void insert(Complex** &arr, int number)                                         // ��������� ������ �������
{                                                                               // cin>>Complex
    cout<<"������� "<<number<<"-� ������� �������"<<endl;
    cin>>*arr[number];
}

void showTable(Complex** &arr, int size)                                    // ����� ������� ��������
{
    cout<<"������ :"<<endl;
    for (int i = 0; i<size; i++)
    {
        cout<<i<<": ";
        if (arr[i]!=NULL)                                                   // ���� ��������� �� ����� ����
        {
            cout<<(*arr[i]);                                         // �� ������� ������
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Complex** &arr, int size)                // �������� �������
{
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);                           // �������� �������� �������
    }
    delete[] arr;                                       // �������� �������
    cout<<"������ �����"<<endl;
    _getch();
    return;
}
