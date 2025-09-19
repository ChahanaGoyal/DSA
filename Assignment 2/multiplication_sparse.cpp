#include <iostream>
using namespace std;
int main()
{
    const int MAX = 100;
    int A[MAX][MAX], B[MAX][MAX];
    int spA[MAX * MAX][3], spB[MAX * MAX][3], spC[MAX * MAX][3];

    int rowsA, colsA, rowsB, colsB;
    cout << "Enter rows and cols of Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter elements of A:" << endl;
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            cin >> A[i][j];

    cout << "Enter rows and cols of Matrix B: ";
    cin >> rowsB >> colsB;
    cout << "Enter elements of B:" << endl;
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            cin >> B[i][j];

    if (colsA != rowsB)
    {
        cout << "Incompatible dimensions for multiplication" << endl;
        return 1;
    }
    // Convert A to triplet form
    int aCount = 1;
    spA[0][0] = rowsA;
    spA[0][1] = colsA;
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            if (A[i][j] != 0)
            {
                spA[aCount][0] = i;
                spA[aCount][1] = j;
                spA[aCount][2] = A[i][j];
                aCount++;
            }
    spA[0][2] = aCount - 1;
    // Convert B to triplet form
    int bCount = 1;
    spB[0][0] = rowsB;
    spB[0][1] = colsB;
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            if (B[i][j] != 0)
            {
                spB[bCount][0] = i;
                spB[bCount][1] = j;
                spB[bCount][2] = B[i][j];
                bCount++;
            }
    spB[0][2] = bCount - 1;
    // Multiply: C = A * B
    spC[0][0] = rowsA;
    spC[0][1] = colsB;
    int cCount = 1;

    for (int i = 1; i <= spA[0][2]; i++)
    {
        for (int j = 1; j <= spB[0][2]; j++)
        {
            if (spA[i][1] == spB[j][0])
            {
                int r = spA[i][0];
                int c = spB[j][1];
                int v = spA[i][2] * spB[j][2];
                // Check if an entry (r,c) already exists in spC
                bool found = false;
                for (int x = 1; x < cCount; x++)
                {
                    if (spC[x][0] == r && spC[x][1] == c)
                    {
                        spC[x][2] += v;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    spC[cCount][0] = r;
                    spC[cCount][1] = c;
                    spC[cCount][2] = v;
                    cCount++;
                }
            }
        }
    }
    spC[0][2] = cCount - 1;

    cout << "Product sparse triplet (row, col, value):" << endl;
    for (int idx = 0; idx <= spC[0][2]; idx++)
    {
        cout << spC[idx][0] << "   "
             << spC[idx][1] << "   "
             << spC[idx][2] << endl;
    }
    return 0;
}
