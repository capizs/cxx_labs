/*Сначала введите последовательность. Затем удалите и продублируйте элементы. Затем выведите полученную последовательность 
(каждый элемент по одному разу). Используйте в программе только один массив.
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). Удалить из последовательности числа, 
содержащие хотя бы пару одинаковых цифр, а среди оставшихся продублировать числа, содержащие цифру 5.*/

#include <iostream>

using namespace std;

int main()
{
    int n, count = 0;
    int arr[10000];
    
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int digits[10] = {0};
        bool hasDuplicates = false;
        bool hasFive = false;
        
        while (num > 0) {
            int digit = num % 10;
            if (digit == 5) hasFive = true;
            digits[digit]++;
            if (digits[digit] > 1) {
                hasDuplicates = true;
                break;
            }
            num /= 10;
        }
        
        if (!hasDuplicates) {
            arr[newSize] = arr[i];
            newSize++;
            if (hasFive) {
                arr[newSize] = arr[i];
                newSize++;
            }
        }
    }
    
    for (int i = 0; i < newSize; i++) {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
