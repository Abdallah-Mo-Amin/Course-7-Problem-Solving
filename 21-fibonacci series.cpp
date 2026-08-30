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


void PrintFibonacciSeries(int N)
{
    // This is my solution
    long double FebNumber = 0, Prev1 = 0, Prev2 = 1;
    for (int i = 1; i <= N; i++)
    {
        FebNumber = Prev1 + Prev2;
        printf("%0.0Lf   ", FebNumber);
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

void PrintFibonacciUsingLoop(short Number)
{
    int FebNumber = 0;
    int Prev2 = 0, Prev1 = 1;
    cout << "1   ";
    for (short i = 2; i <= Number; i++)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << "   ";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main() 
{ 
    PrintFibonacciSeries(15);
    cout << endl;
    PrintFibonacciUsingLoop(15);
    system("pause>0");

    return 0;
}
