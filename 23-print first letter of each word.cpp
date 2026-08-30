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

string ReadString()
{
    string text = "";
    cout << "Please Enter your string?\n";
    getline(cin, text);
    return text;
}

void PrintFirstLetterOfEachWord(string Text)
{
    bool IsFirstLetter = true;

    cout << "\nFirst Letter of this string:\n" << endl;
    for (int i = 0; i < Text.length() - 1; i++)
    {
        if (Text[i] != ' ' && IsFirstLetter)
        {
            cout << Text[i] << endl;
        }

        IsFirstLetter = (Text[i] == ' ' ? true : false);
    }
}

int main() 
{
    PrintFirstLetterOfEachWord(ReadString());

    system("pause>0");

    return 0;
}
