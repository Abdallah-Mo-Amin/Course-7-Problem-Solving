#include <iostream>
#include <cstdlib>  
#include <iomanip> // this library stored the std::setw
#include <cmath>
#include <string> // this library stired the string object
#include <cctype>

#include "MyinputLib.h";
using namespace std;
using namespace MyInputLib;


void PrintFibonacciUsingRecusion(short Number, int Prev1, int Prev2)
{
    int FebNumber = 0;

    if (Number > 0)
    {
        FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;

        cout << FebNumber << "   ";
        PrintFibonacciUsingRecusion(Number - 1, Prev1, Prev2);
    }
}



int main() 
{ 
    PrintFibonacciUsingRecusion(10, 0, 1);
    system("pause>0");

    return 0;
}
