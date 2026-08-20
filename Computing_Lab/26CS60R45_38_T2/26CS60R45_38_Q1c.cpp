#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int matrix[n][n];
    for (int i = 0; i < n; i++)

    {
        for (int j = 0; j < n; j++)

        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = 0; k < n - j - 1; k++)
            {
                if (matrix[i][k] > matrix[i][k + 1])
                {

                    swap(&matrix[i][k], &matrix[i][k + 1]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = 0; k < n - j - 1; k++)
            {
                if (matrix[k][i] < matrix[k + 1][i])
                {

                    swap(&matrix[k][i], &matrix[k + 1][i]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int l = 0;
        int h = n;
        bool f = 0;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (matrix[i][mid] == x)
            {
                f = 1;
                break;
            }
            else if (matrix[i][mid] < x)
            {
                h = mid - 1;
            }
            else
            {

                l = mid + 1;
            }
        }
        if (f)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;

    return 0;
}