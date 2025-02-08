/*Реализуйте быструю сортировку. Изучите, как она работает. Сравните скорость работы с сортировкой обменами.*/

#include <iostream>
#include <thread>

using namespace std;

void QuickSort(int a, int b, int* arr)
{
	if (a >= b)
		return;
	//выбор опорного элемента
	int m = arr[(a + b) / 2];
	//пресорт
	int l = a - 1;
	int r = b + 1;
	while (1)
	{
		do l++; while (arr[l] < m);
		do r--; while (arr[r] > m);
		if (l >= r)
			break;
		swap(arr[l], arr[r]);
	}
	l = r;
	r++;
	QuickSort(a, l, arr);
	QuickSort(r, b, arr);
}

int main()
{
	const int n = 10;
	int arr[10] = {2, 3, 9, 10, 34, 23, 9, 100};
	QuickSort(0, n - 1, arr);
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}