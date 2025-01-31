#include <iostream>
using namespace std;

namespace lab
{
    void Read(int A[100][100], int& n)
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin >> A[i][j];
        return;
    }

    bool Exist(int n)
    {
	    while (n > 0)
	    {
		    if ((n % 10 == 3) || (n % 10 == 5))
                return true;
		    n /= 10;
	    }
        return false;
    }

    bool Check(int A[100][100], int& n)
    {
        int count = 0, count2 = 0;
        for (int i=0; i<n; i++)
            {
                if ((A[i][n - i - 1] > 0) && Exist(A[i][n - i - 1]))
                {
                    count += 1;
                }
                if ((A[i][i] > 0) && Exist(A[i][i]))
                {
                    count += 1;
                }
            }
        cout << count << endl;
        return count == n * 2;
    }

    void Edit(int A[100][100], int& n)
    {
        for (int i=0; i<n; i++)
            {
                int min = 1000, min_n = INT_MAX, sum = 0;
                for (int j=0; j<n; j++)
                {
                    sum += A[j][i] * A[j][i];
                    if (A[j][i] < min_n)
                    {   
                        min = j;
                        min_n = A[j][i];
                    }
                }
                A[min][i] = sum;
            }
            
    }

    void Write(int A[100][100], int& n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cout << A[i][j] << " ";
                if (j == n - 1)
                    cout << endl;
            }
    }
}
