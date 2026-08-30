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
    cout << "\nPlease Enter a character?\n";
    cin >> C1;
    return C1;
}

bool IsVowel(char char1)
{
    char1 = tolower(char1);
    return ((char1 == 'a') || (char1 == 'e') || (char1 == 'i') || (char1 == 'o') || (char1 == 'u'));
}


int main() 
{
    char Ch1 = ReadChar();

    if (IsVowel(Ch1))
        cout << "YES Letter \'" << Ch1 << "\' is vowel\n";
    else
        cout << "NO Letter \'" << Ch1 << "\' is NOT vowel\n";

    system("pause>0");

    return 0;
}
