#include <iostream>
#include <cstdlib>  
#include <iomanip> // this library stored the std::setw
#include <cmath>
#include <string> // this library stired the string object
#include <vector>
#include <cctype>
#include <ctime>
#include <fstream> 
#include "MyinputLib.h";
using namespace std;
using namespace MyInputLib;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 20);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "     ";
        }
        cout << endl;
    }
}

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
                NumberCount++;
        }
    }
    return NumberCount;
}

bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    short MatrixSize = Rows * Cols;
    return CountNumberInMatrix(Matrix1, 0, 3, 3) > (MatrixSize / 2);
}

int main() 
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {0,0,0,} , {0,0,9} , {9,9,9}, };

    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);


    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "\nYes: It is Sparse\n";
    else
        cout << "\nNo: It's NOT Sparce\n";


    system("pause>0");

    return 0;
}
