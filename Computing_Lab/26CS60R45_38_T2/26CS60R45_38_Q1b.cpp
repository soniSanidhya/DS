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
    int n;
    cin >> n;
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
        for (int j = 0; j < n; j++)

        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}