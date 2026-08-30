#include <iostream>
#include <cstdlib>  
#include <iomanip> // this library stored the std::setw
#include <cmath>
#include <string> // this library stired the string object
#include <vector>
#include <cctype>
#include <ctime>
#include <fstream> 
#include "MyinputLib.h"

using namespace std;
using namespace MyInputLib;

char ReadChar()
{
    char C1 = ' ';
    cout << "Please Enter a character?\n";
    cin >> C1;
    return C1;
}


char InvertCharcterCase(char Char1)
{
    return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

int main() 
{
    char Ch1 = ReadChar();

    cout << "\nChar after inberting case:\n";
    cout << InvertCharcterCase(Ch1) << endl;

    system("pause>0");

    return 0;
}
