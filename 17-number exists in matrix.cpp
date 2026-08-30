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

int main() 
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12} , {22,20,1} , {1,0,9}, };

    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    int Number = ReadNumber("\nPlease Enter the number to look for in the matrix? ");


    // using count is slower method
    if (CountNumberInMatrix(Matrix1, Number, 3, 3) > 0)
        cout << "\nYes: it is there\n";
    else
        cout << "\nNo: No it is NOT there\n";

    // using faster methos
    if (IsNumberExistsInMatrix(Matrix1, Number, 3, 3))
        cout << "\nYes: It is there\n";
    else
        cout << "\nNo: It's NOT there\n";


    system("pause>0");

    return 0;
}
