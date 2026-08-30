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

int RandomNumber(int From, int To)
{
    int randomNumber = rand() % (To - From + 1) + From;
    return randomNumber;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1,10);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d    ",2, Matrix[i][j]);
        }
        cout << endl;
    }
}

void PrintMiddleRowOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows / 2;
  
    for (short j = 0; j < Cols; j++)
    {
        printf(" %0*d    ", 2, Matrix[MiddleRow][j]);
    }
    cout << "\n";
}

void PrintMiddleColOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short MiddleCol = Cols / 2;

    for (short i = 0; i < Rows; i++)
    { 
        printf(" %0*d    ",2, Matrix[i][MiddleCol]); 
    }
    cout << "\n";
}

int main() 
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\n\nMiddle Row of Matrix1 is:\n";
    PrintMiddleRowOfMatrix(Matrix1, 3, 3);

    cout << "\n\nMiddle Col of Matrix1 is:\n";
    PrintMiddleColOfMatrix(Matrix1, 3, 3);

    system("pause>0");

    return 0;
}
