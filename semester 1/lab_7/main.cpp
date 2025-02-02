/*При выполнении лабораторной работы используйте процедуры и функции:
1. 	Функция чтения
2. 	Функция обработки (может быть несколько)
3. 	Функция записи
Их необходимо расположить в отдельных файлах (*.hpp и *.cpp) в отдельном пространстве имен.
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если все диагональные элементы матрицы положительны и 
содержат цифры 3 или 5, заменить минимальные элементы столбцов на суммы квадратов элементов соответствующих столбцов.*/

#include <iostream>
#include "func.hpp"

using namespace std;
using namespace lab;

int main()
{
    int n;
    int A[100][100];
    cin >> n;
    Read(A, n);
    if (Check(A, n))
    {
        Edit(A, n);
    }
    Write(A, n);
}