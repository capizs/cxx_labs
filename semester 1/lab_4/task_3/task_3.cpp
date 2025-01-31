/*Переменная x может принимать 2 значения: -1 и 1. Если -1, то вывести в консоль “Negative number”, 
если положительное - “Positive number”.*/

#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    cout << (x==1 ? "Positive number" : "Negative number");
}