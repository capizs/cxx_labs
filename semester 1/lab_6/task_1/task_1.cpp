/*Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Если в последовательности есть хотя бы одно число, 
сумма цифр которого равна 14, упорядочить последовательность по неубыванию.*/

#include <iostream>

using namespace std;

int main()
{
    const int MAX = 10000;
    int n, numbers[MAX];
    bool flag;
    cin >> n;
    flag = false;
    for (int i=0; i<n; i++)
    {
        cin >> numbers[i];
    }
    for (int i=0; i<n; i++)
    {
        if (numbers[i]>=59)
        {
            int sum = 0;
            int num = numbers[i];
            while (num != 0)
            {
                sum += (num % 10);
                num /= 10;
            }
            if (sum == 14)
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
    {
        for (int i=0; i<(n-1); i++)
	        for (int j=i+1; j<n; j++)
	        {
		        if (numbers[i] > numbers[j])
		        {
			        int tmp = numbers[i];
			        numbers[i] = numbers[j];
			        numbers[j] = tmp;
		        }
	        }
    }
    for (int i=0; i<n; i++){
        cout << numbers[i] << " ";
    }

    /*if (n>=59)
    {
        for (int i=0; i<n; i++)
        {
	        cout << numbers[i];
        }
    }*/
}