/*Ввести цифру N, при помощи оператора switch вывести название цифры. Предусмотреть обработку ошибочного ввода N.*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    switch (n)
    {
        case 0:
            cout << "zero";
            break;
        case 1:
            cout << "оne";
            break;
        case 2:
            cout << "two";
            break;
        case 3:
            cout << "three";
            break;
        case 4:
            cout << "four";
            break;
        case 5:
            cout << "five";
            break;
        case 6:
            cout << "six";
            break;
        case 7:
            cout << "seven";
            break;
        case 8:
            cout << "eight";
            break;
        case 9:
            cout << "nine";
            break;
    }
}