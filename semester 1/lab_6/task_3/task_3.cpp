/*Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти столбец содержащий наименьший 
элемент матрицы и заменить все отрицательные элементы этого столбца числом 0.*/

#include <iostream>

using namespace std;

int main()
{
    const int MAX = 100;
    int n, m, matrix[MAX][MAX], min = 101, col = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
	    for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                col = j;
            }
        }
		
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if ((j == col) && (matrix[i][j] < 0))
                matrix[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
	    for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
            if (j == m - 1)
                cout << endl;
        }
}