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

int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Min = Matrix1[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] < Min)
                Min = Matrix1[i][j];
        }
    }
    return Min;
}

int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Max = Matrix1[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] > Max)
                Max = Matrix1[i][j];
        }
    }
    return Max;
}

int main() 
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12} , {22,20,6} , {14,3,9}, };

    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);
    

    cout << "\nMinimum Number is: " << MinNumberInMatrix(Matrix1, 3, 3) << endl;
    cout << "\n\nMax Number is  : " << MaxNumberInMatrix(Matrix1, 3, 3) << endl;

    system("pause>0");

    return 0;
}
