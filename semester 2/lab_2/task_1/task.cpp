/*Дано натуральной число N (N<2^31), выведите его наоборот с использованием рекурсии.*/

#include <iostream>

using namespace std;

int flip(int num, int res = 0)
{
    if (num == 0)
        return res;
    return flip(num / 10, res * 10 + num % 10);
}

int main()
{
    int num;
    cin >> num;
    cout << flip(num);
}