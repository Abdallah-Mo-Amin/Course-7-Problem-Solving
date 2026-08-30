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

short CountLetter(string S1, char Letter)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Letter)
            Counter++;
    }

    return Counter;
}

int main() 
{
    string S1 = ReadString();
    char Ch1 = ReadChar();

    cout << "\n\nLetter \'" << Ch1 << "\' Count = " << CountLetter(S1, Ch1) << endl;
    
    system("pause>0");

    return 0;
}
