/*Дано натуральное число N (N<10^9). Найти сумму четных цифр числа N.*/

#include <iostream>

using namespace std;

int main()
{
    int n, s=0, k;
    cin >> n;
    do
    {
        k = n%10;
        if (k%2==0)
        {
            s+=k;
        }
        n/=10;
    } 
    while (n!=0);
    cout << s;
}