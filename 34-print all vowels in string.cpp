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

string ReadString()
{
    string S1 = "";
    cout << "Please enter your string?\n";
    getline(cin, S1);

    return S1;
}

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

void PrintVowels(string S1)
{
    cout << "\nVowels in string are: ";
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            cout << S1[i] << "    ";
    }
}

int main() 
{
    string S1 = ReadString();

    PrintVowels(S1);

    system("pause>0");

    return 0;
}
