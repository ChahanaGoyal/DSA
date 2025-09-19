#include <iostream>
using namespace std;
int main()
{
    const int MAX = 100;
    int matA[MAX][MAX], matB[MAX][MAX];
    int spA[MAX * MAX][3], spB[MAX * MAX][3], spC[MAX * MAX][3];

    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matA[i][j];

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matB[i][j];
    // Convert A to triplet
    int aCount = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matA[i][j] != 0)
            {
                spA[aCount][0] = i;
                spA[aCount][1] = j;
                spA[aCount][2] = matA[i][j];
                aCount++;
            }
    spA[0][0] = rows;
    spA[0][1] = cols;
    spA[0][2] = aCount - 1;
    // Convert B to triplet
    int bCount = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matB[i][j] != 0)
            {
                spB[bCount][0] = i;
                spB[bCount][1] = j;
                spB[bCount][2] = matB[i][j];
                bCount++;
            }
    spB[0][0] = rows;
    spB[0][1] = cols;
    spB[0][2] = bCount - 1;
    // Add triplets
    int i = 1, j = 1, k = 1;
    spC[0][0] = rows;
    spC[0][1] = cols;

    while (i <= spA[0][2] && j <= spB[0][2])
    {
        int rA = spA[i][0], cA = spA[i][1];
        int rB = spB[j][0], cB = spB[j][1];

        if (rA < rB || (rA == rB && cA < cB))
        {
            spC[k][0] = rA;
            spC[k][1] = cA;
            spC[k][2] = spA[i][2];
            i++;
            k++;
        }
        else if (rB < rA || (rA == rB && cB < cA))
        {
            spC[k][0] = rB;
            spC[k][1] = cB;
            spC[k][2] = spB[j][2];
            j++;
            k++;
        }
        else
        {
            spC[k][0] = rA;
            spC[k][1] = cA;
            spC[k][2] = spA[i][2] + spB[j][2];
            i++;
            j++;
            k++;
        }
    }

    while (i <= spA[0][2])
    {
        spC[k][0] = spA[i][0];
        spC[k][1] = spA[i][1];
        spC[k][2] = spA[i][2];
        i++;
        k++;
    }

    while (j <= spB[0][2])
    {
        spC[k][0] = spB[j][0];
        spC[k][1] = spB[j][1];
        spC[k][2] = spB[j][2];
        j++;
        k++;
    }

    spC[0][2] = k - 1;

    cout << "Sparse triplet of A + B:" << endl;
    cout << "Row  Col  Val" << endl;
    for (int idx = 0; idx <= spC[0][2]; idx++)
    {
        cout << spC[idx][0] << "    "
             << spC[idx][1] << "    "
             << spC[idx][2] << endl;
    }
    return 0;
}