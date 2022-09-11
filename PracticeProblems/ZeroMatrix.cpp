#include <iostream>
using namespace std;

const int M = 5, N = 5;

template <size_t M, size_t N>
void PrintMatrix(int (&matrix)[M][N])
{
    cout << endl;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;
}

template<size_t M, size_t N>
void NullifyRow(int (&matrix)[M][N], int row)
{
    for (int i = 0; i < N; i++)
    {
        matrix[row][i] = 0;
    }
}

template<size_t M, size_t N>
void NullifyCol(int (&matrix)[M][N], int col)
{
    for (int i = 0; i < M; i++)
    {
        matrix[i][col] = 0;
    }
}

template<size_t M, size_t N>
void ZeroMatrix(int (&matrix)[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for (int i = 1; i < M; i++)
    {
        if (matrix[0][i] == 0)
        {
            NullifyCol(matrix, i);
        }
    }

    for (int i = 1; i < M; i++)
    {
        if (matrix[i][0] == 0)
        {
            NullifyRow(matrix, i);
        }
    }

    if (matrix[0][0] == 0)
    {
        NullifyCol(matrix, 0);
        NullifyRow(matrix, 0);
    }
}

int main()
{
    int matrix[N][N] = {   {1,2,0,4,5}, 
                           {5,6,7,8,9},
                           {0,1,1,0,1},
                           {3,1,1,6,7},
                           {7,8,1,2,2}};

    PrintMatrix(matrix);
    ZeroMatrix(matrix);
    PrintMatrix(matrix);

    return 0;
}