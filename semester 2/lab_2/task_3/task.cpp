/*Вам дано поле размерами NхM (2<=N,M<=100). В каждой клетке поля находятся символы:
‘.’ - можно пройти;
‘#’ - нельзя пройти;
‘S’ - начальная клетка;
‘E’ - конечная клетка;
Напишите алгоритм, который определит минимальное количество шагов для перемещения из начальной клетки в конечную. 
Если это сделать невозможно, выведите -1. Ходить во все соседние клетки, которые отмечены ‘.’ (в том числе и по диагонали).*/

#include <iostream>

using namespace std;

void Search(int i, int j, int step, int n, int m, char field[100][100], int table[100][100]) 
{
	if(step >= table[i][j])
		return;

	table[i][j] = step;

	if(field[i][j] == 'E')
		return;

	if(i + 1 < n && field[i+1][j] != '#')
		Search(i+1,j,step+1,n,m,field,table);
	if(i - 1 >= 0 && field[i-1][j] != '#')
		Search(i-1,j,step+1,n,m,field,table);
	if(j + 1 < m && field[i][j + 1] != '#')
		Search(i,j+1,step+1,n,m,field,table);
	if(j - 1 >= 0 && field[i][j - 1] != '#')
		Search(i,j-1,step+1,n,m,field,table);
	if ((i + 1 < n && j + 1 < m) && field[i + 1][j + 1] != '#')
        Search(i + 1, j + 1, step + 1, n, m, field, table);
    if ((i + 1 < n && j - 1 >= 0) && field[i + 1][j - 1] != '#')
        Search(i + 1, j - 1, step + 1, n, m, field, table);
    if ((i - 1 >= 0 && j + 1 < m) && field[i - 1][j + 1] != '#')
        Search(i - 1, j + 1, step + 1, n, m, field, table);
    if ((i - 1 >= 0 && j - 1 >= 0) && field[i - 1][j - 1] != '#')
        Search(i - 1, j - 1, step + 1, n, m, field, table);
}

int main() 
{
	char field[100][100];
	int table[100][100];

	int n, m;
	int is, js;
	int ie, je;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) 
		{
			table[i][j] = INT_MAX;
			cin >> field[i][j];
			if(field[i][j] == 'S') 
			{
				is = i;
				js = j;
			}
			else if(field[i][j] == 'E') 
			{
				ie = i;
				je = j;
			}
		}

	Search(is, js, 0, n, m, field, table);
	std::cout << table[ie][je] << std::endl;
}
