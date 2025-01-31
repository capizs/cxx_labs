/*Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
Упорядочить последовательность по неубыванию произведения цифр числа,
числа с одинаковыми произведениями цифр дополнительно упорядочить по неубыванию первой цифры числа,
числа с одинаковыми произведениями цифр и одинаковыми первыми цифрами дополнительно упорядочить по неубыванию самого числа.
*/

#include <iostream>

using namespace std;

int main()
{
    const short N_MAX = 1000;
    int mas[N_MAX];
    int mult_mas[N_MAX];
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        mas[i] = num;
        
        int digits_mul = 1;
        while (num > 0)
        {
            digits_mul *= num % 10;
            num /= 10;
        }
        mult_mas[i] = digits_mul;
    }
    
    int a, b;
    int mul_a, mul_b;
    short first_a, first_b;

    for (int i = 0; i < n - 1; i++)
    {
        a = mas[i];
        while (a > 0)
        {
            first_a = a % 10;
            a /= 10;
        }
        a = mas[i];
        mul_a = mult_mas[i];

	    for (int j = i + 1; j < n; j++)
	    {            
            b = mas[j];
            while (b > 0)
            {
                first_b = b % 10;
                b /= 10;
            }
            b = mas[j];
            mul_b = mult_mas[j];

            if (mul_a == mul_b)
            {
                if (first_a == first_b)
                {
                    if (a > b)
                    {
                        swap(mas[i], mas[j]);
                        swap(mult_mas[i], mult_mas[j]);
                    }
                }
                else
                {
                    if (first_a > first_b)
                    {
                        swap(mas[i], mas[j]);
                        swap(mult_mas[i], mult_mas[j]);
                    }
                }
            }
            else
            {
                if (mul_a > mul_b)
                {
                    swap(mas[i], mas[j]);
                    swap(mult_mas[i], mult_mas[j]);
                }
            }
            cout << endl;
	    }
    }

    for (int i = 0; i < n; i++)
	    cout << mas[i] << " ";
}