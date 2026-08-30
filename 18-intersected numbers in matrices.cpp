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
            arr[i][j] = RandomNumber(1, 100);
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

bool IsNumberExistsInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
                return true;
        }
    }

    return false;
}

void PrintIntersectedNumbersInMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    int Number = 0
        ;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix1[i][j];

            if (IsNumberExistsInMatrix(Matrix2, Number, Rows, Cols))
                cout << setw(3) << Matrix1[i][j] << "     ";
        }
    }
    cout << endl;
}

int main() 
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12} , {22,20,1} , {1,0,9}, };
    int Matrix2[3][3] = { {5,80,90} , {22,77,1} , {10,8,33}, };

    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    
    cout << "\nMatrix2:\n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers are:\n\n";
    PrintIntersectedNumbersInMatrices(Matrix1, Matrix2, 3,3);

    system("pause>0");

    return 0;
}
