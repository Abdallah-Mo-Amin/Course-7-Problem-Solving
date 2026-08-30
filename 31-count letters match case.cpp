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

short CountLetter(string S1, char Letter, bool MatchCase = true)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter)) // you could use to upper it will work to
                Counter++;
        }
    }

    return Counter;
}

char InvertCharcterCase(char Char1)
{
    return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

int main() 
{
    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\n\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1) << endl;
    

    cout << "Letter \'" << Ch1 << "\' ";
    cout << "Or \'" << InvertCharcterCase(Ch1) << "\' ";
    cout << "Count = " << CountLetter(S1, Ch1, false) << endl;

    system("pause>0");

    return 0;
}
