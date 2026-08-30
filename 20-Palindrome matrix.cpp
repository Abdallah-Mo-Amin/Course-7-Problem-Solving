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

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
                return false;
        }
    }
    return true;
}

int main() 
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {1,2,1} , {5,5,5} , {7,3,7}, };

    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);


    if (IsPalindromeMatrix(Matrix1, 3, 3))
        cout << "\nYes: Matrix is palindrome\n";
    else
        cout << "\nNo: Matrix is NOT palindrome\n";

    system("pause>0");

    return 0;
}
