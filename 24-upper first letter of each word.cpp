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
    string text = "";
    cout << "Please Enter your string?\n";
    getline(cin, text);
    return text;
}

string UpperFirstLetterOfEachWord(string Text)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && IsFirstLetter)
        {
            Text[i] = toupper(Text[i]);
        }

        IsFirstLetter = (Text[i] == ' ' ? true : false);
    }

    return Text;
}

int main() 
{
    string S1 = ReadString();

    cout << "String after conversion:\n";
    S1 = UpperFirstLetterOfEachWord(S1);
    cout << S1 << endl;


    system("pause>0");

    return 0;
}
