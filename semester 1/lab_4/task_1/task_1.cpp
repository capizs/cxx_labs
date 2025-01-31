/*Ввести натуральные числа A, B и C. Если A больше B и B больше C, то вывести A-B-C, 
если B больше A и B  кратно C, то вывести B/С+B-A, в остальных случаях вывести A+B+C.*/

#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if ((a>b) && (b>c))
    {
        std::cout << a-b-c;
    }
    else if ((b>a) && (b%c==0))
    {
        std::cout << b/c+b-a;
    }
    else
    {
        std::cout << a+b+c;
    }
}