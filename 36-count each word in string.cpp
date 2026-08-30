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

short CountWords(string S1)
{
    string delim = " ";
    short Counter = 0;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            Counter++;
        }
        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        Counter++;
    }

    return Counter;
}

int main() 
{
    string S1 = ReadString();
    cout << "The number of words in your string is: "
        << CountWords(S1) << endl;

    system("pause>0");


    return 0;
}
