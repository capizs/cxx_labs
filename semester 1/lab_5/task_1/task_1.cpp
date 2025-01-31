/*Дана последовательность целых чисел {Aj}. Найти произведение чисел, лежащих на отрезке [-2,20], 
наименьшее из таких чисел и номер этого числа в последовательности.*/

#include <iostream>

using namespace std;

int main()
{
    int mult=1, j, i, min=24, n_min=-1;
    cin >> j;
    for (i=0;i!=j;++i)
    {
        int x;
        cin >> x;
        if ((x>=-2)&&(x<=20))
        {
            mult*=x;
            if (x<min)
            {
                min = x;
                n_min = i+1;
            }
        }
    }
    if (min!=24)
    {
        cout << mult << " " << min << " " << n_min;
    }
    else
    {
        cout << "nothing";
    }
    
}