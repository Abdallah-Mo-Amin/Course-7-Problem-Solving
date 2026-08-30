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

short CountVowels(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
        {
                Counter++;
        }
    }

    return Counter;
}

int main() 
{
    string S1 = ReadString();

    cout << "\nNumber of vouls is: " << CountVowels(S1) << endl;

    system("pause>0");

    return 0;
}
