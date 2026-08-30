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

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf(" %0*d    ",1, Matrix[i][j]);
        }
        cout << endl;
    }
}

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int FirstDigonalElement = Matrix[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {

            //check for diagonals element
            if (i == j && Matrix[i][i] != FirstDigonalElement)
            {
                return false;
            }
            //check for rest element
            else if (i != j && Matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {9,0,0} , {0,9,0} , {0,0,9}, };

    cout << "Matrix1:\n";
    PrintMatrix(Matrix1, 3, 3);


    if (IsScalarMatrix(Matrix1, 3, 3))
        cout << "\nYES: Matrix is scalar.\n";
    else
        cout << "\nNO: Matrix is not scalar.\n";

    system("pause>0");


    return 0;
}
