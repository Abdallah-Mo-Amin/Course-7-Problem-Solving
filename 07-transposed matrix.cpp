#include <iostream>
#include <cstdlib>  
#include <iomanip> // this library stored the std::setw
#include <cmath>
#include <string> // this library stired the string object
#include <vector>
#include <cctype>
#include <ctime>
#include <fstream> 
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
    short Counter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Counter++;
            arr[i][j] = Counter;
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arrTransposed[i][j] = arr[j][i];
        }
    }
}

int main() 
{
    srand((unsigned)time(NULL));

    int arr[3][3], arrTransposed[3][3];

    FillMatrixWithOrderedNumbers(arr, 3, 3);
    cout << "The following is a 3x3 orderd matrix:\n";
    PrintMatrix(arr, 3, 3);

    TransposeMatrix(arr, arrTransposed, 3, 3);
    cout << "\nThe following is the transposed matrix:\n";
    PrintMatrix(arrTransposed, 3, 3);

    system("pause>0");

    return 0;
}
