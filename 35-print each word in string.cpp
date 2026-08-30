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


void PrintEachWordInString(string S1)
{
    string delim = " "; // delimiter

    cout << "\nYour string words are: \n\n";
    short pos = 0;
    string sWord; //define a string variable
   

    // use find() function to get the position of the delimiter
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); //store the word
        if (sWord != "")
        {
            cout << sWord << endl;
        }

        S1.erase(0, pos + delim.length()); // erase() until position and move to next word.
    }

    if (S1 != "")
    {
        cout << S1 << endl; // it prints the last word of the string
    }
}

int main() 
{
    PrintEachWordInString(ReadString());

    system("pause>0");


    return 0;
}
