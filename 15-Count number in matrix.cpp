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

short CountNumberInMatrix(int Matrix1[3][3], int Number,short Rows, short Cols)
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

int main() 
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {9,9,0} , {0,9,0} , {0,0,9}, };

    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    int NumberToCheck = ReadNumber("\n\nEnter the number to count in matrix? ");

    cout << "Number " << NumberToCheck << " count in matrix is " 
        << CountNumberInMatrix(Matrix1, NumberToCheck, 3, 3) << endl;

    system("pause>0");


    return 0;
}
