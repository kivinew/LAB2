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

int menu(Complex** &, int &);
void grow(Complex** &, int &);
void createObj(Complex** &, int &, int number=0);
void createCopy(Complex** &, int &, int);
void showTable(Complex** &, int);
void deleteAll(Complex** &, int);

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("LAB1: Complex numbers");

    Complex** arrPointers;                                                  // ���������� ������� ����������
    int arrSize;                                                            // ������ �������

    cout<<"������� ���������� �������� (�� ����� 1): ";
    cin>>arrSize;
    if (arrSize==0)
        arrSize = 1;
    arrPointers = new Complex* [arrSize]();                                 // ����������� �������
    system("cls");

    while (menu(arrPointers, arrSize)==TRUE);

    return 0;
}

int menu(Complex** &objectArray, int &size)                                 // ����� ������� �������� � ����
{
    system("cls");

    showTable(objectArray, size);

        cout<<"\t1        - ������� ������� ������� � ������ ������"<<endl                     // ����
            <<"\tENTER    - ������� ������� �������"<<endl
            <<"\tESC      - ����� �� ���������"<<endl;
    while (!_kbhit());
    int choice;
    choice = _getch();
    switch (choice)
    {
        case ONE:                                                           // ---------�������� ������---------
        {
            createObj(objectArray, size);
            break;
        }
        case ENTER:                                                         // --------������� ���� �������---------
        {
            int number;
            cout<<"������� ����� ������: ";
            cin>>number;
            int countObjects = Complex::getCounter();                       // ���������� �������� � �������
            if (!(number>=size) && !(number<0))
            {
                cout<<endl<<"ENTER    - ������ ������ ������������ �����"<<endl;
                if (objectArray[number]!=NULL)
                {
                    cout<<"DELETE   - ������� ����������� �����"<<endl
                        <<"SPACEBAR - ����������� ����������� �����"<<endl;
                }
                cout<<"��� ������ ������� ����� ������ �������"<<endl;
                while (!_kbhit());                                                  // �������� ������ �������
                choice = _getch();                                                  // ���������� ������!!!  1) �������� ������
                if (choice>83) choice = _getch();                                   //                       2) �������� ��� �������
                switch (choice)
                {
                case ENTER:                                                 // ------�������� ������-------
                    if (objectArray[number]!=NULL)                          // ���� ��������� �� ����� ����
                        objectArray[number]->edit();                        // �� ��� ����� ��������,
                    else                                                    //
                        createObj(objectArray, size, number);               // � ����� �������
                    break;
                case DEL:                                                   // --------�������� ��������� �� ������---------
                    Complex::del(objectArray[number]);
                    break;
                case SPACEBAR:                                              // --------��������� ����������� �����������---------
                    if (objectArray[number]!=NULL)
                        createCopy(objectArray, size, number);
                    break;
                }
            }
            else
            {
                cout<<"����� �� ������� �������!";
                _getch();
            }
            break;
        }
        case ESC:                                                           // ---------����� �� ���������---------
            deleteAll(objectArray, size);
            return FALSE;
            break;
    }
    return TRUE;
}

void grow(Complex** &arr, int &size)                // ���������� ������� ���������� � ��� ����
{
    int newSize;                                    // ����� ������ �������
    newSize = size*2;
    Complex** newArr;                               // ����� ������
    newArr = new Complex*[newSize];
    for (int i = 0; i<newSize; i++)
    {
        if (i<size)                                 // �������� ��������� ������� �������
            newArr[i] = arr[i];                     // ����������� ��������� ������
        else
            newArr[i] = NULL;                       
    }
    delete [] arr;                                  // ����� ������ ������
    arr = newArr;                                   // � ��� ��������� �������� �����
    size = newSize;
    return ;
}

void createObj(Complex** &arr, int &size, int elementNumber)        // ������� ������
{
    if (Complex::getCounter()==size)                                // ���� ���������� �������� ����� ������� �������
        grow(arr, size);                                            // �� ��� ����� ���������
    for (int i=elementNumber; i<size; i++)
	{
		if (arr[i]==NULL)                          	                // ���� ��������� �������, ��
        {                                                           // 
            arr[i] = new Complex(-1, 1);                            // ������� � ���� ������ ������
            return;
        }
	}
    return;
}

void createCopy(Complex** &arr, int &size, int elementToCopy)               // ����������� ������
{
    if (Complex::getCounter()==size)                                        // ���� ���������� �������� ����� ������� �������
        grow(arr, size);                                                    // �� ��� ����� ���������
    for (int i = 0; i<size; i++)
    {
        if (arr[i]==NULL)                          	                        // ���� ��������� �������, ��
        {                                                                   // 
            arr[i] = new Complex(*arr[elementToCopy]);                      // ������� � ���� ������ ������
            return;
        }
    }
    return;
}

void showTable(Complex** &arr, int size)                                    // ����� ������� ��������
{
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (int i = 0; i<size; i++)
    {
        cout<<i<<": ";
        if (arr[i]!=NULL)                                                   // ���� ��������� �� ����� ����
        {
            (*arr[i]).showObject();                                         // �� ������� ������
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
