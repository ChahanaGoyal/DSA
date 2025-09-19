#include <iostream>
using namespace std;
int main()
{
    const int MAX = 100;
    int matrix[MAX][MAX];
    int spmatrix[MAX * MAX][3];
    int transpose[MAX * MAX][3];

    int rows, cols;
    cout << "Enter number of rows and columns: " << endl;
    cin >> rows >> cols;

    cout << "Enter matrix elements row-wise:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];
    // Convert to triplet form
    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                spmatrix[k][0] = i;
                spmatrix[k][1] = j;
                spmatrix[k][2] = matrix[i][j];
                ++k;
            }
        }
    }
    spmatrix[0][0] = rows;
    spmatrix[0][1] = cols;
    spmatrix[0][2] = k - 1;
    // Display sparse triplet
    cout << "Sparse triplet (row, col, value):\n";
    for (int i = 0; i <= spmatrix[0][2]; i++)
    {
        cout << spmatrix[i][0] << "  "
             << spmatrix[i][1] << "  "
             << spmatrix[i][2] << endl;
    }
    // Compute transpose in triplet form
    transpose[0][0] = spmatrix[0][1];
    transpose[0][1] = spmatrix[0][0];
    transpose[0][2] = spmatrix[0][2];

    int t = 1;
    for (int col = 0; col < cols; col++)
    {
        for (int i = 1; i <= spmatrix[0][2]; i++)
        {
            if (spmatrix[i][1] == col)
            {
                transpose[t][0] = spmatrix[i][1];
                transpose[t][1] = spmatrix[i][0];
                transpose[t][2] = spmatrix[i][2];
                ++t;
            }
        }
    }
    // Display transposed sparse triplet
    cout << "Transposed sparse triplet (row, col, value):\n";
    for (int i = 0; i <= transpose[0][2]; i++)
    {
        cout << transpose[i][0] << "  "
             << transpose[i][1] << "  "
             << transpose[i][2] << endl;
    }
    return 0;
}