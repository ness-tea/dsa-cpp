#include <iostream>
using namespace std;

const int N = 5;

template <size_t N>
void RotateMatrix(uint32_t (&matrix)[N][N])
{
    for (int layer = 0; layer < N / 2; layer++)
    {
        for (int i = layer; i < N - layer - 1; i++)
        {
            uint32_t temp = matrix[layer][i];
            matrix[layer][i] = matrix[N - i - 1][layer];
            matrix[N - i - 1][layer] = matrix[N - layer - 1][N - i - 1];
            matrix[N - layer - 1][N - i - 1] = matrix[i][N - layer - 1];
            matrix[i][N - layer - 1] = temp;
        }
    }
}

template <size_t N>
void PrintMatrix(uint32_t (&matrix)[N][N])
{
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;
}

int main()
{
    uint32_t matrix[N][N] = {   {1,2,3,4,5}, 
                                {5,6,7,8,9},
                                {9,10,11,12,13},
                                {13,14,15,16,17},
                                {17,18,19,20,21}};

    PrintMatrix(matrix);
    RotateMatrix(matrix);
    PrintMatrix(matrix);

    return 0;
}